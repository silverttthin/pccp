/*1629, 곱셈, BOJ
 0ms
 27m*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll power(ll a, ll b, ll c){
	if(b==0) return 1; //지수가 0일때 결과 1 
	if(b==1) return a % c; // 지수가 1일때는 그냥  
	
	//지수가 짝수일 때.. 
	ll h = power(a, b/2, c); //지수를 반으로 나눔
	ll result = (h * h) % c;
	
	//지수가 홀수일 때.. 
	if(b%2 ==1){
		result = (result * a)%c; 
	}
	
	
	return result;
	
}


int main(){
	ll A, B, C;
	cin >> A >> B >> C;
	cout << power(A, B, C) << endl;
	
}
