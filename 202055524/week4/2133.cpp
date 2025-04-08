// 2133 / 타일 채우기 / boj
// 0ms
// 30min

#include <iostream>
#include <vector>


int main() {
  std::vector<unsigned> dp(16);
  dp[0] = 1;
  dp[1] = 3;
  for (auto i = 2u; i < 16; ++i) {
    dp[i] += dp[i - 1] * 3;
    for (auto j = 0u; j < i - 1; ++j) {
      dp[i] += dp[j] * 2;
    }
      
  }

  unsigned n;
  std::cin >> n;
  if (n % 2 == 1 || n == 0) {
    std::cout << 0;
  } else {
    std::cout << dp[n / 2];
  }
}
