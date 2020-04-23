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
    int n,k;scanf("%d %d",&n,&k);
    vector<ll> list(n-1);vector<ll> path(k);ll mod = 100000;
    REP(i,n-1){
        ll tmp;scanf("%lld",&tmp);
        list[i]=tmp;
    }
    ll ans=0;
    vector<ll> cum(n);
    FOR(i,1,n){
        cum[i]=list[i-1] + cum[i-1];
    }
    int now = 0;
    REP(j,k){
        int tmp;scanf("%d",&tmp);
        int next = now + tmp;
        ans += abs(cum[now] - cum[next]);
        now = next;
        
    }
    printf("%lld\n",ans%mod);
}