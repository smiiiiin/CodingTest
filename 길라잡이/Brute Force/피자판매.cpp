// 백준 2632 피자판매
// <유사문제 3개>
// 1번) 2143 두배열의 합 || 2번) 1208 부분수열의 합2 || 3번) 부분합 1806
// 3번- 시작,끝 포인터랑 배열 이용해서 만들기

#include <cstdio>
int num,na,nb, a[1000], b[1000], resA[2000001], resB[2000001], ret;
 
// start,end 점 잡아서 sum더하기 빼기 하는거. 되게 비슷한 문제 있었는데
// 큐로- 이분탐색 or 누적합배열- 이분탐색 or 다른방법 찾아보기
void func(int p, int arr[], int resArr[]) {
    for (int i = 1; i <= p; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) sum += arr[j];
        resArr[sum]++; //연속이니까, 이거 계속 한거임 연속합. dfs,bfs큐
        //다 이용가능함.
        if (sum == num) ret++;
        if (i == p) break;
        for (int j = 1; j < p; j++) {
            sum -= arr[j - 1];
            sum += arr[(j + i - 1) % p];
            resArr[sum]++;
            if (sum == num) ret++;}}}
 
int main() {
    //고객이 원하는 총 사이즈, na:a피자 조각개수, nb:b피자 조각개수
    scanf("%d%d%d", &num, &na, &nb);
    for (int i = 0; i < na; i++) scanf("%d", &a[i]);
    for (int i = 0; i < nb; i++) scanf("%d", &b[i]);
 
    func(na, a, resA); func(nb, b, resB);
 
    for (int i = 1; i < num; i++) {
        int j = num - i;
        ret += resA[i] * resB[j];}
    
    printf("%d", ret);}
