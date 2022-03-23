//백준 10809
//백준 10809
#include <iostream>
#include <string>
using namespace std;
int mid[27];
int ret[27];
string str;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
    cin>>str;
    
    fill_n(mid,26,-1);
    fill_n(ret,26,-1);
   
    for(int i=0;i<str.size();i++){
        str[i]=str[i]-97;} //str[i]는 자기 자신이자 알파벳위치 
        
   
    for(int i=0;i<str.size();i++){
        if(mid[str[i]]==-1) //0이면 이미 한번 더해져서 2번째라는 의미가 된다. 
            {ret[str[i]]=i; //i는 입력문장에서 해당문자 위치  
        }
        mid[str[i]]++;}
    
    for(int i=0;i<26;i++){
        cout<<ret[i]<<" ";
    }
    return 0;
}
