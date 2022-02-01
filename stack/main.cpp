#include<iostream>
#include<string>
using namespace std;

class stack{
private:
    int t;
    int* arr;
    int capacity;
   
public:
    stack(int cp){
        this->capacity= cp;
        this-> t=-1;
        this->arr= new int[capacity];
     }
    int size();
    bool empty();
    
    void push (int x);
    int pop();
    int top();
};

bool stack::empty(){
return t==-1; }

void stack::push(int x){
    if(size()==capacity) return;
    else arr[++t]=x;
}

int stack::pop(){
    if(empty()) return t=-1;
    else return arr[t--];
}

int stack::size(){
    if(empty()) return t=-1;
    else return t+1;}

int stack::top(){
    if(empty()) return t=-1;
    return arr[t]; }

int main(){
    int num,da,i{0};
    stack S(100);
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
