#ifndef ENERGY_H
#define ENERGY_H
typedef struct
{
    char ID[30];
    double contPayload;
    double contTare;
    double contGross;
    char contISOCode[30];
    char contType[30];
    double contTemp;
} container;

int determineEnergyContainer();

#endif
