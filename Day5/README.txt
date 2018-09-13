。。总结今天...感觉要回去读高中...等差数列求了半天???

无论是等比也好等差也好..记住千万要把除法放在最后面..不然就GG(整型相除会掉失精度)
很不错...第一时间就想到了两分答案..即可行解的最大值

我们求下标..通过k-Y运算表示从k的左边开始数起第Y个元素.
通过k+Y运算表示从k的右边开始数起第Y个元素..


#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;

LL k,n,m;

bool check(LL Y){
     LL sr = 1;
     if(Y > m ) return false;
     LL mi = Y,num;

     LL lpos = k-Y+1;
     mi += max(sr-1,lpos-1),lpos = max(sr,lpos);
     num = k-lpos,mi += (Y-1+Y-num)*num/2;

     LL rpos = k+Y-1;
     mi += max(sr-1,n - rpos),rpos = min(n,rpos);
     num = rpos-k,mi += (Y-1+Y-num)*num/2;
     if( m < mi) return false;
     return true;
}


int main(){
   LL ans = 0;
   cin  >> n >> m >> k;
   LL l = 1 , r = 1e9;

   while( l <= r){
        LL mid = (l+r) >> 1;
        if(check(mid)){  ans = mid ; l = mid+1; }
        else{  r = mid-1;}
   }
   cout << ans << endl;
}