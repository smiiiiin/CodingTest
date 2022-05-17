//백준 10815 숫자 카드
// 기본맛 BinarySearch
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int m; cin >> m; 
    for (int i = 0; i < m; i++){
        int num; cin>>num;
        bool is=0; int start=0; int en=n-1;
        while(start<=en){
            int mid=(start+en)/2;
            if(num>v[mid])start=mid+1;
            else if(num<v[mid]) en=mid-1;
            else {is=1; break;} //break 안하면 시간초과 
        }
        if (is) cout << 1 << " ";
        else cout << 0 << " ";} return 0;}
