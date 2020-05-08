#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
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
    ll d,g;cin >> d >> g;
    vector<pair<ll,ll>> score(d);
    REP(i,d){
        ll a;ll b;
        cin >> a >> b;
        score[i]=make_pair(a,b);
    }
    ll ans = 10000;
    for(ll i=0;i<(1<<d);i++){
        ll tmpsum = 0;ll cnt =0;
        for(ll j=0;j<d;j++){
            if(i&(1<<j)){
                pair<ll ,ll> aaa=score[j];
                ll leftcnt = aaa.first;ll allsum = aaa.second;
                tmpsum += ((j+1)*leftcnt*100 + allsum);
                cnt+=leftcnt;
            }
        }
        if(tmpsum<g){
            for(ll j=d-1;j>=0;j--){
                if(!(i&(1<<j))){
                    pair<ll,ll> aaa=score[j];
                    ll leftcnt = aaa.first;
                    ll need=g-tmpsum;
                    if(need>((j+1)*100*leftcnt))continue;
                    while(tmpsum<g){
                        tmpsum+=(j+1)*100;
                        cnt++;
                    }
                }
            }
        }
        if(tmpsum>=g)ans = min(ans,cnt);
        //cout << ans << " " << cnt << "ggg" << i << endl;
    }
    cout << ans << endl;
}