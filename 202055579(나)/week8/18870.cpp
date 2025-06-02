#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(0);

    int n; // 10^6
    cin>>n;
    vector<int> originalArr(n);
    
    for(int i=0; i<n; i++) cin>> originalArr[i];

    vector<int> sortedArr = originalArr;
    sort(sortedArr.begin(), sortedArr.end()); 

    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end()); // 중복 원소를 제거합니다.
    // unique는 연속된 중복값들을 하나로 압축. 따라서 sort와 같이 쓰여야함
    // 압축 후 end()를 리턴하는데 erase로 이 반복자를 start로 해서 erase에 넣어야함

    for(int i=0; i<n; i++){
        cout<<lower_bound(sortedArr.begin(), sortedArr.end(), originalArr[i]) - sortedArr.begin()<<" ";
    } // 반복자를 리턴하므로 begin()을 뺴야 개수 얻음

}