#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h>
#endif
#include "util.h"

void print_title() { 
    printf("========================================================\n");
    printf("                     O V E R T A L E              \n");
    printf("========================================================\n\n");
}

void slow_print(const char *str, int delay, int charPosition) { 
    int i = charPosition; // Initialize i with charPosition
    while (str[i] != '\0') {
        printf("%c", str[i]);
        fflush(stdout);
    #ifdef _WIN32
        Sleep(delay);
    #else
        usleep(delay * 1000);
    #endif
        i++;
    }
}

void dot_animation(){
    for(int i = 1; i <= 3; i++){
        printf(". ");
        fflush(stdout);
    #ifdef _WIN32
        Sleep(1000); // Sleep takes milliseconds
    #else
        sleep(1); // sleep takes seconds
    #endif
    }
}

void clear_screen() {
    // Fungsi tambahan biar terminal bersih saat ganti scene
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void trigger_game_over(const char *reason) {
    clear_screen(); 

    printf("\n");
    printf("=========================================\n");
    printf("           G A M E   O V E R             \n");
    printf("=========================================\n\n");
    
    // Tampilkan alasan kematian 
    printf("DEAD: %s\n\n", reason);
    
    printf("=========================================\n");
    printf("Press ENTER to exit the game...");
    getchar(); 
    getchar();
    
    // Keluar paksa dari program
    exit(0); 
}

void animate_suspicion_meter(int *currentValue, int targetValue) {
    int step = (*currentValue < targetValue) ? 1 : -1;
    int value = *currentValue;

    while (value != targetValue) {
        value += step;

        int barLength = value / 2;
        if (barLength > 50) {barLength = 50;}
        if (barLength < 0) {barLength = 0;}

        char bar[60];
        for (int i = 0; i < barLength; i++){ 
        bar[i] = '#';
        bar[barLength] = '\0';

        printf("\rSuspicion: [%s] %d%%   ", bar, value);
        fflush(stdout);

        #ifdef _WIN32
            Sleep(10);
        #else
            usleep(20000);
        #endif
        }
    }

    *currentValue = targetValue;
    printf("\n");
}