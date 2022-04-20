// 백준2580 스도쿠
// [그 구역][그 값]이중배열을 이용한 그 구역엔 그 값은 있어!! 
// Q. 얘는 return을 언제할까? 
// A. 답은 여러개고 상황에 맞춰 채워지기 때문에 굳이 return할 필요가 없다. 
/* 4x4스도쿠를 이용해서 빈칸을 몇개 뚫어서 return을 언제할 지 생각해보기. 
// 아직 찾은 testcase가 없는게 뚤린 얘들끼리 숫자만 바뀔 뿐, 틀린 경우를 찾기가 어렵다. 구멍을 많이 뚫으면 되나? 
2 1 4 3
4 3 2 1
3 4 1 2
1 2 3 4
*/

#include<iostream>
#define MAX 9
using namespace std;
int map[MAX][MAX]; bool Row[MAX][MAX]; bool Col[MAX][MAX]; bool Square[MAX][MAX];

void dfs(int Cnt){
    int cy=Cnt/9; int cx= Cnt%9;
    
    if(Cnt==81) {for(int y=0;y<9;y++){
        for(int x=0;x<9;x++){
            cout<<map[y][x]<<" ";
        }
        cout<<"\n";}
        exit(0);}
        
    if(map[cy][cx]==0){
        for(int i=1;i<10;i++){
            if(Col[cx][i]||Row[cy][i]||Square[(cy / 3) * 3 + (cx / 3)][i]) continue;
            Col[cx][i]=1;Row[cy][i]=1;Square[(cy / 3) * 3 + (cx / 3)][i]=1;
            map[cy][cx]=i;
            dfs(Cnt+1);
            Col[cx][i]=0;Row[cy][i]=0;Square[(cy / 3) * 3 + (cx / 3)][i]=0;
            map[cy][cx]=0;
        }
    }
    else dfs(Cnt+1); //이미 있는 수는 뭘 못하고 들어가지(=다른 조건 충족되는게 여러가지) !말고! 그냥 다음 친구로 넘기는 거다. 
}
 
int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    for (int y = 0; y < MAX; y++){
        for (int x = 0; x < MAX; x++){
            cin >> map[y][x];
            if (map[y][x] != 0){
                Row[y][map[y][x]] = true; //!!!그 구역에 map[y][x]=그값은 있어.  이렇게 해석 
                Col[x][map[y][x]] = true; Square[(y / 3) * 3 + (x / 3)][map[y][x]] = true;}}}
    dfs(0);
    return 0;}
