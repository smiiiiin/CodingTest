//맞았다
#include <iostream>
using namespace std;

class Node{
private:
    int elem;
    Node* next;
public:
    Node(int e){
        this->elem= e;
        this->next= nullptr;
    }
    friend class stack;
    
};

class stack{
private:
    Node* head ;
    Node* tail ;
public:
    bool empty();
    int size();
    void push(int);
    int pop();
    int top();
    stack();
    
};

stack::stack(){
    this-> head= nullptr;
    this-> tail= nullptr;
    
}

bool stack::empty(){
    return (head==nullptr&tail==nullptr);
}

int stack::size(){
    int sz{0};
    Node*cur= head;
    
    if(empty()){return sz;}
    else
    {while(cur->next!=nullptr){
        cur=cur->next;
        sz++;
    }
        sz++;
        return sz;}
}

void stack::push(int e){
    Node* cur=new Node(e);
    if(empty()){head=cur;}
    else{
    cur->next= head;
        head= cur;}
}

int stack::top(){
    if(empty()) return -1;
    else return head->elem;
}

int stack::pop(){
    if(empty()) {return -1;}
    else
    { Node* cur= head;
        head=head->next;
        return cur->elem;}
}


int main(){
    int num,da,i{0};
    stack S;
    string oper;
    
    cin>>num;
    
    while(i!=num){
        cin>>oper;
        
        if(oper=="push"){
            cin>>da;
            S.push(da);
            i++;
            }
        else if(oper=="pop"){
            cout<<S.pop()<<endl;
            i++;
            }
        else if(oper=="top"){
            cout<<S.top()<<endl;
            i++;
            }
        else if(oper=="empty"){
            cout<<S.empty()<<endl;
            i++;
            }
        else if(oper=="size"){
            cout<<S.size()<<endl;
            i++;
            }
        }
    
return 0;}
