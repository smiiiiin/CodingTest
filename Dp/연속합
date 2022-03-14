//백준 1912
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n],dp[n]={0,};
	for(int&i:arr)cin>>i;
	dp[0]=arr[0];
	for(int i=1;i<n;i++)
	dp[i]=max(0,dp[i-1])+arr[i];
	cout<<*max_element(dp,dp+n);
}
