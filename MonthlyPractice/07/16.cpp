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
    ll n,m,k;cin >> n >> m >> k;
    vector<ll> alist(n+1,0);
    vector<ll> blist(m+1,0);
    REP(i,n){
        ll tmp;cin >> tmp;
        alist[i+1]=alist[i]+tmp;
    }
    REP(i,m){
        ll tmp;cin >> tmp;
        blist[i+1]=blist[i]+tmp;
    }
    ll ans=0;
    REP(i,n+1){
        ll target=alist[i];
        if(k-target<0)continue;
        auto bitr=upper_bound(ALL(blist),k-target);
        ll cnt=bitr - blist.begin()-1;
        ans=max(ans,cnt+i);
    }
    REP(i,m+1){
        ll target=blist[i];
        if(k-target<0)continue;
        auto aitr=upper_bound(ALL(alist),k-target);
        ll cnt=aitr-alist.begin()-1;
        ans=max(ans,cnt+i);
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc172/tasks/abc172_c