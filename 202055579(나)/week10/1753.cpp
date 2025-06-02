#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

int v, e, start;

vector<pair<int,int>> adj[20005];
// pair 쌍을 담는 벡터 자료형을 담는 배열
// 인접 그래프이므로 배열의 크기는 노드 개수

int dist[20005];


void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start}); // start~second까지의 거리!!와 경로 번호
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first; // 최대 힙을 최소 힙으로 쓰기위한 꼼수
        int cur = pq.top().second;
        pq.pop();
        
        // 큰값이 큐에 있는데 이미 최소값으로 갱신된 상태면 패스
        if(dist[cur]<cost) continue;

        for(auto edge : adj[cur]){
            int next = edge.first;
            int nCost = edge.second;
            if(dist[cur] + nCost < dist[next]){
                dist[next] = dist[cur] + nCost; // start~cur + next node's cost가 1~next인 dist[next] 비교해 갱신
                pq.push({-dist[next], next});
            }
        }
    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(0);

    cin>>v>>e>>start;

    fill(dist, dist+v+1, INF);
    for(int i=1; i<=e; i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    dijkstra(start);

    for(int i=1; i<=v; i++){
        if((dist[i] == INF)) cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }
}