int iteration(vector <int>& a,int b,int l){
    vector <int> dum(a);
    int m=(b+l)/2;
    int i=b;
    int j=m+1;
    int k=b;
    int count =0;
    while(i<=m && j<=l){
        if(dum[i]>dum[j]){
            a[k]=dum[j];
           // cout<<dum[j]<<endl;
            count+=j-k;
            j++;
            k++;
        }
        else{
            a[k]=dum[i];
           //  cout<<dum[i]<<endl;
            i++;
            k++;
        }
    }
    while(i<=m){
         a[k]=dum[i];
        //  cout<<dum[i]<<endl;
         i++;
         k++;
    }
    while(j<=l){
         a[k]=dum[j];
         count+=j-k;
       //   cout<<dum[j]<<endl;
         j++;
         k++;
    }
    dum.clear();
    return count;
    
}


int mergesort(vector <int>& a,int b,int l){
   if(b==l)
   return 0;
   int x= mergesort(a,b,(b+l)/2);
   int y=mergesort(a,(b+l)/2+1,l);
   int z=iteration(a,b,l);
   return x+y+z;
}

int Solution::findRank(string A) {
    vector <int> v;
    int l=A.size();
    int c=0;
    for(int i=0;i<l;i++){
        c=A[i];
      //  cout<<c<<endl;
        v.push_back(c);
    }
    return mergesort(v,0,l-1);
}
