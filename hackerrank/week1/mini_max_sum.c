#include <stdio.h>
void miniMaxSum(int arr[5]){
    long total = 0;
    int mini = arr[0];
    int max = arr[0];
    for (int i=0; i<5; i++) {
    total += arr[i];
    if(arr[i]<mini) mini = arr[i];
    if(arr[i]>max) max = arr[i];
    }
    long miniSum = total - max;
    long maxSum = total - mini;
    printf("%ld %ld\n", miniSum, maxSum);
}
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    miniMaxSum(arr);
    return 0;
}
