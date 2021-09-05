#include <stdio.h>

void bubbleSort(int *array, int n){
	int temp;
	for (int i = 1; i < n; i++){
		for (int j = 1; j < n; j++){
			if (array[j] < array[j-1]){
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
		}
	}
}

int main(){
	int n;
	printf("Enter the size of an array\n");
	scanf("%d", &n);
	int array[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	bubbleSort(array, n);
	for (int i = 0; i < n; i++){ 
                printf("%d ", array[i]);
        }


}
