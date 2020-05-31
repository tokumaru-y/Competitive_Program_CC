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
    int h,w;cin >> h >> w;
    int n;cin >> n;
    vector<int> cnts(n);
    REP(i,n)cin >> cnts[i];

    vector<vector<int>> ans(h,vector<int>(w));
    int color=1;int cnt=0;
    REP(i,h){
        if(i%2==0){
            REP(j,w){
                ans[i][j]=color;
                cnt++;
                if(cnts[color-1]==cnt)cnt=0,color++;
            }
        } else {
            for(int j=w-1;j>=0;j--){
                ans[i][j]=color;
                cnt++;
                if(cnts[color-1]==cnt)cnt=0,color++;
            }
        }
    }
    REP(i,h){
        REP(j,w){
            cout << ans[i][j];
            if(j!=w-1)cout << " ";
        }
        cout << endl;
    }
}//https://atcoder.jp/contests/arc080/tasks/arc080_b