/*
 ��������...���ǲ�������һ���ܾ����뷨�Ĳ��鼯��

 ����ĵط�����ѧУ�뿳����ߵ�ǰk[i]���� ��������ߵĵ�k[i]������
 ��ߵĵ�k[i]���������ò��鼯����һ���Ż�.
 ������ÿ�����ĸ߶Ƚ�������.����rk[i] ��¼��ʼ��ߵĵ�i�������.
 f[i] // ����ǰ��ߵĵ�i�����ı��. �������.�����

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
    for(int i = 1 ; i <= l ; i++){  rk[i] = p[i].id; }   //��i���Ԫ�������Ǹ�λ��;
    ans = 1;
    for(int i = 1 ; i <= m ; i++){
         cin >> k;
         int fk = ff(rk[k]);
         if(tree[fk-1] && tree[fk+1] ) ans++;
         tree[fk] = 0;
         f[fk] = ff(fk+1);  // �ı�ְ�;
         cout << ans << endl;
    }
}


*/


/*
      �����п��ܻ����Ӷ�,��ô��û�п��ܻ���ٶ���?

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
