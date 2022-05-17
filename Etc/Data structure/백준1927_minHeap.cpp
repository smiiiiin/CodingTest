//1927 minHeap
#include<iostream>
#include<string>
#include<vector>
using namespace std;
enum direction {MIN=1, MAX=-1};

class heap{
private:
    int direction;
    vector<int> v;
    int root;
    int sz;
public:
    heap(int direction){
        v.push_back(-1); //이거?
        this-> direction = direction;
        this-> root= 1;
        this-> sz= 0;
        
    }
    void swap(int a, int b){
        v[0]= v[a];
        v[a]= v[b];
        v[b]= v[0]; //v[1]이라고 하고 앉아있어!!!
}
    int size();
    bool empty();
    void insert(int);
    int pop();
    void upHeap(int);
    void downHeap(int);
    //void print();
};
/*
void heap::print(){
    int idx= root;
    while(idx<=size()){
        cout<<v[idx]<<" ";
        idx++;
    }
}*/

int heap::size(){
    return sz;
}
bool heap::empty(){
    return sz==0;
}

void heap::insert(int elem){ //정리2: 사이즈를 키우고 나서!! push_back
    //을 해야한다!!!
    
    sz++; //정리1: sz건 size()건 상관없다.
    v.push_back(elem);
    upHeap(sz); }
    

void heap::upHeap(int idx){
    if(idx==root){return;
    }
    else{
        int par= idx/2;
        if(v[par]*direction > v[idx] *direction ){
            swap(par, idx);
            upHeap(par);
        }
        else return;
        
    }}

int heap::pop(){
    if(empty()) {return 0;}
    else{
        int r = v[root];
        swap(root, sz); --sz;
        v.pop_back();
        downHeap(root);
        return r;}
}


void heap::downHeap(int idx){
    if(idx==root){return ;}
    int left= 2*idx;
    int right= 2*idx+1;
    if(left<=sz){//왼자식만 있을 때 //<=이라고 안하고 <이라함;
        if(v[left]*direction<v[idx]*direction){
            swap(left, idx);downHeap(left);}
        else return;
    }
    
    else if(right<=sz){//왼, 오 자식 다 있을 때
        if(v[left]*direction<v[right]*direction){
            if(v[left]*direction<v[idx]*direction){ //심지어 왼오도 헷갈림?
                swap(left, idx);
                downHeap(left);}
            else return;
        }
            //어떻게 왼쪽이 작은경우는 생각안함?!?!
        else {
            if(v[right]*direction<v[idx]*direction){
                swap(right, idx);
                downHeap(right);}
            else return;
        }
    }
        
    }
    

int main(){
    heap H(MIN);
    int num, oper;
    //cout<<"몇번? ";
    cin>>num;
    int i{0};
    while(i!=num){
        //cout<<"명령: ";
        cin>>oper;
        
        if(oper == 0){
            cout<<H.pop()<<endl;
            i++;
            }
        else if(oper!=0)
        {
            H.insert(oper);
            i++;
        }
    }
return 0;}
