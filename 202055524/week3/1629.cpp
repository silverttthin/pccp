// 1629 / 곱셈 / boj
// 0ms
// 7분 소요
#include <ios>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t n, times, mod;

  std::cin >> n >> times >> mod;

  size_t result = 1;

  while (times > 0) {
    if (times % 2 == 0) {
      n = (n * n) % mod;
      times /= 2;
    } else {
      result = (n * result) % mod;
      --times;
    }
  }

  std::cout << result;
}
