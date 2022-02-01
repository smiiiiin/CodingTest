//백준 10845번

#include<iostream>
using namespace std;
#include<string>

class Node{
private:
    Node* next;
    int data;
public:
    Node(int e){
        this->next= nullptr;
        this->data= e;
    }
    friend class Q;
};

class Q{
private:
    Node* front;
    Node* rear;
public:
    Q(){
        front= nullptr;
        rear= nullptr;
    }
    bool empty();
    int size();
    void push(int elem);
    int pop();
    int fron();
    int back();
    
};

bool Q:: empty(){
    return (front==rear&&rear==nullptr); }

int Q::size(){ //cur이 front부터 rear까지 for문 써서
    int sz{0};
    Node* cur=front;
    if(front==nullptr) return sz;
    else
    {while(cur!=nullptr){
        cur=cur->next;
        sz++;
    }}
    return sz;}

/*
 int Q::size(){ //cur이 front부터 rear까지 for문 써서
    int sz{0};
    Node* cur=front;
    if(front==nullptr) return sz;
 
    else{
        for(cur=front;cur<=rear;cur++){
            sz++;}
    return sz;}
 
 }
*/
void Q::push(int elem){
    Node* newnode=new Node(elem);
    
    if(empty()){rear= newnode; front= newnode;}
    else{rear->next= newnode;
        rear= newnode;}
}

int Q::fron(){
    return front->data;}


int Q::back(){
    return rear->data;}
 


int Q::pop(){
    Node* cur=front;
    if(empty()){return -1;}
    else{front=front->next; //? pop에서 왜 걸리는 거지?
        return cur->data;}}


int main(){
int num, daa, i{0};
Q que;
string oper;
    cin>>num;
    while(i!=num){
cin>>oper;
        if(oper=="empty"){
            cout<<que.empty()<<endl;
            i++;
        }
        else if(oper=="size"){
            cout<<que.size()<<endl;
            i++;
        }
        else if(oper=="push"){
            cin>>daa;
            que.push(daa);
            i++;
        }
        else if(oper=="pop"){
            cout<<que.pop()<<endl;
            i++;
        }
        else if(oper=="front"){
            cout<<que.fron()<<endl;
            i++;
        }
        else if(oper=="back"){
            cout<<que.back()<<endl;
            i++;
        }
    }
}

