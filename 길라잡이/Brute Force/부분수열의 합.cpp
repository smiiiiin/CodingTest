//백준 1182 부분수열의 합
// 부분집합 할래 말래? in & out dfs
//예전에 dp에서 퇴사문제도 dfs로 풀 수 있긴 하겠다. 일 가는경우? 안가는 경우? 아닌가? 그건 시간이 정해져있으니까? 
#include <iostream>
#include <vector>
using namespace std;

int n,answer; int arr[30]; int cnt{0};

void dfs(int node, int sum) {
    if (node==n) {
        if(sum==answer) cnt++;
        return;}
    dfs(node+1, sum+arr[node]); //하게되는 경우: 안하게 되는 경우를 return후 해야한다. 
    dfs(node+1, sum); //안하게 되는 경우 : return 후 할건 없고 안하게 되더라도 진행은 계속 시켜야한다. 
    
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>answer;
    for(int i=0;i<n;i++) cin>>arr[i];
    dfs(0,0);
    if(answer==0) cnt--;
    cout<<cnt;}
 
