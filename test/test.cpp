#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
// using namespace std;

int MCM(int a[], int n){
    int dp[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j]=0;
        }
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<n-1; j++){
            int k = j+1;
            int min = 999999;
            for(int l=j; l<k; l++){
                if(dp[j][l]+dp[l+1][k]+a[j]*a[l+1]*a[k+1]<min){
                    min=dp[j][l]+dp[l+1][k]+a[j]*a[l+1]*a[k+1];
                }
            }
            dp[j][k]=min;
        }
    }
    return dp[0][n-1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=0; i<=n; i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",MCM(a,n));
    return 0;
}
