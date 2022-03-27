//백준 1676 
// 수를 소인수분해 해서 5의 개수를 구한다. 5는 2랑 짝, 15는 12랑 짝이되서 0을 만드는데 중간에 2만 있으면 의미 없으니까 5를 기준으로 센다. 
// 밑에 알고리즘은 그 수가 5로 나눠지는지 확인 후, 나눠지면 개수를 더하는 방식 

#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    
    int n;
    cin >> n;
    
    for (int i=5; i<=n; i*=5)
        ans += n/i;
        
    cout << ans << '\n';
}


// 오답> 팩토리얼 0의 개수 //뒤에서 부터 0의 개수
//string으로 안되는 이유는 시간초과인것 같다. 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
unsigned long long ret{1};
int main(){
    cin>>n;
    for(int i=n;i>=1;i--){
        ret*=i;
    }
    int num{0};
    cout<<"ret: "<<ret<<"\n";
    string str= to_string(ret);
    unsigned long long sz=str.size();
    cout<<"sz: "<<sz<<"\n";
    
    for(int i=sz-1;i>=0;i--){
        while(1){
            if(str[i]=='0'){
                num++;}
            else break;
        }
    }
    cout<<"num: "<<num<<"\n";

}
