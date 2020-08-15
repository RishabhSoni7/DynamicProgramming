#include<iostream>
#include<cmath>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){
    if(n<=0||maxWeight<=0){
        return 0;
    }
    if(weights[n-1]<=maxWeight){
        int option1=values[n-1]+knapsack(weights,values,n-1,maxWeight-weights[n-1]);
        int option2=knapsack(weights,values,n-1,maxWeight);
        return max(option1,option2);
    }else{
        return knapsack(weights,values,n-1,maxWeight);
    }
}

int main(){
    int weights[]={1,2,4,5};
    int values[]={5,4,8,6};
    int maxWeight=5;
    int ans=knapsack(weights,values,4,5);
    cout<<ans<<endl;
}