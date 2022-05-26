//백준6603 로또: n과m (2)와 거의 유사, 3,4도 유사 
#include <iostream>
#include <vector>
using namespace std;
//start는 S의 인덱스, depth는 lotto의 인덱스
int S[13]; int lotto[6]; int k;

void dfs(int start, int depth) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) cout << lotto[i] << " ";
        cout << endl;
        return;}
    
    //start부터 k-1 까지 순서
    for (int i = start; i < k; i++) {
        lotto[depth] = S[i];
        dfs(i+1, depth+1);}
}

int main(void) {
    while (1) {
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) cin >> S[i];
        dfs(0, 0);
        cout << endl;}}

// 백준 6603 로또: 정답 2
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//start는 S의 인덱스, depth는 lotto의 인덱스
int arr[13]; int lotto[6]; int k;

void dfs(int start, int depth) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) cout << lotto[i] << " ";
        cout << endl;
        return;}
    
    for(int i=start;i<k;i++){
        if(lotto[depth]!=0) continue;
        lotto[depth]=arr[i];
        dfs(i+1,depth+1);
        lotto[depth]=0;
    }
}
 
int main(void) {
    while (1) {
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) cin >> arr[i];
        memset(lotto,0,sizeof(lotto));
        dfs(0, 0);
        cout << endl;}}



//백준6603 로또: 정답 3
#include <iostream>
using namespace std;
int arr[14]; int lotto[7]; int n;

void dfs(int depth, int node) {
    
    if(depth-1 ==6){ for(int i=1;i<=6;i++){ cout<<lotto[i]<<" ";}
        cout<<"\n"; return ;}
    
    //조합이니까 1 3 5 7 8 10 이거는 되는데 5 뽑으면 그보다 작은 수는 볼 필요도 없다
    
    for(int i=node;i<=n;i++){
        lotto[depth]=arr[i]; dfs(depth+1, i+1); }}

int main(void) {
    while (1) {
        cin >> n; if (n == 0) break;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        dfs(1, 1); cout << endl;}}
