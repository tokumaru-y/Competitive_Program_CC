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
vector<int> dx={1,0};vector<int> dy={0,1};
vector<vector<char>> grid;vector<vector<ll>> seen;
ll ans=0;int h,w;
using llt = tuple<ll,int,int>;
void bfs() {
    priority_queue<llt,vector<llt>,greater<llt>> que;
    int sx=0;int sy=0;ll scnt=0;
    if(grid[0][0]=='#')scnt++;
    que.push(llt(scnt,sx,sy));
    while(!que.empty()){
        llt tmp=que.top();que.pop();
        int x=get<1>(tmp);int y=get<2>(tmp);ll cnt=get<0>(tmp);
        REP(i,2){
            int nx=x+dx[i];int ny=y+dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w)continue;
            if(seen[nx][ny]<=cnt)continue;
            if(grid[nx][ny]== '#' && grid[x][y]=='.'){
                que.push(llt(cnt+1,nx,ny));
                seen[nx][ny]=cnt+1;
            } else {
                que.push(llt(cnt,nx,ny));
                seen[nx][ny]=cnt;
            }
        }
    }
}
signed main () {
    cin >> h >> w;
    grid.assign(h,vector<char>(w));
    seen.assign(h,vector<ll>(w,INF));
    REP(i,h)REP(j,w)cin >> grid[i][j];
    bfs();
    cout << seen[h-1][w-1] << endl;
}
//https://atcoder.jp/contests/agc043/tasks/agc043_a