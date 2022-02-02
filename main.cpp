#include<iostream>
#include <string>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node(int e){
    this->data=e;
    this-> next= nullptr;}
    friend class Q;
};

class Q{
private:
    Node* fron;
    Node* rear;
    int sz;
    
public:
    Q(){
    this-> fron= nullptr;
    this-> rear= nullptr;
    this->sz=0;
    }
    
    bool empty();
    int size();
    void push(int);
    int pop();
    int front();
    int back();
};

bool Q::empty(){
return (fron==nullptr&& rear==nullptr); }

int Q::size(){
    return sz;}

void Q::push(int elem){
    sz++;
    Node* newnode= new Node(elem);
    if(empty()){rear=newnode;
                fron=newnode; }
    else{
        rear->next=newnode;
        rear=newnode;}

}
int Q::pop(){
    sz--;
    Node* cur=fron;
    fron= fron->next;
    return cur->data;
}
int Q::front(){
    if(empty()) return -1;
    else return fron->data;
}
int Q::back(){
    if(empty()) return -1;
    else return rear->data;
}



int main(){
    Q que;
    int num, da, i{0};
    string oper;
    cin>>num;
    
    while(i!=num){
        if(oper=="size"){
            cout<<que.size()<<endl;
            i++;
        }
        else if(oper=="empty"){
    cout<<que.empty()<<endl;
            i++;
        }
        else if(oper=="push"){
            cin>>da;
            que.push(da);
            i++;
        }
        else if(oper=="front"){
            cout<<que.front()<<endl;
            i++;
        }
        else if(oper=="pop"){
            cout<<que.pop()<<endl;
            i++;
        }
        else if(oper=="back"){
            cout<<que.back()<<endl;
            i++;
        }
    
   }
return 0;
}
