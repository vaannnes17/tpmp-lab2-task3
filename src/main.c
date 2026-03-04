#include <stdio.h>
#include "airplane.h"

int main() {
    AIRPLANE planes[MAX_AIRPLANES];
    int count;
    char searchDirection[MAX_STRING];
    
    printf("=== АВИАРЕЙСЫ ===\n");
    count = inputAirplanes(planes, MAX_AIRPLANES);
    
    if (count == 0) {
        printf("Нет данных\n");
        return 0;
    }
    
    printf("\n=== ВСЕ РЕЙСЫ ===\n");
    for (int i = 0; i < count; i++) {
        printAirplane(planes[i]);
    }
    
    int maxIndex = findMaxDurationFlight(planes, count);
    if (maxIndex != -1) {
        printf("\n=== РЕЙС С МАКСИМАЛЬНОЙ ДЛИТЕЛЬНОСТЬЮ ===\n");
        printAirplane(planes[maxIndex]);
    }
    
    printf("\nВведите направление для поиска: ");
    scanf("%s", searchDirection);
    printFlightsByDirection(planes, count, searchDirection);
    
    float avgDistance = calculateAverageDistance(planes, count);
    printf("\nСреднее расстояние: %.2f км\n", avgDistance);
    
    countFlightsByModel(planes, count);
    
    return 0;
}
