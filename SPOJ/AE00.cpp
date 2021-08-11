#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= (int)sqrt(i); ++j) if(i%j==0) ans++;
    }
    printf("%d", ans);
    return 0;
}