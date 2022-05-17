//백준1759 암호만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L,C; vector<char> v; vector<char> res;

bool pass(){
    int mo{0};
    for(int i=0;i<L;i++){
        if(res[i]=='a'||res[i]=='e'||res[i]=='i'||res[i]=='o'|| res[i]=='u')  {mo++;}}
    if(mo>0 && L-mo >1) return 1;
    return 0;}


void dfs(int node){
    if((int)res.size()==L){
        if(!pass()) return;
        for(int i=0;i<L;i++) cout<<res[i];
        cout<<"\n";
        return;
    }
    for(int i=node;i<C;i++){
        res.push_back(v[i]);
        dfs(i+1);
        res.pop_back();
    }
    return;}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>L>>C;
    char ch;
    for(int i=0;i<C;i++) {cin>>ch; v.push_back(ch);}
    sort(v.begin(), v.end());
    dfs(0);
    
    return 0;
}
