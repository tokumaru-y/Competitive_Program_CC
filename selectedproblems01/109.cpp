#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
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

ll N,M;

vector<vector<ll>> matcalc(vector<vector<ll>> &A,vector<vector<ll>> &B){
    vector<vector<ll>> C(A.size(),vector<ll>(B[0].size(),0));
    for(ll i=0;i<A.size();i++){
        for(ll k =0;k<B.size();k++){
            for(ll j=0;j<B[0].size();j++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]) % M;
            }
        }
    }
    return C;
}

vector<vector<ll>> matpow(vector<vector<ll>> A, ll n){
    vector<vector<ll>> B(A.size(),vector<ll>(A.size(),0));
    //単位行列
    for(ll i=0;i<A.size();i++){
        B[i][i]=1;
    }
    n--;
    while(n>0){
        if(n&1)B = matcalc(B,A);
        A = matcalc(A,A);
        n >>=1;
    }
    return B;
}
signed main () {
    cin >> N >> M;
    vector<vector<ll>> mat(2,vector<ll>(2));
    mat[0][0]=1;mat[0][1]=1;mat[1][0]=1;mat[1][1]=0;
    mat = matpow(mat,N);
    cout << mat[1][0] << endl;
}