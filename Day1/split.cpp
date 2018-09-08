#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
 /* 正则
 aaaa*/4444*ddd/2223*dgada*****////deqw
/*
aaaa
4444
ddd
2223
dgada
 */

 //
vector<string> q;
string spl,str,t;

bool Notspl(char c){

   int len = spl.length();
   for(int i = 0 ; i < len ; i++){
        if(spl[i] == c) return true;
   }
   return false;
}

int main(){

   cin >> str >> spl ;
   int len = str.length();
   for(int i = 0 ; i < len ;i++){
       if(Notspl(str[i])){
            if(t != ""){  q.push_back(t);  t.clear(); }
       }
       else{   t += str[i]; }
   }

   for(int i = 0 ; i < q.size();i++){
       cout << q[i] << endl;
   }
}
