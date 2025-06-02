#include <bits/stdc++.h>

using namespace std;

int T, r, c;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
char arr[1002][1002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>T;
    
    while(T--){
        cin>>c>>r;
        int fireDist[1002][1002];
        int humanDist[1002][1002];
        for(int i=0; i<r; i++){
            fill(fireDist[i], fireDist[i]+c, 0);
            fill(humanDist[i], humanDist[i]+c, 0);
        }
        queue<pair<int, int> > fire_q = {}, human_q = {};
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>arr[i][j];
                if(arr[i][j] == '*') {
                    fire_q.push({i,j});
                    fireDist[i][j] = 1;
                }
                if(arr[i][j] == '@') {
                    human_q.push({i,j});
                    humanDist[i][j] = 1;
                }
            }
        }

        // first -> fire dist bfs
        while(!fire_q.empty()){
            auto cur = fire_q.front(); fire_q.pop();
            
            for(int dir=0; dir<4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx<0||ny<0||nx>=r||ny>=c || arr[nx][ny] == '#') continue;
                if(fireDist[nx][ny]>0) continue;

                fire_q.push({nx,ny});
                fireDist[nx][ny] = fireDist[cur.first][cur.second] + 1;
            }
        }

        bool escaped= false;

        while(!human_q.empty() && !escaped){
            auto [x,y] = human_q.front(); human_q.pop();
            for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx<0||ny<0||nx>=r||ny>=c){
                cout<<humanDist[x][y]<<"\n";
                escaped = true;
                break;
        }
        if(arr[nx][ny]=='#' || humanDist[nx][ny]>0) continue;
        if(fireDist[nx][ny] != 0 && humanDist[x][y] + 1 >= fireDist[nx][ny]) continue;
        humanDist[nx][ny] = humanDist[x][y]+1;
        human_q.push({nx,ny});
    }
}
        if(!escaped) cout<<"IMPOSSIBLE"<<"\n";
        
    }

    
}