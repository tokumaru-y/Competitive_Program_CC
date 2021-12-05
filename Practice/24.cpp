// https://atcoder.jp/contests/atc001/tasks/dfs_a
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};
vector<vector<char>> grid;
vector<vector<bool>> used;
int sx,sy,ex,ey;
int H,W;
void dfs(int x,int y){
    used[x][y] = true;
    REP(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!(0<=nx && nx <= H-1) || !(0<=ny && ny<= W-1))continue;
        if (used[nx][ny] || grid[nx][ny] == '#')continue;
        dfs(nx,ny);
    }
}


signed main () {
    cin >> H >> W;
    grid.resize(H,vector<char>(W));
    used.resize(H,vector<bool>(W, false));
    REP(i,H)REP(j,W){
        char in;cin >> in;
        if(in=='s'){
            sx = i,sy=j;
        }else if(in=='g'){
            ex=i,ey=j;
        }
        grid[i][j] = in;
    }
    dfs(sx,sy);
    if (used[ex][ey])cout << "Yes" << endl;
    else cout << "No" << endl;
}