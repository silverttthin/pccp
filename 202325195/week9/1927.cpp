/*
1927/최소 힙/BOJ
12ms
32m
*/

#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;

void push(int x){
	sz++;
	heap[sz] = x;
	int i = sz;
	while(i > 1 && heap[i/2] > heap[i]){
		swap(heap[i], heap[i/2]);
		i = i / 2;
	}
}

int top(){
	if(sz == 0) return 0;
	return heap[1];
}

void pop(){
	if(sz == 0) return;

	heap[1] = heap[sz];
	sz--;

	int i = 1;
	while(i * 2 <= sz){
		int left = i * 2;
		int right = i * 2 + 1;
		int minch = left;

		if(right <= sz && heap[right] < heap[left])
			minch = right;

		if(heap[i] > heap[minch]){
			swap(heap[i], heap[minch]);
			i = minch;
		} else {
			break;
		}
	}
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, n;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> n;
		if(n == 0){
			cout << top() << '\n';
			pop();
		} else {
			push(n);
		}
	}
}


/*
//STL 사용
#include<bits/stdc++.h>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	
	int N;
	unsigned int m;
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>m;
		if(m==0){
			if(pq.empty()){
				cout<<0<<"\n";
			}
			else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
		else{
			pq.push(m);
		}
	}
}

*/
