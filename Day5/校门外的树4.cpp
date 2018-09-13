/*
 读错题了...于是产生了另一个很具有想法的并查集。

 读错的地方在于学校想砍掉最高的前k[i]棵树 ，看成最高的第k[i]棵树。
 最高的第k[i]棵树可以用并查集进行一个优化.
 即按照每棵树的高度进行排序.利用rk[i] 记录初始最高的第i棵树编号.
 f[i] // 代表当前最高的第i棵树的编号. 如果被砍.则更新

#include <iostream>
#include <algorithm>
#include <cstdio>
#define LL long long
using namespace std;
const int mmax = 1e6+5;

LL l,m,h,k,ans;
struct Node{
   int val,id;
   bool operator <(const Node & b)const{
      return val > b.val;
   }
}p[mmax];

int f[mmax],tree[mmax],rk[mmax];

int ff(int x){
   if(x == f[x]) return x;
   else f[x] = ff(f[x]);
}

int main(){

    cin >> l >> m;
    for(int i = 1 ; i <= l ; i++) { tree[i] = 1; f[i] = i;}

    for(int i = 1 ; i <= l ; i++){
         scanf("%d",&p[i].val);
         p[i].id = i;
    }
    sort(p+1,p+1+l);
    for(int i = 1 ; i <= l ; i++){  rk[i] = p[i].id; }   //第i大的元素是在那个位置;
    ans = 1;
    for(int i = 1 ; i <= m ; i++){
         cin >> k;
         int fk = ff(rk[k]);
         if(tree[fk-1] && tree[fk+1] ) ans++;
         tree[fk] = 0;
         f[fk] = ff(fk+1);  // 改变爸爸;
         cout << ans << endl;
    }
}


*/


/*
      砍树有可能会增加段,那么有没有可能会减少段呢?

*/

#include <iostream>
#include <cstdio>
#include <queue>
#define LL long long
using namespace std;

LL l,m,h,k,ans;

const int mmax = 1e6+5;

struct Node{
   int val,id;
   bool operator <  (const Node & b)const{
      return val < b.val;
   }
};

priority_queue<Node> q ;
int tree[mmax];
int main(){

    cin >> l >> m ;
    for(int i = 1 ; i <= l ; i++){
        scanf("%d",&h);
        tree[i] = 1;
        q.push(Node{h,i});
    }
    ans = 1;

    for(int i = 0 ; i < m ; i++){
        scanf("%d",&k);
        for(int j = 0 ; j < k ; j++){
            int pos = q.top().id;
            q.pop();
            if(tree[pos-1] && tree[pos+1]) ans++;
            else if(!tree[pos-1] && !tree[pos+1]) ans--;
            tree[pos] = 0 ;
        }
        cout << ans << endl;
    }
}
