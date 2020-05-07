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
int h,w;vector<vector<char>> grid;
int ans = 0;ll nowcnt=0;
using T = tuple<int,int,int>;
queue<T> que;
void dfs(){
    while(!que.empty()){
        T tmp=que.front();que.pop();
        int orix = get<0>(tmp);int oriy = get<1>(tmp);int tmpcnt = get<2>(tmp);
        REP(k,4){
            int nx=orix+dx[k];int ny=oriy+dy[k];
            if(nx<0||nx>h-1||ny<0||ny>w-1)continue;
            if(grid[nx][ny]=='#')continue;
            grid[nx][ny]='#';
            ans = max(ans,tmpcnt);
            que.push(T(nx,ny,tmpcnt+1));
        }
    }
}
signed main () {
    cin >> h >> w;
    grid.assign(h,vector<char>(w));
    REP(i,h){
        string tmp;cin >> tmp;
        REP(j,w){
            grid[i][j]=tmp[j];
            if(tmp[j]=='#')que.push(T(i,j,1));
        }
    }
    dfs();
    cout << ans << endl;
}