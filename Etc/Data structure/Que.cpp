#include<iostream>
#include<string>
using namespace std;


class Q{
private:
    int capacity;
    int fron;
    int rear;
    int* arr;
public:
    Q(int cp){
        this-> capacity= cp;
        this-> fron = -1;
        this-> rear = -1;
        this-> arr =new int[capacity];
    
}
    bool empty();
    int size();
    void push(int);
    int pop();
    int front();
    int back();

};

    bool Q::empty(){
        return rear-fron==0;
    }
    int Q::size(){
     if(empty()) return 0;
     else return  (rear-fron+capacity)%capacity;
    }
    void Q::push(int da){
        rear=(rear+1)%capacity;
            arr[rear]=da;}
        
    
    int Q::pop(){
        if(empty()) {return -1;}
        else{
            int cur= arr[fron+1];//?
        fron=(fron+1)%capacity;
            return cur;}
    }
    int Q::front(){
        return arr[(fron+1)%capacity];//왜 fron+1?
    }
    int Q::back(){
        return arr[rear];
    }

int main(){
int num, daa, i{0};
Q que(1000);
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
            cout<<que.front()<<endl;
            i++;
        }
        else if(oper=="back"){
            cout<<que.back()<<endl;
            i++;
        }
    }
}
