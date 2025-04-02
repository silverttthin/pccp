#include <iostream>
#include <vector>

// 백준 15649 : N과 M (1)
// 알고리즘 : 백트래킹

using namespace std;

vector<int> vi;
vector<bool> vb;

void backtracking(int N, int M) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (vb[i] == true) continue;
        vb[i] = true;
        vi.push_back(i);
        backtracking(N, M - 1);
        vb[i] = false;
        vi.pop_back();
    }
}

int main() {
    int N, M; cin >> N >> M;

    vb.resize(N + 1, false);

    backtracking(N, M);
    return 0;
}
