//백준 11399 ATM
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
vector <int> v;
bool les(int f,int s){
    return f>s;
}
int main() {
    int n;
    scanf("%d",&n);
    int a;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        v.push_back(a);
    }
    int res{0};
    sort(v.begin(),v.end(),les);//오름차순으로 정렬 //역으로 하고 4 3 3 2 1
    
    for(int i=0;i<n;i++){
        res+= (v[i]*(i+1));
    }
        
    cout<<res<<"\n";
    return 0;
}

