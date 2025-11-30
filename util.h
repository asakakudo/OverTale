#ifndef UTILS_H
#define UTILS_H

// Menampilkan judul game
void print_title();

// Menampilkan teks satu per satu dengan delay (ms)
void slow_print(const char *str, int delay, int charPosition);

// Animasi titik (...)
void dot_animation();

// Membersihkan layar terminal
void clear_screen();

// Menampilkan layar Game Over dan alasan kematian
void trigger_game_over(const char *reason);

#endif
