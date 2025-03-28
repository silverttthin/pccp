//2178, 미로탐색, BOJ
//0ms
//1h15m


#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[100][100]; //미로를 입력받을 2차원 배열
int dit[100][100]; //(방문표시)거리를 넣을 2차원 배열
int dx[4] = {1,0,-1,0}; // 행을 기준으로 상하좌우로 이동
int dy[4] = {0,1,0,-1}; // 열을 기준으로 상하좌우로 이동


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i, j;
    cin >> n >> m;
    for(i=0;i<n;i++){
        string s;
        cin >> s;
        for(j=0;j<m;j++){
            board[i][j] = s[j]-'0'; //
        }
    }
    
    for(i=0;i<100;i++){
    	for(j=0;j<100;j++){
    		dit[i][j] = -1; //방문 여부 -1을 사용 dit 배열을 초기화
		}
	}
    queue<pair<int,int>> Q;
    dit[0][0] = 0; //0,0부터 시작 시작 좌표와의 거리는 0
    Q.push({0,0});
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0;dir<4;dir++){//현재위치 기준으로 상하좌우(4번) 확인
            int nx = cur.X + dx[dir]; //현재위치에서 상하좌우로 이동한 좌표(행)
            int ny = cur.Y + dy[dir]; //현재위치에서 상하좌우로 이동한 좌표(열열)
            if(nx < 0 || nx >=n || ny <0 || ny >= m) continue;//각 x, y 좌표가 행 또는 열을 초과하는지 확인
            if(dit[nx][ny]>=0||board[nx][ny]!=1) continue; //방문한 좌표거나 미로 좌표가 0 인지 확인
            dit[nx][ny] = dit[cur.X][cur.Y]+1; //길이를 저장(방문 표시) 거리를 갱신 
            Q.push({nx,ny}); //Q에 현재 좌표값 push


        }


    }

    cout << dit[n-1][m-1]+1; //거리 0부터 시작, 문제에서는 시작을 1로 하기에 +1

}
