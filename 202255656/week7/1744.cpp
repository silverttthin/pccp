#include <iostream>
#include <vector>
#include <algorithm>

// 백준 1744 수 묶기 (그리디)

using namespace std;

int main() {
    int N; cin >> N;

    if (N == 1) {
        int T; cin >> T;
        cout << T << '\n';
        return 0;
    }

    vector<int> negatives;
    vector<int> positives;
    int zero_cnt = 0;

    for (int i = 0; i < N; i++) {
        int T; cin >> T;
        if (T > 0) positives.push_back(T);
        else if (T < 0) negatives.push_back(T);
        else zero_cnt++;
    }

    sort(positives.begin(), positives.end(), greater<>());
    sort(negatives.begin(), negatives.end());

    int result = 0;

    // 양수끼리 내림차순으로 곱
    // 1일 경우 곱하지 말고 더해야 함
    // 마지막으로 남은 수 더해주기
    int i;
    if (positives.size() > 0) {
        for (i = 0; i < positives.size() - 1; i += 2) {
            if (positives[i] == 1 || positives[i + 1] == 1) result += (positives[i] + positives[i + 1]);
            else result += (positives[i] * positives[i + 1]);
        }
        if (i < positives.size()) result += positives[i];
    }
    
    // 음수끼리 오름차순 곱
    // 마지막으로 남은 수 더해주기
    if (negatives.size() > 0) {
        for (i = 0; i < negatives.size() - 1; i += 2)
            result += (negatives[i] * negatives[i + 1]);
        if (i < negatives.size() && zero_cnt == 0) result += negatives[i];
    }

    cout << result << '\n';

    return 0;
}
