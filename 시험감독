//백준 13458
#include <iostream>
using namespace std;

int main() {
    
    int n,b,c;
    int arr[1000000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>b; cin>>c;
    long long master{0}, sub{0};
    long long result;
    
    for(int j=0;j<n;j++){
        arr[j]-=b;
        master++;
        if(arr[j]>0){
            sub+=arr[j]/c;
            if(arr[j]%c!=0){
                sub++;
            }
        }
    }
    result= master+sub;
    cout<<result;
    return 0;
}
