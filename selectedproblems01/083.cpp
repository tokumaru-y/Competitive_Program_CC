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
    int n,m;scanf("%d %d",&n,&m);
    vector<int> list(m,0);
    vector<int> cum(n+1,0);
    REP(i,m){
        SCANF(tmp);
        list[i]=tmp;
    }
    REP(i,m-1){
        int a=max(list[i],list[i+1]);
        int b=min(list[i],list[i+1]);
        cum[b] +=1;cum[a] -= 1;
    }
    FOR(i,1,n+1)cum[i]+=cum[i-1];
    ll ans = 0;
    REP(i,n-1){
        ll a,b,c;scanf("%lld %lld %lld",&a,&b,&c);
        ll sum1=a*cum[i+1];ll sum2=c+b*cum[i+1];
        ans += min(sum1,sum2);
    }
    printf("%lld\n",ans);
}