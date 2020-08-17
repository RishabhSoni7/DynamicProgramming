#include<iostream>
#include<cmath>
using namespace std;

int minSubsetSumDiff(int* set, int n, int s1, int s2){
    if(n==0){
        return abs(s1-s2);
    }

    int option1=minSubsetSumDiff(set,n-1,s1+set[n-1],s2);
    int option2=minSubsetSumDiff(set,n-1,s1,s2+set[n-1]);
    return min(option1,option2);
}

int main(){
    int set[]={1,6,11,9};
    int n=4;
    int ans=minSubsetSumDiff(set,n,0,0);
    cout<<ans<<endl;
}