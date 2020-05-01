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
int H,W;
vector<vector<bool>> seen;vector<vector<ll>> grid;
int dxe[]={-1,0,1,1,1,0};
int dxo[]={-1,-1,0,1,0,-1};
int ody[]={0,-1,-1,0,1,1};
ll check(int w,int h){
    int cntsum=0;
    if(w%2==1){
        REP(i,6){
            int nw=w+ody[i];int nh=h+dxe[i];
            if(nw<0||nw>W+1||nh<0||nh>H+1)continue;
            if(grid[nw][nh]==1)cntsum++;
        }
        REP(i,6){
            int nw=w+ody[i];int nh=h+dxe[i];
            if(nw<0||nw>W+1||nh<0||nh>H+1)continue;
            if(!seen[nw][nh]&&grid[nw][nh]==0)seen[nw][nh]=true,cntsum += check(nw,nh);
        }
    } else {
        REP(i,6){
            int nw=w+ody[i];int nh=h+dxo[i];
            if(nw<0||nw>W+1||nh<0||nh>H+1)continue;
            if(grid[nw][nh]==1)cntsum++;
        }
        REP(i,6){
            int nw=w+ody[i];int nh=h+dxo[i];
            if(nw<0||nw>W+1||nh<0||nh>H+1)continue;
            if(!seen[nw][nh]&&grid[nw][nh]==0)seen[nw][nh]=true,cntsum += check(nw,nh);
        }
    }
    return cntsum;
}

signed main () {
    cin >> H >> W;
    seen.assign(W+2,vector<bool>(H+2,0));
    grid.assign(W+2,vector<ll>(H+2,0));
    FOR(i,1,W+1){
        FOR(j,1,H+1){
            cin >> grid[i][j];
        }
    }
    ll ans=0;
    seen[0][0]=true,ans=check(0,0);
    cout << ans << endl;
}