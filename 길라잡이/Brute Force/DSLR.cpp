// 9019 DSLR
#include<iostream>
#include <list>
#include<queue>
#include<cstdio>
#define MAX 10000
using namespace std;

char c[4] = {'D', 'S', 'L', 'R'};
pair<int, char> cal[10000]; //나를 소개해 준 친구와 그때 눌렀던 연산
int a, b;

void bfs(){
    queue<int> q;
    q.push(a);
    cal[a] = {-1,' '};
    while(!q.empty()){
        int cur= q.front(); q.pop();
        int n_cur;
        if(cur==b) break;
        
        for(int d=0;d<4;d++){
            if(d==0) n_cur= (cur*2) %10000;
            if(d==1) n_cur= (cur==0) ? 9999: cur-1;
            if(d==2) n_cur= (cur%1000)*10 + (cur/1000);
            if(d==3) n_cur= (cur%10)*1000 + (cur/10);
            if(cal[n_cur].first> -2) continue;
            q.push(n_cur);
            cal[n_cur].first= cur; cal[n_cur].second= c[d];}}}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        fill(cal, cal + 10000, make_pair(-2, ' '));
        
        bfs();
        
        int me = b;
        list<char> ops; //연산 앞에서부터 출력하기 위해서
        while(me!=a){
            ops.push_front(cal[me].second);
            me= cal[me].first;}
        
        for(auto c : ops) printf("%c",c);
                printf("\n");}}
