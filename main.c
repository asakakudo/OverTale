#include <stdio.h>
#include "game-state.h"
#include "story.h"
#include "util.h"

int main() {
    GameState player;
    
    player.suspicionMeter = 0;
    player.hasEatenDog = 0;
    player.hasFrisbee = 0;

    play_prologue();
    play_chapter_forest(&player); 

    //play_chapter_house(&player);

    return 0;
}