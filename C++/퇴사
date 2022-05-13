//백준 14501
#include <iostream>
#include <algorithm>
using namespace std;
int n; int t[16], m[16]; int ret{0};

int dp(int day){ //day부터 막날까지 최대이익 함수
    if(day>n+1) return -0x7ffffff;//어차피 max택하니까 작은값 넣기
    if(day==n+1) return 0; //호출될 수도 있어서
    
    ret= max(m[day]+ dp(day+t[day]),dp(day+1));
    return ret;}

int main() {
    cin>>n;
    //--n; 여기다 놓으면 for문 돌때 입력이 모자르게 된다.
    for(int i=1;i<=n;++i) {cin>>t[i]; cin>>m[i];}
    //--n;
    cout<<dp(1)<<"\n"; return 0;}
