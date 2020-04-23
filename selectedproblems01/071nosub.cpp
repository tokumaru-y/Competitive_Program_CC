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

ll modpow(ll a, ll x, ll mod){
    ll res = 1;
    while(x>0){
        if(x&1)res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
};
signed main () {
    int n,m;scanf("%d %d",&n,&m);
    vector<int> city(n);vector<int> list(m);
    REP(i,n){
        SCANF(tmp);
        city[i]=tmp;
    }
    REP(i,m){
        SCANF(tmp);
        list[i]=tmp;
    }
    ll ans = 0 ; ll mod = 1000000007;
    vector<ll> dist(n+1,0);
    for(int h=1;h<=n;h++){
        dist[h] = dist[h-1] + modpow(city[h-1],city[h],mod);
    }
    int now = 0;
    REP(i,m){
        int from = now;int to = list[i];
        now=to;
        if(from>to)swap(from,to);
        ans += dist[to] - dist[from];
    }
    ans += dist[now];
    printf("%lld\n",ans);
}