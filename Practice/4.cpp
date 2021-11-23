// https://atcoder.jp/contests/arc093/tasks/arc093_a
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
    int N;
    cin >> N;
    vector<int> A(N+2, 0);
    ll sum = 0;
    REP(i,N){
        cin >> A[i+1];
        sum += abs(A[i] - A[i+1]);
    }
    sum += abs(A[N]);
    for (int i=1;i<=N;i++){
        int dif = abs(A[i-1] - A[i]) + abs(A[i+1] - A[i]);
        int plus = abs(A[i-1] - A[i+1]);
        cout << sum - dif + plus << endl;
    }
}