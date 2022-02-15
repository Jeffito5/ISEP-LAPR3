#include <stdio.h>
#include <string.h>

//number of rows = x
#define ROW 10
//number of collumns = y
#define COLLUMN 10
//height of the array = z
#define HEIGHT 10

typedef struct
{
    char ID[30];
    double contPayload;
    double contTare;
    double contGross;
    char contISOCode[30];
    char contType[30];
    double contTemp;
} container ;

container array_pt[ROW][COLLUMN][HEIGHT];

/*
Function to add a container to its right position and assigning its ID
*/

void add_cont(int (*array_ptr)[COLLUMN][HEIGHT],int id, int x, int y, int z)
{ 
	*(*(*(array_ptr+x)+y)+z) = id;
} 

/*
Function to set the array to "0"
*/
void clear_array(int (*array_ptr)[COLLUMN][HEIGHT]){
	int i,j,z;
	for (i=0; i<ROW; i++){
		for (j=0; j<COLLUMN; j++) {	
			for(z=0; z<HEIGHT; z++){
				*(*(*(array_ptr+i)+j)+z) = 0;
			}	 		  
		}
	}			
}

/*
Function to print the array without the positions set to "0"
*/
void print_array(int (*array_ptr)[COLLUMN][HEIGHT]){
int i,j,z;
	printf("Showing the filled positions within the array: \n");
        for(i=0; i<ROW; i++){
 			for(j=0; j<COLLUMN; j++){
				 for(z=0; z<HEIGHT; z++){
					 if (array_ptr[i][j][z] != 0)
				 printf("array[%d][%d][%d]= ID:%s \tPayload:%2.2f \tTare:%2.2f \tGross:%2.2f \tISOCode:%s \tType:%s \tTemperature:%2.2f \n",i,j,z,array_pt[i][j][z].ID, array_pt[i][j][z].contPayload, array_pt[i][j][z].contTare, array_pt[i][j][z].contGross, array_pt[i][j][z].contISOCode, array_pt[i][j][z].contType, array_pt[i][j][z].contTemp);
				 }	 	
			}
		}
}

/*
Function to print the array with all the positions, including the "0" positions
*/
void print_arraywith0(int (*array_ptr)[COLLUMN][HEIGHT]){
int i,j,z;
	printf("Showing all the array positions: \n");
        for(i=0; i<ROW; i++){
 			for(j=0; j<COLLUMN; j++){
				 for(z=0; z<HEIGHT; z++){
					 if (array_ptr[i][j][z] != 0)
				  printf("array[%d][%d][%d]= ID:%s \tPayload:%2.2f \tTare:%2.2f \tGross:%2.2f \tISOCode:%s \tType:%s \tTemperature:%2.2f \n",i,j,z,array_pt[i][j][z].ID, array_pt[i][j][z].contPayload, array_pt[i][j][z].contTare, array_pt[i][j][z].contGross, array_pt[i][j][z].contISOCode, array_pt[i][j][z].contType, array_pt[i][j][z].contTemp);
					else printf("array[%d][%d][%d]= Position is empty! \n",i,j,z);
				 }	 	
			}
		}
}

int main() {

	//Matrix used
	int array[ROW][COLLUMN][HEIGHT];

	//Matrix pointer
	int (*array_ptr)[COLLUMN][HEIGHT] = array;
	
	//Reseting the array to "0"
	clear_array(array_ptr);

	//Bootstrap values for the containers

	strcpy(array_pt[1][1][1].ID, "1111"); array_pt[1][1][1].contPayload = 3641; array_pt[1][1][1].contTare = 250; array_pt[1][1][1].contGross = 5000; strcpy(array_pt[1][1][1].contISOCode, "20GP"); strcpy(array_pt[1][1][1].contType, "Refrigerated"); array_pt[1][1][1].contTemp = 7;
	strcpy(array_pt[6][4][4].ID, "2222"); array_pt[6][4][4].contPayload = 3217; array_pt[6][4][4].contTare = 200; array_pt[6][4][4].contGross = 4500; strcpy(array_pt[6][4][4].contISOCode, "20HR"); strcpy(array_pt[6][4][4].contType, "Not Refrigerated"); array_pt[6][4][4].contTemp = -5;
	strcpy(array_pt[4][4][4].ID, "3131"); array_pt[4][4][4].contPayload = 6182.5; array_pt[4][4][4].contTare = 400; array_pt[4][4][4].contGross = 7000; strcpy(array_pt[4][4][4].contISOCode, "20TD"); strcpy(array_pt[4][4][4].contType, "Refrigerated"); array_pt[4][4][4].contTemp = 7;
	strcpy(array_pt[1][2][3].ID, "6421"); array_pt[1][2][3].contPayload = 4612.3; array_pt[1][2][3].contTare = 250; array_pt[1][2][3].contGross = 5000; strcpy(array_pt[1][2][3].contISOCode, "20GP"); strcpy(array_pt[1][2][3].contType, "Refrigerated"); array_pt[1][2][3].contTemp = 7;
	strcpy(array_pt[3][7][2].ID, "5366"); array_pt[3][7][2].contPayload = 2138; array_pt[3][7][2].contTare = 250; array_pt[3][7][2].contGross = 5000; strcpy(array_pt[3][7][2].contISOCode, "20GP"); strcpy(array_pt[3][7][2].contType, "Refrigerated"); array_pt[3][7][2].contTemp = 7;
	
	strcpy(array_pt[2][1][3].ID, "2356"); array_pt[2][1][3].contPayload = 7210.3; array_pt[2][1][3].contTare = 250; array_pt[2][1][3].contGross = 7500; strcpy(array_pt[2][1][3].contISOCode, "22BU"); strcpy(array_pt[2][1][3].contType, "Refrigerated"); array_pt[2][1][3].contTemp = 7;
	strcpy(array_pt[5][2][3].ID, "2341"); array_pt[5][2][3].contPayload = 3082.07; array_pt[5][2][3].contTare = 400; array_pt[5][2][3].contGross = 7000; strcpy(array_pt[5][2][3].contISOCode, "20TD"); strcpy(array_pt[5][2][3].contType, "Not Refrigerated"); array_pt[5][2][3].contTemp = -5;
	strcpy(array_pt[9][3][1].ID, "5674"); array_pt[9][3][1].contPayload = 6312.1; array_pt[9][3][1].contTare = 250; array_pt[9][3][1].contGross = 7500; strcpy(array_pt[9][3][1].contISOCode, "22BU"); strcpy(array_pt[9][3][1].contType, "Refrigerated"); array_pt[9][3][1].contTemp = 7;
	strcpy(array_pt[3][6][9].ID, "3257"); array_pt[3][6][9].contPayload = 4591; array_pt[3][6][9].contTare = 250; array_pt[3][6][9].contGross = 7500; strcpy(array_pt[3][6][9].contISOCode, "22BU"); strcpy(array_pt[3][6][9].contType, "Refrigerated"); array_pt[3][6][9].contTemp = 7;
	strcpy(array_pt[7][3][2].ID, "9753"); array_pt[7][3][2].contPayload = 2098.03; array_pt[7][3][2].contTare = 250; array_pt[7][3][2].contGross = 5000; strcpy(array_pt[7][3][2].contISOCode, "20GP"); strcpy(array_pt[7][3][2].contType, "Not Refrigerated"); array_pt[7][3][2].contTemp = -5;
	
	strcpy(array_pt[5][3][8].ID, "5438"); array_pt[5][3][8].contPayload = 5161.21; array_pt[5][3][8].contTare = 250; array_pt[5][3][8].contGross = 7500; strcpy(array_pt[5][3][8].contISOCode, "22BU"); strcpy(array_pt[5][3][8].contType, "Not Refrigerated"); array_pt[5][3][8].contTemp = -5;
	strcpy(array_pt[3][1][6].ID, "7645"); array_pt[3][1][6].contPayload = 5178.6; array_pt[3][1][6].contTare = 400; array_pt[3][1][6].contGross = 7500; strcpy(array_pt[3][1][6].contISOCode, "20TD"); strcpy(array_pt[3][1][6].contType, "Not Refrigerated"); array_pt[3][1][6].contTemp = -5;
	strcpy(array_pt[5][9][2].ID, "4356"); array_pt[5][9][2].contPayload = 1237; array_pt[5][9][2].contTare = 250; array_pt[5][9][2].contGross = 5000; strcpy(array_pt[5][9][2].contISOCode, "20GP"); strcpy(array_pt[5][9][2].contType, "Refrigerated"); array_pt[5][9][2].contTemp = 7;
	strcpy(array_pt[4][3][2].ID, "2352"); array_pt[4][3][2].contPayload = 5763; array_pt[4][3][2].contTare = 250; array_pt[4][3][2].contGross = 7500; strcpy(array_pt[4][3][2].contISOCode, "22BU"); strcpy(array_pt[4][3][2].contType, "Refrigerated"); array_pt[4][3][2].contTemp = 7;
	strcpy(array_pt[1][2][8].ID, "7352"); array_pt[1][2][8].contPayload = 3652.49; array_pt[1][2][8].contTare = 250; array_pt[1][2][8].contGross = 7500; strcpy(array_pt[1][2][8].contISOCode, "22BU"); strcpy(array_pt[1][2][8].contType, "Refrigerated"); array_pt[1][2][8].contTemp = 7;
	
	strcpy(array_pt[4][7][1].ID, "3427"); array_pt[4][7][1].contPayload = 6512.24; array_pt[4][7][1].contTare = 400; array_pt[4][7][1].contGross = 7000; strcpy(array_pt[4][7][1].contISOCode, "20TD"); strcpy(array_pt[4][7][1].contType, "Refrigerated"); array_pt[4][7][1].contTemp = 7;
	strcpy(array_pt[3][4][3].ID, "2634"); array_pt[3][4][3].contPayload = 3412.5; array_pt[3][4][3].contTare = 200; array_pt[3][4][3].contGross = 4500; strcpy(array_pt[3][4][3].contISOCode, "20HR"); strcpy(array_pt[3][4][3].contType, "Not Refrigerated"); array_pt[3][4][3].contTemp = -5;
	strcpy(array_pt[2][3][2].ID, "2352"); array_pt[2][3][2].contPayload = 4217.08; array_pt[2][3][2].contTare = 250; array_pt[2][3][2].contGross = 5000; strcpy(array_pt[2][3][2].contISOCode, "20GP"); strcpy(array_pt[2][3][2].contType, "Not Refrigerated"); array_pt[2][3][2].contTemp = -5;
	strcpy(array_pt[3][4][8].ID, "7547"); array_pt[3][4][8].contPayload = 6456.12; array_pt[3][4][8].contTare = 250; array_pt[3][4][8].contGross = 7500; strcpy(array_pt[3][4][8].contISOCode, "22BU"); strcpy(array_pt[3][4][8].contType, "Refrigerated"); array_pt[3][4][8].contTemp = 7;
	strcpy(array_pt[8][9][2].ID, "3452"); array_pt[8][9][2].contPayload = 7148; array_pt[8][9][2].contTare = 250; array_pt[8][9][2].contGross = 7500; strcpy(array_pt[8][9][2].contISOCode, "22BU"); strcpy(array_pt[8][9][2].contType, "Refrigerated"); array_pt[8][9][2].contTemp = 7;
	
	strcpy(array_pt[2][7][8].ID, "6237"); array_pt[2][7][8].contPayload = 4313; array_pt[2][7][8].contTare = 250; array_pt[2][7][8].contGross = 5000; strcpy(array_pt[2][7][8].contISOCode, "20GP"); strcpy(array_pt[2][7][8].contType, "Refrigerated"); array_pt[2][7][8].contTemp = 7;
	strcpy(array_pt[3][2][8].ID, "6794"); array_pt[3][2][8].contPayload = 3218.23; array_pt[3][2][8].contTare = 250; array_pt[3][2][8].contGross = 5000; strcpy(array_pt[3][2][8].contISOCode, "20GP"); strcpy(array_pt[3][2][8].contType, "Not Refrigerated"); array_pt[3][2][8].contTemp = -5;
	strcpy(array_pt[5][6][3].ID, "5636"); array_pt[5][6][3].contPayload = 4123; array_pt[5][6][3].contTare = 250; array_pt[5][6][3].contGross = 5000; strcpy(array_pt[5][6][3].contISOCode, "20GP"); strcpy(array_pt[5][6][3].contType, "Refrigerated"); array_pt[5][6][3].contTemp = 7;
	strcpy(array_pt[4][6][5].ID, "9783"); array_pt[4][6][5].contPayload = 1238.79; array_pt[4][6][5].contTare = 200; array_pt[4][6][5].contGross = 4500; strcpy(array_pt[4][6][5].contISOCode, "20HR"); strcpy(array_pt[4][6][5].contType, "Refrigerated"); array_pt[4][6][5].contTemp = 7;
	strcpy(array_pt[3][3][2].ID, "2134"); array_pt[3][3][2].contPayload = 4215.21; array_pt[3][3][2].contTare = 400; array_pt[3][3][2].contGross = 7000; strcpy(array_pt[3][3][2].contISOCode, "20TD"); strcpy(array_pt[3][3][2].contType, "Not Refrigerated"); array_pt[3][3][2].contTemp = -5;
	
	add_cont(array_ptr,1111,1,1,1);
	add_cont(array_ptr,2222,6,4,4);
	add_cont(array_ptr,3131,4,4,4);
	add_cont(array_ptr,6421,1,2,3);
	add_cont(array_ptr,5366,3,7,2);
	add_cont(array_ptr,2356,2,1,3);
	add_cont(array_ptr,2341,5,2,3);
	add_cont(array_ptr,5674,9,3,1);
	add_cont(array_ptr,3257,3,6,9);
	add_cont(array_ptr,9753,7,3,2);
	add_cont(array_ptr,5423,5,3,8);
	add_cont(array_ptr,7645,3,1,6);
	add_cont(array_ptr,4356,5,9,2);
	add_cont(array_ptr,2352,4,3,2);
	add_cont(array_ptr,7352,1,2,8);
	add_cont(array_ptr,3427,4,7,1);
	add_cont(array_ptr,2634,3,4,3);
	add_cont(array_ptr,2352,2,3,2);
	add_cont(array_ptr,7547,3,4,8);
	add_cont(array_ptr,3452,8,9,2);
	add_cont(array_ptr,6237,2,7,8);
	add_cont(array_ptr,6794,3,2,8);
	add_cont(array_ptr,5636,5,6,3);
	add_cont(array_ptr,9783,4,6,5);
	add_cont(array_ptr,2134,3,3,2);
	
	print_arraywith0(array_ptr);

	print_array(array_ptr);
	
	return 0;
}




