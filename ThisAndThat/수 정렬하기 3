#include<iostream>
using namespace std;
int n,num;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
    cin>>n;
    int a[n];
    fill_n(a,n,0);
    for(int i=0;i<n;i++){
        cin>>num;
        a[num]++;
    }
    /*   0 1 2 3 4 5 6 ...
         0 0 0 1 1 0 2
     */
    
    for(int y=0;y<n;y++){
        for(int x=0;x<a[y];x++){//몇번 출력할 지 0번이면 0번 출력함.
            cout<<y<<"\n";}
        }
    
    return 0;
}
