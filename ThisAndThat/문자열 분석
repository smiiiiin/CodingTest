//백준 10820
//모든 변수는 사용하기 한칸 밖에 넣는다. 너무 밖에 넣지 말아라!!!
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    string str;
   // int a{0},b{0},c{0},d{0}; //여기다놓으면틀린다. 
        
    while(getline(cin, str)){
        int a{0},b{0},c{0},d{0}; //이거 while문 밖에 있으면 틀린다. 사용하기 한칸 밖에 넣기 
        //필수 
        for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z'){
            a++;
        }
        else if(str[i]>='A'&&str[i]<='Z'){
            b++;
        }
        else if(str[i]>='0'&&str[i]<='9'){
            c++;
        }
        else if(str[i]==' '){
            d++;
        }
        
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
        
    }
    
    
    return 0;
}
