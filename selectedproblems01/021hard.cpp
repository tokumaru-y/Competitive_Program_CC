#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

const long long INF = 1LL << 60;
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
ll n;vector<ll> h;vector<ll> s;

ll check(ll middle){
    vector<int> count(n,0);
    REP(i,n){
        if(h[i]>middle){
            return false;
        } else {
            count[min(n-1,(middle-h[i])/s[i])]++;
        }
    }
    REP(i,n-1)count[i+1]+=count[i];
    REP(j,n){
        if(count[j]>j+1)return false ;
    }
    return true;
}

signed main () {
    scanf("%lld",&n);
    REP(i,n){
        ll a,b;scanf("%lld %lld",&a,&b);
        h.push_back(a);s.push_back(b);
    }
    ll l = -1, r = 1e18;
    while(r-l>1){
        ll middle = (r+l)/2;
        if(check(middle)){
            r=middle;
        } else {
            l=middle;
        }
    }
    printf("%lld\n",r);
}