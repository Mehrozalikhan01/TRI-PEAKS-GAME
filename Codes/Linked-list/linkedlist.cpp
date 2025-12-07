#include <iostream>
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
template <typename T>
class game {
public:
    T cards[52] = {
    "SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
    "HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
    "DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
    "CA","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK"
     };
    linkedList<string> stack1;
    linkedList<string> stack2;
    void shuffleArray(string arr[]) {
        for (int i = 52 - 1; i > 0; i--) {
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

    void peaks() {

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
}