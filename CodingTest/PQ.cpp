//정렬되지 않은 PQ
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//야 이걸 이용했어야지

class isLess{
public:
    bool operator()(const int a, const int b) const{
        if(a<=b) {return true;}
        else {return false;}
}
};

class isMore{
public:
    bool operator()(const int a, const int b) const{
        if(a<=b) {return false;}
        else {return true;}
}
};

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
    if(empty()) return 0;
    else{
    isLess l;
    int min= *v.begin();
    for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++){
        if(l(*iter,min))
        { min = *iter;
        }
    }
        return min;}
}

int PQ::findMax(){
    if(empty()) return -1;
    else{
    isMore m;
    int max= *v.begin();
    vector<int>::iterator point= v.begin();
    for(vector<int>::iterator iter= v.begin();iter!=v.end();iter++){
        if(m(*iter, max)){
            max=*iter;
            point= iter;
        }
    } return max;}
}

void PQ::delMin(){//iter은 어떻게 삭제하지? min일때 iter은 어떻게 구하지? //여기가 문제래..
    if(empty()){return ;}
    else{
    isLess l;
    int min= *v.begin();
    vector<int>::iterator point= v.begin();
    for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++){
        if(l(*iter, min)){
            min=*iter;
            point= iter;//min을 가르키는 포인터를 동일화하는게 끌고가는거다. pre=cur처럼.
        }}
        v.erase(point);//위치좀!!!
        
    }}


void PQ::delMax(){
    if(empty()) return ;
    else {
        isMore m;
        int max= *v.begin();
        vector<int>::iterator point= v.begin();
        for(vector<int>::iterator iter= v.begin();iter!=v.end();iter++){
            if(m(*iter, max)){
                max=*iter;
                point= iter;
            }
        }
        v.erase(point);
        return;}
}



int main(){
cin.tie(NULL);
ios_base::sync_with_stdio(false);
PQ pqda;
int num, da,  mm, play;
string oper;
cin>>play;
for(int j=0;j<play;j++){
    int i{0};
    cin>>num;
    while(i!=num){
    cin>>oper;
        if(oper=="D"){ //"D -1"이면 이라고 하면 안됨. 왜? 그러면 oper: 이 두번이나 뜬다. 왜지?
            cin>> mm;
            if(mm==1){
                pqda.delMax();}
            else if(mm==-1){
                pqda.delMin();}
            i++;
        }
        
        else if(oper=="I"){
            cin>>da;
            pqda.enqueue(da);
            i++;
            }
        }
    if(pqda.empty()) {cout<<"EMPTY"<<"\n";}
    else{
        cout<<pqda.findMax()<<" ";
        cout<<pqda.findMin()<<"\n";
        }
    }
}

/*
 C++을 사용하고 있고 cin/cout을 사용하고자 한다면, cin.tie(NULL)과 ios_base::sync_with_stdio(false);를 둘 다 적용해 주고, endl 대신 개행문자(\n)를 쓰자. 단, 이렇게 하면 더 이상 scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.
 */
