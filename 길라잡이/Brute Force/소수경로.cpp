// 백준 1963 소수경로
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#define MAX 10000
using namespace std;
bool prime[MAX]; bool Visit[MAX]; int Start, End;
 
void Initialize(){

    memset(prime, 1, sizeof(prime));
        for(int i=2;i< MAX;i++){
            for(int j=i;j*i<MAX;j++){
                prime[i*j]=0;
            }
        }
    
    memset(Visit, 0, sizeof(Visit));    
    }
int cnt{0};
void Solution(){
    queue<pair<int,int>> q;
    q.push({Start,0});
    Visit[Start]=1;
    
    while(!q.empty()){
        int cur= q.front().first; cnt= q.front().second; q.pop();
        if(cur==End ){
        cout<<cnt<<"\n"; return;}
        
        for(int i=0;i<4;i++){
            for(int j=0;j<10;j++){
                string s= to_string(cur);
                s[i] =j+'0';
                int next= stoi(s);
                
                if(!prime[next]|| Visit[next]|| next>9999 || next<1000) continue;
                q.push({next,cnt+1}); Visit[next]=1;
            }
        }
    }
    
cout<<"Impossible"<<"\n";
    
}
    

 
int main(void)
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    for (int T = 1; T <= t; T++){
        Initialize(); //test여러번 하기 위한 초기화 
        cin >> Start >> End;
        Solution();}
    return 0;
}
