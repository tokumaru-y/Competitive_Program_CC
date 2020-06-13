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
vector<ll> fib;
ll makeFib(int n){
    ll f1,f2;
    if(fib[n-1]!=INF)f1=fib[n-1];
    else f1=makeFib(n-1);
    if(fib[n-2]!=INF)f2=fib[n-2];
    else f2=makeFib(n-2);
    return fib[n]=f1+f2;
}
signed main () {
    ll k;cin >> k;
    fib.assign(45,INF);
    fib[0]=1;fib[1]=1;
    ll tmp = makeFib(44);
    cout << fib[k-1] << " " << fib[k] << endl;
}//https://atcoder.jp/contests/arc051/tasks/arc051_b