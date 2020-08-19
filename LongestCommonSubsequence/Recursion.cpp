#include<iostream>
#include<cstring>
using namespace std;

int lcs(string s1, string s2, int m, int n){
    if(m==0||n==0){
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        return 1+lcs(s1,s2,m-1,n-1);
    }else{
        int option1=lcs(s1,s2,m,n-1);
        int option2=lcs(s1,s2,m-1,n);
        return max(option1,option2);
    }
}

int main()  
{  
    string s1= "AGGTAB";  
    string s2 = "GXTXAYB";       
    int m = s1.length();  
    int n = s2.length();
    cout<<"Length of LCS is "<< lcs(s1,s2,m,n) ;   
}  