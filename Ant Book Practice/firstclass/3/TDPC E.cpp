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
    ll d;string n;cin >> d >> n;
    ll nowmod = 1000000007;
    vector<vector<vector<ll>>> dp(n.length()+1,vector<vector<ll>>(d+1,vector<ll>(2,0)));
    dp[0][0][0]=1;
    for(int i=0;i<n.length();i++){
        int digit=n[i]-'0';
        for(ll j=0;j<=d;j++){
            for(int limit=0;limit<2;limit++){
                for(int v=0;v<=(limit?9:digit);v++){
                    ll modd=(j+v)%d;
                    dp[i+1][modd][limit || v<digit]+=dp[i][j][limit];
                    dp[i+1][modd][limit || v<digit]%=nowmod;
                }
            }
        }
    }
    cout << (dp[n.length()][0][0] + dp[n.length()][0][1] - 1)%nowmod << endl;
}