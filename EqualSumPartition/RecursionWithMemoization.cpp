#include<iostream>
#include<cmath>
using namespace std;

bool equalSumPartition(int* set, int n, int sum,int** dp){
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
        bool option1=equalSumPartition(set,n-1,sum-set[n-1],dp);
        bool option2=equalSumPartition(set,n-1,sum,dp);
        dp[n][sum]=option1||option2;
        return dp[n][sum];
    }else{
        dp[n][sum]=equalSumPartition(set,n-1,sum,dp);
        return dp[n][sum];
    }
}

int main(){
    int set[]={1,5,11,3};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
     if(sum%2!=0){
        cout<<"false";
        return 0;
    }
    int** dp= new int*[5];//n+1 where n is size   
    for(int i=0;i<=n;i++){
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++){
            dp[i][j]=-1;
        }
    }
    bool ans=equalSumPartition(set,n,sum/2,dp);
    cout<<ans<<endl;
}