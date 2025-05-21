// 2230 / 수 고르기 / baekjoon 
// 64ms, 40m

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    sort(A.begin(), A.end());

    int start = 0, end = 0;
    long long answer = 2e9 + 1;

    while (start < N && end < N) {
        long long diff = A[end] - A[start];

        if (diff < M) {
            end++;
        } else {
            answer = min(answer, diff);
            start++;
            if (start > end) end = start;
        }
    }

    cout << answer << '\n';
    return 0;
}
