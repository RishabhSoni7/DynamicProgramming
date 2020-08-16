#include<iostream>
using namespace std;

int targetSumFunction(int* set, int n, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0&&sum!=0){
        return 0;
    }
    if(set[n-1]<=sum){
        int option1=targetSumFunction(set,n-1,sum-set[n-1]);
        int option2=targetSumFunction(set,n-1,sum);
        return option1+option2;
    }else{
        return targetSumFunction(set,n-1,sum);
    }
}

int main(){
    int set[]={1,1,2,3};
    int n=4;
    int targetSum=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
    int ans=targetSumFunction(set,n,(sum+targetSum)/2);
    cout<<ans<<endl;
}

