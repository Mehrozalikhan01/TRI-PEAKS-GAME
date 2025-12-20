#include <iostream>
#include <ctime>
using namespace std;
class node {
public:
    string data;
    node *next;
    bool revealed;
    bool removed;
    node(string value) {
        data = value;
        next = nullptr;
        revealed=false;
    }
};
class linkedList {
public:
    node *head;
    linkedList() {
        head = nullptr;
    }

    void insertAtBeginning(string value) {
        node *newNode = new node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(string value) {
        node *temp = head;
        node *newNode = new node(value);
        if (temp == nullptr) {
            head = newNode;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfterValue(string target, string value) {
        node* newNode=new node(value);

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        node* current=head;
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
        node* current = head;
        while (current != nullptr) {
            if (current->revealed==true) {
                cout << current->data << " ";
            }
            else {
                cout<<"*";
            }
            current = current->next;
        }
    }
};

class peakNode {
public:
    string data;
    int level;
    bool revealed;
    bool removed;
    peakNode* next;

    peakNode(string value){
        data=value;
        revealed=false;
        removed=false;
        next=nullptr;
    }
    peakNode(){
        data="";
        revealed=false;
        removed=false;
        next=nullptr;
    }
};
class peakList {
public:
    peakNode* head;

    peakList() {
        head=nullptr;
    }

    void insertEnd(string value) {
        peakNode *temp = head;
        peakNode *newNode = new peakNode(value);
        if (temp == nullptr) {
            head = newNode;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(int level) {
        int countForLevel2=0;
        int countForLevel3=0;
        if (level==1) {
            cout<<"            ";
        }
        else if (level==2) {
            cout<<"        ";
        }
        else if (level==3) {
            cout<<"    " ;
        }
        else {
            cout<<"";
        }
        peakNode* current = head;
        while (current != nullptr) {
            if (level==1) {
                cout<<"    ";
            }
            else if (level==2) {
                cout<<"    ";
            }
            else if (level==3) {
                cout<<"    " ;
            }
            else if (level==4){
                cout<<"    ";
            }
            else {

            }
            cout << current->data;
            countForLevel2++;
            countForLevel3++;

            if (level==1) {
                cout<<"           ";
            }
            else if (level==2&&(countForLevel2==2||countForLevel2==4||countForLevel2==6)) {
                cout<<"     ";
            }
            else if (level==3&&(countForLevel3==3||countForLevel3==6||countForLevel3==9)) {
                cout<<"";
            }
            current = current->next;
        }
        cout<<endl;
    }

};

class game {
public:
    linkedList stack1;
    linkedList stack2;

    peakList array1;
    peakList array2;
    peakList array3;
    peakList array4;

    string cards[52] = {
    "SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK", "HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK", "DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK", "CA","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK"
     };



    void shuffleArray(string arr[]) {
        for (int i = 51; i > 0; i--) {
            int j = rand() % (i + 1);
            string temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    void makeStack1(string arr[]) {
        for (int i=0;i<23;i++) {
        stack1.insertAtEnd(arr[i]);
        }
    }
    void displayStack1() {
        stack1.display();
        cout<<endl;
    }
    void makeStack2(string arr[]) {
        stack2.insertAtEnd(arr[23]);
    }
    void displayStack2() {
        stack2.display();
        cout<<endl;
    }

    void aray1(string arr[]) {
        for (int i=24;i<27;i++) {
            array1.insertEnd(arr[i]);
        }
    }

    void aray2(string arr[]) {
        for (int i=27;i<33;i++) {
            array2.insertEnd(arr[i]);
        }
    }

    void aray3(string arr[]) {
        for (int i=33;i<42;i++) {
            array3.insertEnd(arr[i]);
        }
    }

    void aray4(string arr[]) {
        for (int i=42;i<52;i++) {
                array4.insertEnd(arr[i]);
            }
    }

    void display() {
        array1.display(1);
        array2.display(2);
        array3.display(3);
        array4.display(4);
    }

};
void start() {
    game Tripeaks;
    int randomTimes = rand() %1000;
    for (int i=0;i<=randomTimes;i++) {
        Tripeaks.shuffleArray(Tripeaks.cards);
    }

    Tripeaks.makeStack1(Tripeaks.cards);
    Tripeaks.makeStack2(Tripeaks.cards);
    Tripeaks.displayStack1();
    Tripeaks.displayStack2();
    Tripeaks.aray1(Tripeaks.cards);
    Tripeaks.aray2(Tripeaks.cards);
    Tripeaks.aray3(Tripeaks.cards);
    Tripeaks.aray4(Tripeaks.cards);
    Tripeaks.display();


}

int main() {
    start();
    return 0;
}


/*#include <iostream>
#include <ctime>
using namespace std;

void start() {
    game Tripeaks;
    int randomTimes = rand() %1000;
    for (int i=0;i<=randomTimes;i++) {
        Tripeaks.shuffleArray(Tripeaks.cards);
    }

    Tripeaks.makeStack1(Tripeaks.cards);
    Tripeaks.makeStack2(Tripeaks.cards);
    Tripeaks.displayStack1();
    Tripeaks.displayStack2();
    Tripeaks.aray1(Tripeaks.cards);
    Tripeaks.aray2(Tripeaks.cards);
    Tripeaks.aray3(Tripeaks.cards);
    Tripeaks.aray4(Tripeaks.cards);
    Tripeaks.display();


}

int main() {
    start();
    return 0;
}*/

