// 9019 DSLR
#include<iostream>
#include <list>
#include<queue>
#define MAX 10000
using namespace std;

char c[4] = {'D', 'S', 'L', 'R'};
pair<int, char> cal[10000]; //나를 소개해 준 친구와 그때 눌렀던 연산
int a, b;

void bfs(){
    queue<int> q;
    q.push(a);
    cal[a]={-1,' '};
    while(!q.empty()){
        int cur= q.front(); q.pop();
        int next;
        if(cur==b) break;
        for(int op=0;op<4;op++){
            //D
            if(op==0) next= (cur*2)%10000;
            //s
            else if(op==1) next= (cur==0) ? 9999:cur-1 ;
            //l
            else if(op==2) next= (cur%1000)*10+ (cur/1000);
            //r
            else next= (cur/10)+ (cur%10)*1000;
        
        //방문했던 얘는 또 할 필요가 없음
        if(cal[next].first > -2) continue; //-2로 초기화 되어있음
            
        q.push(next);
        cal[next].first= cur;//날 소개해준 친구
        cal[next].second= c[op]; //날 불러준 op
        }}}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        fill(cal, cal + 10000, make_pair(-2, ' '));
        
        bfs();
        
        int cur = b;
        list<char> ops; //연산 앞에서부터 출력하기 위해서
        while(cur!=a){
            ops.push_front(cal[cur].second);
            cur= cal[cur].first; //날 불러준친구로 cur교체 하면서 앞으로 앞으로
            
        }

        for(auto c : ops) printf("%c",c);
        printf("\n");}
}


