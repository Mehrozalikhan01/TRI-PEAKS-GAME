#include <iostream>
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
    return ptr[rear];
}
t front(){   
    return ptr[rear];
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

void inputing(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
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
if(q1.fron - q1.rear > 0){
    cout<<"     "<<"*";
}
if(q4.fron - q4.rear > 0){
    cout<<"     "<<"*";
}
if(q7.fron - q7.rear > 0){
    cout<<"     "<<"*"<<endl;
}
if(q1.fron - q1.rear > 0){
    cout<<"    "<<"*";
}
if(q2.fron - q2.rear > 0){
    cout<<" *";
}
if(q4.fron - q4.rear > 0){
    cout<<"   "<<"*";
}
if(q5.fron - q5.rear > 0){
    cout<<" *";
}
if(q7.fron - q7.rear > 0){
    cout<<"   "<<"*";
}
if(q8.fron - q8.rear > 0){
    cout<<" *"<<endl;
}
if(q1.fron - q1.rear > 0){
    cout<<"   "<<"*";
}
if(q2.fron - q2.rear > 0){
    cout<<" "<<"*";
}
if(q3.fron - q3.rear > 0){
    cout<<" "<<"*";
}
if(q4.fron - q4.rear > 0){
    cout<<" "<<"*";
}
if(q5.fron - q5.rear > 0){
    cout<<" "<<"*";
}
if(q6.fron - q6.rear > 0){
    cout<<" "<<"*";
}
if(q7.fron - q7.rear > 0){
    cout<<" "<<"*";
}
if(q8.fron - q8.rear > 0){
    cout<<" "<<"*";
}
if(q9.fron - q9.rear > 0){
    cout<<" "<<"*"<<endl;
}
if(q1.rear == 0){
    cout<<"  "; q1.card(); 
}
if(q2.rear == 0){
    cout<<" "; q2.card();
}
if(q3.rear == 0){
    cout<<" "; q3.card();
}
if(q4.rear == 0){
    cout<<" "; q4.card();
}
if(q5.rear == 0){
    cout<<" "; q5.card();
}
if(q6.rear == 0){
    cout<<" "; q6.card();
}
if(q7.rear == 0){
    cout<<" "; q7.card();
}
if(q8.rear == 0){
    cout<<" "; q8.card();
}
if(q9.rear == 0){
    cout<<" ";
    q9.card();
}
if(q10.rear == 0){
    cout<<" ";
    q10.card();
    cout<<endl;
}



}
 void functioning(queue<int> &q1,queue<int> &q2,queue<int> &q3,queue<int> &q4,queue<int> &q5,queue<int> &q6,queue<int> &q7,queue<int> &q8,queue<int> &q9,queue<int> &q10,queue<int> &q11){
    inputing(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
    display(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);
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
queue<int> q11(24);
functioning(q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11);


}