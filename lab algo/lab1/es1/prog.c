#include <stdio.h>

int main(void){
        int arr[] = {1, 55, 26, 17, 8, 44, 23, 66, 35, 88};
	int arr2[] = {1, 55, 26, 17, 8, 44, 23, 66, 35, 88};
        int length = 10, count = 0, i = 0, j = 0, swapped = 0, temp = 0;
        for(i = 0; i < length - 1; i++) {
        	for(j = 0; j < length - 1; j++) {
                        count++;
                        if(arr[j] > arr[j + 1]) {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }

	for(i = 0; i < length; i++) {
                printf("%d ", arr[i]);
        }

	printf("\n%d iterations\n", count);

        swapped = 1;
        count = 0;
	for(i = 0; i < length - 1 && swapped; i++) {
        	swapped = 0;
                for(j = 0; j < length - 1; j++) {
                        count++;
                        if(arr2[j] > arr2[j + 1]) {
                                swapped = 1;
                                temp = arr2[j];
                                arr2[j] = arr2[j + 1];
                                arr2[j + 1] = temp;
                        }
                }
        }
	for(i = 0; i < length; i++) {
                printf("%d ", arr2[i]);
        }
	printf("\n%d iterations\n", count);
	return 0;
}
