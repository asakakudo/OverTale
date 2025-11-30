#ifndef STORY_H
#define STORY_H

#include "game-state.h"

void play_prologue();

// Fungsi buat Chapter 1
// Mengembalikan 1 jika pemain makan anjing, 0 jika ga makan
void play_chapter_forest(GameState *state);

#endif

