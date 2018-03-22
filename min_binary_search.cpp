//Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

//Find the minimum element.

int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int last = A[n-1];
    int low =0 ;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid]>last)
           low = mid+1;
        else if(A[mid]<=last){
             high = mid-1;
             last = A[mid];
        }
    }
    return last;
}
