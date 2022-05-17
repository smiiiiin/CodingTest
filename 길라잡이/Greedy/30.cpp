//백준 10610 30
//<algorithm> greater<>(), less<>()
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string str;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>str;
    sort(str.begin(),str.end(),greater<>()); //less<>()는 반대
    //큰수부터 나열 greedy 이것저것 뒤죽박죽 할 필요없다. 
    if(str[str.size()-1]!=0) cout<< -1;
    else {
        long long sum{0};
        for(auto i: str){
            sum+= i-'0'; //어차피 3의 배수는 자리수만 더하면 되니까
        }
        if(sum%3==0) cout<<str;
        else cout<<-1;
        
    }
    return 0;
}
   
