#include <stdio.h>
long long int count=0;
void merge_sort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
void merge(int arr[], int start, int mid, int end){
   
    int arr1[mid-start+1],arr2[end-mid],i,j1=0,j2=0;
    for(i=0;i<mid-start+1;i++){
        arr1[i] = arr[start+i];
        
    }
    for(i=0;i<end-mid;i++){
        arr2[i] = arr[mid+1+i];
        
    }
    for(i=0;i<end-start+1;i++){
        if(j1<=mid-start&&j2<end-mid){
            if(arr1[j1]<=arr2[j2]){
                arr[start+i] = arr1[j1];
                j1++;
            }else{
                arr[start+i] = arr2[j2];
                j2++;
                count += mid-start-j1+1;
        }
        }else if(j1<=mid-start){
            arr[start+i] = arr1[j1];
            j1++;
        }else{
            arr[start+i] = arr2[j2];
            j2++;
        }
        
    }
}
int main() {
	int t,n,*arr,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++){
        count = 0;
        scanf("%d",&n);
        arr = (int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            scanf("%d",arr+j);
            //printf("bb %d\n",arr[j]);
        }
        merge_sort(arr,0,n-1);
        
        printf("%lld\n",count);
	}
	
	
	
	
	return 0;
}
