//백준 11047 동전 
//백준 11047 동전 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int res{0};
vector<int> v;

bool les(int f,int s){
    return f>s  ;
}

int main(){
    int n,k;
    cin >> n>>k;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    
    sort(v.begin(),v.end(),les ); // 내림차순
    
    while(k>0){
        for(int i=0;i<v.size();i++){
            if(v[i]<k){
        k-=v[i];
        res++;}}
    }
    
    cout<<res<<"\n";
    return 0;
    
    
}
