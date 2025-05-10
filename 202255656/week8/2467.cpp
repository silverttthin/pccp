#include <iostream>
#include <vector>
#include <climits>

#define ll long long

// 백준 2467 용액 (투 포인터)
// https://www.acmicpc.net/problem/2467

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;

    // living tip : 솔루션은 화학에서 용액이라는 뜻으로 쓰인다.
    vector<ll> solution (N);

    for (int i = 0; i < N; i++) cin >> solution[i];

    int l = 0, r = N - 1;
    ll lv, rv;
    ll ms = LONG_LONG_MAX;
    while (l < r && l < N && r >= 0) {
        ll sl = solution[l], sr = solution[r];
        if (abs(sl + sr) < ms) {
            lv = sl;
            rv = sr;
            ms = abs(sl + sr);
        }

        ll asl = abs(sl), asr = abs(sr);
        if (asl < asr) r--;
        else l++;
    }

    cout << lv << " " << rv << endl;

    return 0;
}
