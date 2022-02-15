#include <stdio.h>
#include "determineEnergyContainer.h"
#include "is_refrigerated.h"

//Assumindo que o contentor tem as seguintes dimensões: 6m x 2,5m x 2,5 m -> Tal como é demonstrado no word de exemplo de cálculos fornecido, o valor de Rt vai ser = 3,13*10^-3 K/W

#define VALORRT 0.00313

int determineEnergyContainer()
{
	int result, x, y, z;		
	int tempoViagem;												    //resultado diferente de 0 e 1
	double temperatura, deltaQ = 0, rt, q, energia;
	double temperaturaIntMax = 7;
	
	printf("\nPlease type the container position (x,y,z)");
	scanf("%d %d %d", &x, &y, &z);
	
	result = is_refrigerated(container,x, y, z);
	
	if(result == 0){
		printf("\nThe container is not refrigerated");
	}else if(result == 1){
		
		printf("\nPlease type the outside temperature:");				//Pede a temperatura exterior necessária para os cálculos
		scanf("%lf", &temperatura);
		
		deltaQ = temperatura - temperaturaIntMax;
		
		rt = VALORRT;													//Valor RT
		
		q = deltaQ/rt;
		
		printf("\nPlease type the trip duration:");						
		scanf("%d", &tempoViagem);
		
		energia = q * tempoViagem;										//Formula utilizada para receber a energia necessaria durante a viagem toda
		
		printf("Vai ser necessario fornecer %lf J de energia ao contentor", energia);
	}
	
	return 0;
}

