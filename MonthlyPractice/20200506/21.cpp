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
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end(), greater<long long>());

    if (N % 2 == 0) {
        long long res = 0;
        for (int i = 0; i < N/2 - 1; ++i) res += A[i] * 2;
        res += A[N/2 - 1];
        res -= A[N/2];
        for (int i = N/2 + 1; i < N; ++i) res -= A[i] * 2;
        cout << res << endl;
    }
    else {
        long long res1 = 0;
        for (int i = 0; i < N/2 - 1; ++i) res1 += A[i] * 2;
        res1 += A[N/2 - 1] + A[N/2];
        for (int i = N/2 + 1; i < N; ++i) res1 -= A[i] * 2;
        
        long long res2 = 0;
        for (int i = 0; i < N/2; ++i) res2 += A[i] * 2;
        res2 -= A[N/2] + A[N/2 + 1];
        for (int i = N/2 + 2; i < N; ++i) res2 -= A[i] * 2;
        cout << max(res1, res2) << endl;
    }
}//https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c