// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
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
    int N,M;
    cin >> N >> M;
    vector<int> A(N,-1);
    REP(i,N)cin >> A[i];
    vector<ll> sum_list;
    REP(i,N){
        sum_list.push_back(A[i]);
        REP(j,N){
            ll tmp = A[i]+A[j];
            sum_list.push_back(tmp);
        }
    }
    sort(sum_list.begin(), sum_list.end());
    ll ans = 0;
    A.push_back(0);
    REP(i,N+1)REP(j,N+1){
        ll tmp = A[i]+A[j];
        ll num_left = M - tmp;
        if (num_left<0)continue;
        auto itr = lower_bound(sum_list.begin(), sum_list.end(),num_left);
        if (*itr > num_left && itr == sum_list.begin())continue;
        if (*itr > num_left)itr--;
        ans = max(ans, *itr+tmp);
    }
    cout << ans << endl;
}