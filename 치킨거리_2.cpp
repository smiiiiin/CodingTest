//DFS, 재귀, 백트래킹(스택 or복사), 모든 노드 방문
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct POSI{
    int x,y;
};

int n, m, type, ret;
//int sum{0},mini{1000000}; 전역변수: 여기다가 하면 틀린다.
vector<POSI> home, shop, pick;


void update(){
    int sum{0}; //for문 돌아서 결과 나오기 직전에 초기화하자. 전역변수로 초기화하면 틀린다.
    for(int i=0; i<home.size();++i){
    int mini{1000000}; //for문 돌아서 결과 나오기 직전에 초기화//
        for(int j=0; j<pick.size();++j){
            mini= min(mini, abs(home[i].y-pick[j].y)+abs(home[i].x-pick[j].x));
        }
        sum+=mini;
    }
    if(ret>sum){
        ret= sum;
    }
    return;
}

void dfs(int pos){ //pos가 cur같은 느낌. 이거 스타트와 링크랑 완전 비슷한거임.
    
    if(pick.size()==m){ //dfs꽉차면 한번 해본 거니까 이제 빼자. 업데이트 하자.
        update();} //어차피 뒤에서 dfs로 또 다시 돌릴거다. 
    
    //사이즈 안찼으니 계속 넣고 dfs돌리자.
    for(int i=pos; i<shop.size(); ++i){
        pick.push_back(shop[i]);
        dfs(i+1); //여기서 사이즈 차면
        pick.pop_back();
        
    }
        
}

int main() {
    POSI target;
    cin>>n; cin>>m;
    for(int y=0;y<n;++y){
        for(int x=0;x<n;++x){
            cin>>type;
            if(type==1){
                target.y=y; //map[][]으로 너무 크니까 이렇게 저장한 듯.
                target.x=x;
                home.push_back(target);
            }
            if(type==2){
                target.y=y;
                target.x=x;
                shop.push_back(target);}}}
    
    ret= 0x7ffffff; //답은 min이니 이걸로 초기화
    dfs(0);
    cout<<ret;
    return 0;
}
