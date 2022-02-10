//DFS, 재귀, 백트래킹, (스택 or 복사), 모든노드, visited(큐도 마찬가지)
#include <iostream>
#include <algorithm>
using namespace std;

int pan[20][20];
int team1[10]; //1에 들어온 사람들(=사람들이름=인덱스번호) //넣어보고 빼보고를 1에서 한다고 해봐.
int team2[10];
int pick[20]; //사원별로 pick의 bool상태
int n, ret;

void update(){
    int team1_size{0}, team2_size{0};
    for(int i=0; i<n; ++i){
        if(pick[i]==1){ //1번으로 들어오면 인덱스 그 해당 사람이 들어온다.
            team1[team1_size++]= i;
        }
        else
            team2[team2_size++]= i;
    }//
    
    int sum_1=0; int sum_2=0;
    for(int i=0;i<n/2;++i){
        for(int j=i+1;j<n/2;++j){
            sum_1+=pan[team1[i]][team1[j]]+pan[team1[j]][team1[i]];
            sum_2+=pan[team2[i]][team2[j]]+pan[team2[j]][team2[i]];
        }
    }
    if(ret> abs(sum_1-sum_2)){
        ret=abs(sum_1-sum_2);
    }
    
   
}

void dfs(int cur, int pick_count){ //치킨거리에서 pick_count를 변수로 안넣은 방법
    if(pick_count==n/2){
        update(); //
        return;
    }
    for(int i=cur;i<n;++i){ //이부분 못 떠올림.
        pick[i]=1;
        dfs (i+1, pick_count+1); //i+1이 아니라 pick_count+1;
        pick[i]=0;}
}
//0부터 4까지
//pick[0], [1]에 각각1표시 즉, 1에 들어간다.
//dfs(2)= update()하고 pick[2]=1 dfs(3,3) pick[3]=1 , pick[3]=0;

int main() {
    cin>>n;
    for(int y=0;y<n;++y){
        for(int x=0;x<n;++x){
            cin>>pan[y][x];
        }
    }
    
    ret= 0x7ffffff;
    dfs(0,0);
    cout<<ret;
    return 0;
}
