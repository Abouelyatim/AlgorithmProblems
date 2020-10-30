#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define min(a, b) ((a < b) ? a : b)
int n = 9999;//nb element
int S[10000];//tab des elements
int INF = 1e9;
int dp[10000][10000];


int go(int id, int sum) {
    if (dp[id][sum] != -1) {
        return dp[id][sum];
    }
    if (sum == 0 && id == 0) {
        return 0;
    }
    if (id == 0) {
        return INF;
    }
    int ans;
    if (sum >= S[id])
        ans = min(go(id - 1, sum), go(id - 1, sum - S[id]) + 1);
        //ans=go(id - 1, sum)||(go(id - 1, sum - S[id]) + 1);
    else {
        ans = go(id - 1, sum);
    }
    dp[id][sum] = ans;
    return ans;
}
int main()
{
    int i;
    for (i = 0; i < n; i++) {
        //S[i] = i + 1;
        S[i] = rand();
    }
    memset(dp, -1, sizeof dp);
    int sum = 3500;
    /*for (i = 0; i < n; i++) {
        printf("%d ", S[i]);
    }*/
    printf("\n");
    clock_t begin =clock();
    long long ans = go(n, sum);
    clock_t end =clock();
	clock_t tempExec = (double) (end-begin)*1000/CLOCKS_PER_SEC;
    if (ans == INF) {
        printf("nest pas trouve\n");
    } else {
        printf("minimum subset: %d ,time: %d ms", ans,tempExec);
        
    }
    return 0;
}
