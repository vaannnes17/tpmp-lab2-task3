#include <stdio.h>
#include <string.h>
#include "airplane.h"

int inputAirplanes(AIRPLANE *planes, int maxCount) {
    int count;
    printf("Введите количество авиарейсов (не более %d): ", maxCount);
    scanf("%d", &count);
    
    if (count > maxCount) {
        count = maxCount;
    }
    
    for (int i = 0; i < count; i++) {
        printf("\n--- Авиарейс №%d ---\n", i + 1);
        printf("Номер рейса: ");
        scanf("%d", &planes[i].flightNumber);
        printf("Время вылета (часы минуты): ");
        scanf("%d %d", &planes[i].departureTime.hours, &planes[i].departureTime.minutes);
        printf("Время прилёта (часы минуты): ");
        scanf("%d %d", &planes[i].arrivalTime.hours, &planes[i].arrivalTime.minutes);
        printf("Направление: ");
        scanf("%s", planes[i].direction);
        printf("Марка самолёта: ");
        scanf("%s", planes[i].aircraftModel);
        printf("Расстояние (км): ");
        scanf("%d", &planes[i].distance);
    }
    
    return count;
}

void printAirplane(AIRPLANE plane) {
    int duration = calculateFlightDuration(plane);
    int durationHours = duration / 60;
    int durationMinutes = duration % 60;
    
    printf("Рейс №%d | %s | %s | %02d:%02d-%02d:%02d | %d км | %02d:%02d\n",
           plane.flightNumber,
           plane.direction,
           plane.aircraftModel,
           plane.departureTime.hours, plane.departureTime.minutes,
           plane.arrivalTime.hours, plane.arrivalTime.minutes,
           plane.distance,
           durationHours, durationMinutes);
}

int calculateFlightDuration(AIRPLANE plane) {
    int departure = plane.departureTime.hours * 60 + plane.departureTime.minutes;
    int arrival = plane.arrivalTime.hours * 60 + plane.arrivalTime.minutes;
    
    if (arrival < departure) {
        arrival += 24 * 60;
    }
    
    return arrival - departure;
}

int findMaxDurationFlight(AIRPLANE *planes, int count) {
    if (count <= 0) return -1;
    
    int maxIndex = 0;
    int maxDuration = calculateFlightDuration(planes[0]);
    
    for (int i = 1; i < count; i++) {
        int duration = calculateFlightDuration(planes[i]);
        if (duration > maxDuration) {
            maxDuration = duration;
            maxIndex = i;
        }
    }
    
    return maxIndex;
}

void printFlightsByDirection(AIRPLANE *planes, int count, const char *direction) {
    printf("\nРейсы по направлению '%s':\n", direction);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(planes[i].direction, direction) == 0) {
            printAirplane(planes[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Рейсов не найдено\n");
    }
}

float calculateAverageDistance(AIRPLANE *planes, int count) {
    if (count == 0) return 0;
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += planes[i].distance;
    }
    
    return (float)sum / count;
}

void countFlightsByModel(AIRPLANE *planes, int count) {
    printf("\nКоличество рейсов по маркам самолётов:\n");
    
    int counted[MAX_AIRPLANES] = {0};
    
    for (int i = 0; i < count; i++) {
        if (counted[i]) continue;
        
        int modelCount = 1;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(planes[i].aircraftModel, planes[j].aircraftModel) == 0) {
                modelCount++;
                counted[j] = 1;
            }
        }
        
        printf("%s: %d\n", planes[i].aircraftModel, modelCount);
    }
}
