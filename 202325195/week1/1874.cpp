/*1874/스택 수열/BOJ
28ms
49분 소요*/

#include<iostream>

using namespace std;

const int mx = 1000005;
int dat[mx];
int pos = 0;
int in = 0;

char res[mx];

void push(int x){
	
	dat[pos++] = x;
	res[in++] = '+';
}

void pop(void){
	
	pos--;
	res[in++] = '-';
	
}

int top(void){
	if(pos > 0) return dat[pos-1];
	return -1;
}

int main(){
	
	int n, i, j=0;
	scanf("%d",&n);
	int * seq = new int[n];
	for(i=0;i<n;i++){
		scanf("%d",&seq[i]);
	}
	
	i = 1;
	while(j<n){
		if(top()<seq[j]){
			push(i++);
		}
		else if(top()==seq[j]){
			pop();
			j++;
		}
		else{
			cout << "NO" << '\n';
			delete[] seq;
			return 0;
		}
		
	}
	
	for(i=0;i<in;i++){
		cout << res[i] << '\n';
	}
	
	delete[] seq;
	return 0;
	
}
