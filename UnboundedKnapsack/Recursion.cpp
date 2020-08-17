#include<iostream>
#include<cmath>
using namespace std;

int unboundedKnapsack(int* weights, int* values, int n, int maxWeight){
    if(n<0||maxWeight<0){ //edge case
        return 0;
    }
    if(n==0||maxWeight==0){
        return 0;
    }
    if(weights[n-1]<=maxWeight){
        int option1=values[n-1]+unboundedKnapsack(weights,values,n,maxWeight-weights[n-1]);
        int option2=unboundedKnapsack(weights,values,n-1,maxWeight);
        return max(option1,option2);
    }else{
        return unboundedKnapsack(weights,values,n-1,maxWeight);
    }
}

int main(){
    int weights[]={1,2,4,5};
    int values[]={5,4,8,6};
    int n=4;
    int maxWeight=5;
    int ans=unboundedKnapsack(weights,values,n,maxWeight);
    cout<<ans<<endl;
}