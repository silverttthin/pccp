/*
17298/오큰수/BOG
188ms
20m
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> s; // index, value

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    /*
    입력순대로 스택에 넣다가
    만약 top보다 크다면 result에 기록한다.
    */

    cin >> n;

    int inp;
    vector<int> result(n, -1);
    for (int i=0; i<n; ++i)
    {
        cin >> inp;
        while (!s.empty() && s.top().second < inp)
        {
            result[s.top().first] = inp;

            s.pop();
        }
            
        s.push({i, inp});
    }   

    for (auto& e : result)
        cout << e << ' ';
}