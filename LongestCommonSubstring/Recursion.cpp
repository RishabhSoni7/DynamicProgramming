#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int lcsubstring(string s1, string s2, int m, int n, int ans){
    if(m==0||n==0){
        return ans;
    }

    if(s1[m-1]==s2[n-1]){
        return lcsubstring(s1,s2,m-1,n-1,ans+1);
    }   

    return max(ans,max(lcsubstring(s1,s2,m-1,n,0),lcsubstring(s1,s2,m,n-1,0)));
    
}

int main()  
{  
    string s1= "adcbd";  
    string s2 = "adecbd";       
    int m = s1.length();  
    int n = s2.length();
    cout<<"Length of Longest Common Substring is "<< lcsubstring(s1,s2,m,n,0) ;   
}  