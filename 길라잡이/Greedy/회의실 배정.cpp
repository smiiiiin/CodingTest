// 백준 1931 회의실 배정
// 작은 단위부터 시작해서 경우의 수를 나눠야 한다.
// 이 문제는 끝나는 시간을 기준으로 세워야한다. 왜 시작시간부터 하면 안돼?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//comp함수는 종료시간이 이르고 (시작시간도짧아서 점유시간이 짧게) 그거 순으로
//먼저 순서를 나열한다.
bool comp(pair<int, int>& f,pair<int, int>& s ){ //&참조 하지마?
    if(f.second==s.second) return f.first<s.first;
    return f.second<s.second;}

int main() {
    int n;
    cin >> n;
    //arr[n]하면 푹푹 꺼지는 거다. 배열마다
    vector<pair<int, int>> arr;
    int a,b;
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&a,&b);
        arr.push_back({a,b});}
    
    sort(arr.begin(), arr.end(), comp); //종료시간이 빠른것부터,
    int flag = arr[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++) {//배열0부터 돌아보면서
        if (flag <= arr[i].first) { //시작시간이 기준의 끝시간보다 뒤면
            flag = arr[i].second; // 그것의 종료시간이 이젠 기준
            ans++;
        }
    }
    printf("%d\n", ans);
}
