1.学习了极大极小算法.
CCF 棋局评估:
http://www.cnblogs.com/chuxinbufu/p/9583044.html
先说说极大极小算法，是指给可能出现的所有状态赋予一个评估值，两个玩家通过计算不同下棋策略对应不同的评估值，来决定如何下棋。对于井字棋游戏来说，它的博弈树（各种走法组合形成的树）如下：


Alice(MAX)下X，Bob(MIN)下O，直到到达了树的终止状态即一位棋手占领一行，一列、一对角线或所有方格都被填满。Utility指效用函数，定义游戏者在状态S下的数值。在这道题中，就是指：

- 对于Alice已经获胜的局面，评估得分为(棋盘上的空格子数+1)；
　　- 对于Bob已经获胜的局面，评估得分为 -(棋盘上的空格子数+1)；
　　- 对于平局的局面，评估得分为0；

所以，在上图策略树中，无论当前局势如何，Alice（MAX）总会选择最大的评估分对应的走法，Bob（MIN）总会选择最小的评估分对应的走法。这样才能使自己尽快的赢得比赛（这一点是关键，要想清楚）。题目中只给出了策略树中叶子节点的评估分的计算方法（赢，输或平局情况的评估分计算方法），那如何计算策略树中每个非叶子节点对应的评估分值呢？

答案是采用深度优先搜索对整个策略树进行后序遍历，这样，先计算策略树中叶子节点的评估值，在一层层的往上计算非叶子节点的评估值，最终，会得到整个策略树的评估值，这样就可以确定玩家在当前情况下应该如何走棋了。



//代码一:
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int mp[4][4];
bool hok(int h,int f){                                            
    return mp[h][0]==f&&mp[h][0]==mp[h][1]&&mp[h][1]==mp[h][2];          //判断行是否三颗相连
}
bool lok(int l,int f){
    return mp[0][l]==f&&mp[0][l]==mp[1][l]&&mp[1][l]==mp[2][l];          //判断列是否三颗相连
}
int spa(){
    int res=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(!mp[i][j])res++;
    return res;
}
int win(int f){                                                          //判断当前局面胜负情况
    int wi=0,ans=1;
    if(hok(0,f)||hok(1,f)||hok(2,f))wi=1;
    if(lok(0,f)||lok(1,f)||lok(2,f))wi=1;
    if(mp[0][0]==f&&mp[0][0]==mp[1][1]&&mp[1][1]==mp[2][2])wi=1;
    if(mp[0][2]==f&&mp[0][2]==mp[1][1]&&mp[1][1]==mp[2][0])wi=1;
    if(!wi)return 0;
    ans+=spa();
    return (f==1)?ans:-ans;                                              
}
int dfs(int peo){                                                        //对抗搜索
    if(!spa())return 0;
    int Max=-10,Min=10;
    for(int i=0;i<3;i++){
        for(int j=0,w;j<3;j++){
            if(!mp[i][j]){                                               //枚举可以落棋的位置
                mp[i][j]=peo+1;
                w=win(peo+1);
                if(w){
                    mp[i][j]=0;
                    return w>0?max(Max,w):min(Min,w);
                }
                if(!peo)Max=max(Max,dfs(1));
                else    Min=min(Min,dfs(0));
                mp[i][j]=0;
            }
        }
    }
    return peo?Min:Max;                                                  //0-Alice-Max，1-Bob-Min
}
int main(){
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin>>mp[i][j];
        int x=win(1),y=win(2);
        if(x){cout<<x<<endl;continue;}
        if(y){cout<<y<<endl;continue;}
        cout<<dfs(0)<<endl;                                              //0表示Alice下，1表示Bob下
    }
    return 0;
}


//代码二:


#include <bits/stdc++.h>

using namespace std;

int q[10];

int checkok(){
    int i1, i2, ok = 0;
    for(i1 = 1; i1 <= 3; i1++)
    {
        i2 = 3 * (i1 - 1);
        if ((q[i1] == q[i1 + 3])&&(q[i1 + 3] == q[i1 + 6]) && (q[i1] != 0)){
            if(q[i1] == 1) ok = 1; else ok = 2;
            break;
        }
        if ((q[i2 + 1] == q[i2 + 2]) &&(q[i2 + 2] == q[i2 + 3]) && (q[i2 + 1] != 0)){
            if(q[i2 + 1] == 1) ok = 1; else ok = 2;
            break;
        }
    }
    if( (!ok) && ((q[1] == q[5]) && (q[5] == q[9]) && (q[1] != 0)) )
        if(q[1] == 1) ok = 1; else ok = 2;

    if( (!ok) && (q[3] == q[5]) && (q[5] == q[7]) && (q[3] != 0))
        if(q[3] == 1) ok = 1; else ok = 2;

    i2 = 0;
    for(i1 = 1; i1 <= 9; i1++)
        if(q[i1] == 0) i2++;

    if(ok == 1) return (i2 + 1);
    else if(ok == 2) return -(i2 + 1);
    else if(i2 == 0) return 0;
    else return 100;
}

int dfs(int turn){
    int value = checkok();
    if(value != 100) return value;
    int i1,i2;
    if(turn == 1) i2 = -100;
    else i2 = 100;
    for(i1 = 1; i1 <= 9; i1++){
        if(q[i1] != 0) continue;
        if(turn == 1){
            q[i1] = 1;
            i2 = max(i2, dfs(0));
        }else{
            q[i1] = 2;
            i2 = min(i2, dfs(1));
        }
        q[i1] = 0;
    }
    return i2;
}

int main()
{
    //freopen("a.txt", "r", stdin);
    int T,i1,i2;
    scanf("%d", &T);
    while(T--)
    {
        for(i1 = 1; i1 <= 9; i1++){
            scanf("%d", &i2);
            q[i1] = i2;
        }
        printf("%d\n", dfs(1));
    }
    return 0;
}


//   自己代码:
#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long

int maz[10][10];
using namespace std;

int cul(){
   int cnt = 1;
   for(int i = 1 ; i <= 3; i++){
       for(int j = 1 ; j <= 3; j++){
           if(!maz[i][j]) cnt++;
       }
   }
   return cnt;
}

int get_sc(){     //计算当前局面的得分,不可能同时赢的情况
   int sc = cul();
   for(int i = 1 ; i <= 3; i++){
       if(maz[i][1] == maz[i][2] && maz[i][2] == maz[i][3]){
           if(maz[i][1] == 1) return sc;
           else if(maz[i][1] == 2) return -sc;
       }

        if(maz[1][i] == maz[2][i] && maz[2][i] == maz[3][i]){
           if(maz[1][i] == 1) return sc;
           else if(maz[1][i] == 2) return -sc;
       }

   }

   if((maz[1][1] ==  maz[2][2] && maz[2][2] == maz[3][3]) || ( maz[1][3] == maz[2][2] && maz[2][2] == maz[3][1]) ) {
        if(maz[2][2] == 1) return sc;
        else if(maz[2][2] == 2) return -1*sc;
   }

   if( sc == 1) return 0;
   return 100;
}

int dfs(int id){

     int sc = get_sc();
     if(sc != 100) return sc;
     if(id == 1) sc = -100;
     else sc = 100;

     for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            if(!maz[i][j]){
                if(id == 1) { maz[i][j] = 1; sc = max(sc,dfs(2)); }
                else {  maz[i][j] = 2;  sc = min(sc,dfs(1));      }
                maz[i][j] = 0 ;
            }
        }
     }

    return sc;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        for(int i = 1 ; i <= 3 ; i++){
            for(int j = 1 ; j <= 3; j++){
                cin >> maz[i][j];
            }
        }
        cout << dfs(1) << endl;
    }
}





概念:

完全数：因子之和等于它本身的自然数