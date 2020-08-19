#include<iostream>
#include<cstring>
using namespace std;

int lcs(string s1, string s2, int m, int n){
    if(m==0||n==0){
        return 0;
    }

    int** dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }

    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
            }else{
            int option1=dp[i][j-1];
            int option2=dp[i-1][j];
            dp[i][j]=max(option1,option2);
            }
        }
    }
    return dp[m][n];
}

int main()  
{  
    string s1= "AGGTAB";  
    string s2 = "GXTXAYB";       
    int m = s1.length();  
    int n = s2.length();
    cout<<"Length of LCS is "<< lcs(s1,s2,m,n) ;   
}  