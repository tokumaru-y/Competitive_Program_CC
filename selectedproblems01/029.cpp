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
signed main () {
    int h,w;scanf("%d %d",&h,&w);
    int sx,sy;scanf("%d %d",&sx,&sy);sx--;sy--;
    int gx,gy;scanf("%d %d",&gx,&gy);gx--;gy--;
    vector<string> g(h);
    vector<int> dx = {1,0,-1,0};vector<int> dy = {0,1,0,-1}; 
    REP(i,h){
        string inp;cin >> inp;
        g[i] = inp;
    }
    vector<vector<int>> ans(h,vector<int>(w,-1));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(sx,sy,0));ans[sx][sy]=0;
    while(!q.empty()){
        tuple<int,int,int> tmp = q.front();q.pop();
        int x = get<0>(tmp); int y = get<1>(tmp);int cnt = get<2>(tmp);
        for(int k=0;k<4;k++){
            int nx=x+dx[k];int ny=y+dy[k];
            if(nx<0 || nx>=h || ny < 0 || ny>=w)continue;
            if(g[nx][ny] == '.' && ans[nx][ny]==-1){
                ans[nx][ny] = cnt+1;
                q.push(make_tuple(nx,ny,cnt+1));
            }
        }
    }
    printf("%d\n",ans[gx][gy]);
}