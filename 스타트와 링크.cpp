//DFS, 재귀, 백트래킹, (스택! or 복사), 모든노드, visited(큐도 마찬가지)
#include <iostream>
#include <vector> //이거 치킨거리처럼 해보기
#include <algorithm>

using namespace std;
struct POSI{
    int y,x;
};
vector <POSI> pick, person, candi;
POSI target;

int type;
int n, ret;

void update(){ //이 함수가 호출됐다는거= 지금 딱 찼다는 거 이때 값을 구해놓아야한다(중요)
    int pick_size{0}, team2_size{0};
    for(int i=0; i<n; ++i){
        if(person[i]==1){ //1번으로 들어오면 인덱스 그 해당 사람이 들어온다.
            pick[pick_size++]= i;
        }
        else
            team2[team2_size++]= i;
    }//
    
    int sum_1=0; int sum_2=0;
    for(int i=0;i<n/2;++i){ //team1의 0,1,2인덱스에 1,2,7사원이 있으면 1,2의 조합 + 1,7의
     //조합 다하면 2,7의 조합을 보기 때문에 이중for문이 필수다.
            for(int j=i+1;j<n/2;++j){
                sum_1+=pan[team1[i]][team1[j]]+pan[team1[j]][team1[i]];
                sum_2+=pan[team2[i]][team2[j]]+pan[team2[j]][team2[i]];
            }
        }
   
    if(ret> abs(sum_1-sum_2)){
        ret=abs(sum_1-sum_2);
    }}
    
   


void dfs(int cur, int pick_count){ //치킨거리에서 pick_count를 변수로 안넣은 방법
    //변수가 왜 cur과 pick_count 2개인지?
    if(pick_count==n/2){
        update(); //
        return;
    }
    for(int i=cur;i<n;++i){ //이부분 못 떠올림. //cur부터인지 왜
        person[i]=1; //채우고
        dfs (i+1, pick_count+1); //i+1이 아니라 pick_count+1; ??
        person[i]=0; //비우고
        
    }
}

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
