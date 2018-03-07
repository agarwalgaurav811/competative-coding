//Find Maximum Index Product

//sol1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;


int main() {
    
    int n;
    cin>>n;
    

    ll arr[n];
 
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    if(n<3)
    {
      cout<<0<<endl;
      return 0;
    }
    
    int it=n-1;
    ll left;
    ll right=n+1;
    
    while(it>=0 && arr[it]<=arr[n-1]) {
        it--;
    }
        
    left=max(it+1,0);
    ll mx=0;
    it=n-2;
    while(it>=0){
        
        if(arr[it]<arr[it+1]){
            
            right=it+2;
           // cout<<right<<endl;
            for(int i=it-1;i>=left && i>=0;i--)
            {
                if(arr[i]>arr[it])
                {
                    left=i+1;
                   // cout<<left<<endl;
                    break;
                }
            }
        }
        else if(arr[it]>arr[it+1])
        {
            int i;
            for(i=right-1;i<n;i++)
            {
                if(arr[i]>arr[it])
                {
                    right=i+1;
                   // cout<<right<<endl;
                    break;
                }
            }
            if(i==n)
                right=n+1;
            for(i=it-1;i>=0;i--)
            {
                if(arr[i]>arr[it])
                {
                    left=i+1;
                 //   cout<<left<<endl;
                    break;
                }
            }
            if(i<0)
              left=-1;
        }
       if(right<n+1 && left>=0)
          mx=max(mx,left*right);
        
       it--; 
        
    }
       
    cout<<mx<<endl;    
 
    
    return 0;
}

//sol2
#include <bits/stdc++.h>
using namespace std; 
#define PII pair <int, int>
int leftprod[100005]; int rightprod[100005]; int arr[100005]; 
int main()
{
    stack <PII> first, second;
    int a; cin >> a;
    for (int g=1;g<=a; g++) cin >> arr[g]; 
    for (int g=1;g<=a; g++)
    {
        while (!first.empty() && first.top().first<=arr[g]) first.pop();
        if (first.empty()){first.push(PII(arr[g], g)); continue;}
        leftprod[g]=first.top().second; 
        first.push(PII(arr[g], g)); 
    }
    for (int g=a; g>=1; g--)
    {
        while (!second.empty() && second.top().first<=arr[g]) second.pop();
        if (second.empty()){second.push(PII(arr[g], g)); continue;}
        rightprod[g]=second.top().second; 
        second.push(PII(arr[g], g)); 
    }long long ans=0; 
    for (int g=1; g<=a; g++)
    {
        long long t=1LL*leftprod[g]*rightprod[g];
        if (t>ans) ans=t; 
    }
    cout << ans; return 0; 
}

