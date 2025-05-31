/*BOJ/14888/연산자 끼워넣기
0ms
70m
*/
#include<bits/stdc++.h>

using namespace std;

int N;
int re;
int op[4];
int num[105];
int re_max = -1000000000;
int re_min = 1000000000;

void func(int k, int res){
	if(k == N){ 
		re_max = max(re_max, res);
		re_min = min(re_min, res);
		return;
		
	}
	for(int i = 0; i<4; i++){
		if(op[i]>0){
		op[i]--;
		switch (i){
			case 0:
				func(k+1,res+num[k]);
				break;
			case 1:
				func(k+1,res-num[k]);
				break;
			case 2:
				func(k+1,res*num[k]);
				break;
			default:
				func(k+1,res/num[k]);
		}
		op[i]++;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>> N;
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	for(int i=0;i<4;i++){
		cin>>op[i];
	}
	
	func(1,num[0]);
	
	cout<<re_max<<"\n";
	cout<<re_min;
	
	
	return 0;
}
