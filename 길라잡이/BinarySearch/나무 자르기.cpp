//백준 2805 나무 자르기
// 최소한 m 은 가져가는데 최대 높이를 해서 환경보호 원한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m; vector<int> v;
int main() {
    cin>>n>>m;
    for(auto i=0 ;i<n;i++){
        int x; cin>>x; v.push_back(x);}
    int start{0},result{0};
    // long long int sum{0};은 틀린다. 
    int en= *max_element(v.begin(), v.end());
    while(start<=en){
        //위치도 중요하다. 변수는 바로 직후 바깥에다가 두기!!
        long long int sum{0};
        int mid= (start+en)/2;
        for(auto i=0;i<n;i++){
            if(mid<v[i]) sum+= v[i]-mid;}
         
        if(sum>=m){result= mid; start=mid+1; }
        
        //조건이 충족안되면 높이는 낮아지면서 환경보호를 덜한다.
        else en=mid-1;}
    cout << result; }
