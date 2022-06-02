//백준1806 부분합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, ans; cin >> n >> ans; vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int start{0}, end{0}, sum{0},minLen{987654321};
    while(start<=end && end<=n){
        if(sum<ans) sum+=arr[end++];
        else  {
            minLen= min(minLen,end-start); sum-=arr[start++];}}
    if (minLen == 987654321) cout << 0 << endl;    // 불가능 하면 0 출력
    else cout << minLen << "\n";
    return 0;}

//큐버전
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[100001];int n,s,cnt{0};

void bfs(){
    queue<int> q; int sum{0};
    for(int i=0;i<n;i++){
        q.push(arr[i]); sum+=arr[i]; 
        while(sum>=s){
            if(cnt==0) cnt= q.size();
            int qs= q.size();
            cnt= min(cnt, qs);
            int cur=q.front();  sum-=cur; q.pop();}}}

int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>arr[i];
    bfs();
    cout<<cnt<<"\n";
    return 0;}
