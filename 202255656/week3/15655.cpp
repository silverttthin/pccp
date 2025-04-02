#include <iostream>
#include <vector>
#include <algorithm>

// 백준 15655 N과 M (6) / 백트래킹

using namespace std;

vector<int> nums;
vector<int> vi;

void backtracking(int N, int M, int p) {
    if (M == 0) {
        for (int i : vi) cout << i << " ";
        cout << '\n';
        return ;
    }

    for (int i = p + 1; i < N; i++) {
        vi.push_back(nums[i]);
        backtracking(N, M - 1, i);
        vi.pop_back();
    }
}

int main() {
    int N, M; cin >> N >> M;

    nums.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    backtracking(N, M, -1);

    return 0;
}
