#include <iostream>
#include <vector>

// 백준 15650 N과 M (2)
// 알고리즘 : 백트래킹

using namespace std;

vector<int> vi;

void backtracking(int N, int M, int p) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
    }
        
    for (int i = p + 1; i <= N; i++) {
        vi.push_back(i);
        backtracking(N, M - 1, i);
        vi.pop_back();
    }
}

int main() {
    int N, M; cin >> N >> M;

    backtracking(N, M, 0);

    return 0;
}
