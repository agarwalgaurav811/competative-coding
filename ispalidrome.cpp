
//mine sol
int Solution::isPalindrome(string A) {
    int n=A.size();
    string s;
    for(int i=0;i<n;i++){
        int a=A[i];
        if(a>=48 && a<=57 || a>=65 && a<=90)
           s.push_back(A[i]);
        else if(a>=97 && a<=122){
            a-=32;
            char c=a;
            s.push_back(c);
        }
      
    }
    n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])
           return 0;
    }
    return 1;
}
//other


class Solution {
    public:
        bool isPalindrome(string s) {

            int i = 0, j = (int)s.size() - 1;
            while(i < j)
            {
                while(i < j && !isalnum(s[i])) i++;
                while(i < j && !isalnum(s[j])) j--;
                if (toupper(s[i]) != toupper(s[j])) return false; 
                i++;
                j--;
            }
            return true;
        }

};

//other
