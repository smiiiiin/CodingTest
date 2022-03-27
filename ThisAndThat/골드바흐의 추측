//백준 6588 골드바흐의 추측
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int a,b;
    bool suc{false};
    int input{1};
    while(input){
        cin>>input;
        for(int j=1; j<input/2 ;j++){ //0부터하면 왜?
            a= j*2+1;
            b=input-a;
            if(isPrime(a)&& isPrime(b)){
                cout<<input<<" = "<<a<<" + "<<b<<"\n";
                suc=true;
                break;
            }
        }
        if(!suc){ cout << "Goldbach's conjecture is wrong\n"; break;}
    }
}
