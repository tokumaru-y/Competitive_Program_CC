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
    vector<ll> mxlist(m);vector<ll> mylist(m);
    REP(i,m){
        ll a,b;cin >> a >> b;
        mxlist[i]=a;mylist[i]=b;
    }
    int n;cin >> n;
    vector<ll> nxlist(n);vector<ll> nylist(n);
    map<pair<ll,ll>,int> intlist;
    REP(i,n){
        ll a,b;cin >> a >> b;
        nxlist[i]=a;nylist[i]=b;
        intlist[make_pair(a,b)]++;
    }
    REP(i,m)REP(j,n){
        ll xdif=mxlist[i]-nxlist[j];
        ll ydif=mylist[i]-nylist[j];
        bool flag = true;
        REP(k,m){
            ll targetx=mxlist[k]-xdif;
            ll targety=mylist[k]-ydif;
            if(intlist[make_pair(targetx,targety)]==0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout << -xdif << " " << -ydif << endl;
            return 0;
        }
    }
}