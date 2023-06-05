//{ Driver Code Starts
//Initial Template for C

#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int A[n];
        for(int i = 0; i < n; i++)
            scanf("%d",&A[i]);
        int key;
        scanf("%d",&key);
        int answer = search(A, 0, n - 1, key); 
        printf("%d\n",answer);
    }
return 0;
}

// } Driver Code Ends


//User function Template for C


    
int search(int A[], int l, int h, int key) { 
    // l: The starting index
    // h: The ending index, you have to search the key in this range
        
    //complete the function here
    while(l<=h)
   {
       int m = l+(h-l)/2;
       if(A[m]==key)//if key is found at mid
       {
           return m;
       }
       if(A[l]<=A[m])//checking left part of array is sorted
       {
           if(A[l]<=key && A[m]>=key)//if key is between mid and low
           {
                h = m-1;   
           }
           else
           {
               l = m+1;
           }
       }
       else//checking right part of array is sorted
       {
           if(A[m]<=key && A[h]>=key)//if key is between mid and high
           {
               l = m+1;
           }
           else
           {
               h = m-1;
           }
       }
   }
   return -1;
} 
    
