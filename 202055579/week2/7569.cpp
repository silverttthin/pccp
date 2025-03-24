#include <bits/stdc++.h>

using namespace std;

int c,r,h, cur;
int arr[102][102][102];
int dist[102][102][102];

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int,int,int>> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>c>>r>>h;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                cin>>cur;
                arr[i][j][k] = cur;
                if(cur == 1) q.push({i,j,k}); 
                if(cur == 0) dist[i][j][k] = -1;
                // 왜 안익은 토마토를 -1로 두는가?
                // => 추후 방문해 큐에 넣어야해서
            }
        }
    }


    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int curx,cury,curz;
        tie(curz,curx,cury) = cur;

        for(int dir=0; dir<6; dir++){
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];
            int nz = curz + dz[dir];
            if(nx<0||ny<0||nz<0||nx>=r||ny>=c||nz>=h) continue;
            if(dist[nz][nx][ny] >=0) continue;

            dist[nz][nx][ny] = dist[curz][curx][cury] + 1;
            q.push({nz,nx,ny});
        }
    }

    int ans=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                if(dist[i][j][k] == -1){
                    cout<<-1;
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }

    cout<<ans;

    
}