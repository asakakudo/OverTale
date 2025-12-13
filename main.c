#include <stdio.h>
#include "game-state.h"
#include "story.h"
#include "util.h"

int main() {
    GameState player;
    
    player.suspicionMeter = 0;
    player.hasEatenDog = 0;
    player.hasFrisbee = 0;
    player.hasBall = 0;
    player.hasKnife = 0;
    player.hasKnot = 0;

    play_prologue();
    play_chapter_forest(&player); 
    play_chapter_house(&player);
    play_chapter_TheFields(&player);
    play_chapter_conflict(&player);

    return 0;
}