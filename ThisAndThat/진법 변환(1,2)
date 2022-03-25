//백준 11005 : 10->b진법 만들기 
// 97 65는 a A고 48은 0이다. 
/* 진법 특 
    1ㄴ
    1ㄴ
    0ㄴ
    2ㄴ
    
    몫이 아니라 나머지에 대해서 ... 거슬러오르면 이진법 2011(2) 이런식 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, b;
	vector<char> v;
	cin>>n>>b;
	
	while(n>0){
		int tmp=n%b;
		char c;
		if(tmp>=10&&tmp<=35) c=tmp+55; //A=65라서 
		else c=tmp+48; //0은 48이라서 
		v.push_back(c);
		n/=b;
	}
	
	reverse(v.begin(), v.end()); //뒤집기 필수 
	for(auto i:v)cout<<i;
}

 
 //백준 2745 // 1373 1212 4개가 하나의 set b진법->10진법 만들기 
//솔직히 와닿지 않은데 일단 외우자.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int sum = 0;
    cin >> s ;
    for (int i=0; i<s.size(); i++) {
              
            sum =sum* 2 + (s[i] - '0');
        cout<<sum<<" ";
    }
    cout<<"\n";
    cout << sum<<"\n";
        return 0;
}




