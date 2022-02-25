// For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]' 
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').
// Test Cases-
// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation Of Sample Output 1:
// We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
long long int Merge(long long arr[],long long left,long long  mid,long long right)
{
    
    long long int temp[(right-left+1)];
    long long int inv_count=0;
    int i=left,j=mid,k=0;
    while((i<=(mid-1))&&(j<=right))
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            //here we count inversion wrt to elements after the
            //lower element added
            inv_count+=(mid-i);
        }
    }
        while(i<=(mid-1))
            temp[k++]=arr[i++];
        while(j<=right)
            temp[k++]=arr[j++];
        
        for(i=left,k=0;i<=right;i++,k++)
            arr[i]=temp[k];
       return inv_count;
    }


long long int Merge_Sort(long long arr[],long long left,long long right)
{
    long long inv_count=0,mid;
    if(left<right)
    {
        mid=(left+right)/2;
        inv_count=Merge_Sort(arr,left,mid);
        inv_count+=Merge_Sort(arr,mid+1,right);
        inv_count+=Merge(arr,left,mid+1,right);
        
    }
    return inv_count;
}
    



long long getInversions(long long *arr, int n){
    // Write your code here.
     
    return Merge_Sort(arr,0,n-1);
   
}