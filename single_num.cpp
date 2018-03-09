//Given an array of integers, every element appears thrice except for one which occurs once.

//Find that element which does not appear thrice.

//Note: Your algorithm should have a linear runtime complexity.

//Could you implement it without using extra memory?
//mine sol
int Solution::singleNumber(const vector<int> &A) {
    int n=A.size();
    int nb=sizeof(A[0])*8;
    int ans=0;
    for(int j=0;j<nb;j++)
    {
         long long r=0;
         for(int i=0;i<n;i++)
           r+=A[i]&(1<<j);

         r=r%3;
         if(r)
           ans+=1<<j;
           
    }
    return ans;
}
//using bitmask
int singleNumber(const vector<int> &A) {
    int n = A.size();
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}
