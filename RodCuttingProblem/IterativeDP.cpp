#include<iostream>
#include<cmath>
using namespace std;

int rodCutting(int* length, int* price, int n, int lengthOfRod){
    if(n<0||lengthOfRod<0){ //edge case
        return 0;
    }

    int** dp= new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[lengthOfRod+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=lengthOfRod;j++){
            if(i==0||j==0){
                dp[i][j]=0;
                continue;
            }
            if(length[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][lengthOfRod];
}

int main(){
    int length[]={1,2,3,4}; //length of rod //pieces in which they can be cut // can be variable not necessary 1 to length
    int price[]={5,4,8,6};
    int n=4; 
    int lengthOfRod=4;
    int ans=rodCutting(length,price,n,lengthOfRod);
    cout<<ans<<endl;
}