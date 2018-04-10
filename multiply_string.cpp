
#define a s.str()
string Solution::multiply(string A, string B) {
    

  // if(A.find(" ")!=A.end())
   //  A.erase(A.find(" "));
        // cout<<"/"<<(int)*(A.end()-1)<<"/"<<endl;
     A.erase(A.end()-1);
   //  cout<<"/"<<A<<"/"<<endl;
   int l1=A.length();
   int l2=B.length();
   string v;
   // if(l2>l1)
   //   swap(A,B);
   //string a;
   ostringstream s,S;
   int temp=0;
   int prev_r=0;
   int r=0;
   int j=0;
   int k=0;
   for(int i=l2-1;i>=0;i--)
   {
       prev_r=0;
       for(j=l1-1;j>=1;j--)
       {
           //temp=atoi(B[i].str_c())*atoi(A[j].str_c());
           temp=(B[i]-'0')*(A[j]-'0');
           temp+=prev_r;
          //     cout<<temp<<endl;
           r= temp%10;
           prev_r=temp/10;
           s<<r;
       }
     //  temp=atoi(B[i].str_c())*atoi(A[0].str_c());
       temp=(B[i]-'0')*(A[0]-'0');
       temp+=prev_r;
         //  cout<<temp<<endl;
       if(temp>9)
       {
            r=temp%10;
            temp/=10;
            if(!r)
              s<<r;
            temp=r*10+temp;
       }
           //cout<<temp<<endl;
       s<<temp;
      // a=s.str();
      // reverse(a.begin(),a.end());
      // for(int k=0;k<l2-1-i;k++)
      //     a.push_back('0');
       k=l2-i-1;
       // a.append(s.str());
      // v.push_back(a);
      // s.str("");
      // cout<<a<<endl;
       if(i==l2-1){
           //v=a;
           //a.clear();
           v=s.str();
           s.str("");
           continue;
       }
       int s1=v.size();
       int s2=s.str().size()+k;
       prev_r=0;
       if(s1>s2){
           for(j=0;j<k;j++){
               r=(v[j]-'0');
               S<<r;
           }
           for(j=k;j<s2;j++)
           {
               temp=(v[j]-'0')+(a[j-k]-'0')+prev_r;
          //     cout<<temp<<endl;
               r= temp%10;
               prev_r=temp/10;
               S<<r;
           }
           while(prev_r>0 && j<s1-1){
               temp=(v[j]-'0')+prev_r;
               r= temp%10;
               prev_r=temp/10;
               S<<r; 
               j++;
           }
           if(j==s1-1){
               temp=(v[j]-'0')+prev_r;
               if(temp>9)
               {
                   r=temp%10;
                   temp/=10;
                   if(!r)
                      S<<r;                   
                   temp=r*10+temp;
               }
           //cout<<temp<<endl;
               S<<temp;
           }
           else{
               while(j<s1){
                    S<<(v[j]-'0');
                    j++;
               }
           }
           v = S.str();
           
       }
       else{
           for(j=0;j<k;j++){
               r=(v[j]-'0');
               S<<r;
           }           
           for(j=k;j<s1;j++)
           {
               temp=(v[j]-'0')+(a[j-k]-'0')+prev_r;
          //     cout<<temp<<endl;
               r= temp%10;
               prev_r=temp/10;
               S<<r;
           }
           while(prev_r>0 && j<s2-1){
               temp=(a[j-k]-'0')+prev_r;
               r= temp%10;
               prev_r=temp/10;
               S<<r; 
               j++;
           }
           if(j==s2-1){
               temp=(a[j-k]-'0')+prev_r;
               if(temp>9)
               {
                   r=temp%10;
                   temp/=10;
                   if(!r)
                      S<<r;                
                   temp=r*10+temp;
               }
           //cout<<temp<<endl;
               S<<temp;
           }
           else{
               while(j<s2){
                    S<<(a[j-k]-'0');
                    j++;
               }
           }
           v = S.str();           
  
       }
       S.str("");
       s.str("");
       //a.clear();
   }
       reverse(v.begin(),v.end());
       cout<<v<<endl;
   
}
