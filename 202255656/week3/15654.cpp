#include <iostream>
#include <vector>
#include <algorithm>

// 백준 15654 N과 M (5) / 백트래킹

using namespace std;

vector<int> container;
vector<int> vi;
vector<bool> vb;


void backtracking(int N, int M) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vb[i] == true) continue;
        vb[i] = true;
        vi.push_back(container[i]);
        backtracking(N, M - 1);
        vb[i] = false;
        vi.pop_back();
    }
}

int main() {
    int N, M; cin >> N >> M;

    vb.resize(N, false);
    container.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> container[i];

    sort(container.begin(), container.end());

    backtracking(N, M);

    return 0;
}
