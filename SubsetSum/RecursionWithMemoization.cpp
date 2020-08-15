#include<iostream>
#include<cmath>
using namespace std;

bool subsetSum(int* set, int n, int sum,int** dp){
    if(n<0||sum<0){ //edge case
        return false;
    }
    if(sum==0){
        return true; //empty set
    }
    if(n==0&&sum!=0){
        return false;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }

    if(set[n-1]<=sum){
        bool option1=subsetSum(set,n-1,sum-set[n-1],dp);
        bool option2=subsetSum(set,n-1,sum,dp);
        dp[n][sum]=option1||option2;
        return dp[n][sum];
    }else{
        dp[n][sum]=subsetSum(set,n-1,sum,dp);
        return dp[n][sum];
    }
}

int main(){
    int set[]={3, 34, 4, 12, 5, 2};
    int sum=9;
    int** dp= new int*[7];//n+1 where n is size
    for(int i=0;i<=7;i++){
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++){
            dp[i][j]=-1;
        }
    }
    bool ans=subsetSum(set,6,sum,dp);
    cout<<ans<<endl;
}