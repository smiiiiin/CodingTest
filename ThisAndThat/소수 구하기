//백준 1929

#include<iostream>
#include<vector>
using namespace std;
long long arr[100];
long long a,b;
vector<long long> v;

int main(){
    cin>>a>>b;
    for(long long i=a;i<=b;i++){
        arr[i]=i;
    }
    for(long long i=a;i<=b;i++){
        for(int j=2;j<arr[i];j++){
            if(arr[i]==1||arr[i]%j==0) arr[i]=-1;
        }
        if(arr[i]==1) arr[i]=-1;
        if(arr[i]!=-1) v.push_back(arr[i]);
    }
    for(auto i:v) cout<<i<<"\n";
    //53이면 자기자신까지의 수로 나눠보고 안나눠지면 출력
    return 0;
}
