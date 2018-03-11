//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    string s;
	    cin>>s;
	    vector <string> arr;
	    int n=s.size();
	    int prev=0;
	    for(int j=0;j<n;j++){
	        if(s[j]=='.'){
	            arr.push_back(s.substr(prev,j-prev));
	           // cout<<arr.back()<<endl;
	            prev=j+1;
	        }
	    }
	    if(s[n-1]!='.')
	        arr.push_back(s.substr(prev,n-prev));
	        
	    n=arr.size();
	    string rev;
	    rev.append(arr[n-1]);
	    n--;
	    while(n--){
	        rev.append(".");
	        rev.append(arr[n]);
	    }
	    cout<<rev<<endl;
	}
	
	return 0;
}
