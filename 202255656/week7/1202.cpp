#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>

// 백준 1202 보석 도둑 / 그리디
// https://www.acmicpc.net/problem/12027

using namespace std;

struct compare_pq{
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};

struct compare_sort{
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first < p2.first;
    }   
};

int main() {
    int N, K; cin >> N >> K;
    
    vector<pair<int, int>> jewelries;
    for (int i = 0; i < N; i++) {
        int M, V; cin >> M >> V;
        jewelries.push_back({M, V});
    }
    sort(jewelries.begin(), jewelries.end(), compare_sort());

    vector<int> bags (K);
    for (int i = 0; i < K; i++) cin >> bags[i];
    sort(bags.begin(), bags.end());

    int j = 0;
    long long result = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pq> pq;
    for (int i = 0; i < K; i++) {
        for (; j < N && jewelries[j].first <= bags[i]; j++) pq.push(jewelries[j]);
        if (!pq.empty()) {
            result += pq.top().second;
            pq.pop();
        }
    }

    cout << result << '\n';

    return 0;
}
