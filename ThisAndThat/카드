//백준 11652
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int n;
    int max{1};
    long long ans{0};
    long long arr[100001];
    int cnt = 1;
    
    cin >> n;
 
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    sort(arr+1, arr + n+1); //1111 2 33 44444444 여기서 답은 4가된다.
    ans=arr[1]; // 초기화 안하면 틀림...왜 ? 지? 
    for(int i = 2; i <= n; i++){
        if(arr[i] == arr[i-1])
            cnt++;
        else
            cnt = 1;
        
        if(max < cnt){
            max = cnt;
            ans = arr[i];
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
