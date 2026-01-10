/*#include <iostream>
#include <cstdlib>
using namespace std;
template<typename T>
class node {
public:
    T data;
    node<T> *next;

    node(T value) {
        data = value;
        next = nullptr;
    }
};
template<typename T>
class linkedList {
public:
    node<T> *head;

    linkedList() {
        head = nullptr;
    }

    void insertAtBeginning(T value) {
        node<T> *newNode = new node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(T value) {
        node<T> *temp = head;
        node<T> *newNode = new node<T>(value);
        if (temp == nullptr) {
            head = newNode;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfterValue(T target, T value) {
        node<T>* newNode=new node<T>(value);
        node<T>* current=head;
        while (current->data!=target) {
            if (current->next==nullptr) {
                cout<<"Value does not exist! "<<endl;
                return;
            }
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }

    void display() {
        node<T> *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int get_card(string card)
{
    string value = card.substr(1);

    if (value == "A")
{
    
    return 1;

    }

    if (value == "J")
    {
        
        return 11;
    }
    if (value == "Q")
    {
return 12;

    }
    if (value == "K")

    {
return 13;
    }
    return stoi(value);
}

template <typename T>*/
class setup {
public:
    bool gameOver;
    bool gameWon;
    linkedList stack1;
    linkedList stack2;
    linkedList array1, array2, array3, array4;

    string cards[52];

    setup() {
        gameOver = false;
        gameWon = false;

        string cardArray[52] = {
            "SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK",
            "HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
            "DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
            "CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"
        };
   for(int i = 0; i < 52; i++) {
            cards[i] = cardArray[i];
        }
    }

    void shuffle() {
        for (int i = 51; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(cards[i], cards[j]);
        }
    }

    void initGame() {
        stack1.clear();
        stack2.clear();
        array1.clear();
        array2.clear();
        array3.clear();
        array4.clear();
        gameOver = false;
        gameWon = false;

        shuffle();

        int c = 0;
        for (int i = 0; i < 3; i++) array1.insertAtEnd(cards[c++]);
        for (int i = 0; i < 6; i++) array2.insertAtEnd(cards[c++]);
        for (int i = 0; i < 9; i++) array3.insertAtEnd(cards[c++]);
        for (int i = 0; i < 10; i++) array4.insertAtEnd(cards[c++]);

        for (int i = 0; i < 23; i++) stack1.insertAtEnd(cards[c++]);
        stack2.insertAtEnd(cards[c++]);

        initializeChildren();
        updateReveals();
    }

    void initializeChildren() {
        node* t3 = array3.head;
        node* t4 = array4.head;
        while (t3 && t4) {
            t3->child1 = t4;
            t3->child2 = t4->next;
            t3 = t3->next;
            t4 = t4->next;
        }

        node* t2 = array2.head;
        t3 = array3.head;
        int idx = 0;
        while (t2 && t3) {
            t2->child1 = t3;
            t2->child2 = t3->next;

            if (idx == 1 || idx == 3) t3 = t3->next->next;
            else t3 = t3->next;
            t2 = t2->next;
            idx++;
        }

        node* t1 = array1.head;
        t2 = array2.head;
        while (t1 && t2) {
            t1->child1 = t2;
            t1->child2 = t2->next;
            t2 = t2->next->next;
            t1 = t1->next;
        }
    }

    void updateReveals() {
        auto checkAndReveal = [](linkedList& list) {
            node* temp = list.head;
            while (temp) {
                if (!temp->child1 && !temp->child2) {
                    temp->revealed = true;
                } else if ((!temp->child1 || temp->child1->removed) &&
                         (!temp->child2 || temp->child2->removed)) {
                    temp->revealed = true;
                }
                temp = temp->next;
            }
        };
        checkAndReveal(array4);
        checkAndReveal(array3);
        checkAndReveal(array2);
        checkAndReveal(array1);
    }

  

int getRankValue(char r) {
        if (r == 'A') return 1;
        if (r == 'T') return 10;
        if (r == 'J') return 11;
        if (r == 'Q') return 12;
        if (r == 'K') return 13;
        return r - '0';
    }

    bool isValidMove(string cardData) {
        node* top = stack2.getTail();
        if (!top) return true;

        int v1 = getRankValue(cardData[1]);
        int v2 = getRankValue(top->data[1]);

        if (abs(v1 - v2) == 1) return true;
        if ((v1 == 1 && v2 == 13) || (v1 == 13 && v2 == 1)) return true;

        return false;
    }




  void drawCard(string data, int x, int y, bool rev, bool rem) {
        if (rem) return;
        Rectangle rect = {(float)x, (float)y, 70, 90};

        if (!rev) {
            DrawRectangleRec(rect, BLUE);
            DrawRectangleLinesEx(rect, 2, DARKBLUE);
            DrawText("?", x + 25, y + 30, 30, WHITE);
        } else {
            DrawRectangleRec(rect, WHITE);
            DrawRectangleLinesEx(rect, 2, BLACK);
            Color txtCol = (data[0] == 'H' || data[0] == 'D') ? RED : BLACK;
            DrawText(data.c_str(), x + 15, y + 30, 25, txtCol);
        }
    }
/*void displayPeaks() 
 {
    node<string>* current = peaksLL.head;
    int i = 0;
    while (current != nullptr)
    
    {
if (revealed[i])
 cout << current->data << " ";
        else
    cout << "* ";
        current = current->next;
        i++;
    }
    cout << endl;
}


};

void start() {
    game<string> Tripeaks;
    int randomTimes = rand() %1000;
    for (int i=0;i<=randomTimes;i++) {
        Tripeaks.shuffleArray(Tripeaks.cards);
    }

    Tripeaks.makeStack1(Tripeaks.cards);
    Tripeaks.makeStack2(Tripeaks.cards);
    Tripeaks.displayStack1();
    Tripeaks.displayStack2();
    Tripeaks.peaks();
}

int main() {
    start();




}*/
