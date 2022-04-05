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
