#include<iostream>
#include<cmath>
using namespace std;

int coinChangeNumberOfWays(int* coin, int n, int sum){
    if(n<0||sum<0){ //edge case
        return 0;
    }

    if(sum==0){
        return 1;
    }

    if(n==0){
        return 0;
    }

    if(coin[n-1]<=sum){
        int option1=coinChangeNumberOfWays(coin,n,sum-coin[n-1]);
        int option2=coinChangeNumberOfWays(coin,n-1,sum);
        return option1+option2;
    }else{
         return coinChangeNumberOfWays(coin,n-1,sum);
    }

}

int main(){
    int coin[]={1,2,3};
    int n=3;
    int sum=4;
    int ans=coinChangeNumberOfWays(coin,n,sum);
    cout<<ans<<endl;
}