#include <iostream>
#include <stack>

using namespace std;

// 백준 10799: 쇠막대기
// https://www.acmicpc.net/problem/10799

int main() {
    // ilp : iron laser pattern
    string ilp; cin >> ilp;

    char prev = '\0';
    int rodCount = 0;
    stack<char> s;
    int count = 0;
    for (char il : ilp) {
        if (il == '(') s.push(il);
        else if (il == ')') {
            s.pop();
            if (prev == '(') rodCount += s.size();
            else rodCount++;
        }
        else return 1;
        prev = il;
    }

    cout << rodCount << endl;

    return 0;
}
