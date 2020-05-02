#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
#define SQUARE(x) ((x)*(x))
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
vector<int> a,b,c,d;
int N,M,Q;

ll calc(vector<int> numlist){
    ll res = 0;
    for(int i=0;i<Q;i++){
        if(numlist[b[i]] - numlist[a[i]]==c[i])res+=d[i];
    }
    return res;
}


void dfs(vector<int> &numlist, ll &res){
    if(numlist.size()==N+1){
        ll tmp = calc(numlist);
        res=max(res,tmp);
        return ;
    }
    int pushnum = numlist.back();
    for(int i=pushnum;i<=M;i++){
        numlist.push_back(i);
        dfs(numlist,res);
        numlist.pop_back();
    }
}

ll solve(){
    vector<int> numlist({1});
    ll res =0;
    dfs(numlist,res);
    return res;
}

int main () {
    cin >> N >> M >> Q ;
    a.resize(Q);b.resize(Q);c.resize(Q);d.resize(Q);
    REP(i,Q)cin >> a[i] >> b[i] >> c[i] >> d[i];
    cout << solve() << endl;
}