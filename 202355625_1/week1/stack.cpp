// 10828/스택/baekjoon
// 216ms
// 1h
#include <iostream>
#include <vector>
using namespace std;
 int main(){
     int n;
     cin >> n;
     vector<int> stack;
     int pos=0;
     while(n--){
         string s;
         cin >> s;
         if(s=="push"){
             int num;
             cin >> num;
             stack.push_back(num);
             pos++;
         }else if(s=="pop"){
             if(pos==0) cout << -1 << endl;
             else{
                 cout << stack[pos-1] << endl;
                 stack.pop_back();
                 pos--;
             }
         }else if(s=="size"){
             cout << pos << endl;;
         }else if(s=="empty"){
             if(pos==0) cout << 1 << endl;
             else cout << 0 << endl;
         }else if(s=="top"){
             if(pos==0) cout << -1 << endl;
             else{
                 cout << stack[pos-1] << endl;
             }
         }
     }
 }
