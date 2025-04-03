#include <iostream>
#include <vector>
#include <algorithm>

// 백준 15656 N과 M (7) / 백트래킹

using namespace std;

vector<int> arr;
vector<int> vi;

void backtracking(int N, int M) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        vi.push_back(arr[i]);
        backtracking(N, M - 1);
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


    backtracking(N, M);
    
    return 0;
}
