#include<iostream>
#include<cmath>
using namespace std;

int coinChangeNumberOfWays(int* coin, int n, int sum){
    if(n<0||sum<0){ //edge case
        return 0;
    }

    if(sum==0){
        return 1;
    }

    if(n==0){
        return 0;
    }

    int** dp= new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
    }

    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=sum;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j){
                dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int coin[]={1,2,3};
    int n=3;
    int sum=4;
    int ans=coinChangeNumberOfWays(coin,n,sum);
    cout<<ans<<endl;
}