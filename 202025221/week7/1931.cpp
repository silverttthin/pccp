#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> inputs(N);
    for (int i = 0; i < N; i++) {
        cin >> inputs[i].first >> inputs[i].second;
    }
    sort(inputs.begin(), inputs.end(), [](auto a, auto b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    int idx = 1;
    int cnt = 1;
    int curTime = inputs[0].second;

    for (; idx < N; idx++) {
        if (curTime <= inputs[idx].first) { // 현재 시간 <= 다음 회의 시작 시간을 만족해야 회의 추가 가능
            curTime = inputs[idx].second;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
