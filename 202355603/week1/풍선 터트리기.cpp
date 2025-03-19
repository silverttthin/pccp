#include <string>
#include <vector>
using namespace std;


int solution(vector<int> a) {
    int a_len = a.size();
    int answer = 2;
    vector<int> left(a_len), right(a_len);
    
    left[0] = a[0]; right[a_len - 1] = a[a_len - 1];
    for (int i = 1; i < a_len; i++){
        left[i] = min(left[i - 1], a[i]);
    }
    for (int i = a_len - 2; i >= 0; i--){
        right[i] = min(right[i + 1], a[i]);
    }
    for (int i = 1; i < a_len - 1; i++){
        if ((left[i - 1] > a[i]) || (right[i + 1] > a[i])){
            answer++;
        }
    }
    return answer;
}
