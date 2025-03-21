/*10773/제로/BOJ
12ms
10분 소요
*/
#include<iostream>

using namespace std;

const int MX = 100000;

int pos=0;

int dat[MX];


void push(int x){

    dat[pos++] = x;

}

void pop(void){

    pos--;
}


int main(){

    int k, i, sum = 0;
    scanf("%d",&k);

    for(i=0;i<k;i++){
        int a;
        scanf("%d",&a);

        if(a!=0){
            push(a);
        }
        else{
            pop();
        }
        
    }

    for(i=0;i<pos;i++){
        sum += dat[i];
    }

    cout << sum << endl;

}
