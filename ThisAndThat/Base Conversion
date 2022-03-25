//백준 11576 a진법->b진법
#include <bits/stdc++.h> //를 사용하면 reverse()를 저기서 사용해도 된단다.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve()
{
    int a, b; cin >> a >> b;
    int n; cin >> n;
    int num = 0;
    int k = n - 1; //앞에서부터 더해줄거 생각하면
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        num += x * pow(a, k);
        k--;
    }
    
    vector<int> ans;
    while (num)
    {
        int tmp = num % b;
        
        ans.push_back(tmp);
        num /= b;
    }
    reverse(ans.begin(), ans.end());
    for (auto u : ans)
    {
        cout << u << " ";
    }cout << "\n";
}
int main()
{
    solve();
    return 0;
}
