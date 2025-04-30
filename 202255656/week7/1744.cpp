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
    int i;
    if (positives.size() > 0) {
        for (i = 0; i < positives.size() - 1; i += 2) {
            if (positives[i] == 1 || positives[i + 1] == 1) result += (positives[i] + positives[i + 1]);
            else result += (positives[i] * positives[i + 1]);
        }
        if (i < positives.size()) result += positives[i];
    }
    
    if (negatives.size() > 0) {
        for (i = 0; i < negatives.size() - 1; i += 2)
            result += (negatives[i] * negatives[i + 1]);
        if (i < negatives.size() && zero_cnt == 0) result += negatives[i];
    }

    cout << result << '\n';

    return 0;
}
