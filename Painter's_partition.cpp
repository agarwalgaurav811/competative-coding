//You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much
//time a painter takes to paint 1 unit of board. You have to
//get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.
bool ispossible(int A,long long tim,vector<int> &C){
    long long sum=0;
    long long i=0;
    for(i=0;i<C.size() && A;i++){
        sum+=C[i];
        if(sum>tim){
            sum=0;
            i--;
            A--;
            
        }
    }
    if(i<C.size())
      return false;
    else 
      return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long tim=0;
    for(int i=0;i<C.size();i++){
        tim+=C[i];
    }
    long long low=0;
    long long high=tim;
    while(low<=high){
    int mid=low+(high-low)/2;
        if(ispossible(A,mid,C)){
            high=mid-1;
            tim=mid;
        }
        else
           low=mid+1;
    }
    int ans =(tim*B)%10000003;
    return ans;
}
