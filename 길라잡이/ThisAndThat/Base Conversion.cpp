// 백준 11576 Base Conversion a진법->b진법
// 10진수를 이용: a->10진수는 a자리 수에 맞게 곱한다, ->b진수로 b로 나눈다
//를 사용하면 reverse()를 저기서 사용해도 된단다.
#include <iostream> //를 사용하면 reverse()를 저기서 사용해도 된단다.
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    int n; cin >> n; //자리 수
    int num_ten = 0; //10진수 num
    /* a진수-> 10진수
     n이 3이고
     17진법 1 2 16 이면
     1*(17의 2승)+ 2*(17의 1승) + 16*(17의 0승) 이므로
     */
    int k = n - 1;
    for (int i = 0; i < n; i++){
        int x; cin >> x; // 수를 입력한다
        num_ten += x * pow(a, k); //a의 k승
        k--;}
    
    
    /*10진수 -> b진수 :b진수로 가면 b로 가눈다 10진수로 가면 곱한다
     방법: 10진수를 b로 나눠서 나머지를 위로 거슬러 올라가기 !
     */
    vector<int> ans;
    while (num_ten){ //num_ten!=0
        int tmp = num_ten % b;
        ans.push_back(tmp);
        num_ten /= b;
    }
    reverse(ans.begin(), ans.end()); //거슬러 올라가니까
    for (auto u : ans) cout << u << " ";
    cout << "\n";
    return 0;}
