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
vector<ll> deepth;
ll ans = 0;

signed main () {
    int n;cin >> n;n++;
    deepth.resize(n);
    vector<ll> maxdeepth(n);
    ll cnt = 1;
    REP(i,n){
        ll tmp ;cin >> tmp;
        if(i==0&&tmp!=0){
            cout << -1 << endl; return 0;
        }
        deepth[i]=tmp;
        maxdeepth[i]=cnt;
        cnt*=2;
    }
    ll ans = 0;ll pre = 0 ;
    for(int i=n-1;i>=0;i--){
        if(maxdeepth[i]<deepth[i]){
            cout << -1 << endl;return 0;
        }
        if(i==n-1)ans+=deepth[i],pre=deepth[i];
        else if(i==0)ans++;
        else {
            if(deepth[i]==0)ans+=pre;
            else{
                ll mina=deepth[i]+ceil(pre/2);
                if(pre%2==0)mina--;
                pre=mina+deepth[i];
                ans += mina + deepth[i];
            }
/*             ll canma = deepth[i+1]+(ll)ceil(deepth[i]/2);
            ll upcan = (maxdeepth[i-1]-deepth[i-1])*2;
            cout << canma << endl;
            if(canma>upcan){
                cout << -1 << endl;return 0;
            } else {
                ans+=canma;
            }
 */        }
    }
    cout << ans << endl;
}