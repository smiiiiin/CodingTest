//백준6603 로또
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

// 내가 작성해봄 
// 백준6603 로또
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
