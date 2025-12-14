#ifndef GAME_STATE_H
#define GAME_STATE_H

typedef struct {
    int suspicionMeter; // 0 - 100
    int hasEatenDog;    // 1 : True, 0 : False
    int hasFrisbee;     // 1 : True, 0 : False
    int hasBall;
    int hasKnife;
    int HelpOrNot;
} GameState;

#endif