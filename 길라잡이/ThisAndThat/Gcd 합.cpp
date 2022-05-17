//백준 9613

#include <iostream>
using namespace std;
#define ll long long 
ll a,b;

ll gcd(ll a, ll b){
    ll c= a%b; //굳이 뭐가 작고큰지 할필요 없는게 알아서 자동으로 됨. 계산해봐. 
    
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}


int main()
{
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(false);
    int t,n;
    int arr[100];
    
    cin>>t;
    while(t--){
        cin>>n;
        fill_n(arr,n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    
        ll sum{0};
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                sum+=gcd(arr[i],arr[j]);
            
            }
            
        }
        cout<<sum<<"\n";
    }
    return 0;
}



