#include<iostream>
using namespace std;

int countSubsetSumDiff(int* set, int n, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0&&sum!=0){
        return 0;
    }
    if(set[n-1]<=sum){
        int option1=countSubsetSumDiff(set,n-1,sum-set[n-1]);
        int option2=countSubsetSumDiff(set,n-1,sum);
        return option1+option2;
    }else{
        return countSubsetSumDiff(set,n-1,sum);
    }
}

int main(){
    int set[]={1,1,2,3};
    int n=4;
    int diff=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=set[i];
    }
    int ans=countSubsetSumDiff(set,n,(sum+diff)/2);
    cout<<ans<<endl;
}

