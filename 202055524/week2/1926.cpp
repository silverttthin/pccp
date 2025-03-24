// 1926 / 그림 / boj
// 16ms
// 26m 소요

#include <algorithm>
#include <deque>
#include <ios>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int width, height;

  std::cin >> height >> width;

  std::vector<int> board;
  
  board.reserve(width * height);
  
  for (auto i = 0; i < height; ++i) {
    for (auto j = 0; j < width; ++j) {
      int input = 0;
      std::cin >> input;
      board.push_back(input);
    }
  }

  // check pos
  std::deque<std::pair<int, int>> queue;

  size_t max_area = 0, num_area = 0;
  for (auto i = 0; i < height; ++i) {
    for (auto j = 0; j < width; ++j) {
      const auto pos = i * width + j;

      auto &cur = board[pos];
      
      if (!cur) {
        continue;
      }

      ++num_area;

      board[i * width + j] = 0;
      queue.push_back({i, j});

      size_t area = 0;
      while (!queue.empty()) {
        const auto [y, x] = queue.front();
        queue.pop_front();
        if (y - 1 >= 0 && board[(y - 1) * width + x]) {
          board[(y - 1) * width + x] = 0;
          queue.push_back({y - 1, x});
        }
        
        if (y + 1 < height && board[(y + 1) * width + x]) {
          board[(y + 1) * width + x] = 0;
          queue.push_back({y + 1, x});
        }

        if (x - 1 >= 0 && board[y * width + x - 1]) {
          board[y * width + x - 1] = 0;

          queue.push_back({y, x - 1});
        }
        
        if (x + 1 < width && board[y * width + x + 1]) {
          board[y * width + x + 1] = 0;
          queue.push_back({y, x + 1});
        }

        ++area;
      }

      max_area = std::max(max_area, area);
    }
  }

  std::cout << num_area << "\n" << max_area;
}
