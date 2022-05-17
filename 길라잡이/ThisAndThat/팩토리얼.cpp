//백준 10872 팩토리얼 //반복 시간복잡도 o(n) 공간복잡도o(1) 저장되는 변수 2개 
#include<iostream>
using namespace std;

int n; 
long long ret{1}; //초기화 중요하다. 
int main(){
    cin>>n;
    for(int i=n;i>=1;i--){
        ret*=i;
    }
    cout<<ret<<"\n";
}

//백준 10872 팩토리얼 //재귀 보기에 편하다. o(n^) 의 시간복잡도 
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int fac(int n){
    if(n==1||n==0) return 1;
    else return fac(n-1)*n;
}
int n;

int main(){
    cin>>n;
    cout<<fac(n);
}
