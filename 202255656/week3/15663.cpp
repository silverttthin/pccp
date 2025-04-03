#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 백준 15663 N과 M (9) / 백트래킹

vector<int> arr;
vector<int> vi;
vector<bool> vb;

void backtracking(int N, int M) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return;
    }

    int prev_int = 0;
    for (int i = 0; i < N; i++) {
        if (prev_int == arr[i]) continue;
        if (vb[i] == true) continue;
        vb[i] = true;
        vi.push_back(arr[i]);
        backtracking(N, M - 1);
        vi.pop_back();
        vb[i] = false;
        prev_int = arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    vb.resize(N, false);

    arr.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    backtracking(N, M);

    return 0;
}
