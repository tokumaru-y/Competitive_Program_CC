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
vector<vector<char>> grid;
vector<vector<int>> seen;
int sx,sy,ex,ey;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<int,int> tmp=q.front();q.pop();
        int x=tmp.first;int y=tmp.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];int ny=y+dy[i];
            if(nx<0||nx>h-1||ny<0||ny>w-1)continue;
            if(seen[nx][ny]>=0 || grid[nx][ny]=='#')continue;
            seen[nx][ny]=seen[x][y]+1;
            q.push(make_pair(nx,ny));
        }
    }
}
signed main () {
    cin >> h >> w;
    cin >> sx >> sy;cin >> ex >> ey;
    sx--;sy--;ex--;ey--;
    grid.assign(h,vector<char>(w));
    seen.assign(h,vector<int>(w,-1));
    REP(i,h)REP(j,w)cin >> grid[i][j];
    seen[sx][sy]=0;
    bfs(sx,sy);
    cout << seen[ex][ey] << endl;
}