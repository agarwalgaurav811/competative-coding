//Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, 
//find the area of largest rectangle in the histogram.

#define mp make_pair
#define S (s.top().second)
#define f (s.top().first)
int Solution::largestRectangleArea(vector<int> &A) {
    
    int l=A.size();
    stack <pair<int,int> > s;
    int ans=0;
    int h=0;
    int prev=0;
    int cur=0;
    for(int i=0;i<l;i++)
    {
      
        if(!s.empty() && f<=A[i]){
          s.push(mp(A[i],i));
         // cout<<f<<" "<<S<<endl;
        }

        else
          {
              


              while(!s.empty() && f>A[i]){
                h=f;
               // cur=S;
                s.pop(); 
                if(!s.empty())
                   ans=max(ans,(i-S-1)*h);
                else
                   ans=max(ans,(i)*h);
                 //  cout<<"ans "<<ans<<endl;
              }
            //  cout<<i<<" "<<arr[i]<<endl;

              s.push(mp(A[i],i));
             // cout<<f<<" "<<S<<endl;
          } 
          
    }
    prev=0;
    cur=0;
    if(!s.empty()){
        prev=S;
        cur=S-1;
        h=f;
        s.pop();
     while(!s.empty())
     {
        ans=max(ans,(prev-S)*h);
       // cout<<"ans "<<ans<<endl;
        h=f;
        cur=S-1;
        s.pop();
    }
    ans=max(ans,(prev+1)*h);
   // cout<<"ans "<<ans<<endl;
    }
    return ans;
    
}
