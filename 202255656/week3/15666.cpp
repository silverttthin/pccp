#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 15666 N과 M (12) / 백트래킹

vector<int> vi;
vector<int> arr;

void backtracking(int N, int M, int P) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return;
    }

    int prev_int = 0;
    for (int i = P; i < N; i++) {
        if (prev_int == arr[i]) continue;
        vi.push_back(arr[i]);
        backtracking(N, M - 1, i);
        vi.pop_back();
        prev_int = arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    arr.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    backtracking(N, M, 0);

    return 0;
}
