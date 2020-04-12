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
    int towns;scanf("%d",&towns);
    vector<vector<double>> list(towns,vector<double>(2));
    REP(i,towns){
        double a,b;scanf("%lf %lf",&a,&b);
        list[i][0]=a;list[i][1]=b;
    }
    double ans = 0;
    int div = 1;
    for(int i = 2;i<=towns;i++){
        div *= i;
    }
    vector<int> tmp(towns);
    for(int i=0;i<towns;i++)tmp[i] = i;
    do{
        for(int i=0;i<towns-1;i++){
            ans += pow((list[tmp[i]][0]-list[tmp[i+1]][0])*(list[tmp[i]][0]-list[tmp[i+1]][0]) + (list[tmp[i]][1]-list[tmp[i+1]][1])*(list[tmp[i]][1]-list[tmp[i+1]][1]), 0.5);
        }
    }while(next_permutation(tmp.begin(),tmp.end()));
    printf("%f",ans/div);
}