//백준 1746 날짜 계산
// 톱니바퀴는 잔바리(현재위치)를 빼고 톱니바퀴 수를 (크기) 나누면 모두 0일때 , 단 같이 증가한다  
#include <iostream>
using namespace std;
int E, S, M;
int calculateYear(void)
//바로 밑에 개념이 핵심인데 년도라는건 도는 톱니바퀴는 달라도 결국 떨이들 나머지가 ESM이 되는거고 year이 같은거다. +1한 정도가 같다. 
{       //Year - E = 15*x
        //Year - S = 28*y
        //Year - M = 19*z
        int result;
        int year = 1;
        while (1){
        //위의 3식을 동시에 만족하는 EMS는 1개다. 
            if ((year-E) %15==0 &&(year-S) %28==0&&(year-M) %19==0){
                  result=year;  break;}
            year++;}
    
        return result;
}

int main(void){
        cin >> E >> S >> M;
        cout << calculateYear() << endl; return 0;}
