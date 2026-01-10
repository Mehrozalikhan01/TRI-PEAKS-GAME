#include <iostream>
#include <fstream>
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
queue(t s){
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
t empty(){
    return rear==fron+1;
}

void card(){
if(front() > 10){
switch(front()){
    case 11:
    cout<<"J";
    break;
    case 12:
    cout<<"Q";
    break;
    case 13:
    cout<<"K";
    break;}
    }
    else{
        cout<<front();
    }
}
friend void functioning(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11);

};

void filling(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
   q1.rear = 0; q1.fron = -1;
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

    q1.enqueue(7);q1.enqueue(7);q1.enqueue(8);q1.enqueue(9);
q2.enqueue(8);q2.enqueue(6);q2.enqueue(10);
q3.enqueue(9);q3.enqueue(11);
q4.enqueue(10);q4.enqueue(3);q4.enqueue(4);q4.enqueue(5);
q5.enqueue(11);q5.enqueue(2);q5.enqueue(12);
q6.enqueue(12);q6.enqueue(13);
q7.enqueue(13);q7.enqueue(4);q7.enqueue(2);q7.enqueue(1);
q8.enqueue(1);q8.enqueue(5);q8.enqueue(3);
q9.enqueue(2);q9.enqueue(6);
q10.enqueue(3);
for(int i=4;i<=13;i++){
q11.enqueue(i);}
for(int i=1;i<=13;i++){
    q11.enqueue(i);}
    q11.enqueue(1);
}

void display(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
if((q1.rear == q2.rear)&&(q2.rear==q2.fron+1)){
cout<<"     ";q1.card();
}else if(q1.rear<=3 ){
    cout<<"     "<<"*";
}else{
    cout<<"      ";}
if((q4.rear == q5.rear)&&(q5.rear==q5.fron+1)){
cout<<"     ";q4.card();
}else if(q4.rear<=3){
    cout<<"     "<<"*";
}else{
    cout<<"      ";}
if((q7.rear == q8.rear)&&(q8.rear==q8.fron+1)){
cout<<"     ";q7.card();cout<<endl;
}else if(q7.rear<=3){
    cout<<"     "<<"*"<<endl;
}
else{
    cout<<endl;
}
//line 2
if(q1.rear==2 && q2.rear>=2){
 cout<<"    ";q1.card();
}else if(q1.rear<=2){
    cout<<"    "<<"*";
}else{
    cout<<"     ";}
if(q2.rear==2 && q3.rear>=2){
 cout<<" ";q2.card();
}else if(q2.rear<=2){
    cout<<" *";
}else{
    cout<<"  ";}
if(q4.rear==2 && q5.rear>=2){
 cout<<"   ";q4.card();
}else if(q4.rear<=2){
    cout<<"   "<<"*";
}else{
    cout<<"    ";}
if(q5.rear==2 && q6.rear>=2){
 cout<<" ";q5.card();
}else if(q5.rear<=2){
    cout<<" *";
}else{
    cout<<"  ";}
if(q7.rear==2 && q8.rear>=2){
 cout<<"   ";q7.card();
}else if(q7.rear<=2){
    cout<<"   "<<"*";
}else{
    cout<<"    ";}
if(q8.rear==2 && q9.rear>=2){
 cout<<" ";q8.card();cout<<endl;
}else if(q8.rear<=2){
    cout<<" *"<<endl;
}
else{cout<<endl;}
//line 3
if(q1.rear==1 && q2.rear>=1){
cout<<"   ";q1.card();
}else if(q1.rear<=1){
    cout<<"   "<<"*";
}else{
    cout<<"    ";}
if(q2.rear==1 && q3.rear>=1){
cout<<" ";q2.card();
}else if(q2.rear<=1){
    cout<<" "<<"*";
}else{
    cout<<"  ";}
if(q3.rear==1 && q4.rear>=1){
cout<<" ";q3.card();
}else if(q3.rear<=1){
    cout<<" "<<"*";
}else{
    cout<<"  ";}
if(q4.rear==1 && q5.rear>=1){
cout<<" ";q4.card();
}else if(q4.rear<=1){
    cout<<" "<<"*";
}else{
    cout<<"  ";}
if(q5.rear==1 && q6.rear>=1){
cout<<" ";q5.card();
}else if(q5.rear<=1){
    cout<<" "<<"*";
}else{
    cout<<"  ";}
if(q6.rear==1 && q7.rear>=1){
cout<<" ";q6.card();
}else if(q6.rear<=1){
    cout<<" "<<"*";
}else{
    cout<<"  ";}
if(q7.rear==1 && q8.rear>=1){
cout<<" ";q7.card();
}else if(q7.rear<=1){
    cout<<" "<<"*";
}else{
    cout<<"  ";}
if(q8.rear==1 && q9.rear>=1){
cout<<" ";q8.card();
}else if(q8.rear<=1){
    cout<<" "<<"*";
}else{
    cout<<"  ";}
if(q9.rear==1 && q10.rear>=1){
cout<<" ";q9.card();cout<<endl;
}else if(q9.rear<=1){
    cout<<" "<<"*"<<endl;
}
else{
    cout<<endl;
}
//line 4
if(q1.rear == 0){
    cout<<"  "; q1.card(); 
}
else{
    cout<<"   ";}
if(q2.rear == 0){
    cout<<" "; q2.card();
}else{
    cout<<"   ";}
if(q3.rear == 0){
    cout<<" "; q3.card();
}else{
    cout<<"   ";}
if(q4.rear == 0){
    cout<<" "; q4.card();
}else{
    cout<<"   ";}
if(q5.rear == 0){
    cout<<" "; q5.card();
}else{
    cout<<"   ";}
if(q6.rear == 0){
    cout<<" "; q6.card();
}else{
    cout<<"   ";}
if(q7.rear == 0){
    cout<<" "; q7.card();
}else{
    cout<<"   ";}
if(q8.rear == 0){
    cout<<" "; q8.card();
}else{
    cout<<"   ";}
if(q9.rear == 0){
    cout<<" ";
    q9.card();
}else{
    cout<<"   ";}
if(q10.rear == 0){
    cout<<" ";
    q10.card();
    cout<<endl;
}


cout<<endl<<" ";q11.card();cout<<" *"<<endl;



}
void update(queue<int> &q11,queue<int> &q){
    int cnt=0;
    int array[52];
do{
   array[cnt++]=q11.dequeue();
}while(q11.rear != q11.fron);
q11.rear=0;q11.fron=-1;
q11.enqueue(q.dequeue());
for(int i=0;i<cnt;i++){
    q11.enqueue(array[i]);
}

}

void incstock(int num,queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
if(q1.front()==num){
    update(q11,q1);}
   else if(q2.front()==num){
    update(q11,q2);}
    else if(q3.front()==num){
    update(q11,q3);}
    else if(q4.front()==num){
   update(q11,q4);}
    else if(q5.front()==num){
    update(q11,q5);}
    else if(q6.front()==num){
    update(q11,q6);}
    else if(q7.front()==num){
    update(q11,q7);}
    else if(q8.front()==num){
    update(q11,q8);}
    else if(q9.front()==num){
    update(q11,q9);}
    else if(q10.front()==num){
   update(q11,q10);}
}
void inputing(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
    int num;
    cout<<"Enter the card number which you want to add to stock or \n for exit enter 0  \n for suffle enter -1:";
    cin>>num;
    if(num==-1){
        cout<<"Stock shuffled \n";
        q11.dequeue();
    }
   else if(num==0){
        cout<<"Thanks for playing game \n ";
        exit(0);
    }
   else if(num-1 == q11.front() || num+1 == q11.front() || (num==1 && q11.front()==13)||(num==13 && q11.front()==1)){
incstock(num,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    }
    else{
        cout<<"This card cant be addon the stack \n";
    }
}

void chkwin(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
    if(q1.empty() && q2.empty() && q3.empty() && q4.empty() && q5.empty() && q6.empty() && q7.empty() && q8.empty() && q9.empty() && q10.empty() ){
cout<<"YOU WIN! \n";
return;}
else if(q11.empty()){
    cout<<"YOUR LOSE! \n";
    return;}
}

void saving(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
   ofstream file("file.txt");
    if (!file) {
        cout << "File not opened!\n";
        return;
    }
    
    for (int i = 1; i <= 11; i++) {
        queue<int> temp = q11;  
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

void loading(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11) {
    ifstream file("file.txt");
    if (!file) {
        cout << "File not opened!\n";
        return;
    }
    
    int helper;
    for (int i = 1; i <= 11; i++) {
        queue<int> *temp = &q11;
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
 void functioning(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
   while(true){cout<<"1. Start new game \n";
   cout<<"2. Continue game \n";
   cout<<"3.(Enter anything for exit) Exit \n";
   int input;
   cout<<"Enter your choice: ";
   cin>>input;
   if(input==1){
    filling(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);}
    else if(input==2){
        loading(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11); }
        else{exit(0);}


    while((!q1.empty() && !q2.empty() && !q3.empty() && !q4.empty() && !q5.empty() && !q6.empty() && !q7.empty() && !q8.empty() && !q9.empty() && !q10.empty()) || (!q11.empty())){
    display(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    inputing(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    saving(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    chkwin(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
}
   }
 }
int main(){
queue<int> q1(4);
queue<int> q2(3);
queue<int> q3(2);
queue<int> q4(4);
queue<int> q5(3);
queue<int> q6(2);
queue<int> q7(4);
queue<int> q8(3);
queue<int> q9(2);
queue<int> q10(1);
queue<int> q11(52);
functioning(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);


}