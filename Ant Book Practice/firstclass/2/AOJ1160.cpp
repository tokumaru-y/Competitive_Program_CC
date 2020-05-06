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
int h,w;
vector<vector<int>> grid;
vector<vector<bool>> seen;
int xx[8] = {0,-1,-1,-1,0,1,1,1};
int yy[8] = {1,1,0,-1,-1,-1,0,1};
void dfs(int x,int y){
    seen[x][y] = true;
    for(int i=0;i<8;i++){
        int nx = x+xx[i];int ny = y+yy[i];
        if(nx<0||nx>h-1||ny<0||ny>w-1)continue;
        if(!seen[nx][ny] && grid[nx][ny]==1){
            dfs(nx,ny);
        }
    }
}
signed main () {
    while(cin >> w >> h){
        if(h+w==0)break;
        int cnt = 0;
        grid.assign(h,vector<int>(w));
        seen.assign(h,vector<bool>(w,false));
        REP(i,h)REP(j,w)cin >> grid[i][j];
        REP(i,h)REP(j,w){
            if(grid[i][j]==1 && !seen[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}