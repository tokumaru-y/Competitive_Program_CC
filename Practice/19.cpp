// https://atcoder.jp/contests/arc061/tasks/arc061_a
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
    string S;cin >> S;
    int size = S.size();
    ll ans = 0;
    for(int bit=0;bit<(1<<(size-1)); bit++){
        ll progrece_num = S[0]-'0';
        for(int i=0;i<size-1;i++){
            if (bit & (1<<i)){
                ans += progrece_num;
                progrece_num=0;
            }
            progrece_num = progrece_num*10 + S[i+1] - '0';
        }
        ans += progrece_num;
    }
    cout << ans << endl;
}