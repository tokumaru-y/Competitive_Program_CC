#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
#define VECTOR(a,b,c,name) vector<vector<vector<double>>>(name)((a),vector<vector<double>>((b),vector<double>((c),0.0)))
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
    ll n,d;cin >> n >> d;
    vector<int> numcnt;
    int numlist[3]={2,3,5};
    for(int i : numlist){
        int tmpcnt =0;
        while(d%i==0){
            d/=i;
            tmpcnt++;
        }
        numcnt.push_back(tmpcnt);
    }
    if(d!=1){
        cout << 0 << endl;
        exit(0);
    }
    vector<vector<vector<double>>>dp(numcnt[0]+1,vector<vector<double>>(numcnt[1]+1,vector<double>(numcnt[2]+1,0.0)));
    dp[0][0][0]=1;
    int xnum[6] = {0,1,0,2,0,1};
    int ynum[6] = {0,0,1,0,0,1};
    int znum[6] = {0,0,0,0,1,0};
    REP(i,n){
        vector<vector<vector<double>>>tmpdp(numcnt[0]+1,vector<vector<double>>(numcnt[1]+1,vector<double>(numcnt[2]+1,0.0)));
        REP(x,numcnt[0]+1)REP(y,numcnt[1]+1)REP(z,numcnt[2]+1){
            REP(j,6){
                int nx=min(numcnt[0],x+xnum[j]);
                int ny=min(numcnt[1],y+ynum[j]);
                int nz=min(numcnt[2],z+znum[j]);
                tmpdp[nx][ny][nz]+=dp[x][y][z]/6;
            }
        }
        dp=tmpdp;
    }
    printf("%.10lf\n",dp[numcnt[0]][numcnt[1]][numcnt[2]]);
}