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
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    ll n;cin >> n;
    for(ll i=1;i<=3500;i++){
        for(ll j=1;j<=3500;j++){
            if((4*i*j-n*(i+j)==0) || (n*i*j)%(4*i*j-n*(i+j))!=0 )continue;
            ll tmp = (n*i*j)/(4*i*j-n*(i+j));
            if(tmp>=1){
                cout << i << " " << j << " " << tmp << endl;
                return 0;
            }
        }
    }
}//https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_c