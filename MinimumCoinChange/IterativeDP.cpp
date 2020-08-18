#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int minimumCoins(int* coin, int n, int value){
    if(n<0||value<0){ //edge case
        return 0;
    }

    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[value+1];
    }

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<=value;j++){
        dp[0][j]=INT_MAX-1; //as INT_MAX+1 can exceed the int limit
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=value;j++){
            if(coin[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);          
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][value];

}

int main(){
    int coin[]={25,10,15};
    int n=3;
    int value=30;
    int ans=minimumCoins(coin,n,value);
    cout<<ans<<endl;
}