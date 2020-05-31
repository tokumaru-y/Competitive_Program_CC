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
vector<ll> calcdis;
vector<vector<pair<int,ll>>> inlist;

void dfs(int k,ll predis){
    auto nextpai = inlist[k];
    for(pair<int,ll> next : nextpai){
        int nextnode = next.first;
        ll dis = next.second;
        if(calcdis[nextnode]!=-1)continue;
        calcdis[nextnode] = predis + dis;
        dfs(nextnode,calcdis[nextnode]);
    }
}
signed main () {
    int n;cin >> n;
    inlist.assign(n,vector<pair<int,ll>>());
    REP(i,n-1){
        int a,b;ll c;cin >> a >> b >> c;
        a--;b--;
        inlist[a].push_back(make_pair(b,c));
        inlist[b].push_back(make_pair(a,c));
    }
    int q,k;cin >> q >> k;
    k--;
    calcdis.assign(n,-1);
    calcdis[k]=0;
    dfs(k,0);
    REP(i,q){
        int x,y;cin >> x >> y;
        x--;y--;
        ll ans = calcdis[x] + calcdis[y];
        cout << ans << endl;
    }
}//https://atcoder.jp/contests/abc070/tasks/abc070_d