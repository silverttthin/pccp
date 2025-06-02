#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, t;
    cin >> n;
    stack<int> S;
    int cnt = 1;
    string ans;
    while (n--) {
        cin >> t;
        // 현재 cnt가 입력값보다 작거나 같으면 스택에 push
        while (cnt <= t) { 
        S.push(cnt++);
        ans += "+\n";
        }

        // top이 t랑 다르면 무조건 틀린 수열
        if (S.top() != t) { 
        cout << "NO\n";
        return 0;
        }

        S.pop();
        ans += "-\n";
    }
    cout << ans;
}
