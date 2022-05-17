//백준 2751
//2751 수 정렬하기2 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    int n,a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    
    for(int i=0;i<n;i++){
        cout<<v[i]<<"\n";}
       
}

