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
    int m;cin >> m;
    vector<ll> mx(m);vector<ll> my(m);
    map<pair<ll,ll>,int> nmap;
    REP(i,m){
        ll a,b;cin >> a >>b;
        mx[i]=a;my[i]=b;
    }
    int n;cin >> n;
    vector<ll> nx(n);vector<ll> ny(n);
    REP(i,n){
        ll a,b;cin >> a >> b;
        nx[i]=a;ny[i]=b;
        nmap[make_pair(a,b)]++;
    }

    REP(i,m)REP(j,n){
        ll xdif=(nx[j]-mx[i]); ll ydif=(ny[j]-my[i]);
        bool flag = true;
        REP(k,m){
            pair<ll,ll> tmp = make_pair(xdif+mx[k],ydif+my[k]);
            if(!nmap[tmp]){
                flag =false;
            }
        }
        if(flag){
            cout << xdif << " " << ydif << endl;
            return 0;
        }
    }
}//https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d