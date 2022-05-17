// 백준2143 두 배열의 합 
// 중단에 중요 정리!! 글 참고할 것. 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1; const int minINF = -1e9-1;

int N,M,T; long long result = 0; 
int A[1001]; vector<int> sumA; int B[1001]; vector<int> sumB;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>T; cin>>N;
	for(int i = 1;i<=N;++i){
		cin>>A[i]; A[i] += A[i-1];} //합의 누적배열 만든다. 

	cin>>M;
	for(int i = 1;i<=M;++i){
		cin>>B[i]; B[i] += B[i-1];} //합의 누적배열 만든다. 

	for(int i = 1;i<=N;++i){
		for(int j = 0;j<i;++j){
			sumA.push_back(A[i] - A[j]);}} //모든 조합의 합들을 벡터에 넣는다.
			
	for(int i = 1;i<=M;++i){
		for(int j = 0;j<i;++j){
			sumB.push_back(B[i] - B[j]);}} //모든 조합의 합들을 벡터에 넣는다. 

	//sort(sumA.begin(),sumA.end());
	sort(sumB.begin(),sumB.end()); //왜 sumb벡터는 오름차순이 되어야하는가? 굳이 필요없는거 같은데 왜 없으면 틀릴까? 

	for(auto x : sumA){
		int high = upper_bound(sumB.begin(),sumB.end(),T-x) - sumB.begin(); //두개 합해서 그 값되는 경우 인덱스
		//위치를 넘어선 경우, 전 경우 뽑은 다음에 빼기 해줌으로써 (결과)개수를 더해간다. 
		int low = lower_bound(sumB.begin(),sumB.end(),T-x) - sumB.begin();
		result += (high-low);}

	cout<<result;
    return 0;}


// !!!중요 정리) 내가 배운 큐 이용해서 만들어 본건데 왜틀? 2003 수들의 합에서는 sum이 답을 초과하면 앞에걸 pop하는데 이는 배열이 
// 한개일때만 조건에 알맞는 조합을 뱉는 거지, 모든 조합을 뱉지 못하므로 그냥 위의 방법이 맞다. 누적합한다음에 누적합의
// 배열들, 저거 dfs로 내가 1,1 1,2 1,3 1,4 2,2 2,3 이렇게 시작점과 끝점을 만들어서 다 더해보고 이렇게 한거 
// 어차피 연속이니까 누적합으로 한다음에 빼기로 하는게 더 빠르게 된다. 


//백준2143 두 배열의 합 
#include <iostream>
#include<algorithm>
#include<vector>
#include <queue>
#define MAX 1001
using namespace std;
vector<int> v1,v2; queue<int> q1, q2;
int n1,n2,num,sum,cnt; int arr1[MAX]; int arr2[MAX];  long long ans;

void bfs(){
    for(int i=0;i<n1;i++){
        q1.push(arr1[i]);
        sum+=arr1[i];
        v1.push_back(sum);
        while(ans>sum){
            int cur= q1.front();
            sum-=cur;
            q1.pop();
        }
    }
    
    for(int i=0;i<n2;i++){
        q1.push(arr2[i]);
        sum+=arr2[i];
        v2.push_back(sum);
        while(ans>sum){
            int cur= q2.front();
            sum-=cur;
            q2.pop();
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>ans;
    cin>>n1;
    for(int i=0;i<n1;i++) cin>>arr1[i];
    cin>>n2;
    for(int i=0;i<n2;i++) cin>>arr2[i];
    bfs();
    sort(v2.begin(), v2.end());
    for(auto i: v1) {
        int after= upper_bound(v2.begin(), v2.end(), ans-i)-v2.begin();
        int before= lower_bound(v2.begin(), v2.end(), ans-i)-v2.begin();
        cnt+= after-before;
    }
    cout<<cnt;}
