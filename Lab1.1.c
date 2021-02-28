#include <stdio.h>

void hoursPrint (unsigned const int hours) {
    if (hours / 60 < 10) {
        printf("0%d:", hours / 60);
    }
    else {
        printf("%d:", hours / 60);
    }
}

void minutesPrint (unsigned const int minutes) {
    if (minutes % 60 < 10) {
        printf("0%d", minutes % 60);
    }
    else {
        printf("%d", minutes % 60);
    }
}

void oneWay(unsigned int* startMinutes, unsigned const int travelTime, unsigned const int breakTime) {
    hoursPrint (*startMinutes);
    minutesPrint (*startMinutes);
    printf(" - ");

    *startMinutes += travelTime;
    
    hoursPrint (*startMinutes);
    minutesPrint (*startMinutes);

    *startMinutes += breakTime;
}

void calcShedule (
    unsigned int* startMinutes,
    unsigned const int finishMinutes,
    unsigned const int travelTime,
    unsigned const int breakTime
) {
    printf(" From A to B \t\t\tFrom B to A\n");

    /*The work of the bus includes the path to the starting point, so there will be no path only to B*/
    while (*startMinutes <= finishMinutes && *startMinutes + 2 * (travelTime + breakTime) <= finishMinutes) {
        oneWay(startMinutes, travelTime, breakTime);
        printf("\t\t\t");
        oneWay(startMinutes, travelTime, breakTime);
        printf("\n");
    }
}

int main() {

    unsigned int startHours, startMinutes, finishHours, finishMinutes, travelTime, breakTime;

    do {
        fflush(stdin);
        printf("Enter starting time(please, use \"6 00\" format): ");
    }
    while (scanf(" %d %d", &startHours, &startMinutes) != 2 || startHours > 22 || startMinutes > 60);
    fflush(stdin);
    startMinutes += startHours * 60;

    do {
        fflush(stdin);
        printf("Enter finish time(please, use \"22 00\" format): ");
        fflush(stdin)
    }
    while (scanf(" %d %d", &finishHours, &finishMinutes) != 2 || finishHours <= startHours ||
          ((finishHours == 24 && finishMinutes != 0) || finishHours > 24 || finishMinutes > 60));
    finishMinutes += finishHours * 60;

    do {
        fflush(stdin);
        printf("Enter travel time in minutes(10 - minimum, 360 - maximum): ");
        fflush(stdin);
    }
    while (scanf("%d", &travelTime) != 1 || travelTime > 360 || travelTime < 10);

    do {
        fflush(stdin);
        printf("Enter time to rest in minutes(travel time or 120 is maximum): ");
        fflush(stdin);
    }
    while (scanf(" %d", &breakTime) != 1 || breakTime > 120 || breakTime > travelTime);

    calcShedule(&startMinutes, finishMinutes, travelTime, breakTime);
    return 0;
}