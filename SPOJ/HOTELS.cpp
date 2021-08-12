#include <iostream>
using namespace std;

int a[300002];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int sum = 0, maxSum = 0;
    for(int i=0, j=0; i < n; ++i){
        scanf("%d", &a[i]);
        sum += a[i];
        while(sum > m) sum -= a[j++];
        maxSum = max(maxSum, sum);
    }
    printf("%d", maxSum);
    return 0;
}