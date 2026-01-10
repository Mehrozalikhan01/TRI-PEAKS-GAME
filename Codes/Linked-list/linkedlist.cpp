#include <iostream>
#include <ctime>
#include "raylib.h"
#include <string>
using namespace std;

class node {
public:
    string data;
    int level;
    bool revealed;
    bool removed;
    node* next;
    node* child1;
    node* child2;

    node(string value){
        data=value;
        revealed=false;
        removed=false;
        next=nullptr;
        child1=nullptr;
        child2=nullptr;
    }
    node(){
        data="";
        revealed=false;
        removed=false;
        next=nullptr;
        child1=nullptr;
        child2=nullptr;
    }
};

class linkedList {
public:
    node *head;

    linkedList() {
        head=nullptr;
    }

    void insertAtEnd(string value) {
        node *newNode=new node(value);
        if(head==nullptr) {
            head=newNode;
            return;
        }
        node *temp=head;
        while(temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
    }

   void display(int level) {
        int count2=0;
        int count3=0;
        if(level==1) cout<<"          ";
        else if(level==2) cout<<"       ";
        else if(level==3) cout<<"   ";
        node* temp=head;
        while(temp!=nullptr) {
            if(temp->removed){
                    cout<<"__";
            }
            else if(temp->revealed) {
                cout<<temp->data;
            }
            else {
                cout<<"**";
            }
            if(level==1) cout<<"    ";
            else if(level==2) cout<<"    ";
            else if(level==3) cout<<"    ";
            else if(level==4) cout<<"    ";
            count2++;
            count3++;
            if(level==1) {
                cout<<"           ";
            }
            else if(level==2&&(count2==2||count2==4||count2==6)) {
                cout<<"     ";
            }
            else if(level==3&&(count3==3||count3==6||count3==9)) {
                cout<<"";
            }
            temp=temp->next;
        }
        cout<<endl;
    }
    void displayHiddenStack(){
        cout<<"****";
    }
    void displayFaceUpStack() {
        if(head==nullptr){
            cout<<"    ";
            return;
        }
        node* temp=head;
        while(temp->next!=nullptr) {
            temp=temp->next;
        }
        cout<<temp->data;
    }


};

class setup{
public:
    string input;
    linkedList stack1;
    linkedList stack2;
    linkedList array1;
    linkedList array2;
    linkedList array3;
    linkedList array4;

    string cards[52]={
        "SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK",
        "HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
        "DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
        "CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"
    };

    void shuffle(){
        for(int i=51;i>0;i--) {
            int j=rand()%(i+1);
            string temp=cards[i];
            cards[i]=cards[j];
            cards[j]=temp;
        }
    }
    void makeStacks(){
        for(int i=0;i<23;i++) {
            stack1.insertAtEnd(cards[i]);
        }
        stack2.insertAtEnd(cards[23]);
    }
    void makeLevels(){
        for(int i=24;i<27;i++) {
            array1.insertAtEnd(cards[i]);
        }
        for(int i=27;i<33;i++) {
            array2.insertAtEnd(cards[i]);
        }
        for(int i=33;i<42;i++) {
            array3.insertAtEnd(cards[i]);
        }
        for(int i=42;i<52;i++) {
            array4.insertAtEnd(cards[i]);
        }
    }
    void initializeLevels(){
        node* temp=array1.head;
        while(temp!=nullptr){
            temp->level=1;
            temp=temp->next;
        }
        temp=array2.head;
        while(temp!=nullptr){
            temp->level=2;
            temp=temp->next;
        }
        temp=array3.head;
        while(temp!=nullptr){
            temp->level=3;
            temp=temp->next;
        }
        temp=array4.head;
        while(temp!=nullptr){
            temp->level=4;
            temp=temp->next;
        }
    }
    void makeLevel4Reveal(){
        node* temp=array4.head;
        while(temp!=nullptr){
            temp->revealed=true;
            temp=temp->next;
        }
    }
    void stack2Reveal(){
        node* temp=stack2.head;
        while(temp!=nullptr){
            temp->revealed=true;
            temp=temp->next;
        }
    }
    void displayGame(){
        array1.display(1);
        array2.display(2);
        array3.display(3);
        array4.display(4);
        cout<<endl;
        cout<<endl;
        stack1.displayHiddenStack();
        cout<<"    ";
        stack2.displayFaceUpStack();
        cout<<endl;
    }
    void validateInput(string &in){
        if(in=="99"){
                if(stack1.head!=nullptr){
            node* temp=stack1.head;
            stack1.head=stack1.head->next;
            stack2.insertAtEnd(temp->data);
            delete temp;
        }
        else{
        cout<<"No more cards in stock!"<<endl;
    }
        return;
    }
    bool found=false;
    while(!found){
        node* temp=array1.head;
        while(temp!=nullptr){
            if(temp->revealed&&!temp->removed){
                if(in==temp->data){
                    node* stk2Temp=stack2.head;
                    while(stk2Temp->next!=nullptr){
                        stk2Temp=stk2Temp->next;
                    }
                    string t=stk2Temp->data;
                    char inSecond=in[1];
                    char stkSecond=t[1];
                    bool valid=false;
                    if(inSecond>='2'&&inSecond<='9'){
                        int inValue=inSecond-'0';
                        if(stkSecond>='2'&&stkSecond<='9'){
                            int stkValue=stkSecond-'0';
                            if(inValue==stkValue+1||inValue==stkValue-1){
                                valid=true;
                            }
                        }else if(stkSecond=='A'){
                            if(inValue==2){
                                valid=true;
                            }
                        }else if(stkSecond=='T'){
                            if(inValue==9){
                                valid=true;
                            }
                        }
                    }else if(inSecond=='A'){
                        if(stkSecond=='2'||stkSecond=='K'){
                            valid=true;
                        }
                    }else if(inSecond=='T'){
                        if(stkSecond=='9'||stkSecond=='J'){
                            valid=true;
                        }
                    }else if(inSecond=='J'){
                        if(stkSecond=='T'||stkSecond=='Q'){
                            valid=true;
                        }
                    }else if(inSecond=='Q'){
                        if(stkSecond=='J'||stkSecond=='K'){
                            valid=true;
                        }
                    }else if(inSecond=='K'){
                        if(stkSecond=='Q'||stkSecond=='A'){
                            valid=true;
                        }
                    }
                    if(valid){
                        found=true;
                    }
                    break;
                }
            }
            temp=temp->next;
        }
        if(!found){
            temp=array2.head;
            while(temp!=nullptr){
                if(temp->revealed&&!temp->removed){
                    if(in==temp->data){
                        node* stk2Temp=stack2.head;
                        while(stk2Temp->next!=nullptr){
                            stk2Temp=stk2Temp->next;
                        }
                        string t=stk2Temp->data;
                        char inSecond=in[1];
                        char stkSecond=t[1];
                        bool valid=false;
                        if(inSecond>='2'&&inSecond<='9'){
                            int inValue=inSecond-'0';
                            if(stkSecond>='2'&&stkSecond<='9'){
                                int stkValue=stkSecond-'0';
                                if(inValue==stkValue+1||inValue==stkValue-1){
                                    valid=true;
                                }
                            }else if(stkSecond=='A'){
                                if(inValue==2){
                                    valid=true;
                                }
                            }else if(stkSecond=='T'){
                                if(inValue==9){
                                    valid=true;
                                }
                            }
                        }else if(inSecond=='A'){
                            if(stkSecond=='2'||stkSecond=='K'){
                                valid=true;
                            }
                        }else if(inSecond=='T'){
                            if(stkSecond=='9'||stkSecond=='J'){
                                valid=true;
                            }
                        }else if(inSecond=='J'){
                            if(stkSecond=='T'||stkSecond=='Q'){
                                valid=true;
                            }
                        }else if(inSecond=='Q'){
                            if(stkSecond=='J'||stkSecond=='K'){
                                valid=true;
                            }
                        }else if(inSecond=='K'){
                            if(stkSecond=='Q'||stkSecond=='A'){
                                valid=true;
                            }
                        }
                        if(valid){
                            found=true;
                        }
                        break;
                    }
                }
                temp=temp->next;
            }
        }
        if(!found){
            temp=array3.head;
            while(temp!=nullptr){
                if(temp->revealed&&!temp->removed){
                    if(in==temp->data){
                        node* stk2Temp=stack2.head;
                        while(stk2Temp->next!=nullptr){
                            stk2Temp=stk2Temp->next;
                        }
                        string t=stk2Temp->data;
                        char inSecond=in[1];
                        char stkSecond=t[1];
                        bool valid=false;
                        if(inSecond>='2'&&inSecond<='9'){
                            int inValue=inSecond-'0';
                            if(stkSecond>='2'&&stkSecond<='9'){
                                int stkValue=stkSecond-'0';
                                if(inValue==stkValue+1||inValue==stkValue-1){
                                    valid=true;
                                }
                            }else if(stkSecond=='A'){
                                if(inValue==2){
                                    valid=true;
                                }
                            }else if(stkSecond=='T'){
                                if(inValue==9){
                                    valid=true;
                                }
                            }
                        }else if(inSecond=='A'){
                            if(stkSecond=='2'||stkSecond=='K'){
                                valid=true;
                            }
                        }else if(inSecond=='T'){
                            if(stkSecond=='9'||stkSecond=='J'){
                                valid=true;
                            }
                        }else if(inSecond=='J'){
                            if(stkSecond=='T'||stkSecond=='Q'){
                                valid=true;
                            }
                        }else if(inSecond=='Q'){
                            if(stkSecond=='J'||stkSecond=='K'){
                                valid=true;
                            }
                        }else if(inSecond=='K'){
                            if(stkSecond=='Q'||stkSecond=='A'){
                                valid=true;
                            }
                        }
                        if(valid){
                            found=true;
                        }
                        break;
                    }
                }
                temp=temp->next;
            }
        }
        if(!found){
            temp=array4.head;
            while(temp!=nullptr){
                if(temp->revealed&&!temp->removed){
                    if(in==temp->data){
                        node* stk2Temp=stack2.head;
                        while(stk2Temp->next!=nullptr){
                            stk2Temp=stk2Temp->next;
                        }
                        string t=stk2Temp->data;
                        char inSecond=in[1];
                        char stkSecond=t[1];
                        bool valid=false;
                        if(inSecond>='2'&&inSecond<='9'){
                            int inValue=inSecond-'0';
                            if(stkSecond>='2'&&stkSecond<='9'){
                                int stkValue=stkSecond-'0';
                                if(inValue==stkValue+1||inValue==stkValue-1){
                                    valid=true;
                                }
                            }else if(stkSecond=='A'){
                                if(inValue==2){
                                    valid=true;
                                }
                            }else if(stkSecond=='T'){
                                if(inValue==9){
                                    valid=true;
                                }
                            }
                        }else if(inSecond=='A'){
                            if(stkSecond=='2'||stkSecond=='K'){
                                valid=true;
                            }
                        }else if(inSecond=='T'){
                            if(stkSecond=='9'||stkSecond=='J'){
                                valid=true;
                            }
                        }else if(inSecond=='J'){
                            if(stkSecond=='T'||stkSecond=='Q'){
                                valid=true;
                            }
                        }else if(inSecond=='Q'){
                            if(stkSecond=='J'||stkSecond=='K'){
                                valid=true;
                            }
                        }else if(inSecond=='K'){
                            if(stkSecond=='Q'||stkSecond=='A'){
                                valid=true;
                            }
                        }
                        if(valid){
                            found=true;
                        }
                        break;
                    }
                }
                temp=temp->next;
            }
        }
    }
}
    void initializeChildren(){
    node* temp3=array3.head;
    node* temp4=array4.head;
    int index4=0;
    while(temp3!=nullptr){
        if(temp4!=nullptr){
            temp3->child1=temp4;
            if(temp4->next!=nullptr){
                temp3->child2=temp4->next;
            }
            temp4=temp4->next;
        }
        temp3=temp3->next;
        index4++;
    }
    node* temp2=array2.head;
    temp3=array3.head;
    int count2=0;
    while(temp2!=nullptr&&temp3!=nullptr){
        temp2->child1=temp3;
        if(temp3->next!=nullptr){
            temp2->child2=temp3->next;
        }
        if(count2==1||count2==3){
            if(temp3->next!=nullptr){
                temp3=temp3->next->next;
            }
        }else{
            temp3=temp3->next;
        }
        temp2=temp2->next;
        count2++;
    }
    node* temp1=array1.head;
    temp2=array2.head;
    while(temp1!=nullptr&&temp2!=nullptr){
        temp1->child1=temp2;
        if(temp2->next!=nullptr){
            temp1->child2=temp2->next;
        }
        if(temp2->next!=nullptr&&temp2->next->next!=nullptr){
            temp2=temp2->next->next;
        }else{
            break;
        }
        temp1=temp1->next;
    }
}
    void reveal(){
    node* temp=array1.head;
    while(temp!=nullptr){
        if(!temp->revealed){
            if((!temp->child1&&!temp->child2)||
            (temp->child1 && temp->child2 &&
             temp->child1->removed && temp->child2->removed ))
            {
                    temp->revealed=true;
            }
            }
            temp=temp->next;
        }
    temp = array2.head;
    while (temp!=nullptr){
        if(!temp->revealed){
            if((!temp->child1&&!temp->child2)||
            (temp->child1 && temp->child2 &&
             temp->child1->removed && temp->child2->removed ))
            {
                    temp->revealed=true;
            }
            }
        temp=temp->next;
    }
    temp=array3.head;
    while(temp!=nullptr){
        if(!temp->revealed){
            if((!temp->child1&&!temp->child2)||
            (temp->child1 && temp->child2 &&
             temp->child1->removed && temp->child2->removed ))
            {
                    temp->revealed=true;
            }
            }
        temp=temp->next;
    }
}

bool validMove(){
    if(stack1.head!=nullptr){
        return true;
    }
     if(stack2.head==nullptr){
        return false;
    }
    node* stk2Temp = stack2.head;
    while(stk2Temp->next!=nullptr){
        stk2Temp=stk2Temp->next;
    }
    string t=stk2Temp->data;
    char stkSecond= t[1];

    node* temp = array1.head;
    while(temp!=nullptr){
        if(temp->revealed&&!temp->removed){
            char cardSecond=temp->data[1];
            if(isValid(cardSecond,stkSecond)){
                return true;
            }
        }
        temp=temp->next;
    }
    temp=array2.head;
    while(temp!=nullptr){
        if(temp->revealed&&!temp->removed){
            char cardSecond=temp->data[1];
            if(isValid(cardSecond,stkSecond)){
                return true;
            }
        }
        temp=temp->next;
    }
    temp=array3.head;
    while(temp!=nullptr){
        if(temp->revealed&&!temp->removed){
            char cardSecond=temp->data[1];
            if(isValid(cardSecond,stkSecond)){
                return true;
            }
        }
        temp=temp->next;
    }
    temp=array4.head;
    while(temp!=nullptr){
        if(temp->revealed&&!temp->removed){
            char cardSecond=temp->data[1];
            if(isValid(cardSecond,stkSecond)){
                return true;
            }
        }
        temp=temp->next;
    }
    return false;
}
bool isValid(char card,char stack){
    if(card>='2'&&card<='9'){
        int cardVal=card-'0';
        if(stack>='2'&&stack<='9'){
            int stackVal=stack-'0';
            if(cardVal==stackVal+1||cardVal==stackVal-1){
                return true;
            }
        }else if(stack=='A'){
            if(cardVal==2){
                return true;
            }
        }else if(stack=='T'){
            if(cardVal==9){
                return true;
            }
        }
    }else if(card=='A'){
        if(stack=='2'||stack=='K'){
            return true;
        }
    }else if(card=='T'){
        if(stack=='9'||stack=='J'){
            return true;
        }
    }else if(card=='J'){
        if(stack=='T'||stack=='Q'){
            return true;
        }
    }else if(card=='Q'){
        if(stack=='J'||stack=='K'){
            return true;
        }
    }else if(card=='K'){
        if(stack=='Q'||stack=='A'){
            return true;
        }
    }
    return false;
}
    void takeInput() {
    cout << "Enter a card name: ";
    cin >> input;

    if (input == "99") {
        if (stack1.head != nullptr) {
            node* temp = stack1.head;
            stack1.head = stack1.head->next;
            stack2.insertAtEnd(temp->data);
            delete temp;
        } else {
            cout << "No more cards in stock!" << endl;
        }
        cout << endl;
        return;         // only return in the 99 case
    }

    validateInput(input);

    node* temp = array1.head;
    while (temp != nullptr) {
        if (temp->revealed && !temp->removed && input == temp->data) {
            temp->removed = true;
            stack2.insertAtEnd(temp->data);
            reveal();
        }
        temp = temp->next;
    }

    temp = array2.head;
    while (temp != nullptr) {
        if (temp->revealed && !temp->removed && input == temp->data) {
            temp->removed = true;
            stack2.insertAtEnd(temp->data);
            reveal();
        }
        temp = temp->next;
    }

    temp = array3.head;
    while (temp != nullptr) {
        if (temp->revealed && !temp->removed && input == temp->data) {
            temp->removed = true;
            stack2.insertAtEnd(temp->data);
            reveal();
        }
        temp = temp->next;
    }

    temp = array4.head;
    while (temp != nullptr) {
        if (temp->revealed && !temp->removed && input == temp->data) {
            temp->removed = true;
            stack2.insertAtEnd(temp->data);
            reveal();
        }
        temp = temp->next;
    }
}
};


int main(){
    int swidth=1000;
    int slenght=900;
     InitWindow(swidth, slenght, "TriPeaks - Raylib Window");
     SetTargetFPS(60);
/*char ch = 219; // The solid block*/

    cout<<"================================================================"<<endl;
    cout<<"=========================TRIPEAKS==============================="<<endl;
    cout<<"================================================================"<<endl;
    cout<<endl;
    cout<<"                    ~~ HOW TO PLAY ~~                      "<<endl;
    cout<<endl;
    cout<<"  OBJECTIVE: Clear all cards from the three peaks!         "<<endl;
    cout<<endl;
    cout<<"  RULES:                                                    "<<endl;
    cout<<"  • Select cards that are ONE rank higher or lower         "<<endl;
    cout<<"    than the top card of the waste pile                    "<<endl;
    cout<<"  • Example: If waste pile shows 7, you can play 6 or 8    "<<endl;
    cout<<"  • Kings (K) wrap with Aces (A) and Queens (Q)            "<<endl;
    cout<<"  • Aces (A) wrap with Kings (K) and Twos (2)              "<<endl;
    cout<<endl;
    cout<<"  COMMANDS:                                                 "<<endl;
    cout<<"  • Enter card name (e.g., SA, H7, DK) to play a card      "<<endl;
    cout<<"  • Enter 99 to draw a new card from the stock pile        "<<endl;
    cout<<endl;
    cout<<"  SYMBOLS:                                                  "<<endl;
    cout<<"  • ** = Hidden card (not yet playable)                    "<<endl;
    cout<<"  • __ = Removed card (already played)                     "<<endl;
    cout<<"  • Card codes: S=Spades, H=Hearts, D=Diamonds, C=Clubs    "<<endl;
    cout<<"  • Ranks: A,2-9,T(10),J,Q,K                               "<<endl;
    cout<<endl;
    cout<<"============================================================"<<endl;
    cout<<endl;
    cout<<"            Press ENTER to start the game...               "<<endl;
    cin.get();
    cout<<endl;

    srand(time(0));
    setup Setup;
    Setup.shuffle();
    Setup.makeStacks();
    Setup.makeLevels();
    Setup.initializeLevels();
    Setup.initializeChildren();
    Setup.makeLevel4Reveal();
    Setup.stack2Reveal();
    Setup.displayGame();
    while (!WindowShouldClose())
    {
        if (Setup.validMove())
        {Setup.displayGame();
        Setup.takeInput();
    Setup.reveal();
Setup.stack2Reveal();
}
else 
{ cout<<"NO valid moves left! Game over, "<<endl;
cout<<"Press ENTER to exit..."<<endl;
cin.ignore(numeric_limits<streamsize> ::max(), '\n');
break;
    }
    BeginDrawing();
    ClearBackground (WHITE);
    Drawtext("Tipeaks Game", 40, 40, 20, RAYWHITE);
    EndDrawing();
}
CLoseWindow();
return 0;
}