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
    vector<ll> alist(n);vector<ll> blist(n);
    REP(i,n){
        ll s,t;cin >> s >> t;
        alist[i]=s;blist[i]=t;
    }
    ll ans = INF;
    REP(i,n)REP(j,n){
        ll tmpsum = 0;
        ll sta = alist[i];ll en = blist[j];
        REP(k,n){
            tmpsum += abs(sta-alist[k])+abs(alist[k]-blist[k])+abs(blist[k]-en);
        }
        ans = min(ans,tmpsum);
    }
    cout << ans << endl;
}