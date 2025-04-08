// 20312 / cpu 벤치마크 / boj
// 328ms
// 40min, 30점(서브테스크)
// 비고: 만점 받으려면 다른 방법으로 풀어야 할 듯
#include <cstdint>
#include <iostream>
#include <vector>


int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  constexpr unsigned DIV = 1000000000 + 7;
  unsigned N = 0;
  std::cin >> N;

  const auto width = (N - 1);
  std::vector<std::vector<uint64_t>> dp(N, std::vector<uint64_t>(N));


  uint64_t result = 0;
  for (auto i = 0; i < width; ++i) {
    std::cin >> dp[i + 1][i];
    result += dp[i + 1][i];
  }


  for (auto j = 1; j < width; ++j) {
    for (auto i = 0; i < width - j; ++i) {
      auto y_pos = i + j + 1;
      auto x_pos = i;

      dp[y_pos][x_pos] = (dp[y_pos - 1][x_pos] * dp[y_pos][y_pos - 1]) % DIV;
      result = (result + dp[y_pos][x_pos]) % DIV;
    }
  }

  std::cout << result;
}
