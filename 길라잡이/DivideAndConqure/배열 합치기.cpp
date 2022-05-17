// 백준 11728 배열 합치기
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,i,arr[2000001];
int main(void)
{
	scanf("%d%d",&n,&m);
	for(i=0; i<n+m; i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n+m);
	for(i=0; i<n+m; i++)
		printf("%d ",arr[i]);
	return 0;
}
