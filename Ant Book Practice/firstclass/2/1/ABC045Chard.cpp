#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,n) for(ll i=0;i < (n);i++)
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
    string s;cin >> s;
    ll ans = 0;
    for(ll i=0;i<(1<<s.size()-1);i++){
        ll tmp=s[0]-'0';
        for(ll j=0;j<(s.size()-1);j++){
            if(i&(1<<j)){
                ans += tmp;
                tmp = 0;
            }
            tmp = tmp*10 + (s[j+1]-'0');
        }
        ans +=tmp;
    }
    cout << ans << endl;
}