#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

const long long INF = 1LL << 60;
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
int w,h;
vector<vector<int>> grid;
vector<vector<bool>> seen;
vector<int> dx={1,0,-1,0};vector<int> dy={0,1,0,-1};
int dfs(int i,int j, int& cnt){
    cnt++;
    int res= cnt;
    for(int q=0;q<4;q++){
        int x = dx[q]+i;int y = dy[q]+j;
        if(x<0 || x >=h || y < 0 || y >= w)continue;
        if(grid[x][y]==1 && !seen[x][y]){
            seen[x][y] = true;
            res = dfs(x,y,cnt);
        }
    }
    cnt--;
    return res;
}
signed main () {
    scanf("%d",&w);scanf("%d",&h);
    grid.assign(h,vector<int>(w,0));
    REP(i,h){
        REP(j,w){
            int tmp;scanf("%d",&tmp);
            grid[i][j]=tmp;
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]==1){
                int cnt = 0;
                seen.assign(h,vector<bool>(w,false));
                seen[i][j] = true;
                ans = max(ans,dfs(i,j,cnt));
            }
        }
    }
    printf("%d\n",ans);
}