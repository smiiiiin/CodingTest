//백준 1212 8진수 2진수 
/*
 72-> 56+2= 58 111/0(이건 나와야해)10
 36-> 24+6= 30 0(이건나오면 안돼) 11/110
 나중에 다시 돌아오자. 시간 너무 많이 썼다. 거의 1.5시간
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector <long long> v;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
    string s="";
    getline(cin,s);
    
    for(long long i=s.size()-1;i>=0;i--){
        s[i]-='0';
        while(s[i]>0){
        int tmp=s[i] %2;
            s[i]/=2;
        v.push_back(tmp);
        }
        
    }
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i;
    cout<<"\n";
    return 0;
}


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
