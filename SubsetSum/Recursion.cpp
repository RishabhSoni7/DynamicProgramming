#include<iostream>
#include<cmath>
using namespace std;

bool subsetSum(int* set, int n, int sum){
    if(n<0||sum<0){ //edge case
        return false;
    }
    if(sum==0){
        return true; //empty set
    }
    if(n==0&&sum!=0){
        return false;
    }
    if(set[n-1]<=sum){
        bool option1=subsetSum(set,n-1,sum-set[n-1]);
        bool option2=subsetSum(set,n-1,sum);
        return option1||option2;
    }else{
        return subsetSum(set,n-1,sum);
    }
}

int main(){
    int set[]={3, 34, 4, 12, 5, 2};
    int sum=9;
    bool ans=subsetSum(set,6,sum);
    cout<<ans<<endl;
}