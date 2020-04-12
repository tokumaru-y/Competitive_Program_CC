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
    vector<int> list(n);
    REP(i,n){
        int tmp;scanf("%d",&tmp);
        list[i]= tmp;
    }
    int q;scanf("%d",&q);
    vector<bool> sumTable(400001,false);
    for(int i=0;i<(1<<n);i++){
        int tmp_sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))tmp_sum+=list[j];
        }
        sumTable[tmp_sum]=true;
    }
    REP(i,q){
        int target;scanf("%d",&target);
        if(sumTable[target]){
            printf("yes\n");
        } else{
            printf("no\n");
        }
    }
    
}