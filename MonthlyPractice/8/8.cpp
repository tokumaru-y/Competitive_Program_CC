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
    ll n;cin >> n;
    vector<ll> hen(n);
    REP(i,n)cin >> hen[i];
    ll ans=0;
    REP(i,n)FOR(j,i+1,n)FOR(k,j+1,n){
        if(hen[i] == hen[j] || hen[j] == hen[k] || hen[k] == hen[i])continue;
        ll x=hen[i]+hen[j];
        ll y=hen[j]+hen[k];
        ll z=hen[k]+hen[i];
        if(hen[i]<y && hen[j] < z && hen[k]<x)ans++;
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc175/tasks/abc175_b