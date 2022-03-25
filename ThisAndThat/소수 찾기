//백준 1978

#include<iostream>
#include<vector>
using namespace std;
int arr[100];
int n;
vector<int> v;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=2;j<arr[i];j++){
            if(arr[i]==1||arr[i]%j==0) arr[i]=-1;
        }
        if(arr[i]==1) arr[i]=-1;
        if(arr[i]!=-1) v.push_back(arr[i]);
    }
    
    cout<<v.size()<<"\n";
    //53이면 자기자신까지의 수로 나눠보고 안나눠지면 출력
    return 0;
}
