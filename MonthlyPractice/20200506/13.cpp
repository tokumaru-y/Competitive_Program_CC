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
    vector<ll> x(n); vector<ll> y(n);
    REP(i,n){
        cin >> x[i] >> y[i] ;
    }
    ll ans=0;
    REP(i,n){
        REP(j,n){
            if(i==j)continue;
            ll p = x[j]-x[i];ll q = y[j]-y[i];
            ll tmp = 0;
            REP(s,n){
                REP(t,n){
                    if(x[t]-x[s]==p && y[t]-y[s]==q)tmp++;
                }
            }
            ans = max(ans,tmp);
        }
    }
    cout << n - ans << endl;
}//https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_b