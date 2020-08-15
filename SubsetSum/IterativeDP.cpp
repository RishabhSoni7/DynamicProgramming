#include<iostream>
#include<cmath>
using namespace std;

bool subsetSum(int* set, int n, int sum){
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
        for(int j=0;j<=sum;j++){
            if(sum==0){
                dp[i][sum]=1;
                continue;
            }
            if(i==0&&sum!=0){
                dp[i][j]=0;
                continue;
            }
            if(set[i-1]<=j){
                bool option1=dp[i-1][j-set[i-1]];
                bool option2=dp[i-1][j];
                dp[n][sum]=option1||option2;
            }else{
                dp[n][sum]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int set[]={3, 34, 4, 12, 5, 2};
    int sum=9;
    bool ans=subsetSum(set,6,sum);
    cout<<ans<<endl;
}