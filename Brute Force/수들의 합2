//백준2003 수들의 합2
#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

queue<int> q; int sum{0};  int arr[10010];
int main(){
	int n,res; cin>>n>>res;
	for(int i=0;i<n;i++) cin>>arr[i];
	int cnt{0};
	for(int i=0;i<n;i++){
	    q.push(arr[i]);
	    sum+=arr[i];
	    while(sum>res){int now= q.front();
	    sum-=now;
	    q.pop();}
	    if(sum==res) cnt++;
	}
	cout<<cnt;}
    
// 시작,끝 포인터들 위치의 조합 출력 dfs
// 이렇게 하면 시간초과 뜬다. 근데 결과가 맞게 나오긴 나온다:) 나름 뿌듯 ...
//백준2003 수들의 합2
#include <stdio.h>
#include <iostream>
using namespace std;
int v[3]; int n,ans,cnt;  int arr[10001];

void dfs(int node, int depth){
    if(depth==3) { 
    int sum=0;
    for(int i=v[1];i<=v[2];i++){
        sum+=arr[i];}
        if(sum==ans) cnt++;
        return;}
    
    for(int i=node;i<=n;i++){
        v[depth]=i;
        dfs(i,depth+1);}}

int main(){
    scanf("%d %d",&n,&ans);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	dfs(1,1);
	printf("%d\n",cnt);}
