//백준 2875 대회 or 인턴
//손으로 일일이 해보는게 상책이다 그래야 오류를 찾아낸다. 

#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    int total= n+m;
    int team= min(n/2,m); //할 수 있는 한 팀 많이 생성
    if(total-(team*3)<k){ //k가 없으면
        n=n-(team*2); m=m-team;
    
        while(n+m <k){ //근데 팀빼고 남은 인원이 K보다 작으면 경시대회 나갈얘가 없
            team--; n+=2; m++; //그래서 k생길때까지 team에서 풀어주기
        }
    }
    cout<<team<<"\n";
    return 0;
}
   
