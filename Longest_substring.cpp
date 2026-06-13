#include <iostream>
using namespace std;

int main(){
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int n1 = s1.length();
    int n2 = s2.length();
    int dp[n1][n2];
    for(int i=0;i<n2;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int maxval = 0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            maxval = max(maxval, dp[i][j]);
        }
    }
    cout<<"Length of longest common substring: "<<maxval;
}
