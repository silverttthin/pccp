#include <iostream>
#include <deque>
#include <utility>

using namespace std;

// 백준 2346 : 풍선 터뜨리기
// 알고리즘 : 자료구조 덱
// https://www.acmicpc.net/problem/2346

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    deque<pair<int, int>> balloons;
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        balloons.push_back({t, i});
    }

    while (!balloons.empty()) {
        auto [paper, num] = balloons.front(); balloons.pop_front();
        cout << num << " ";
        if (paper > 0) for (int i = paper - 1; i > 0; i--) {
            balloons.push_back(balloons.front());
            balloons.pop_front(); 
        } else if (paper < 0) for (int i = paper; i < 0; i++) {
            balloons.push_front(balloons.back());
            balloons.pop_back();
        }
    }

    return 0;
}
