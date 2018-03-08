
//solution1
unsigned int Solution::reverse(unsigned int A) {

    unsigned int count = sizeof(A)*8-1;
    unsigned int reverse_num = A;
    A >>=1;
    while(A){
        reverse_num <<= 1;
        reverse_num |= A & 1;
        A >>= 1;
        count--;
    }
    reverse_num = reverse_num <<= count;
    return reverse_num;
}

//fastest
unsigned int Solution::reverse(unsigned int A) {

    unsigned int count = sizeof(A)*8-1;
    unsigned int reverse_num = A;
    A >>=1;
    while(A){
        reverse_num <<= 1;
        reverse_num |= A & 1;
        A >>= 1;
        count--;
    }
    reverse_num = reverse_num <<= count;
    return reverse_num;
}
//written by me initially
#include <math.h>
unsigned int Solution::reverse(unsigned int A) {
    
    unsigned int rev=0;
    unsigned int b=0;
    unsigned int power =pow(2,31);
    while(A)
    {
        b=A-(A&(A-1));
        A=A-b;
        rev+=power/b;
    }
    return rev;
}

