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
    ll needred,needblue,red,blue,none;cin >> needred >> needblue >> red >> blue >> none;
    vector<ll> reds(red);vector<ll> blues(blue);vector<ll> nones(none);
    REP(i,red)cin >> reds[i];
    REP(i,blue)cin >> blues[i];
    REP(i,none)cin >> nones[i];
    sort(ALL(reds),greater<ll>());
    sort(ALL(blues),greater<ll>());
    sort(ALL(nones),greater<ll>());
    vector<ll> ans;
    REP(i,needred)ans.push_back(reds[i]);
    REP(i,needblue)ans.push_back(blues[i]);
    sort(ALL(ans));
    auto noneitr = nones.begin();
    REP(i,needred+needblue){
        if(ans[i]>=*noneitr)break;
        ans[i]=*noneitr;
        ++noneitr;
    }
    cout << accumulate(ALL(ans),0LL) << endl;
}
//https://atcoder.jp/contests/abc160/tasks/abc160_e