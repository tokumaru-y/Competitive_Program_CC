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

signed main () {
    int n,m;scanf("%d %d",&n,&m);
    vector<vector<int>> list(n+4,vector<int>(n+4,0));
    REP(i,m){
        //座標(a,b),(a+c,b),(a+c,b+c)
        //斜めに和をとると０になるように
        int a,b,c;cin >> a >> b >> c;
        list[a][b]++;list[a][b+1]--;
        list[a+c+1][b]--;list[a+c+2][b+1]++;
        list[a+c+1][b+c+2]++;list[a+c+2][b+c+2]--;
    }
    //累積和の順番:横->縦->斜め[(0,0)=>(1,1)]の要領
    REP(i,n+3)REP(j,n+3){
        list[i+1][j+1]+=list[i+1][j];
    }
    REP(i,n+3)REP(j,n+3){
        list[i+1][j+1]+=list[i][j+1];
    }
    REP(i,n+3)REP(j,n+3){
        list[i+1][j+1]+=list[i][j];
    }
    ll ans=0;
    REP(i,n+4){
        REP(j,n+4){
            if(list[i][j]>0)ans++;
        }
    }
    cout << ans << endl;
}