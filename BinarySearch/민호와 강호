// https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=221432986308&proxyReferer=https:%2F%2Fwww.google.com%2F
//백준 11662 민호와 강호: 삼분탐색
//백준 11662 민호와 강호: 삼분탐색
#include <iostream>
#include <cmath>
#define INF 0x3f3f3f
using namespace std;
int ms[2], me[2], ks[2], ke[2];

// minho_start to minho_end
pair<double, double> minho(double p){
    return {ms[1] + (me[1] - ms[1])*(p/100),
        ms[0] + (me[0] - ms[0])*(p/100)};
    }

// kangho_satrt to kangho_end
//시간이 p일때 강호의 위치
pair<double, double> kangho(double p){ //시작점+v0t 공식
    return {ks[1] + (ke[1] - ks[1])*(p/100),
    ks[0] + (ke[0] - ks[0])*(p/100)};}

int main(){
    cin >> ms[1] >> ms[0] >> me[1] >> me[0]
    >> ks[1] >> ks[0] >> ke[1] >> ke[0];
    //이번엔 시간이다. 시간이0일때 출발지에서 같이 있고 시간이 100으로
    //임의로 잡으니까 도착지에서 차이가 0이다.
    double start=0, en=100, p, q, ans=INF;

    while(start+ (1e-6) <= en){ //절대,상대오차는 10의 -6승까지 허용
        p = (2*start +en)/3;
        q = (start+ 2*en)/3;
        
        //시간이 p일때 민호의 위치
        pair<double, double> m_p = minho(p);
        pair<double, double> m_q = minho(q);
        pair<double, double> k_p = kangho(p);
        //시간이 q일때 강호의 위치
        pair<double, double> k_q = kangho(q);
        
        double p_len = pow(m_p.first-k_p.first, 2)
        + pow(m_p.second-k_p.second, 2);
        
        double q_len = pow(m_q.first-k_q.first, 2)
        + pow(m_q.second-k_q.second, 2);
        
        p_len = sqrt(p_len); // p에서 민호와 강호 사이 거리
        q_len = sqrt(q_len); // q에서 -
        
        ans = min(p_len, q_len);
        //3차 그래프 그려보면 최소값이 어딨는지 알 수있다.
        if(p_len >= q_len) start = p;
        else en = q;}
    
    cout.setf(ios::fixed); // 고정소수점 출력
    cout.precision(10); //소수점이하 10자리 출력
    cout << ans << endl;
}
