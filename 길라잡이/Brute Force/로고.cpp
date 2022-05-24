//백준 3108 로고
/*  X2 하는 이유 원래 안겹치는 데 겹치는 경우 
   여기서는 음수, 양수의 문제가 아니라 (2,2)(3,3)과 (1,1)(4,4) 사각형의 경우
   둘러싸고 있는 경우, 선이여서 겹쳐지지 않는데 우리는 MAP에서 칸으로 표현해서 X2함으로써 
   분산 시켜줘야 한다. */

//  if (MAP[1000][1000] == 2) res--; 0,0에서 붓은 닿아있는 상태이므로. 
#include<iostream>
#define MAX 2001
using namespace std;
 
int n; int map[MAX][MAX]; int dy[4] = { -1,1,0,0 }; int dx[4] = { 0,0,-1,1 };
 
void dfs(int y, int x){
    if(y<0||x<0||y>=MAX||x>=MAX) return;
    if(map[y][x]==2||map[y][x]==0) return;
    map[y][x]=2;
    for(int d=0;d<4;d++){
        int ny= y+dy[d]; int nx= x+dx[d]; dfs(ny,nx);
    }}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++){
        int a,b,c,d;
        cin >> a>>b>>c>>d;
 
        a = (a + 500)*2; b = (b + 500)*2 ; 
        c = (c + 500)*2 ; d = (d + 500)*2;
 
        for (int i = a; i <= c; i++){ //테두리1 표시
            map[b][i] = 1;
            map[d][i] = 1;}
        for (int i = b; i <= d; i++){
            map[i][a] = 1;
            map[i][c] = 1;}}
    
    
    int ret{0};
    for(int y=0;y<MAX;y++){
        for(int x=0;x<MAX;x++){
            if(map[y][x]==1) {dfs(y,x); ret++;}
        }
    }
    
    if (map[1000][1000]==2) ret--;
    cout<<ret<<"\n";
    
    return 0; }
