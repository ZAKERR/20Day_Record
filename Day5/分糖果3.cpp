/*
#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;

LL k,n,m;

bool check(LL Y){  //等比数列记得....要/2放在最后面..
     LL sr = 1;
     if(Y > m ) return false;
     LL mi = Y,num;

     //定位左边1的位置:
     LL lpos = k-Y+1;   //从第k个位置开始左边
     mi += max(sr-1,lpos-1),lpos = max(sr,lpos);
     num = k-lpos,mi += (Y-1+Y-num)*num/2;

     //定位右边1的位置
     LL rpos = k+Y-1;   //从第k个位置开始左边
     mi += max(sr,n - rpos),rpos = min(n,rpos);
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

*/


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
