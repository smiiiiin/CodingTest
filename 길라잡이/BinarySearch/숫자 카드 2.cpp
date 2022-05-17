//백준 10816 숫자 카드 2
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, num, q;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {cin>>v[i];} //(1) push_back(num);이렇게 해도 안되고
    sort(v.begin(),v.end());
    cin>>m;
    for(int j=0;j<m;j++) {
        cin>>q;
        /*
        //(2) int high, int low이렇게 해도 안된다.
        // 위치(포인터)를 리턴하기때문에 auto라고 적어줘야한다.
        auto high= upper_bound( v.begin(), v.end(), q);
        auto low= lower_bound( v.begin(), v.end(), q);
        */
        
        //(2) int high, int low이렇게 해도 안된다.
        // 위치(포인터)를 리턴하기때문에 auto라고 적어줘야한다.
        int high= upper_bound( v.begin(), v.end(), q)-v.begin() ;
        int low= lower_bound( v.begin(), v.end(), q)-v.begin() ;
        
        
        cout<<high-low<<" ";}
    return 0;}

    
    /*
    좌표압축 문제랑 다른 이유. 3번째 매개변수인 num이 int형이고 좌표압축은 vector클래스이기 때문에 vector에서는 -vec.begin()을 써줘야한다.
    */
