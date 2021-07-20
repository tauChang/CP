#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define AC ios::sync_with_stdio(0),cin.tie(0);

ll solve(string& s){
    int n = s.length();
    ll dp[3] = {0};
    dp[n%3]=1;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == '0') dp[i%3] = 0;
        else if(i+1 < n && s[i+1] == '0') dp[i%3] = dp[(i+2)%3];
        else if(s[i] == '1' || (s[i] == '2' && i+1 < n && s[i+1]-'0'<=6)) dp[i%3] = dp[(i+1)%3] + dp[(i+2)%3];
        else dp[i%3] = dp[(i+1)%3];
    }
    return dp[0];
}

int main(){
    string s;
    while(cin >> s){
        if(s[0] == '0') break;
        cout << solve(s) << endl;
    }
    return 0;
}