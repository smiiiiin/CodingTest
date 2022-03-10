//백준 2225
//인덱스 범위 초기화를 잘하자:) 

#include <iostream>
#include <vector>
#include <algorithm>
int n,k;
int map[201][201];
using namespace std;
int main()
{
    cin>>n>>k;
    
    for(int i=0;i<=n;i++) {map[i][0]=0; map[i][1]=1; }
     for(int x=2;x<=k;x++){
        for(int y=0;y<=n;y++){
            for(int j=0;j<=y;j++){
                map[y][x]= (map[y][x]+ map[j][x-1])%1000000000;}}}
     
     cout<<map[n][k];

}

/*합이 n이 되는데 정수k개를 더한다.
20 1 20 1개
20 2 (0,20) (1,19) (2,18) ... (19,1) (20,0) 21개
20 3 (0,20의 dp[2]) (1, 19의 dp[2]) (2, 18의 dp[2])...
 (18, 2의 dp[2]) (19, 1의 dp[2]) (20, 0의 dp[2])
      21+20+19+...+3+2+1
 20 4 (0, 20의 dp[3]) (1, 19의 dp[3]), (2, 18의 dp[3]), ... (20, 0의 dp[3])
 map[n][1]=1;
 map[n][2]= n+1; map[n][1]+=n; // for(int i=0;i<=n;i++){+=map[i][1];}
 map[n][3]= i=0;i<=n;i++ +=map[i][2];*/
 
