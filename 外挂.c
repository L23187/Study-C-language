#include <stdio.h> 
int main()
{
    int nums1[4] = {1,2,2,1},nums2[2] = {2,2};
    int nums1Size = 4,nums2Size = 2;
    int x = 0,i,j;
    int a[x];
    for(i = 0;i<nums1Size;i++){
        for(j = 0;j<nums2Size;j++){
            if(nums1[i]==nums2[j]){
                a[x] = nums1[i];
                x++;
            }
        }
    }
    int k = 1;
    for(i = 1;i<x;i++){
    	if(a[i] != a[i-1]){
    		a[k] = a[i];
    		k++;
		}
	}
	for(i = 0;i<k;i++){
		printf("%d ",a[i]);
	}
    return 0;
}
