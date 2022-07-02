#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#ifndef _CLEAR_SCREEN_MAC_
#define _CLEAR_SCREEN_ system("clear")
#endif

void input_radar_count(int len);

int *RADARS;
int *TECHNIQUES;
int CURRENT;

void input_radar_count(int len) {
    int i, j;
    RADARS = (int * ) malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i) 
        RADARS[i] = -1;

    for(i = 0; i < len; ++i) {
        printf("Total %d types of radars, Enter their jamming techniques count: ", len);
        for(j = 0; j < len; ++j)
            if(RADARS[j] == -1)
                printf(" x");
            else 
                printf(" %d", RADARS[j]);
        printf("\nEnte the count of jaming technique #%d: ", i+1);
        scanf("%d", &RADARS[i]);
        _CLEAR_SCREEN_;
    }
}

void start_simulation(int * arr, int len, int technique_len) {
    input_radar_count(technique_len);
    for(int i = 0; i < len; ++i) {
        printf("%d ", RADARS[i]);
    }
    printf("\n");
}
