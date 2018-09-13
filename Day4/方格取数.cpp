#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mmax = 10;
int dis[mmax][mmax],vis[mmax][mmax],maz[mmax][mmax],nex[mmax][mmax];

int dir_x[2] = {1,0};
int dir_y[2] = {0,1};

bool check(int x ,int y){
   if( x <= 0 || x > 9 || y <= 0 || y > 9) return false;
   return true;
}

int dfs(int x , int y){   //从(x,y)到(9,9)的最高得分路径

    if(x == 9 && y == 9) return maz[9][9];
    if(dis[x][y] != -1)  return dis[x][y];
    dis[x][y] = 0;
    for(int i = 0 ; i < 2 ; i++){
        int tx = x + dir_x[i];
        int ty = y + dir_y[i];
        if(check(tx,ty) && !vis[tx][ty]){
            vis[tx][ty] = 1;
            if( dis[x][y] < dfs(tx,ty)){
                dis[x][y] = dfs(tx,ty);
                nex[x][y] = tx*9+ty;
            }
            vis[tx][ty] = 0;
        }
    }
    dis[x][y] += maz[x][y];
    return dis[x][y];
}

void out(int x,int y){

   int tx = nex[x][y]/9,ty = nex[x][y]%9;
   cout << tx << "   " << ty << endl;
   if(x == 9 && y == 9 ) return ;
   out(tx,ty);
}


int main(){
     freopen("read.txt","r",stdin);
     freopen("1.txt","w",stdout);

     for(int i = 1 ; i <= 9 ;i++){
        for(int j = 1 ; j <= 9 ;j++){
            cin >> maz[i][j];
        }
     }

     memset(dis,-1,sizeof dis);
     memset(vis,0,sizeof vis);
     memset(nex,0,sizeof nex);
     vis[1][1] = 1;
     dfs(1,1);
     cout << 1 << "   " << 1 << endl;
     out(1,1);

     cout << dis[1][1] << endl;

}

