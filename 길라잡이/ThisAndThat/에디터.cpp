//백준 1406
//삽입, 삭제에 용이한 linked list를 떠올렸다, 물론 vector로도 가능하다. 
/*
 #include<string> 사용할 경우
 list<string> l; //이렇게 하면 string 길게 하나 다 들어가는거다. (apple, banana, fire...like this)
 //<괄호>안에는 덩어리가 들어갈 수도 낱개가 들어갈수도 어쨋든 단위를 표시하는 곳이다.

 */


#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> l;
    list<char>::iterator cur;
    string str;
    char op, ch;
    int n;
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin>>str;
    for(int i=0;i<str.size();i++){
        l.push_back(str[i]);
    }
    cur= l.end();
    cin>>n;
    while(n--){
        cin>>op;
        
        if(op=='L'){
            if(cur!=l.begin()) cur--;
        }
        else if(op=='D'){
            if(cur!=l.end()) cur++;
        }
        else if(op=='B'){
            if(cur!=l.begin())
                //--cur; erase(cur); 하면 틀림 
                cur= l.erase(--cur);
        }
        else{//P
            cin>>ch;
            l.insert(cur,ch);
        }
    }
    
    for(list<char>::iterator cur=l.begin(); cur!=l.end();cur++){
        cout<<*cur;
    }
}

