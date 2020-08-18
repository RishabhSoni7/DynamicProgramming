#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int minimumCoins(int* coin, int n, int value){
    if(n<0||value<0){ //edge case
        return 0;
    }

    if(value==0){
        return 0;  //as number of coins asked
    }

    if(n==0){
        return INT_MAX-100;  //1+karenge to limit se exceed ho sakta hai
    }

    if(coin[n-1]<=value){
        int option1=1+minimumCoins(coin,n,value-coin[n-1]);
        int option2=minimumCoins(coin,n-1,value);
        return min(option1,option2);
    }else{
         return minimumCoins(coin,n-1,value);
    }

}

int main(){
    int coin[]={25,10,15};
    int n=3;
    int value=30;
    int ans=minimumCoins(coin,n,value);
    cout<<ans<<endl;
}