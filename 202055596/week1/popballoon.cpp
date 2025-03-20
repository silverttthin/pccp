/*
풍선터뜨리기/프로그래머스
11ms
35m
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int a_len = a.size();
    vector<int> leftMin(a_len);
    vector<int> rightMin(a_len);
    
    leftMin[0] = a[0]; // 0 ~ i 중 최솟값
    rightMin[a_len - 1] = a[a_len - 1]; // i ~ a_len - 1 중 최솟값
    
    for (int i=1; i<a_len; ++i)
    {
        leftMin[i] = min(leftMin[i - 1], a[i]);
        rightMin[a_len - 1 - i] = min(rightMin[a_len - i], a[a_len - 1 - i]);
    }
    
    answer = 2; // 처음과 끝 인자는 항상 가능        
    
    // 본인과 양 옆의 최댓값을 비교해서
    for (int i=1; i<a_len-1; ++i)
    {
        if (max(a[i], max(leftMin[i-1], rightMin[i+1])) != a[i])
            answer += 1;
    }
    
    return answer;
}
