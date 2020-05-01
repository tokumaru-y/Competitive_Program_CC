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
vector<vector<bool>> seen;vector<vector<int>> vertical;vector<vector<int>> horizon;
bool check(int h,int w){
    int nh=horizon[h][w];
    if(w==0){
        if(nh==0)return true;
        return false;
    } else {
        if(nh==0&&vertical[h][w-1]==0)return true;
        return false;
    }
}
ll search(int h,int w,ll cnt){
    REP(i,4){
        int nh = h+dx[i];int nw = w+dy[i];
        if(nh<0||nh>=H||nw<0||nw>=W)continue;
        if(check(nh,nw)){
            seen[nh][nw]=true;
            search(nh,nw,cnt+1);
        }
    }
}
signed main () {
    while(cin >> W >> H){
        if(H+W==0)break;
        seen.assign(H,vector<bool>(W,false));
        vertical.assign(H,vector<int>(W-1));
        horizon.assign(H-1,vector<int>(W));
        REP(i,(H*2)-1){
            if(i%2==0){
                REP(j,W-1)cin >> vertical[i][j];
            } else {
                REP(j,W)cin >> horizon[i-1][j];
            }
        }
        ll ans;
        seen[0][0]=true;
        ans = search(0,0,1);
        cout << ans << endl;
    }
}