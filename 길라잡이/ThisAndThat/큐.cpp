//백준 10845
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
    int n; cin>>n;
    queue<int> q;
    while (n--) {
        string op; cin>>op;
        int a{0};
        if (op == "push") {
            cin>>a;
            q.push(a);
        }
        
        else if (op == "pop") {
            if(q.empty()) cout<<-1<<"\n";
            else {cout<< q.front()<<"\n"; q.pop();}
        }
        
        else if (op == "size") {
            cout<<q.size()<<"\n";
        }
        
        else if (op == "empty") {
            if(q.empty())cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        
        else if (op == "front") {
            if(q.empty()) {cout<<-1<<"\n";}
            else {cout<<q.front()<<"\n";}
        }
        
        else {
            if(q.empty()) {cout<<-1<<"\n";}
            else {cout<<q.back()<<"\n";}
        }
    }
    return 0;
}
