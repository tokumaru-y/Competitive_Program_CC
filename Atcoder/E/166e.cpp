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
    int n;cin >> n;
    vector<pair<int,ll>> list(n);
    vector<ll> sumlist(n);
    REP(i,n){
        ll a ;cin >> a;
        list[i]=make_pair(i+1,a);
        sumlist[i]=i+1+a;
    }
    sort(ALL(sumlist));
    ll ans =0;
    REP(i,n){
        pair<int,ll> tmp=list[i];
        int a=tmp.first;ll b=tmp.second;
        ll target=a-b;
        ll ind1= lower_bound(ALL(sumlist),target) - sumlist.end();
        ll ind2= upper_bound(ALL(sumlist),target) - sumlist.end();
        ans += ind2 - ind1;
    }
    cout << ans << endl;
}