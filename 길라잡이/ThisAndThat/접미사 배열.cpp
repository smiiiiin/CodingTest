//백준 11656
//substr(시작인덱스, 길이) ; 이게 핵심
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string str;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    cin>>str;
    for(int i=0;i<str.size();i++){
        v.push_back(str.substr(i, str.size())); //substr(시작인덱스, 문자길이 )
    }
    sort(v.begin(),v.end());
    
    for(int i= 0;i<v.size() ;i++){
        cout<< v[i]<<'\n';
        
    }
    return 0;
}
