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
ll extgcd(ll a, ll m) {
    long long b = m;ll u = 1;ll  v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

ll roop(ll x,ll m){
    ll cnt = 0;ll res = 1;
    while(x>0){
        res *= x;
        res %= m;
        x--;
    }
    return res;
}
signed main () {
    SCANF(N);SCANF(K);
    ll mod = 1000000007;
    ll a=roop(N-1+K,mod);ll b=roop(N-1,mod);ll c=roop((N-1+K)-(N-1),mod);
    ll div = extgcd(b*c,mod);
    printf("%lld\n",(a*div)%mod);
}