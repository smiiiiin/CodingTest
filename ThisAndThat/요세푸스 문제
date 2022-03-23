//백준 1158 요세푸스 queue로 원형queue만들기
//개쩐다..amazing and awesome idea!!

#include <iostream>
#include <queue>
using namespace std;
queue<int> q; //iterator는 vector랑 list에만 있구나.

int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    cout<<"<";
    n--;
    while(n--){
        for(int i=1;i<k;i++){ //k-1 번 동안 3번부터 죽이고 싶으면 1에서 2번움직여야하니가.
            q.push(q.front()); //앞에 있는걸 동구멍에 넣어준다.
            q.pop();//앞에 있는데는 뒤로가니까 없애주고
        }
        cout<<q.front()<<", ";
        q.pop(); //나 사망kill당함.
        
    }
    cout << q.front() << ">";
    
    
    return 0;
}
