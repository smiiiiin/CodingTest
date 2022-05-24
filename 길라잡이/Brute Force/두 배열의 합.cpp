// 백준2143 두 배열의 합 
// 중단에 중요 정리!! 글 참고할 것. 
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321; const int minINF = -987654321;

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
	sort(sumB.begin(),sumB.end()); // 만약 수가 2222인 경우 2가 필요할때가 4번이니까 정렬이 필수 
	
	for(auto x : sumA){
		int high = upper_bound(sumB.begin(),sumB.end(),T-x) - sumB.begin(); //두개 합해서 그 값되는 경우 인덱스
		//위치를 넘어선 경우, 전 경우 뽑은 다음에 빼기 해줌으로써 (결과)개수를 더해간다. 
		int low = lower_bound(sumB.begin(),sumB.end(),T-x) - sumB.begin();
		result += (high-low);}

	cout<<result;
    return 0;}
