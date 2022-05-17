//Kakao Coding Test
/*
문제> input: aabbaccc 2a2ba3c 이길이는 7 그래서 output: 7
abcabcdede 는 전혀 압축되지 않는다 s의 길이는 1000이하이고 소문자로만 이루어져있다
// 아래와 같이 주어진다
#include<iostream>
#include <vector>
using namespace std;

int solution(string s){
int answer;
return answer;}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s){
  int answer=s.length();
  for(int i=1;i<=s.length()/2;++i){
    int pos=0; int len = s.length();
    for( ;;){
      string unit = s.substr(pos,i);
      pos+=i;
      if(pos>=s.length()) break;
      int cnt= 0;
      for(;;) {
      if(unit.compare(s.substr(pos,i))==0){
        cnt++;
        pos+=i;}
        else {break; }}
        
        if(cnt>0){len-= i*cnt;
          if(cnt<9) len+=1;
          else if(cnt<99) len+=2;
          else if(cnt<999) len+=3;
          else len+=4;
        
        }
        }
        answer= min(answer, len); }
return answer;}



