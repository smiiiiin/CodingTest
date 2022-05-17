//백준 2110 공유기 설치
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 200000;
int n, c; int arr[MAX];

bool possible(int dist){
    //cnt가 1인 이유: 처음에 공유기를 설치하고 시작하니깐. 사이의 거리와 공유기 
    int cnt{1}, cur; cur=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-cur>=dist) {cnt++; cur=arr[i];}}
    if(cnt>=c) return true;
    return false;}

int main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int start{1}, result{0}; int en= arr[n-1]-arr[0];
    
    while(start<=en){
        int mid=(start+en)/2;
        if(possible(mid)) {result=mid; start=mid+1;}
        else en=mid-1;}
    
    cout << result << "\n";
    return 0;}
