#include<iostream>
#include<cstring>
using namespace std;

int lcs(string s1, string s2, int m, int n, int** dp){
    if(m==0||n==0){
        return 0;
    }

    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(s1[m-1]==s2[n-1]){
        dp[m][n]=1+lcs(s1,s2,m-1,n-1,dp);
        return dp[m][n];
    }else{
        int option1=lcs(s1,s2,m,n-1,dp);
        int option2=lcs(s1,s2,m-1,n,dp);
        dp[m][n]=max(option1,option2);
        return dp[m][n];
    }
}

int main()  
{  
    string s1= "AGGTAB";  
    string s2 = "GXTXAYB";       
    int m = s1.length();  
    int n = s2.length();

    int** dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<"Length of LCS is "<< lcs(s1,s2,m,n,dp) ;   
}  