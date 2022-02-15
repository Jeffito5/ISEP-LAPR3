#include <stdio.h>
#include <occupied.h>

//number of rows/length = x
#define LENGTH 10
//number of collumns/width = y
#define WIDTH 10
//height of the matrix = z
#define HEIGHT 10

int main() {
	int *ptrvec;
	int tamanho=10;
	int percorrer;

	//Matrix used
	int matrix[LENGTH][WIDTH][HEIGHT];

	//Matrix pointer
	int (*matrix_ptr)[WIDTH][HEIGHT] = matrix;

	//Bootlineap values for the containers
	add_cont(matrix_ptr,1111,1,1,1);
	add_cont(matrix_ptr,2222,6,4,4);
	add_cont(matrix_ptr,3131,4,4,4);
	add_cont(matrix_ptr,6421,1,2,3);
	add_cont(matrix_ptr,5366,3,7,2);
	add_cont(matrix_ptr,2356,2,1,3);
	add_cont(matrix_ptr,2341,5,2,3);
	add_cont(matrix_ptr,5674,9,3,1);
	add_cont(matrix_ptr,3257,3,6,9);
	add_cont(matrix_ptr,9753,7,3,2);
	add_cont(matrix_ptr,5423,5,3,8);
	add_cont(matrix_ptr,7645,3,1,6);
	add_cont(matrix_ptr,4356,5,9,2);
	add_cont(matrix_ptr,2352,4,3,2);
	add_cont(matrix_ptr,7352,1,2,8);
	add_cont(matrix_ptr,3427,4,7,1);
	add_cont(matrix_ptr,2634,3,4,3);
	add_cont(matrix_ptr,2352,2,3,2);
	add_cont(matrix_ptr,7547,3,4,8);
	add_cont(matrix_ptr,3452,8,9,2);
	add_cont(matrix_ptr,6237,2,7,8);
	add_cont(matrix_ptr,6794,3,2,8);
	add_cont(matrix_ptr,5636,5,6,3);
	add_cont(matrix_ptr,9783,4,6,5);
	add_cont(matrix_ptr,2134,3,3,2);
	
	
	if(width>0){
		percorrer=lengh+width*tamanho;
		if(height>0){
			percorrer=height*tamanho*tamanho+percorrer;
		}
	}
	
	
	if(start()==1){
		printf("Ocupado");
	}else{
		printf("Nao ocupado");
	}
	
	return 0;
}
