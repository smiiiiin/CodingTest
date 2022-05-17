// 백준 11729 하노이탑 이동 순서
#include <iostream>
using namespace std;
void dfs(int n, int start, int pass, int end){
    if(n == 1) printf("%d %d\n", start, end);
        else{
            dfs(n-1,start,end,pass); //뒤에서 바꾸고 
            printf("%d %d\n",start,end);
            dfs(n-1,pass,start,end);}} //앞에서 바꾸고 
        
int main() {
    int n; cin >> n;
    cout << (1<<n) -1 << "\n"; //2의 num승 -1
    dfs(n,1,2,3);}
