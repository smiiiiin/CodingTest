//백준 1654 랜선자르기
#include<iostream>
using namespace std;
int k, n, ans; int arr[10001];
int  maxi = 0; long long mid, en, start;

int main(){
    cin >> k >> n;
    for (int i = 0; i < k; i++){
        cin >> arr[i];
        if (maxi < arr[i]) maxi = arr[i];}
    start = 1; //0으로는 나눌 수 없다.
    en = maxi;
    ans = 0;
    while(start<=en){
    mid= (start+en)/2;
    int cnt{0};
        for(int i=0;i<k;i++) cnt+=arr[i]/mid;
        if(cnt>=n) {start=mid+1; ans= mid;}
        else en=mid-1;}
    cout << ans;}
