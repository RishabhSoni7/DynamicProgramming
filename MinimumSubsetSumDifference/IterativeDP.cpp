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
    int ans=0;
    for(int j=sum/2;j>=0;j--){
        if(dp[n][j]==1){
            ans=sum-(2*j);
            break;
        }
    }
    return ans;
}

int main(){
    int set[]={1,6,11,9};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
    int ans=subsetSum(set,n,sum);
    cout<<ans<<endl;
}