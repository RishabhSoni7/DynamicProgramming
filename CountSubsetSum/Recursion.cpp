#include<iostream>
using namespace std;

int countSubsetSum(int* set, int n, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0&&sum!=0){
        return 0;
    }
    if(set[n-1]<=sum){
        int option1=countSubsetSum(set,n-1,sum-set[n-1]);
        int option2=countSubsetSum(set,n-1,sum);
        return option1+option2;
    }else{
        return countSubsetSum(set,n-1,sum);
    }
}

int main(){
    int set[]={3, 9, 4, 12, 5, 2};
    int n=6;
    int sum=9;
    int ans=countSubsetSum(set,n,sum);
    cout<<ans<<endl;
}

// int countSubsetSum(int* set, int n, int sum,int count){
//     if(sum==0){
//         count++;
//         return count;
//     }
//     if(n==0&&sum!=0){
//         return count;
//     }
//     if(set[n-1]<=sum){
//         count=countSubsetSum(set,n-1,sum-set[n-1],count);
//         count=countSubsetSum(set,n-1,sum,count);
//         return count;
//     }else{
//         count=countSubsetSum(set,n-1,sum,count);
//         return count;
//     }
// }

// int main(){
//     int set[]={3, 9, 4, 12, 5, 2};
//     int n=6;
//     int sum=9;
//     int ans=countSubsetSum(set,n,sum,0);
//     cout<<ans<<endl;
// }

