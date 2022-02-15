#include <stdio.h>
#include <string.h>

//number of rows/length = x
#define LENGTH 10
//number of collumns/width = y
#define WIDTH 10
//height of the matrix = z
#define HEIGHT 10

int (*matrix_ptr)[WIDTH][HEIGHT];
int num_elements = 1000;

/*
Function to add a container to its right position and assigning its ID based on a txt file with the values needed
*/
void add_cont(FILE * MatrixBootstrap, int (*matrix_ptr)[WIDTH][HEIGHT]){

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


int main() {     
	
	//matrix used  
	int matrix[LENGTH][WIDTH][HEIGHT];  
	
	//Matrix pointer
	matrix_ptr = matrix;
	
	add_cont("MatrixBootstrap.txt", matrix);
	
    //number of occupied slots
	int num_occupied_slots = occupied_slots();
	printf("Number of occupied slots = %d\n", num_occupied_slots); 
	
	return 0; 
}
