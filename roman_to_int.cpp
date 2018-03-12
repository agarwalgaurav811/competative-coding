
//Given a roman numeral, convert it to an integer.

//Input is guaranteed to be within the range from 1 to 3999.

int Solution::romanToInt(string A) {
    int n=A.size();
    int ans=0;
    int i=0;
    while(i<n && A[i]=='M')
    {
            i++;
            ans+=1000;
    }
    if(i<n && A[i]=='D')
    {
            i++;
            ans+=500;
    }
    else if(i<n-1 && A[i]=='C' && A[i+1]=='D')
    {
        
            i+=2;
            ans+=400;
    }
    else if(i<n-1 && A[i]=='C' && A[i+1]=='M')
    {
        
            i+=2;
            ans+=900;
    }
    while(i<n && A[i]=='C')
    {
            i++;
            ans+=100;
    }
    if(i<n && A[i]=='L')
    {
            i++;
            ans+=50;
    }
    else if(i<n-1 && A[i]=='X' && A[i+1]=='L')
    {
        
            i+=2;
            ans+=40;
    }
    else if(i<n-1 && A[i]=='X' && A[i+1]=='C')
    {
        
            i+=2;
            ans+=90;
    }
    while(i<n && A[i]=='X')
    {
            i++;
            ans+=10;
    }
    if(i<n && A[i]=='V')
    {
            i++;
            ans+=5;
    }
    else if(i<n-1 && A[i]=='I' && A[i+1]=='V')
    {
        
            i+=2;
            ans+=4;
    }
    else if(i<n-1 && A[i]=='I' && A[i+1]=='X')
    {
        
            i+=2;
            ans+=9;
    }
    while(i<n && A[i]=='I')
    {
            i++;
            ans+=1;
    }
    return ans;
}

//other
int romanint(char a){
    switch (a){
        case 'X':
            return 10;
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'L':
            return 50;
        case 'M':
            return 1000;
        case 'C':
            return 100;
        case 'D':
            return 500;
        default:
            return 0;
    }
}

int Solution::romanToInt(string A) {
    int total=0;
    for(int i=0;i<A.size();i++){
        int j=romanint(A[i]),k=0;
        if(i<A.size()-1)
            k=romanint(A[i+1]);
        if(i<A.size()-1 && k>j){
            total=total-j;
            total=total+k;
            i++;
        }
        else{
            total=total+j;
        }
    }
    return total;
}
