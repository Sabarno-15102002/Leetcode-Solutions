//{ Driver Code Starts
//Initial Template for C

#include<stdio.h>
#include<stdbool.h>


// } Driver Code Ends
//User function Template for C

int peakElement(int arr[], int n)
{
   // Your code here
   int s = 0;
   int e = n-1;
   int mid;
   while(s<=e){
       mid = s+(e-s)/2;
       
       bool flag1 = true;
       bool flag2 = true;
       
        if(mid>0 && arr[mid]<arr[mid-1])
            flag1 = false;
            
        if(mid+1<n && arr[mid]<arr[mid+1])
            flag2 = false;
            
        if(flag1 && flag2)
            return mid;
            
        if(flag1){
            s = mid+1;
        }
        
        else
            e = mid-1;
        
   }
   
   return s;
}

//{ Driver Code Starts.

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			tmp[i] = a[i];
		}
		bool f=0;
		
		int A = peakElement(tmp,n);
		
		if(A<0 && A>=n)
		    printf("0\n");
		else
		{
    		if(n==1 && A==0)
    		    f=1;
    		else if(A==0 && a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 && a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] && a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		printf("%d\n", f);
		}
		
	}

	return 0;
}
// } Driver Code Ends