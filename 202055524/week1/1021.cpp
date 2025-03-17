//  1021 / 회전하는 큐 / boj
// 실행시간 0ms
// 풀이 시 38분 소요

#include <cassert>
#include <deque>
#include <iostream>
#include <algorithm>
int main() {

  int queue_size, input_len;
  std::cin >> queue_size >> input_len;

  std::deque<int> deque;

  for (auto i = 1; i <= queue_size; ++i) {
    deque.push_back(i);
  }

  int cnt = 0;
  for (auto i = 0; i < input_len; ++i) {
    int input = 0;
    std::cin >> input;
    auto pos = std::find(deque.begin(), deque.end(), input) - deque.begin();
    auto rev_pos = deque.size() - pos;

    // go front
    if (pos < rev_pos) {
      cnt += pos;
      while (deque.front() != input) {
        auto tmp = deque.front();
        deque.pop_front();
        deque.push_back(tmp);

      }
    } else {
      cnt += rev_pos;
      while (deque.front() != input) {

        auto tmp = deque.back();
        deque.pop_back();
        deque.push_front(tmp);

      }
    }
    assert(deque.front() == input);
    deque.pop_front();
  }

  std::cout << cnt;
}
