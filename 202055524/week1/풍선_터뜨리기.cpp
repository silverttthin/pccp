#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    if(a.size() < 3) {
        return a.size();
    }
    
    
    size_t left_cnt = 0;
    
    auto min_offset = min_element(a.begin(), a.end());
    int min_elem = *a.begin();
    
    // left iteration
    auto cur_pos = a.begin();
    while(cur_pos != min_offset) {
        if(*cur_pos <= min_elem) {
            min_elem = *cur_pos;
            ++left_cnt;
        }
        ++cur_pos;
    }
    // right iteration
    cur_pos = std::prev(a.end());
    min_elem = *cur_pos;
    size_t right_cnt = 0;
    while(cur_pos != min_offset) {
        if(*cur_pos <= min_elem) {
            min_elem = *cur_pos;
            ++right_cnt;
        }
        --cur_pos;
    }

    return left_cnt + right_cnt + 1;
}
