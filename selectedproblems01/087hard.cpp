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
struct UF{
    vector<ll> par;vector<ll> deepth;
    UF(int n): par(n),deepth(n,1){
        REP(i,n)par[i]=i;
    }
    ll root(ll x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }
    bool same(ll x,ll y){
        ll rx=root(x);ll ry=root(y);
        return rx==ry;
    }
    void unite(ll x,ll y){
        ll rx=root(x);ll ry=root(y);
        if(rx==ry)return;
        deepth[rx]+=deepth[ry];
        deepth[ry]=deepth[rx];
        par[ry]=rx;
    }
    ll resnum(ll x){
        ll rx=root(x);
        return deepth[rx];
    }
};

signed main() {
    ll n,m;scanf("%lld %lld",&n,&m);
    vector<ll> ans(m);vector<pair<ll,ll>> inlist(m);
    REP(i,m){
        ll a,b;scanf("%lld %lld",&a,&b);
        a--;b--;
        inlist[i]=make_pair(a,b);
    }
    ll tmpsum = (n*(n-1))/2;
    UF tree(n);
    for(ll i=m-1;i>=0;i--){
        P tmp = inlist[i];
        ll a = tmp.first;ll b = tmp.second;
        ll minus=0;
        ans[i]=tmpsum;
        if(!tree.same(a,b)){
            minus = tree.resnum(a) * tree.resnum(b);
            tree.unite(a,b);
        }
        tmpsum-=minus;
    }
    //reverse(ALL(ans));
    for(ll out : ans)printf("%lld\n",out);
}