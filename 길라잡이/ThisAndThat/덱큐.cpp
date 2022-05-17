//백준 10866
//출력사항 형식도 중요하다. cout이 없는데 cout<<"\n"<<endl; 하게되면 괜히 띄어쓰기 한다. 

#include <iostream>
#include <queue>
#include <deque>
#include <string>

using namespace std;
deque<int> dq;
string op;
int n;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="push_front"){
            int e;
            cin>>e;
            dq.push_front(e);}
        else if(op=="push_back"){
            int e; //어차피 새롭게 위에 덮어쓰는 거 아님?
            cin>>e;
            dq.push_back(e);
            
        }
        else if(op=="pop_front"){
            if(dq.empty()) cout<<-1<<"\n";
            else {cout<<dq.front(); cout<<"\n";
                dq.pop_front();}}
            
        else if(op =="pop_back"){
            if(dq.empty()) cout<<-1<<"\n";
            else {cout<<dq.back(); cout<<"\n";
                dq.pop_back();}}
        
        else if(op=="size"){
            cout<< dq.size()<<"\n";
        }
        else if(op=="empty"){
            if(dq.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(op=="front"){
            if(dq.empty()) cout<<-1<<"\n";
            else {cout<<dq.front(); cout<<"\n";}
        }
        else if(op=="back"){
            if(dq.empty()) cout<<-1<<"\n";
            else {cout<<dq.back(); cout<<"\n";}
        }
        
    }return 0;
}
