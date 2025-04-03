#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 15657 N과 M (8) / 백트래킹

vector<int> arr;
vector<int> vi;

void backtracking(int N, int M, int P) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return;
    }

    for (int i = P; i < N; i++) {
        vi.push_back(arr[i]);
        backtracking(N, M - 1, i);
        vi.pop_back();
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
