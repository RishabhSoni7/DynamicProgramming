#include<iostream>
#include<cmath>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){
    if(n<0||maxWeight<0){ //edge case
        return 0;
    }

    int** dp= new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[maxWeight+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWeight;j++){
            if(i==0||j==0){
                dp[i][j]=0;
                continue;
            }
            if(weights[i-1]<=j){
                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][maxWeight];
}

int main(){
    int weights[]={1,2,4,5};
    int values[]={5,4,8,6};
    int maxWeight=5;
    int ans=knapsack(weights,values,4,5);
    cout<<ans<<endl;
}