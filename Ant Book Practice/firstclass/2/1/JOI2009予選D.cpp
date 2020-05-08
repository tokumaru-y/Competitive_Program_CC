#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
template<class TYPE> TYPE makepow(TYPE target, TYPE x){
    TYPE res = target;
    while(x>1){
        res *=target;
        x--;
    }
    return res;
}
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
    int n,k;cin >> n >> k;
    vector<bool> seen;
    seen.assign(100000000,false);
    vector<int> list(n);
    REP(i,n)cin >> list[i];
    int ans =0;
    sort(ALL(list));
    do{
        ll tmp =0;int digit = 0;
        REP(i,k){
            if(digit==0)tmp+=list[i];
            else tmp+=list[i]*makepow(10,digit);
            digit = log10(tmp)+1;
        }
        if(!seen[tmp])ans++;
        seen[tmp]=true;
    }while(next_permutation(ALL(list)));
    cout << ans << endl;
}