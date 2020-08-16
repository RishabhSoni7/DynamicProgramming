#include<iostream>
#include<cmath>
using namespace std;

bool equalSumPartition(int* set, int n, int sum){
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
        bool option1=equalSumPartition(set,n-1,sum-set[n-1]);
        bool option2=equalSumPartition(set,n-1,sum);
        return option1||option2;
    }else{
        return equalSumPartition(set,n-1,sum);
    }
}

int main(){
    //int set[]={1,5,11,5};
    int set[]={3, 34, 4, 12, 5, 2};
    int n=6;
    int sum=0;
    for(int i=0;i<6;i++){
        sum+=set[i];
    }
    if(sum%2!=0){
        cout<<"false";
        return 0;
    }
    bool ans=equalSumPartition(set,n,sum/2);
    cout<<ans<<endl;
}