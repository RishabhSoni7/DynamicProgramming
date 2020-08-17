#include<iostream>
#include<cmath>
using namespace std;

int minSubsetSumDiff(int* set, int n, int s1, int s2, int**dp){
    if(n==0){
        dp[n][abs(s1-s2)]=abs(s1-s2);
        return dp[n][abs(s1-s2)];
    }

    if(dp[n][abs(s1-s2)]!=-1){
        return dp[n][abs(s1-s2)];
    }

    int option1=minSubsetSumDiff(set,n-1,s1+set[n-1],s2,dp);
    int option2=minSubsetSumDiff(set,n-1,s1,s2+set[n-1],dp);
    dp[n][abs(s1-s2)]=min(option1,option2);
    return  dp[n][abs(s1-s2)];
}

int main(){
    int set[]={1,6,11,8};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
    int** dp= new int*[n+1];//n+1 where n is size
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++){
            dp[i][j]=-1;
        }
    }
    int ans=minSubsetSumDiff(set,n,0,0,dp);
    cout<<ans<<endl;
}