#include<iostream>
#include<cmath>
using namespace std;

bool equalSumPartition(int* set, int n, int sum){
    if(n<0||sum<0){ //edge case
        return false;
    }
    if(sum==0){
        return true; //empty set
    }
    if(n==0&&sum!=0){
        return false;
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
                bool option1=dp[i-1][j-set[i-1]];
                bool option2=dp[i-1][j];
                dp[i][j]=option1||option2;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
      for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
      }
    return dp[n][sum];
}

int main(){
    int set[]={3, 26, 4, 12, 5, 2};
    int n=6;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
    if(sum%2!=0){
        cout<<"false";
        return 0;
    }
    bool ans=equalSumPartition(set,n,sum/2);
    cout<<ans<<endl;
}