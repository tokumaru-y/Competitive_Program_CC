#include <bits/stdc++.h>
using namespace std;
int main () {
    string s,t;
    cin >> s;
    cin >> t;
    int dp[s.length()+1][t.length()+1]={};
    for(int i=0;i<s.length();i++){
        for(int j=0;j<t.length();j++){
            if(s[i]==t[j]){
                dp[i+1][j+1] > dp[i][j]+1?dp[i+1][j+1]=dp[i+1][j+1]:dp[i+1][j+1]=dp[i][j]+1;
            }
            dp[i+1][j+1] > dp[i+1][j] ? dp[i+1][j+1]=dp[i+1][j+1] :dp[i+1][j+1] = dp[i+1][j];
            dp[i+1][j+1] > dp[i][j+1] ? dp[i+1][j+1]=dp[i+1][j+1] :dp[i+1][j+1] =dp[i][j+1];
        }
    }
    string ans = "";
    int i=s.length();int j =t.length();
    while( i>0 && j>0) {
        if(dp[i][j] == dp[i-1][j]){
            --i;
        } else if (dp[i][j] == dp[i][j-1]){
            --j;
        } else {
            ans = s[i-1] + ans ;
            --i;--j;
        }
    }
    cout << ans << endl;
}