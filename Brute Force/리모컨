//백준 1107 리모컨
//백준 1107 리모컨
#include <string> //to_string(n) n->string으로
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<bool> broken(10,false);

bool click(int now){
    string s = to_string(now);
    for(int i = 0; i <s.length();i++){
        if(broken[s[i]-'0']) {return false;}} //하나라도 버튼이 고장난 수이면 안됨.
        return true;}

int main(){
    int destination,n;    scanf("%d %d",&destination,&n);
    int b;
    for(int i = 0; i < n; i++){
        scanf("%d",&b);
        broken[b] = true;}
    string st = to_string(destination);
    int minimum = abs(destination-100); //최대로 잡아놓되, +로 계속 가는 걸로 잡아놈.
    for(int i = 0; i <= 1000000; i++){
        if(click(i)){
            int tmp = abs(destination-i)+to_string(i).length(); //채널과의
            //차이+ 버튼을 누른 수 (bool click()에서 하나라도 버튼이 고장난 수가 아니니깐) 
            minimum = min(minimum,tmp);        }    }
    
    printf("%d \n",minimum);
    return 0;
}
