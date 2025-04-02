#include <iostream>
#include <vector>

// 백준 15651 N과 M (3)
// 알고리즘 : 백트래킹

using namespace std;

vector<int> vi;

void backtracking(int N, int M) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return;
    } 

    for (int i = 1; i <= N; i++) {
        vi.push_back(i);
        backtracking(N, M - 1);
        vi.pop_back();
    }
}

int main() {
    int N, M; cin >> N >> M;

    backtracking(N, M);

    return 0;
}
