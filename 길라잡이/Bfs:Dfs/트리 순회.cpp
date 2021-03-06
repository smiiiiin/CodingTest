//백준 1991 트리 순회
#include <iostream>
#include <utility>

#define MOD 1000003
using namespace std;
#define ll long long
using pll = pair<ll, ll>;

ll n;
char x, y, z;

struct NODE {
    char left;
    char right;
};

NODE node[26];

void pre(char now) {
    if (now == '.') return;
    cout << now;
    pre(node[now - 'A'].left);
    pre(node[now - 'A'].right);
}

void in(char now) {
    if (now == '.') return; 
    in(node[now - 'A'].left);
    cout << now;
    in(node[now - 'A'].right);
}

void post(char now) {
    if (now == '.') return;
    post(node[now - 'A'].left);
    post(node[now - 'A'].right);
    cout << now;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
   cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x >> y >> z;
        node[x - 'A'].left = y;
        node[x - 'A'].right = z;
    }
    pre('A');
    cout << "\n";
    in('A');
    cout << "\n";
    post('A');
    cout << "\n"; 
}
