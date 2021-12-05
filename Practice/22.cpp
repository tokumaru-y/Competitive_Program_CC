// https://atcoder.jp/contests/arc029/tasks/arc029_1
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int N;cin >> N;
    vector<int> T(N,-1);
    REP(i,N)cin >> T[i];
    int ans = IINF;
    for(int bit=0;bit<(1<<N);bit++){
        int sum1=0;
        int sum2=0;
        for(int i=0;i<N;i++){
            if (bit&(1<<i))sum1+=T[i];
            else sum2+=T[i];
        }
        ans = min(ans, max(sum1,sum2));
    }
    cout << ans << endl;
}