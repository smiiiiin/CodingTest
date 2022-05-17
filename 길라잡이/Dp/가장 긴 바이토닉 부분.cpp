//백준 11054 가장 긴 바이토닉 부분 수열
#include<iostream>
#include<algorithm> //max, fill
#define MAX 1001
using namespace std;

int main(){
    int n; cin>>n; int arr[MAX]; int dp_in[MAX]; int dp_de[MAX];
    for(int i=1;i<=n;i++) cin>> arr[i];
    fill(dp_in+1, dp_in+n+1,1); fill(dp_de+1, dp_de+n+1,1);
    //증가하는 번호를 매긴다
    for(int cock=2;cock<=n;cock++){
        for(int j=1;j<cock;j++){
            if(arr[j]<arr[cock]) dp_in[cock]=max(dp_in[cock], dp_in[j]+1);}}
    
    //감소하는 번호를 매긴다
    for(int cock=n-1;cock>0;cock--){
        for(int j=n;j>cock;j--){
            if(arr[j]<arr[cock]) dp_de[cock]=max(dp_de[cock], dp_de[j]+1);}}
    int res{0};
    for(int i=1;i<=n;i++)
         res= max(res, dp_in[i]+dp_de[i]);
    cout<<res-1<<"\n"; return 0;}
/*
 arr 1 5 2 1 4 3 4 5 2 1  증가번호
 dp  1 2 2 1 3 3 3 4 2 1
 
 arr 1 2 5 4 3 4 1 2 5 1  감소번호
 dp  1 2 3 3 3 4 1 2 5 1
 */
