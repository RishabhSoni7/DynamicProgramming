#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int minimumCoins(int* coin, int n, int sum){
    if(n<0||sum<0){ //edge case
        return 0;
    }

    if(sum==0){
        return 0;  //as number of coins asked
    }

    if(n==0){
        return INT_MAX-100;  //1+karenge to limit se exceed ho sakta hai
    }

    if(coin[n-1]<=sum){
        int option1=1+minimumCoins(coin,n,sum-coin[n-1]);
        int option2=minimumCoins(coin,n-1,sum);
        return min(option1,option2);
    }else{
         return minimumCoins(coin,n-1,sum);
    }

}

int main(){
    int coin[]={25,10,15};
    int n=3;
    int sum=30;
    int ans=minimumCoins(coin,n,sum);
    cout<<ans<<endl;
}