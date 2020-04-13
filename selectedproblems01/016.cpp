#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
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
signed main () {
    int n;scanf("%d",&n);
    vector<int> P(n);vector<int> Q(n);
    REP(i,n){
        int tmp;scanf("%d",&tmp);
        P[i]=tmp;
    }
    REP(i,n){
        int tmp;scanf("%d",&tmp);
        Q[i]=tmp;
    }
    vector<int> base(n);
    REP(i,n)base[i]=i+1;
    int a,b;
    int cnt=0;
    do{
        cnt++;
        vector<int> tmp(n);
        for(int i=0;i<n;i++){
            tmp[i]=base[i];
        }
        if(tmp==P)a=cnt;
        if(tmp==Q)b=cnt;
    }while(next_permutation(base.begin(),base.end()));
    int ans=abs(a-b);
    printf("%d",ans);
}