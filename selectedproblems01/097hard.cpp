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

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return (a * b) / gcd(a,b);
}
signed main () {
    ll n,m;scanf("%lld %lld",&n,&m);
    vector<ll> list(n);
    REP(i,n){
        ll tmp;scanf("%lld",&tmp);
        list[i]=tmp/2;
    }
    while(list[0]%2==0){
        REP(i,n){
            if(list[i]%2!=0){
                cout << 0 << endl;
                exit(0);
            };
            list[i]/=2;
        }
        m/=2;
    }
    REP(i,n){
        if(list[i]%2==0){
            cout << 0 << endl;
            exit(0);
        }
    }
    ll div = 1;
    REP(i,n){
        div = lcm(div,list[i]);
    }
    ll ans = ((m/div)+1)/2;
    printf("%lld\n",ans);
}