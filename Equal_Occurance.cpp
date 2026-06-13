#include <iostream>
#include <map>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    int val = 0 ;
    int maxlen = 0;
    map<int,int> mp;
    mp[0] = -1; 
    for(int i=-1;i<n;i++){
        if(s[i]=='0'){
            val--;
        }
        else{
            val++;
        }
        if(mp.find(val)!=mp.end()){
            maxlen = max(maxlen,i-mp[val]);
        }
        else{
            mp[val] = i;
        }
    }
    cout<<maxlen<<endl;
}
