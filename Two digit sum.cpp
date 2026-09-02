#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int
using namespace std;
int main(){
        int n;
        cin>>n;
        for(int k=0;k<n;k++){
            string a,b;
            cin>>a>>b;
            int r=a.length();
            int c=b.length();
            vector<int> ma(r),mb(c);
            ma[0]=a[0]-'0';
            mb[0]=b[0]-'0';
            for(int i=1;i<r;i++){
                ma[i]=(ma[i-1]+(a[i]-'0'))%10;
            }
            for(int i=1;i<c;i++){
                mb[i]=(mb[i-1]+(b[i]-'0'))%10;
            }
            if(ma[r-1]!=mb[c-1]){
                cout<<"-1";
                continue;
            }
            vector<vector<int>> dp(r+1, vector<int>(c+1,0));

			for(int i=1;i<=r;i++){
			    for(int j=1;j<=c;j++){
			        if(ma[i-1]==mb[j-1]){
			            dp[i][j]=dp[i-1][j-1]+1;
			        }
			        else{
			            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			        }
			    }
			}
			
			cout << dp[r][c] << '\n';
        }
        return 0;
    }
