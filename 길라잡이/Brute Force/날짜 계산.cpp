//백준 1746 날짜 계산
//답
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
            if ((year - E) % 15 == 0 && (year - S) % 28 == 0
                && (year - M) % 19 == 0){
                    result = year;
                    break;}
            year++;}
    
        return result;
}

int main(void){
        cin >> E >> S >> M;
        cout << calculateYear() << endl; return 0;}



// 내 시간초과 답
#include <iostream>
int E,S,M;
int year{0};
int y{0};
int m{0};
int d{0};

using namespace std;

int main(){
    scanf("%d %d %d",&E,&S,&M);
    while(1){
        y=(y+1)%15;
        m=(m+1)%28;
        d=(d+1)%19;
        year++;
        if(y==E && m==S && d==M) break;
    }
    printf("%d \n", year);
    
    
    return 0;
}

