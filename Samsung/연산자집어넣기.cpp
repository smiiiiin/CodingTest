#include <iostream>
using namespace std;
 
int n;
int number[11];
int op[4];
int ret_min = 0x7fffffff;
int ret_max = ret_min * -1;
 
void dfs(int result, int count) {
    
    if (count == n - 1) {
        if (ret_min > result) {
            ret_min = result;
        }
        if (ret_max < result) {
            ret_max = result;
        }
        return;
    }
 
    for (int i = 0; i < 4; ++i) {
        if (op[i] != 0) {
            --op[i]; //dfs중심으로 넣고 빼고  (사용했으니까 넣었으니까 연산 수 빼고)
            if (i == 0) {
                dfs(result + number[count + 1], count + 1);
            }
            else if (i == 1) {
                dfs(result - number[count + 1], count + 1);
            }
            else if (i == 2) {
                dfs(result * number[count + 1], count + 1);
            }
            else if (i == 3) {
                dfs(result / number[count + 1], count + 1);
            }
            ++op[i];
        }
    }
}
 
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>number[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin>>op[i];
    }
 
    dfs(number[0], 0);
 
    cout<<ret_max<<endl;
    cout<<ret_min;
    return 0;
}
