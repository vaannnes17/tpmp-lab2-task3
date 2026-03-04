#ifndef AIRPLANE_H
#define AIRPLANE_H

#define MAX_AIRPLANES 12
#define MAX_STRING 50

typedef struct {
    int hours;
    int minutes;
} Time;

typedef struct {
    int flightNumber;
    Time departureTime;
    Time arrivalTime;
    char direction[MAX_STRING];
    char aircraftModel[MAX_STRING];
    int distance;
} AIRPLANE;

int inputAirplanes(AIRPLANE *planes, int maxCount);
void printAirplane(AIRPLANE plane);
int calculateFlightDuration(AIRPLANE plane);
int findMaxDurationFlight(AIRPLANE *planes, int count);
void printFlightsByDirection(AIRPLANE *planes, int count, const char *direction);
float calculateAverageDistance(AIRPLANE *planes, int count);
void countFlightsByModel(AIRPLANE *planes, int count);

#endif
