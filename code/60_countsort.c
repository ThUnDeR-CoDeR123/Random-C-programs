#include<stdio.h>
#include<limits.h>

int maxarr(int * arr,int n){
    int max=arr[0];
    int size=n;
    for(int i=1;i<size;i++){
        max=(arr[i]>max)?arr[i]:max;
    }
    return max;
}
void count(int * arr,int n){
    int max=maxarr(arr,n);
    int carr[max+1];
    for (int i=0;i<max+1;i++) carr[i]=0;
    int size=n;
    for(int i=0;i<size;i++){
        carr[arr[i]]++;
    }
    int k=0,i=0;
    while(i<max+1){
        if(carr[i]!=0){
            arr[k]=i;
            carr[i]=carr[i]-1;
            k++;
            // i++;
        }
        else{
            i++;
        }
    
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    count(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

}