    #include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

vector<pair<int, int>> adj[101];
int dist[101];

void dijkstra(int start){

    // 1. start 지점을 큐에 추가하고 거리 초기화
    priority_queue<pair<int,int>> pq;
    pq.push({0,start}); 
    dist[start] = 0;


    // 2. 큐에서 거리가 가장 가까운 노드를 선택
    while(!pq.empty()){

        // 2-1. 해당 노드까지의 거리, 해당 노드명 추출
        int cost = -pq.top().first; // - 곱해야 최소힙처럼 사용가능함 + 그냥 큐에서 쓰는 용도
        int cur = pq.top().second;
        pq.pop();
        
        // 2-2. 최소값으로 갱신된 상태면 패스
        if(dist[cur]<cost) continue;

        // 2-3. 현재 노드에서 연결된 노드들 중 dist 갱신 작업 때리기
        for(auto edge : adj[cur]){
            int next = edge.first;
            int nCost = edge.second;
            if(dist[cur] + nCost < dist[next]){
                dist[next] = dist[cur] + nCost; 
                pq.push({-dist[next], next});
            }
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    fill(dist,dist+100+1, INF);

}