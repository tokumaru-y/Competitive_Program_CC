#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,n) for(ll i=0;i < (n);i++)
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
    ll n;cin >> n;
    vector<ll> tako(n);
    REP(i,n)cin >> tako[i];
    ll ans = 0;
    ll sum = 0;
    REP(i,n){
        sum += tako[i];
        sum %= MOD;
    }
    REP(i,n-1){
        sum -= tako[i];
        if(sum < 0)sum+=MOD; // ここがないとうまく回らない。
        ans += (sum* tako[i])%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc177/tasks/abc177_c