#include <stdio.h>

int main (){
	
	int numbergenerators=0;
	float power=0;
	int container7number = 25;
	int container5number = 15;
	float containersize = 72.5;
	float material1resistance = 150;
	float material2resistance = 0.12;
	float material3resistance = 15;
	float material4resistance = 0.03;
	float material1size = 0.001;
	float material2size = 0.008;
	float material3size = 0.001;
	float material4size = 0.013;
	float totalresistance7 = 0.0;
	float totalresistance5 = 0.0;
	float totalenergy = 0.0;
	int traveltime=3600;
	float totalgeneratedenergy = 0.0;
	
	printf("How many generators do you have?\n");
	scanf("%d", &numbergenerators);
	printf("How much power each one have?(Watt)\n");
	scanf("%f", &power);
	
	
	totalresistance7 = (material1size/(material1resistance*containersize))+(material2size/(material2resistance*containersize))+(material3size/(material3resistance*containersize));
	totalresistance5 = (material1size/(material1resistance*containersize))+(material4size/(material4resistance*containersize))+(material3size/(material3resistance*containersize));
	
	totalenergy = (((25-7)/totalresistance7)*container7number*traveltime)+(((25+5)/totalresistance5)*container5number*traveltime);
	
	totalgeneratedenergy = numbergenerators*power*traveltime;
	
	if(totalenergy>totalgeneratedenergy){
		printf("not enough energy generated!!\n");
	}

}
