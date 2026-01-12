#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

template<class t>
class queue{
public:
int fron;
int rear;
int size;
int countremain;
t *ptr;
queue(int s){
ptr=new t [s];
size=s;
fron=-1;
rear=0;
}

void enqueue(t data){
ptr[++fron]=data;
}
t dequeue(){
    return ptr[rear++];
}
t front(){   
    return ptr[rear];
}
bool empty(){
    return rear==fron+1;
}


friend void functioning(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11);

};

void fillingeasy(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
    q2.rear = 0; q2.fron = -1;
    q3.rear = 0; q3.fron = -1;
    q4.rear = 0; q4.fron = -1;
    q5.rear = 0; q5.fron = -1;
    q6.rear = 0; q6.fron = -1;
    q7.rear = 0; q7.fron = -1;
    q8.rear = 0; q8.fron = -1;
    q9.rear = 0; q9.fron = -1;
    q10.rear = 0; q10.fron = -1;
    q11.rear = 0; q11.fron = -1;

    q1.enqueue("QH");q1.enqueue("JH");q1.enqueue("10D");q1.enqueue("9H");
    q2.enqueue("10S");q2.enqueue("9D");q2.enqueue("8S");
    q3.enqueue("8D");q3.enqueue("7C");
    q4.enqueue("6C");q4.enqueue("KS");q4.enqueue("QD");q4.enqueue("JS");
    q5.enqueue("5H");q5.enqueue("JH");q5.enqueue("10H");
    q6.enqueue("AD");q6.enqueue("9S");
    q7.enqueue("QC");q7.enqueue("9C");q7.enqueue("8C");q7.enqueue("7D");
    q8.enqueue("10D");q8.enqueue("7S");q8.enqueue("6H");
    q9.enqueue("8H");q9.enqueue("5C");
    q10.enqueue("6S");
    q11.enqueue("2C");q11.enqueue("3D");q11.enqueue("4H");q11.enqueue("5S");
    q11.enqueue("6D");q11.enqueue("7H");q11.enqueue("8C");q11.enqueue("9S");
    q11.enqueue("10C");q11.enqueue("JD");q11.enqueue("QH");q11.enqueue("KS");
    q11.enqueue("AC");q11.enqueue("2D");q11.enqueue("3H");q11.enqueue("4C");
    q11.enqueue("5D");q11.enqueue("6H");q11.enqueue("7S");q11.enqueue("8D");
    q11.enqueue("9H");q11.enqueue("10C");q11.enqueue("JC");q11.enqueue("QD");
}
void fillingmedium(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
    q2.rear = 0; q2.fron = -1;
    q3.rear = 0; q3.fron = -1;
    q4.rear = 0; q4.fron = -1;
    q5.rear = 0; q5.fron = -1;
    q6.rear = 0; q6.fron = -1;
    q7.rear = 0; q7.fron = -1;
    q8.rear = 0; q8.fron = -1;
    q9.rear = 0; q9.fron = -1;
    q10.rear = 0; q10.fron = -1;
    q11.rear = 0; q11.fron = -1;

    q1.enqueue("KS");q1.enqueue("QH");q1.enqueue("JS");q1.enqueue("10H");
    q2.enqueue("JH");q2.enqueue("10S");q2.enqueue("9D");
    q3.enqueue("9S");q3.enqueue("8C");
    q4.enqueue("7D");q4.enqueue("8D");q4.enqueue("7S");q4.enqueue("6D");
    q5.enqueue("6H");q5.enqueue("6C");q5.enqueue("5H");
    q6.enqueue("9H");q6.enqueue("4S");
    q7.enqueue("7C");q7.enqueue("AD");q7.enqueue("KD");q7.enqueue("QS");
    q8.enqueue("5D");q8.enqueue("QC");q8.enqueue("JH");
    q9.enqueue("3S");q9.enqueue("10D");
    q10.enqueue("2C");
    q11.enqueue("8H");q11.enqueue("9C");q11.enqueue("10D");q11.enqueue("JS");
    q11.enqueue("QH");q11.enqueue("KC");q11.enqueue("AD");q11.enqueue("2D");
    q11.enqueue("3H");q11.enqueue("4C");q11.enqueue("5S");q11.enqueue("6H");
    q11.enqueue("7D");q11.enqueue("8C");q11.enqueue("9S");q11.enqueue("10C");
    q11.enqueue("JD");q11.enqueue("QS");q11.enqueue("KH");q11.enqueue("AC");
    q11.enqueue("2C");q11.enqueue("3D");q11.enqueue("4H");q11.enqueue("5C");
}

void fillinghard(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
    q2.rear = 0; q2.fron = -1;
    q3.rear = 0; q3.fron = -1;
    q4.rear = 0; q4.fron = -1;
    q5.rear = 0; q5.fron = -1;
    q6.rear = 0; q6.fron = -1;
    q7.rear = 0; q7.fron = -1;
    q8.rear = 0; q8.fron = -1;
    q9.rear = 0; q9.fron = -1;
    q10.rear = 0; q10.fron = -1;
    q11.rear = 0; q11.fron = -1;

    q1.enqueue("AH");q1.enqueue("KC");q1.enqueue("QH");q1.enqueue("JD");
    q2.enqueue("QS");q2.enqueue("JH");q2.enqueue("10D");
    q3.enqueue("10C");q3.enqueue("9S");
    q4.enqueue("8D");q4.enqueue("9D");q4.enqueue("8H");q4.enqueue("7S");
    q5.enqueue("6H");q5.enqueue("7H");q5.enqueue("6C");
    q6.enqueue("4S");q6.enqueue("5S");
    q7.enqueue("3C");q7.enqueue("2D");q7.enqueue("AD");q7.enqueue("KS");
    q8.enqueue("2H");q8.enqueue("KD");q8.enqueue("QC");
    q9.enqueue("AC");q9.enqueue("JS");
    q10.enqueue("9C");
    q11.enqueue("10S");q11.enqueue("JH");q11.enqueue("QD");q11.enqueue("KC");
    q11.enqueue("AD");q11.enqueue("2S");q11.enqueue("3H");q11.enqueue("4D");
    q11.enqueue("5C");q11.enqueue("6S");q11.enqueue("7D");q11.enqueue("8C");
    q11.enqueue("9H");q11.enqueue("10D");q11.enqueue("JS");q11.enqueue("QC");
    q11.enqueue("KH");q11.enqueue("AS");q11.enqueue("2C");q11.enqueue("3D");
    q11.enqueue("4H");q11.enqueue("5S");q11.enqueue("6D");q11.enqueue("7C");
}

void display(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
cout<<"<<<<<<<<<<<<<(PLAY ARENA)>>>>>>>>>>>>> \n";
    if((q1.rear == q2.rear)&&(q2.rear==q2.fron+1)){
cout<<"        "<<q1.front();
}else if(q1.rear<=3 ){
    cout<<"       "<<"{*}";
}else{
    cout<<"          ";}
if((q4.rear == q5.rear)&&(q5.rear==q5.fron+1)){
cout<<"          "<<q4.front();
}else if(q4.rear<=3){
    cout<<"         "<<"{*}";
}else{
    cout<<"            ";}
if((q7.rear == q8.rear)&&(q8.rear==q8.fron+1)){
cout<<"          "<<q7.front();cout<<endl;
}else if(q7.rear<=3){
    cout<<"         "<<"{*}"<<endl;
}
else{
    cout<<endl;
}
//line 2
if(q1.rear==2 && q2.rear>=2){
 cout<<"      "<<q1.front();
}else if(q1.rear<=2){
    cout<<"     "<<"{*}";
}else{
    cout<<"        ";}
if(q2.rear==2 && q3.rear>=2){
 cout<<"  "<<q2.front();
}else if(q2.rear<=2){
    cout<<" {*}";
}else{
    cout<<"    ";}
if(q4.rear==2 && q5.rear>=2){
 cout<<"      "<<q4.front();
}else if(q4.rear<=2){
    cout<<"     "<<"{*}";
}else{
    cout<<"        ";}
if(q5.rear==2 && q6.rear>=2){
 cout<<"  "<<q5.front();
}else if(q5.rear<=2){
    cout<<" {*}";
}else{
    cout<<"    ";}
if(q7.rear==2 && q8.rear>=2){
 cout<<"      "<<q7.front();
}else if(q7.rear<=2){
    cout<<"     "<<"{*}";
}else{
    cout<<"        ";}
if(q8.rear==2 && q9.rear>=2){
 cout<<"  "<<q8.front();cout<<endl;
}else if(q8.rear<=2){
    cout<<" {*}"<<endl;
}
else{cout<<endl;}
//line 3
if(q1.rear==1 && q2.rear>=1){
cout<<"    "<<q1.front();
}else if(q1.rear<=1){
    cout<<"   "<<"{*}";
}else{
    cout<<"     ";}
if(q2.rear==1 && q3.rear>=1){
cout<<"  "<<q2.front();
}else if(q2.rear<=1){
    cout<<" "<<"{*}";
}else{
    cout<<"    ";}
if(q3.rear==1 && q4.rear>=1){
cout<<"  "<<q3.front();
}else if(q3.rear<=1){
    cout<<" "<<"{*}";
}else{
    cout<<"    ";}
if(q4.rear==1 && q5.rear>=1){
cout<<"  "<<q4.front();
}else if(q4.rear<=1){
    cout<<" "<<"{*}";
}else{
    cout<<"    ";}
if(q5.rear==1 && q6.rear>=1){
cout<<"  "<<q5.front();
}else if(q5.rear<=1){
    cout<<" "<<"{*}";
}else{
    cout<<"    ";}
if(q6.rear==1 && q7.rear>=1){
cout<<"  "<<q6.front();
}else if(q6.rear<=1){
    cout<<" "<<"{*}";
}else{
    cout<<"    ";}
if(q7.rear==1 && q8.rear>=1){
cout<<"  "<<q7.front();
}else if(q7.rear<=1){
    cout<<" "<<"{*}";
}else{
    cout<<"    ";}
if(q8.rear==1 && q9.rear>=1){
cout<<"  "<<q8.front();
}else if(q8.rear<=1){
    cout<<" "<<"{*}";
}else{
    cout<<"    ";}
if(q9.rear==1 && q10.rear>=1){
cout<<"  "<<q9.front();cout<<endl;
}else if(q9.rear<=1){
    cout<<" "<<"{*}"<<endl;
}
else{
    cout<<endl;
}
//line 4
if(q1.rear == 0){
    cout<<"  "<< q1.front(); 
}
else{
    cout<<"    ";}
if(q2.rear == 0){
    cout<<"  "<< q2.front();
}else{
    cout<<"    ";}
if(q3.rear == 0){
    cout<<"  "<< q3.front();
}else{
    cout<<"    ";}
if(q4.rear == 0){
    cout<<"  "<< q4.front();
}else{
    cout<<"    ";}
if(q5.rear == 0){
    cout<<"  "<< q5.front();
}else{
    cout<<"    ";}
if(q6.rear == 0){
    cout<<"  "<<q6.front();
}else{
    cout<<"    ";}
if(q7.rear == 0){
    cout<<"  "<< q7.front();
}else{
    cout<<"    ";}
if(q8.rear == 0){
    cout<<"  "<< q8.front();
}else{
    cout<<"    ";}
if(q9.rear == 0){
    cout<<"  "<<q9.front();
}else{
    cout<<"    ";}
if(q10.rear == 0){
    cout<<"  "<<q10.front();
    cout<<endl;
}


cout<<endl<<" "<<q11.front();cout<<" {*}"<<endl;



}
void update(queue<string> &q11,queue<string> &q){
    int cnt=0;
    string array[52];
do{
   array[cnt++]=q11.dequeue();
}while(q11.rear != q11.fron);
q11.rear=0;
q11.fron=-1;
q11.enqueue(q.dequeue());
for(int i=0;i<cnt;i++){
    q11.enqueue(array[i]);
}

}

void incstock(string num,queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
    if(!q1.empty() && q1.front()==num){
        update(q11,q1);
        cout<<"Card Adding to stock....";
    }
    else if(!q2.empty() && q2.front()==num){
        update(q11,q2);
         cout<<"Card Adding to stock....";
    }
    else if(!q3.empty() && q3.front()==num){
        update(q11,q3);
         cout<<"Card Adding to stock....";   
    }
    else if(!q4.empty() && q4.front()==num){
        update(q11,q4);
      cout<<"Card Adding to stock....";  
    }
    else if(!q5.empty() && q5.front()==num){
        update(q11,q5);
       cout<<"Card Adding to stock...."; 
    }
    else if(!q6.empty() && q6.front()==num){
        update(q11,q6);
       cout<<"Card Adding to stock....";  
    }
    else if(!q7.empty() && q7.front()==num){
        update(q11,q7);
       cout<<"Card Adding to stock...."; 
    }
    else if(!q8.empty() && q8.front()==num){
        update(q11,q8);
       cout<<"Card Adding to stock....";  
    }
    else if(!q9.empty() && q9.front()==num){
        update(q11,q9);
       cout<<"Card Adding to stock....";  
    }
    else if(!q10.empty() && q10.front()==num){
        update(q11,q10);
        cout<<"Card Adding to stock...."; 
    }
    else{
         cout<<"Card not found....";
    }
   
}
void inputing(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
    string num;
    cout<<"Enter the card number which you want to add to stock or \n for exit enter 0  \n for suffle enter 1 : ";
    cin>>num;
    if(num=="0"){
        cout<<"Thanks for playing game \n ";
        exit(0);
    }
    else if(num=="1"){
        cout<<"Stock shuffling... \n";
        q11.dequeue();
    }
   else if(num[0] == 'K' || num[0] == 'Q' || num[0] == 'J' ||num[0] == 'A' ||  num[1] == '0' || (num[0] <= '9' && num[0]>= '2')){
    string stk=q11.front();
    if(num[0]< '9' && num[0]> '2' ){
        if(num[0] == stk[0]+1 || num[0] == stk[0]-1){
            incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
        else{
        cout<<"This card cant be addon to the stack \n";}
    }
    else if(num[0] == 'K' || num[0] == 'Q' || num[0] == 'J' ||num[0] == 'A' ||  num[1] == '0' || num[0] == '2' || num[0] == '9'){
        if(num[0]=='K' && (stk[0]=='Q' || stk[0]=='A')){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
        else if (num[0]=='Q' && (stk[0]=='K' || stk[0]=='J')){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
         else if (num[0]=='J' && (stk[0]=='Q' || stk[1]=='0')){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
        else if (num[0]=='A' && (stk[0]=='2' || stk[0]=='K')){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
        else if (num[1]=='0' && (stk[0]=='J' || stk[0]=='9')){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
        else if (num[0]=='9' && (stk[0]=='8' || stk[1]=='0')){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
        else if (num[0]=='2' && (stk[0]=='3' || stk[1]=='A')){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
        }
        else{
        cout<<"This card cant be addon to the stack \n";}
    }
 else { cout<<"This card doesnot exist \n";}

    }
    
}

void chkwin(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
    if(q1.empty() && q2.empty() && q3.empty() && q4.empty() && q5.empty() && q6.empty() && q7.empty() && q8.empty() && q9.empty() && q10.empty() ){
cout<<"YOU WIN! \n";
  cout<<"(Redirecting  back to main menu.....)";
  Sleep(3000);
return;}
else if(q11.empty()){
    cout<<"YOUR LOSE! \n";
    cout<<"(Redirecting  back to main menu.....)";
    Sleep(3000);
    return;}
}

void saving(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
   ofstream file("file.txt");
    if (!file) {
        cout << "File not opened!\n";
        return;
    }
    
    for (int i = 1; i <= 11; i++) {
        queue<string> temp = q11;  
        if (i == 1) temp = q1;
        else if (i == 2) temp = q2;
        else if (i == 3) temp = q3;
        else if (i == 4) temp = q4;
        else if (i == 5) temp = q5;
        else if (i == 6) temp = q6;
        else if (i == 7) temp = q7;
        else if (i == 8) temp = q8;
        else if (i == 9) temp = q9;
        else if (i == 10) temp = q10;
        
        file << temp.rear << " " << temp.fron << " ";
        
        int start = temp.rear;
        int end = temp.fron;
        for(int j = start; j <= end; j++) {
            file << temp.ptr[j] << " ";
        }
        file << endl;
    }
    file.close();
}

void loading(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11) {
    ifstream file("file.txt");
    if (!file) {
        cout << "File not opened!\n";
        return;
    }
    
    string helper;
    for (int i = 1; i <= 11; i++) {
        queue<string> *temp = &q11;
        if (i == 1) temp = &q1;
        else if (i == 2) temp = &q2;
        else if (i == 3) temp = &q3;
        else if (i == 4) temp = &q4;
        else if (i == 5) temp = &q5;
        else if (i == 6) temp = &q6;
        else if (i == 7) temp = &q7;
        else if (i == 8) temp = &q8;
        else if (i == 9) temp = &q9;
        else if (i == 10) temp = &q10;
   
        file >> temp->rear >> temp->fron;
        
        string line;
        getline(file, line); 
        istringstream iss(line);
        int index = temp->rear;
        while (iss >> helper) {
            temp->ptr[index++] = helper;
        }
    }
    file.close();
}
 void functioning(queue<string> &q1,queue<string> &q2,queue<string> &q3,queue<string> &q4,queue<string> &q5,queue<string> &q6,queue<string> &q7,queue<string> &q8,queue<string> &q9,queue<string> &q10,queue<string> &q11){
   while(true){
    system("cls");
    cout<<"<<<<---------------------(TRI PEAKS)---------------------->>>> \n";
    cout<<"1. Start new game \n";
   cout<<"2. Continue game \n";
   cout<<"3.(Enter anything for exit) Exit \n";
   int input;
   cout<<"Enter your choice: ";
   cin>>input;
   if(input==1){
    cout<<"<<<<<<<<+++++++++============+++++++++>>>>>>>>> \n";
    cout<<"Select game difficulty level: \n 1)Easy \n 2)Medium \n3)(press any thing for) Hard \n";
    cout<<"Enter your choice : ";
    int choice;
    cin>>choice;
    if(choice==1){
    fillingeasy(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);}
else if(choice==2){
    fillingmedium(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    }
else{
    fillinghard(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    }}
    else if(input==2){
        loading(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11); }
        else{exit(0);}


    while((!q1.empty() && !q2.empty() && !q3.empty() && !q4.empty() && !q5.empty() && !q6.empty() && !q7.empty() && !q8.empty() && !q9.empty() && !q10.empty()) || (!q11.empty())){
    system("cls");
        display(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    inputing(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    saving(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    chkwin(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    Sleep(1000);
}
   }
 }
int main(){
queue<string> q1(4);
queue<string> q2(3);
queue<string> q3(2);
queue<string> q4(4);
queue<string> q5(3);
queue<string> q6(2);
queue<string> q7(4);
queue<string> q8(3);
queue<string> q9(2);
queue<string> q10(1);
queue<string> q11(52);
functioning(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);


}