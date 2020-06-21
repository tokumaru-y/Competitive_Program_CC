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
    vector<ll> inlist(n);
    REP(i,n){
        cin >> inlist[i];
    }
    vector<ll> numlist(n);
    map<ll,int> cnt;
    REP(i,n){
        int s = i+1;
        numlist[i]=s-inlist[i];
        cnt[s+inlist[i]]++;
    }
    sort(ALL(numlist));
    ll ans = 0;
    ll rowcnt = 0;
    REP(i,n){
        ans+=cnt[numlist[i]];
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc166/tasks/abc166_e