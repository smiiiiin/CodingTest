//정렬되지 않은 PQ
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class PQ{
private:
    int root;
    vector<int> v;
    
public:
    PQ(){
    this-> root=0;
    
    }
    bool empty();
    int size();
    void enqueue(int e);
    int findMin();
    int findMax();
    void delMin();
    void delMax();

};

bool PQ::empty(){
    return v.size()==0;}

int PQ::size(){
    int sz{0};
    for(vector<int>::iterator i=v.begin();i<=v.end();i++){
        sz++;
    }
    return sz;
}

void PQ::enqueue(int e){
    v.push_back(e);
}
int PQ::findMin(){
int min=9999999;

for(vector<int>::iterator iter=v.begin();iter<=v.end();iter++){
    if(*iter<=min){
min=*iter;}
}
return min;}

void PQ::delMin(){
int min=9999999;

for(vector<int>::iterator iter=v.begin();iter<=v.end();iter++){
    if(*iter<=min){
min=*iter;
        iter++;//이걸 안하면 어떡해!
    }
    v.erase(iter);
}}



int PQ::findMax(){

int max=0;

for(vector<int>::iterator iter=v.begin();iter<=v.end();iter++){
    if(*iter>=max){
        max=*iter;}
}
return max;}

void PQ::delMax(){

int max=0;
for(vector<int>::iterator iter=v.begin();iter<=v.end();iter++){
    if(*iter>=max){
        max=*iter;
        iter++;
    }
    v.erase(iter);
}}



int main(){
    PQ pqda;
    string oper;
    int play, num, da, i{0};
    cin>>play;
    for(int j=0;j<play;j++){ //게임을 몇번 할건지
        cin>>num;
        while(i!=num){
            cin>>oper;
            
            if(oper=="D -1"){
                pqda.delMin();
                i++;
                }
            
            else if(oper=="I"){
                cin>>da;
                pqda.enqueue(da);
                i++;
                }
            
            else if(oper=="D 1"){
                pqda.delMax();
                i++;
            }}
        cout<<pqda.findMax()<<" ";
        cout<<pqda.findMin();
    }
    
return 0;
}
