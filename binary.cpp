
//Given a number N >= 0, find its representation in binary.
//mine sol

string Solution::findDigitsInBinary(int A) {
    if(!A)
      return "0";
    char bin_num[32];
    memset(bin_num,0,32);
    int r=0;
    int i=31;
    while(A){
        r=A%2;
        A=A/2;
        if(r)
           bin_num[i]='1';
        else
           bin_num[i]='0';
        i--;
    }
    string bin_n(bin_num+i+1,bin_num+32);
    return bin_n;
}

//method2:
 class Solution {
    public:
        string findDigitsInBinary(int n) {
            string ans;
            if (n == 0) return "0";
            
            while (n > 0) {
            int rem = n % 2; 
            ans.push_back((char)('0' + rem));
            n /= 2;
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    
    //method 3:
    
  string Solution::findDigitsInBinary(int A) {
    
    char represent[33] = {0};
    int i=0;
    for(;i<32;i++)
    {
        if(A%2 == 1)
            represent[31-i] = '1';
        else
            represent[31-i] = '0';
            
        A /= 2;
        if( A == 0 )
            break;
    }
    
    string x(represent+31-i);
    
    return x;

}


