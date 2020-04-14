#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

const long long INF = 1LL << 60;
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
signed main () {
    ll n,m;scanf("%lld %lld",&n,&m);
    vector<ll> p(n+1);
    p[0]=0;
    for(int i = 1;i<n+1;i++){
        ll tmp;scanf("%lld",&tmp);
        p[i] = tmp;
    }
    vector<ll> sumlist1;
    int ind = 0;
    for(int i=0;i<n+1;i++){
        for(int j=i+1;j<n+1;j++){
            sumlist1.push_back(p[i] + p[j]);
        }
    }
    REP(i,(n+1)*(n+1)){
        printf("%lld ",sumlist1[i]);
    }
    sumlist1.push_back(0);
    sort(ALL(sumlist1));
    printf("%lld\n",n);
    ll ans = 0;
    for(int i=0;i<(n+1)*(n+1);i++){
        ll tmp = m - sumlist1[i];
        if(tmp<0)continue;
        int left = 0;int right = (n+1)*(n+1)-1;
        while(right-left>1){
            int middle = (left + right) /2;
            if(sumlist1[middle] + tmp > m){
                right = middle;
            } else {
                left = middle;
            }
        }
        ans = max(sumlist1[left],ans);
    }
    printf("%lld\n",ans);
}