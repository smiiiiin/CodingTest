//백준 1212 8진수 2진수 




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
