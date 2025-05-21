/*
10815/숫자카드/BOJ
208ms
17m
*/
 
#include<bits/stdc++.h>

using namespace std;

int a[500005];

int b[500005];


int N,M;

int binarySearch(int target){
	int st = 0;
	int en = N-1;
	while(st<=en){
		int mid = (st+en)/2;
		if(a[mid] < target){
			st = mid+1;
		}
		else if(a[mid]>target){
			en = mid-1;
		}
		else return 1;
	}
	return 0; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	cin>>M;
	for(int i = 0; i<M;i++){
		cin>>b[i];
	}
	sort(a,a+N);
	
	for(int i=0;i<M;i++){
		cout << binarySearch(b[i]) <<' ';
	}
	
	
}
