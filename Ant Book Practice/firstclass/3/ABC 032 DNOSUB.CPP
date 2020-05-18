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
    ll n,w;cin >> n >> w;
    if(n<=30){
        //vector<ll> values(n);vector<ll> weights(n);
        vector<pair<ll,ll>> half;
        vector<pair<ll,ll>> afterhalf;
        ll halfindex = n / 2;
        map<ll,ll> halftable;
        REP(i,halfindex){
            ll a,b;cin >> a >> b;
            half.push_back(make_pair(b,a));
            if(halftable.count(b)==0){
                halftable[b]=a;
            } else {
                halftable[b]=max(halftable[b],a);
            }
        }
        REP(i,n-halfindex){
            ll a,b;cin >> a >> b;
            afterhalf.push_back(make_pair(b,a));
        }
        sort(ALL(half));
        ll ans = 0;
        for(auto pobject : afterhalf){
            ll weight=pobject.first;ll value=pobject.second;
            ll left = w - weight;
            if(left<0)continue;
            auto itr = lower_bound(ALL(half),left);
            while(itr!=half.end()){
                value+=halftable[(*itr).second];
                left-=
            }

        }
    } else {

    }
}