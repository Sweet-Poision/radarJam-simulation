#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#ifndef _CLEAR_SCREEN_MAC_
#define _CLEAR_SCREEN_ system("clear")
#endif

void input_radar_count(const int len);
void copy_radar_data(const int * arr,const int len);

int *RADARS;
int *TECHNIQUES;
int CURRENT;

void input_radar_count(const int len) {
    _CLEAR_SCREEN_;
    int i, j;
    TECHNIQUES = (int * ) malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i) 
        TECHNIQUES[i] = -1;

    for(i = 0; i < len; ++i) {
        printf("Total %d types of radars, Enter their jamming techniques count: ", len);
        for(j = 0; j < len; ++j)
            if(TECHNIQUES[j] == -1)
                printf(" x");
            else 
                printf(" %d", TECHNIQUES[j]);
        printf("\nEnter the count of jaming technique #%d: ", i+1);
        scanf("%d", &TECHNIQUES[i]);
        _CLEAR_SCREEN_;
    }
}

void copy_radar_data(const int * arr,const int len) {
    int i;
    RADARS = (int * )malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i) 
        RADARS[i] = arr[i];
}

void start_simulation(const int * arr, const int len, const int technique_len) {
    input_radar_count(technique_len);
    copy_radar_data(arr,len);
}
