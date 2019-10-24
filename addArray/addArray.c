#include<stdio.h>

int main(){
	int height = 1, width = 1;
	int height2 = 1, width2 = 1;
	int **arr, **arr2;
	
	printf("first matrix height: ");
	scanf("%d", &height);
	printf("first matrix width: ");
	scanf("%d", &width);

	arr = (int**) malloc ( sizeof(int*) * height );
	for(int i=0; i<height; i++){
	    arr[i] = (int*) malloc ( sizeof(int) * width );
	}

	printf("second matrix height: ");
	scanf("%d", &height2);
	printf("second matrix width: ");
	scanf("%d", &width2);

	arr2 = (int**) malloc ( sizeof(int*) * height2 );
	for(int i=0; i<height2; i++){
	    arr2[i] = (int*) malloc ( sizeof(int) * width2 );
	}

	// arr insert data
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			printf("first matrix[%d][%d]: ", i,j);
			scanf("%d", &arr[i][j]);
		}
	}
	for(int i=0; i<height2; i++){
		for(int j=0; j<width2; j++){
			printf("second matrix[%d][%d]: ", i,j);
			scanf("%d", &arr2[i][j]);
		}
	}

	// arr add data
	printf("\nAdd matrix!!\n");
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			printf("%d  ", arr[i][j]+arr2[i][j]);
		}
		printf("\n");
	}
	// memory free
	for(int i=0; i<height; i++){
		    free(arr[i]);
	}
	free(arr);
	for(int i=0; i<height; i++){
		    free(arr2[i]);
	}
	free(arr2);
	return 0;
}
