/*
1780/종이의개수/BOG
344ms
40m
*/

#include <iostream>
#include <vector>
using namespace std;

int result[3];
vector<vector<int>> paper;

void cut(int x, int y, int r)
{
    int isSame = true;
    for (int i=x; i<x+r; ++i)
        for (int j=y; j<y+r; ++j)
            if (paper[x][y] != paper[i][j])
            {
                isSame = false;
                break;
            }
      
    // 하나로 잘림
    if (isSame)
    {
        result[paper[x][y] + 1] += 1;
        return;
    }

    // 9개로 쪼개야 해
    r /= 3;
    for (int i=0; i<3; ++i)
        for (int j=0; j<3; ++j)
            cut(x + i * r, y + j * r, r);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;

    paper = vector<vector<int>>(n, vector<int>(n));

    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> paper[i][j];

    cut(0, 0, n);

    for (auto& e : result)
        cout << e << '\n';
}