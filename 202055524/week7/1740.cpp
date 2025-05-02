// 1740 / 거듭제곱 / boj
// 0ms
// 10min

#include <cstdint>
#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  uint64_t digit = 0;
  uint64_t n = 1, ret = 0;

  std::cin >> digit;
  while (digit) {
    ret += (digit & 1) * n;
    n *= 3;
    digit = digit >> 1;
  }

  std::cout << ret;
}
