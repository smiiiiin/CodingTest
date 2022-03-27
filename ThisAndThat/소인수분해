//백준 11653 소인수분해
// 순서대로 나누면 i는 당연히 소수가 된다. 4로 나뉘는 얘는 그 전에 2로 나뉘었을것이 뻔하니깐.  이걸로 n부터 m까지 소수구하기도 가능했을듯. 

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
long long n;
vector<int> v;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n;
    if(n==1) return 0;
    
    for(int i=2;i<=n;i++){ //왜n까지 나눠야하지? 3인경우
        while(n%i==0){ //i는 당연히 소수가 된다. 4로 나뉘는 얘는 그 전에
            //2로 나뉘었을것이 뻔하니깐. 
            n/=i;
            cout<<i<<"\n";
        }
    }
    return 0;
}
