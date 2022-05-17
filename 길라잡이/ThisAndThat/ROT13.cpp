//백준 11655
#include <iostream>
#include <string>
using namespace std;
char ROT13(char c) {
    if('A' <= c && c <= 'Z') return (char)((c-'A'+13)%26+'A');
    
    if('a' <= c && c <= 'z') return (char)((c-'a'+13)%26+'a');
    
    return c;
}
int main() {
    string s;
    getline(cin , s);
    for(char c : s) cout << ROT13(c);
    return 0;
}
