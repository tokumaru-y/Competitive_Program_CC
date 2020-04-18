#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int m;scanf("%d",&m);
    vector<vector<int>> cost(m+1,vector<int>(m+1));
    vector<int> p(m+1);
    FOR(i,1,m+1){
        int a,b;scanf("%d %d",&a,&b);
        p[i-1] = a;p[i]=b;
    }
    REP(i,m)cost[i][i] = 0;
    int min_cost;
    for (int l = 2; l <= m; l++) {  // 行列の個数
        for (int i = 1; i <= m - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                if (k == i) min_cost = cost[i][k] + cost[k+1][j] + p[i-1] * p[k] * p[j];
                else min_cost = min(min_cost, cost[i][k] + cost[k+1][j] + p[i-1] * p[k] * p[j]);
            }
            cost[i][j] = min_cost;
        }
    }
    cout << cost[1][m] << endl;
}