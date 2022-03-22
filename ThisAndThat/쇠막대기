//백준 10799
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    vector<char> v;
    string str;
    
    cin>>str;
    int total{0};
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            v.push_back(str[i]);
        }
        else if(str[i]==')'&& str[i-1]=='('){
            v.pop_back();
            total+=v.size();
        }
        else{v.pop_back();
            total++;
            }
        }
    
    cout<<total<<"\n";
    return 0;
}
