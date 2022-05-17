// 백준 2331 반복수열 
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX = 300000 + 1;
int P;
int visited[MAX];
void DFS(int num){
        visited[num]++; //반복구간이 한번 반복되었다는 것을 의미

        if (visited[num] == 3) return;//3번이상 반복되면 삭제 
        int sum = 0;
        while (num){
                 sum += (int)pow((num % 10), P);
                 num /= 10;}
        DFS(sum);}

int main(void){
        ios_base::sync_with_stdio(0);cin.tie(0);
        int A;
        cin >> A >> P;
        DFS(A);
        int result = 0; //한번만 등장한 숫자들이 반복구간에 속하지 않은 숫자들

        for (int i = 0; i < MAX; i++)
                 if (visited[i] == 1)
                         result++;
        cout << result << "\n";
        return 0;
}
 
 
 
// 백준 2331 내정리 위 코드랑 거의비슷
#include<iostream>
#include<vector>
#include <cmath>
using namespace std;
#define MAX 3000001
int n,p,ret{0};
int visited[MAX]; //자기 노드번호= 인덱스에 횟수 넣으면 된다.  

void dfs(int node){
    visited[node]++;
    int sum{0};
    while(node){
        sum+= pow((node%10),p);
        node/=10;
    }
    if(visited[sum]<3){
    dfs(sum);}
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
       
        cin>>n>>p;
        dfs(n);
        for(int i=0;i<=MAX;i++) //n까지가 아니라 MAX까지여야 한다. 
        {
            if(visited[i]==1){
                ret++;
            }
        }
        cout<<ret<<"\n";
    
    
}
