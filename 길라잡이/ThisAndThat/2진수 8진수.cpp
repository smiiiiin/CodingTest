//백준 1373
//백준 1373 1212
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector <int> v;
int main(){
    string s="";
    getline(cin,s);
    while(s.size()%3!=0){ //s의 size가 3의 배수일때 까지 s앞에 '0'붙이기
        s.insert(0,"0");
    }
    string ans="";
    for(int i=0;i<s.size();i+=3){ //크게 3개씩 돌면서 시작포인트를 3개씩 징검다리 건널건데
        int tmp=0;
        for(int j=i;j<i+3;j++){ //그때마다 그 안에서 다라락, 다라락, 살펴보기 
            tmp= tmp*2 + (s[j]-'0'); //string으로 입력받은거니까 '0'빼줘서 숫자로 만들고. 
        }
        v.push_back(tmp);
    }
   
    for(auto i:v) cout<<i;
    cout<<"\n";
    return 0;
}
