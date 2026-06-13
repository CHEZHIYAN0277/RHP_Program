#include <iostream>
using namespace std;

int main(){
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int n1 = s1.length();
    int n2 = s2.length();
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=n2;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(s1[i] == s2[j]){
                dp[i+1][j+1] = 1 + dp[i][j];
            }
            else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    cout<<"Length of longest common subsequence: "<<dp[n1][n2];
}
