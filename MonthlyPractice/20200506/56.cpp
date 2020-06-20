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
    ll n;cin >> n;int cnt = 0;vector<ll> ans;
    for(ll i=max(n - 160,(ll)0);i<=n;i++){
        string num = to_string(i);
        ll tmp = 0;
        for(char t : num){
            tmp+=t - '0';
        }
        if(tmp+i==n)ans.push_back(i),cnt++;
    }
    cout << cnt << endl;
    for(ll a : ans)cout << a << endl;
}//https://atcoder.jp/contests/arc034/tasks/arc034_2