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
    ll n,k;cin >> n >> k;
    ll ans=0;
    vector<ll> list(n+1,0);vector<ll> sortlist(n+1,0);
    sortlist[0]=n;
    FOR(i,1,n+1){
        list[i]=list[i-1]+i;
        sortlist[i]=sortlist[i-1]+(n-i);
    }
    for(int i=k-1;i<=n;i++){
        ans+=sortlist[i]-list[i]+1;
        ans%=MOD;
    }
    cout << ans << endl;
}