#include<iostream>
#include<cmath>
using namespace std;

int subsetSum(int* set, int n, int sum){
    if(n<0||sum<0){ //edge case
        return 0;
    }
    if(sum==0){
        return 1; //empty set
    }
    if(n==0&&sum!=0){
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
            if(set[i-1]<=j){
                int option1=dp[i-1][j-set[i-1]];
                int option2=dp[i-1][j];
                dp[i][j]=option1||option2;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int set[]={3, 34, 4, 12, 5, 2};
    int n=6;
    int sum=9;
    int ans=subsetSum(set,n,sum);
    cout<<ans<<endl;
}