//백준 1212 8진수 2진수 
// 백준 1212 8진수 2진수 시간제한 1초는 시간이 핵심 8->2진수로 바로가야한다
// 백준 11576 Base Conversion a진법->b진법 2초짜리다
// 조건: 입력값이 0일때는 0 출력값은 1부터 시작해야 한다
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string num; stack<int>res;

int main() {
    bool pass=1;
    cin >> num;
    if (num == "0") {
        pass=0;
        cout << 0 << endl;
        } //main 함수 밖에 있으면서 return;을 해야지만 시간초과가 안된다 왜일까?
    //여기서 return;의 의미는 하던것을 중단하고 main으로 간다는 의미다
    if(pass){
    int sz = num.size();
    for (int i = sz - 1; i >= 0; i--) {
        int cur = num[i] - '0';
        for (int j = 0; j < 3; j++) {
            int num = cur % 2;
            cur = cur / 2;
            res.push(num);
        }}
    
    //반드시 1로 시작해야 하므로 가장 먼저 오는 1을 찾음
    while (res.top() != 1) res.pop();
    
    while (!res.empty()) {
        cout << res.top();
        res.pop();}
        cout << endl;}
    return 0;}




//내가 작성해본 건데 왜 돌아가지 않을까?
// 백준 1212 8진수 2진수 시간제한 1초는 시간이 핵심 8->2진수로 바로가야한다
// 백준 11576 Base Conversion a진법->b진법 2초짜리다
// 314 앞에서 들어오는 순서부터 3을 2진수로 1을 2진수로 4를 2진수로
// 3개씩 끊어서 vector에 넣어뒀다가 앞에서부터 auto로 꺼낸다

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string to_two(int n){
    string ans="";
    vector<int> v;
    while(n){
        int c= n%2;
        v.push_back(c);
        n/=2;
    }
    reverse(v.begin(),v.end());
    for(auto i:v) {ans+=i;}
    return ans;}

int main()
{
    //8진수 입력받기
    string str=""; getline(cin,str);
    vector<string> res;
    for (int i = 0; i < str.length(); i++){
        int cur_n=str[i]-'0';
        res.push_back(to_two(cur_n));}
    
    for(auto i: res) cout<<i;
    cout<<"\n";
    
    
    return 0;}
