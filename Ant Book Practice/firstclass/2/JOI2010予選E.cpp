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
int n,w,h;vector<vector<char>> grid;
int ans=0;
void dfs(int x,int y,char target){
    queue<tuple<int,int,int>> que;
    que.push(make_tuple(x,y,0));
    vector<vector<bool>> seen(h,vector<bool>(w,false));
    seen[x][y]=true;
    int nextx;int nexty;
    while(!que.empty()){
        tuple<int,int,int> tmp=que.front();que.pop();
        int orix=get<0>(tmp);int oriy=get<1>(tmp);int tmpcnt = get<2>(tmp);
        for(int i=0;i<4;i++){
            int nx=orix+dx[i];int ny=oriy+dy[i];
            if(nx<0 || nx>h-1 || ny<0 || ny>w-1)continue;
            if(grid[nx][ny]==target){
                ans+=tmpcnt+1;
                queue<tuple<int,int,int>>().swap(que);
                nextx=nx;nexty=ny;
                break;
            }
            if(seen[nx][ny] || grid[nx][ny]=='X')continue;
            seen[nx][ny]=true;
            que.push(make_tuple(nx,ny,tmpcnt+1));
        }
    }
    if(n==target-'0')return;
    else dfs(nextx,nexty,target+1);
}
signed main () {
    cin >> h >> w >> n;
    grid.assign(h,vector<char>(w));
    int sx,sy;
    REP(i,h){
        string tmp;cin >> tmp;
        REP(j,w){
            grid[i][j]=tmp[j];
            if(grid[i][j]=='S')sx=i,sy=j;
        }
    }
    dfs(sx,sy,'1');
    cout << ans << endl;
}