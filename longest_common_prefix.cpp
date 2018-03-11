
//mine sol
string Solution::longestCommonPrefix(vector<string> &A) {
    int n=A.size();
    string com=A[0];     
    int s1=com.size();
    for(int i=1;i<n;i++){
        int s2=A[i].size();
        int j=0;
        while(j<s1 && j<s2 ){
           if(com[j]!=A[i][j])
             break;
           j++;
        }
        s1=j;
    }
    com.resize(s1);
    return com;
    
    
}
