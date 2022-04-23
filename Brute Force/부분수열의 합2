//백준 1208 부분수열의 합2 //그냥 다 해보는건데 dfs에서 두부분으로 나눴을 뿐이다.
#include <iostream>
#include <map>
using namespace std;
int n, ans; int arr[41]; map<int, int> m; long long cnt;
 
void frontDfs(int idx, int sum){ //앞부분
    if(idx==n/2) {m[sum]++; return;}
    frontDfs(idx+1, sum+arr[idx]);
    frontDfs(idx+1, sum);}

void backDfs(int idx, int sum){ //뒷부분
    //앞부분 서, 네가 m에 저장해놓은 걸 활용할게 return때마다 뒷파트의 sum과 정해진 ans를 이용해서.
    if(idx==n) {cnt+=m[ans-sum]; return;}
    backDfs(idx+1, sum+arr[idx]);
    backDfs(idx+1, sum);}

int main(){
    cin >> n >> ans;
    for(int i = 0; i < n; i++) cin >> arr[i];
    frontDfs(0, 0); backDfs(n/2, 0);
    
    if(!ans) cout << cnt-1; //if ans==0 dfs(0,0)안하게 되는 경우, 0 을 cnt+1 gkrpehla
    else cout << cnt;
    return 0;}
