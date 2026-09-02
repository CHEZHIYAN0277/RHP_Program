#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int p=0;
	while(m--){
		int t,x;
		cin>>t>>x;
		x=x%n;
		if(t==1){
			p=p+x;
			if(p>n){
				p-=n;
			}
		}
		else{
			cout<<s[(p+(x-1))%n]<<endl;
		}
	}
}
