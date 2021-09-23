#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 10005
using namespace std;

class Job{
public:
    int s, e, v;
} J[MAXN];
int dp[MAXN];

bool cmp(const Job& j1, const Job& j2) {return j1.e < j2.e; }

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d %d", &J[i].s, &J[i].e, &J[i].v);
            J[i].e+=J[i].s;
        }
        sort(begin(J), begin(J)+n, cmp);
        dp[0] = J[0].v;
        for(int i = 1; i < n; ++i){
            Job tmp; tmp.e = J[i].s;
            int p = upper_bound(begin(J), begin(J)+i, tmp, cmp)-begin(J)-1;
            dp[i] = max(dp[i-1], (p<0 ? 0:dp[p])+J[i].v);
        }
        printf("%d\n", dp[n-1]);
    }
    return 0;
}