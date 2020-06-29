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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int n;cin >> n;
    vector<ll> xlist(n);vector<ll> ylist(n);
    vector<vector<bool>> grid(5001,vector<bool>(5001,false));
    REP(i,n){
        ll a,b;cin >> a >> b;
        xlist[i]=a;ylist[i]=b;
        grid[a][b]=true;
    }
    ll ans = 0;
    REP(i,n)REP(j,n){
        int x1=xlist[i];int y1=ylist[i];
        int x2=xlist[j];int y2=ylist[j];
        int x3=x1+y2-y1;int y3=y1+x1-x2;
        int x4=x2+y2-y1;int y4=y2+x1-x2;
        ll s = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        if(x3<0 || x3>5000 || y3<0 || y3>5000)continue;
        if(x4<0 || x4>5000 || y4<0 || y4>5000)continue;
        if(grid[x3][y3] && grid[x4][y4])ans = max(ans,s);
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c