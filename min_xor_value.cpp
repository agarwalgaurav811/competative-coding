//mine sol
#include <bits/stdc++.h>
#include <algorithm>
int Solution::findMinXor(vector<int> &A) {
    int mx=9999999999;
    int n=A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n-1;i++)
            mx=min(mx,A[i]^A[i+1]);

    
    return mx;
    
    
    
}
//leightweight

oid quickSort(vector<int> &A, int start, int end) {
	if (start >= end) return;
	int i = start + 1;
	int j = end;
	int pivot = A[start];
	while (1) {
		while (i <= end && A[i] <= pivot) i++;
		while (j >= start && A[j]>pivot) j--;
		if (j <i) break;
		std::swap(A[i], A[j]);
	}
	swap(A[start], A[j]);
	quickSort(A, start, j - 1);
	quickSort(A, j + 1, end);
}

int Solution::findMinXor(vector<int> &A) {
	quickSort(A, 0, A.size() - 1);
	int min = INT_MAX;
	for (int i = 0; i < A.size() - 1; i++) {
		int tempResult = A[i] ^ A[i + 1];
		if (tempResult < min) min = tempResult;
	}
	return min;
}
