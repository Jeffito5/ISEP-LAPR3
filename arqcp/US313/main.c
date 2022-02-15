#include <stdio.h>
#include <string.h>

//length = x, width = y, height = z
#define LENGTH 10
#define WIDTH 10
#define HEIGHT 10

/*
Function to add a container to its right position and assigning its ID
*/
void add_cont(int (*matrix_ptr)[WIDTH][HEIGHT],int id, int x, int y, int z)
{ 
	*(*(*(matrix_ptr+x)+y)+z) = id;
} 
   
/*
Function to set the matrix to "0"
*/
void clear_matrix(int (*matrix_ptr)[WIDTH][HEIGHT]){
	int i,j,z;
	for (i=0; i<LENGTH; i++){
		for (j=0; j<WIDTH; j++) {	
			for(z=0; z<HEIGHT; z++){
				*(*(*(matrix_ptr+i)+j)+z) = 0;
			}	 		  
		}
	}			
}


/*
Function to print the matrix without the positions set to "0"
*/
void print_matrix(int (*matrix_ptr)[WIDTH][HEIGHT]){
int i,j,z;
	printf("Showing the filled positions within the matrix: \n");
        for(i=0; i<LENGTH; i++){
 			for(j=0; j<WIDTH; j++){
				 for(z=0; z<HEIGHT; z++){
					 if (matrix_ptr[i][j][z] != 0)
				 printf("matrix[%d][%d][%d]=%d \n",i,j,z,matrix_ptr[i][j][z]);
				 }	 	
			}
		}
}

/*
Function to print the matrix with all the positions, including the "0" positions
*/
void print_matrixwith0(int (*matrix_ptr)[WIDTH][HEIGHT]){
int i,j,z;
	printf("Showing all the matrix positions: \n");
        for(i=0; i<LENGTH; i++){
 			for(j=0; j<WIDTH; j++){
				 for(z=0; z<HEIGHT; z++){
				 printf("matrix[%d][%d][%d]=%d \n",i,j,z,matrix_ptr[i][j][z]);
				 }	 	
			}
		}
}

int main() {

	//Matrix used
	int matrix[LENGTH][WIDTH][HEIGHT];

	//Matrix pointer
	int (*matrix_ptr)[WIDTH][HEIGHT] = matrix;
	
	//Reseting the matrix to "0"
	clear_matrix(matrix_ptr);

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

	print_matrixwith0(matrix_ptr);
	print_matrix(matrix_ptr);
	
	return 0;
}




//Possible solution to read and use data from a .txt file (WIP, not working for now)

/*
Function to add a container to its right position and assigning its ID based on a txt file with the values needed
*/
/*void add_cont(FILE * MatrixBootstrap, int (*matrix_ptr)[WIDTH][HEIGHT]){

    int x;
    int y;
    int z;
    int id;
    
    char size[1024];
    char *line;
    
    while (fgets(size, 1024, MatrixBootstrap)) {

        line = strtok(size, ",");

        x = strtol(line, NULL, 10);
        line = strtok(NULL, ",");

        y = strtol(line, NULL, 10);
        line = strtok(NULL, ",");

        z = strtol(line, NULL, 10);
        line = strtok(NULL, ",");

        id = strtol(line, NULL, 10);

        ((*(matrix_ptr+x)+y)+z) = id;
    }

    fclose(MatrixBootstrap);
}
*/





