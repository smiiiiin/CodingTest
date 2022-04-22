//백준1644 소수의 연속합 //이거 큐로도 가능 밑에 있음.

// if else if랑 if if는 다르다. else if는 if에서 걸러서 내려온 것, if-if는 새롭게 다시
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void) {
    int ans; vector<bool> check; vector<int> prime;
    scanf("%d", &ans);
    check.resize(ans + 1, true);

    //소수만들기
    for(int i=2;i*i<=ans;i++){ //i는 루트 n까지만 보면 된다.
        for(int j=i; i*j <=ans;j++){
            //check인덱스 안에 들어가는 수 i*j가 <=n일때까지
            check[i*j]=0;}}

    for (int i = 2; i <= ans ; i++) {
            if (check[i]) prime.push_back(i);}

    int cnt = 0, end = 0, start = 0, sum = 0;
    while (1){
        if (sum >= ans) sum -= prime[start++];
        else if(end== prime.size()) break;
        else sum += prime[end++];
        if(sum==ans)cnt++; }
    
    printf("%d", cnt);
    return 0;}


//백준1644 소수의 연속합 : 큐로
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(void) {
    int ans; vector<bool> check; vector<int> prime;
    scanf("%d", &ans);
    check.resize(ans + 1, true);

    //소수만들기
    for(int i=2;i*i<=ans;i++){ //i는 루트 n까지만 보면 된다.
        for(int j=i; i*j <=ans;j++){
            //check인덱스 안에 들어가는 수 i*j가 <=n일때까지
            check[i*j]=0;}}

    for (int i = 2; i <= ans ; i++) {
            if (check[i]) prime.push_back(i);}

    queue<int> q; int sum{0},cnt{0};
    
    for(int i=0;i<prime.size();i++) {
        q.push(prime[i]); sum+=prime[i];
        while(sum>ans) {int cur= q.front(); sum-=cur; q.pop();}
        if(sum==ans) cnt++;}
    
    printf("%d", cnt);
    return 0;
}
