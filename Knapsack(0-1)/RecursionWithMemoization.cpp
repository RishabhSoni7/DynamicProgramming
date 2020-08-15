#include<iostream>
#include<cmath>
#include <bits/stdc++.h> 
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight,int** dp){
    if(n<=0||maxWeight<=0){
        return 0;
    }
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    if(weights[n-1]<=maxWeight){
        int option1=values[n-1]+knapsack(weights,values,n-1,maxWeight-weights[n-1],dp);
        int option2=knapsack(weights,values,n-1,maxWeight,dp);
        dp[n][maxWeight]=max(option1,option2);
        return dp[n][maxWeight];
    }else{
        dp[n][maxWeight]=knapsack(weights,values,n-1,maxWeight,dp);
        return dp[n][maxWeight];
    }
}

int main(){
    int weights[]={1,2,4,5};
    int values[]={5,4,8,6};
    int maxWeight=5;
    int** dp= new int*[5];//n+1 where n is size
    for(int i=0;i<=4;i++){
        dp[i]=new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            dp[i][j]=-1;
        }
    }
    int ans=knapsack(weights,values,4,5,dp);
    cout<<ans<<endl;
}