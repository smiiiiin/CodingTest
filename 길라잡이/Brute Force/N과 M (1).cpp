// 백준 15649 N과 M (1)

/* 번호 찍어내는건 cnt에서 하는거라 cnt를 깊이로 생각하면 됨, visited는 딱히 관계가 없다. 그냥 !visited이면 들어가서 해주는 거임
   dfs(1)에서 i=2,3,4인 경우를 못함, dfs(2)에서는 i=3,4인경우를 못하고 dfs(3)에서는 i=4인 경우를 못해서 return 후 이것들을 해준다.
   visited[i]=0;에서 i는 arr[cnt]=i에서 i이므로 현재 dfs()안에 들어간 숫자의 -1이라고 보면 된다. */

#include <iostream>
using namespace std;

int n,m; int arr[9]; bool visited[9];

void dfs(int depth) {
    
    if (depth-1 == m) {
        for(int i=1;i<=m;i++) cout<<arr[i]<<" ";
        cout<<"\n"; return;}
        
    for(int i=1;i<=n;i++){ //i는 node에 대해서 , dfs()와 dfs() 사이의 것들을 못함. i=1일때 i=2,3,4,5
        if (!visited[i]) {
            visited[i] = 1; arr[depth]=i;
            dfs(depth+1);
            visited[i]=0;
            //cout<<"out: "<<i<<" "; //test해볼 수 있는 코드
        }}}

int main() {cin >> n>>m; dfs(1); }



/*
//백준6603 로또
#include <iostream>
using namespace std;
int arr[14]; int lotto[7]; int n;

void dfs(int depth, int node) {
    
    if(depth-1 ==6){ for(int i=1;i<=6;i++){ cout<<lotto[i]<<" ";}
        cout<<"\n"; return ;}
    
    //조합이니까 1 3 5 7 8 10 이거는 되는데 5 뽑으면 그보다 작은 수는 볼 필요도 없다
    
    for(int i=node;i<=n;i++){ //visited 쓰지 않고 node이용해서 뒤덮어쓰는 것도 가능하다
        //input을 7 6으로 넣고 n과 m(2)와 비교하자
        lotto[depth]=arr[i]; dfs(depth+1, i+1); }}

int main(void) {
    while (1) {
        cin >> n; if (n == 0) break;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        dfs(1, 1); cout << endl;}}
*/

/*
//백준 15650 N과 M (2)
#include <iostream>
using namespace std;

int n,m;
int arr[8]={0,};
bool visited[8]={0,};

void dfs(int depth, int node) { //브루트포스
    
    if (depth-1 == m) {
        for(int i=1;i<=m;i++){
            cout<<arr[i]<<" ";}
            cout << '\n';
        return; //그 전으로 돌아갓 (손으로 그린 그래프에서)
        }
    
    for(int i=node;i<=n;i++){
        if(!visited[i]) {
            //visited[i]=1;
            arr[depth]=i;
            dfs(depth+1, i+1);  // dfs(depth+1, node+1);은 안된다
            //visited[i]=0;
            
        }}
}
 

int main() {
    cin>>n>>m;
    dfs(1,1);
}
*/

// 백준 15649 N과 M (1) : 순열 뽑는 가지 수 - nPm
// 큰 수에서 작은수도 봐야하기 때문에 i=1부터 시작이고 같은 수가 중복 들어가면 안되서  visited를 체크 해줘야한다.
// 두번째 말의 의미는 7 6 이 입력인 경우에 7 5 4 3 2 1 이렇게 할때 7 5 하고 다시 7을 하면 안되기 때문에 visited가 필요

/* 번호 찍어내는건 cnt에서 하는거라 cnt를 깊이로 생각하면 됨, visited는 딱히 관계가 없다. 그냥 !visited이면 들어가서 해주는 거임
   dfs(1)에서 i=2,3,4인 경우를 못함, dfs(2)에서는 i=3,4인경우를 못하고 dfs(3)에서는 i=4인 경우를 못해서 return 후 이것들을 해준다.
   visited[i]=0;에서 i는 arr[cnt]=i에서 i이므로 현재 dfs()안에 들어간 숫자의 -1이라고 보면 된다. */

#include <iostream>
using namespace std;

int n,m; int arr[9]; bool visited[9];

void dfs(int index) {
    
    if (index-1 == m) {
        for(int i=1;i<=m;i++) cout<<arr[i]<<" ";
        cout<<"\n"; return;}
        
    for(int i=1;i<=n;i++){ //i는 node에 대해서 , dfs()와 dfs() 사이의 것들을 못함. i=1일때 i=2,3,4,5
        if (!visited[i]) {
            visited[i] = 1; arr[index]=i;
            dfs(index+1);
            visited[i]=0;
            //cout<<"out: "<<i<<" "; //test해볼 수 있는 코드
        }}}

int main() {cin >> n>>m; dfs(1); }
