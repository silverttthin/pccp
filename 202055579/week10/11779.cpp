#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

int node, edge;
int startCity, endCity;

vector<pair<int,int>> adj[1002];
int dist[1002];
int prevNode[1002]; // 최단경로의 각 노드의 이전 노드정보


void dijkstra(int start){

    // 1. pq, dist를 시작점에 대해 초기화
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    // 2. dist가 가장 최소인 노드 선택
    while(!pq.empty()){
        int cost = -pq.top().first;  // 이건 걍 큐에서 뽑을 때 쓰는 기준으로만 쓰임
        int curNode = pq.top().second; pq.pop();

        // 2-1. 이미 최적화가 된 노드는 패스
        if(dist[curNode]<cost) continue;

        // 2-2. 현재 노드까지의 거리 + 이웃 노드간 거리와 dist[이웃노드] 비교갱신
        for(auto edge: adj[curNode]){
            int nextNode = edge.first;
            int nextCost = edge.second;

            if(dist[curNode] + nextCost < dist[nextNode]){
                dist[nextNode] = dist[curNode] + nextCost;
                pq.push({-dist[nextNode], nextNode});
                prevNode[nextNode] = curNode;
            }
        }

    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(0);

    cin>>node>>edge;
    fill(dist, dist+node+1, INF);

    for(int i=1; i<=edge; i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c}); // toNode, weight 순으로 저장
    }
    
    cin>>startCity>>endCity;

    dijkstra(startCity);

    // 경로출력용 배열 초기화
    vector<int> path;
    path.push_back(endCity);


    while(path.back() != startCity){
        path.push_back(prevNode[path.back()]);
    }
    reverse(path.begin(), path.end());



    cout<<dist[endCity]<<"\n";
    cout << path.size() << "\n";
    for(auto node: path) cout<<node<<" ";
}