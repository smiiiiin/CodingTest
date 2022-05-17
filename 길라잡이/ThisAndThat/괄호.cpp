//백준 9012
#include <iostream>
#include<stack>
#include<string>

using namespace std;
int t,k,a;
string str;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin>>t;
    while(t--){
        stack<char> v;
        cin>>str;
        bool flag=1;
        for(int i=0;i<str.size();i++){
            
            if(str[i]=='(') v.push(str[i]);
            
            else if(str[i]==')'){
                if(v.empty()){flag=0;}
                else
                {v.pop();}
            }
        }
        if(!v.empty() || !flag)
            {cout<<"NO"<<"\n";}
        else {cout<<"YES"<<"\n";}
    }
    return 0;
}
