//백준 1912
#include<iostream>
#include<algorithm>
using namespace std;
//음수가 들어갈때는 0을 활용해보자

int main(){
	int n; cin>>n;
    int arr[n], dp[n]={0,};
    for(auto &i: arr) cin>>i; dp[0]=arr[0]; //auto만 쓰면 안된다, auto& 를 써야지 비상수참조자란다. 
    //앞에서부터 차근차근왔는데 최선이 음수야 그럼 난 걔를 버려도 돼
    for(int i=1;i<n;i++) dp[i]= max(0,dp[i-1])+arr[i];
    cout<<*max_element(dp,dp+n)<<"\n"; return 0;}
