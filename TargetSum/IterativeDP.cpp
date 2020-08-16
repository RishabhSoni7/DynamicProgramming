#include<iostream>
using namespace std;

int targetSumFunc(int* set, int n, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0&&sum!=0){
        return 0;
    }

    int** dp=new int*[n+1];
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
            if(set[i-1]<=j){
                dp[i][j]=dp[i-1][j-set[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int set[]={1,1,2,3};
    int n=4;
    int targetSum=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
    int ans=targetSumFunc(set,n,(sum+targetSum)/2);
    cout<<ans<<endl;
}

