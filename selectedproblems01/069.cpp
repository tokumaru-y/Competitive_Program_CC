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

signed main () {
    vector<bool> prime(100001,true);
    prime[0]=false;prime[1]=false;
    for(int i=2;i*i<=100000;i++){
        if(prime[i]){
            int tmp = i+i;
            while(tmp<=100000){
                prime[tmp]=false;
                tmp+=i;
            }
        }
    }
    vector<int> cnt(100010,0);
    for(int i=3;i<=100001;i+=2){
        if(prime[i] && prime[(i+1)/2])cnt[i] = cnt[i-2] + 1;
        else cnt[i]=cnt[i-2];
    }
    int q;scanf("%d",&q);
    REP(i,q){
        int a,b;scanf("%d %d",&a,&b);
        printf("%d\n",cnt[b] - cnt[a-2]);
    }
}