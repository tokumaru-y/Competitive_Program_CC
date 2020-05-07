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
vector<vector<bool>> seen;
int sx,sy,ex,ey;
using T =tuple<int,int,int>;
void dfs() {
    priority_queue<T,vector<T>,greater<T>> que;
    que.push(T(0,sx,sy));
    while(!que.empty()){
        T tmp = que.top();que.pop();
        int orix=get<1>(tmp);int oriy=get<2>(tmp);int nowcnt=get<0>(tmp);
        REP(i,4){
            int nx=orix+dx[i];int ny=oriy+dy[i];
            if(nx<0||nx>h-1||ny<0||ny>w-1)continue;
            if(seen[nx][ny])continue;
            if(grid[nx][ny]=='#'){
                if(nowcnt<=1){
                    que.push(T(nowcnt+1,nx,ny));
                    seen[nx][ny]=true;
                }
                continue;
            }
            seen[nx][ny]=true;
            que.push(T(nowcnt,nx,ny));
        }
    }
}
signed main () {
    cin >> h >> w;
    grid.assign(h,vector<char>(w));
    seen.assign(h,vector<bool>(w,false));
    REP(i,h){
        string tmp;cin >> tmp;
        REP(j,w){
            grid[i][j]=tmp[j];
            if(tmp[j]=='s')sx=i,sy=j;
            if(tmp[j]=='g')ex=i,ey=j;
        }
    }
    seen[sx][sy]=true;
    dfs();
    if(seen[ex][ey])cout << "YES" << endl;
    else cout << "NO" << endl;
}