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
bool checkstr(int left, int right,string leftword,string rightword){
    if(leftword==rightword)return (right-left)%2==1;
    else return (right-left)%2==0;
}
signed main () {
    int n;cin >> n;
    string vac = "Vacant";
    int left = 0;int right=n/2;
    string leftword,rightword;
    cout << left << endl;cin >> leftword;
    if(leftword==vac)return 0;
    cout << right << endl;cin >> rightword;

    if(!checkstr(left,right,leftword,rightword)){
        swap(leftword,rightword),left=right;right=n;
    }
    string str;
    while(right-left>1){
        int mid=(right+left)/2;
        cout << mid << endl;
        cin >> str;
        if(str==vac)return 0;
        if(checkstr(left,mid,leftword,str))rightword=str,right=mid;        
        else leftword=str,left=mid;
    }
}//https://atcoder.jp/contests/apc001/tasks/apc001_c