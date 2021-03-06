//백준 2004 
//int 2^32-1, long long 2^64-1  

#include <iostream>

using namespace std;

int powerof(int x, int n)
{
    int c = 0;
    while (x >= n)
    {
        x /= n;
        c += x;
    }

    return c;
}

int main()
{
    int n, m;

    cin >> n >> m;

    int count2 = powerof(n, 2) - powerof(n - m, 2) - powerof(m, 2);
    int count5 = powerof(n, 5) - powerof(n - m, 5) - powerof(m, 5);

    cout << (count2 < count5 ? count2 : count5) << endl;
    return 0;
}












//오답: 백준 2004
//이렇게 하면 메모리 초과가 뜬다.  순열구하고 여기서 /5이용해서 0구하기
//다른방법이 필요하다.

#include <iostream>
//nCm의 끝자리 0의 개수 출력하기
// (n)
// (m)  이 행렬의 의미가 엔씨엠 조합이다!!

using namespace std;
int a,b;
long long n{0};

int combination(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
    long long ans = 0;
    cin >> a>>b;;
    n= combination(a,b);
    
    while(n%5==0){
        n/=5;
        ans++;
    }
        
    cout << ans << '\n';
}
