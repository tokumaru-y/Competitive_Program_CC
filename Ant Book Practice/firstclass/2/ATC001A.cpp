#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
typedef long long ll;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};
int  h,w;
vector<vector<char>> grid;
int sx,sy,ex,ey;
vector<vector<bool>> seen;
void dfs(int x,int y){
    if(grid[x][y]=='g')return;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];int ny = y+dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
        if(seen[nx][ny] || grid[nx][ny]=='#')continue;
        seen[nx][ny]=true;
        dfs(nx,ny);
    }
}
signed main () {
    cin >> h >> w;
    grid.resize(h,vector<char>(w));
    seen.resize(h,vector<bool>(w,false));
    REP(i,h){
        string sin;cin >> sin;
        REP(j,w){
            if(sin[j]=='s')sx=i,sy=j;
            if(sin[j]=='g')ex=i,ey=j;
            grid[i][j]=sin[j];
        }
    }
    seen[sx][sy]=true;
    dfs(sx,sy);
    if(seen[ex][ey])cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}