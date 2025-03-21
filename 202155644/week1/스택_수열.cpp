// 문제 번호/제목/출처 - 1874/스택 수열/백준 온라인 저지
// 실행 시간 - 8ms
// 해결하는데 걸린 시간 - 약 13분 (문제 이해에 시간이 오래 걸림)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> stk; // 벡터 애호가입니다^^
  string ans;
  int i = 1;

  while (N--) {
    int curr; cin >> curr;

    while (i <= curr) {
      stk.push_back(i++);
      ans += "+\n";
    }

    if (curr == stk.back()) {
      stk.pop_back();
      ans += "-\n";
    } else {
      return cout << "NO", 0;
    }
  }

  cout << ans;
} // 8ms

/* 첫 풀이:

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> stk;
  vector<char> ans;
  int i = 1;

  while (N--) {
    int curr; cin >> curr;

    while (i <= curr) {
      stk.push_back(i++);
      ans.push_back('+');
    }

    if (curr == stk.back()) {
      stk.pop_back();
      ans.push_back('-');
    } else {
      return cout << "NO", 0;
    }
  }

  for (char it : ans) cout << it << '\n';
} // 20ms

*/
