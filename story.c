#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h> // For sleep() / usleep() on Unix-like systems
#endif
#include "story.h"
#include "util.h"  // Ngambil fungsi slow_print dan clear_screen dari util.h

void play_prologue() {
    // Dipecah menjadi string terpisah biar tidak perlu menghitung offset
    
    const char *part1 = 
        "Deep beneath the surface of the earth, hidden away from the touch of sunlight,\n"
        "there existed a world of darkness unknown to mankind.\n"
        "In that forgotten place, a strange creature was born, a shapeless entity";

    const char *part2 = "It is you";

    const char *part3 = 
        "You've lived alone for centuries, surrounded only by echoes and silence.\n"
        "Yet inside your heart, one dream never faded:\n"
        "to one day reach the surface, and live peacefully with the surface dwellers";

    const char *part4 = "humans";

    const char *part5 = 
        "Every night you imagined warmth, laughter, and the feeling of being accepted.\n"
        "Even though you knew.. you were nothing like a human.\n\n"
        "Until one night, a crack in the earth opened,\n"
        "and the moonlight touched your body for the very first time.\n"
        "This was the moment you've been waiting for.";

    print_title();
    #ifdef _WIN32
    Sleep(2000); // Sleep takes milliseconds
    #else
    sleep(2); // sleep takes seconds
    #endif

    slow_print(part1, 35, 0); //print story opening pertama 
    dot_animation();
    printf("\n\n");

    slow_print(part2, 35, 0); 
    dot_animation();
    printf("\n\n");

    slow_print(part3, 35, 0); 
    dot_animation();
    printf("\n\n");

    slow_print(part4, 35, 0); 
    dot_animation();
    printf("\n\n");

    slow_print(part5, 35, 0); 
    printf("\n\n"); 

    printf("Press ENTER to continue...");
    getchar(); 
    printf("\n");
}
    
// Fungsi buat Chapter 1
void play_chapter_forest(GameState *state) {

    slow_print("\nYou crawled out of the abyss and was met with the sight of the surface,\n", 35, 0);
    slow_print("It is beautifull, stunning, nothing like you've ever seen, the moon light shines on your body,\n", 35, 0);
    slow_print("the wind of the night soothes your skin,\n", 35, 0);
    slow_print("it slithers through the pine trees, blessing your ears with such peacefull ambience.\n", 35, 0);
    slow_print("As you admire your soroundings\n", 35, 0);
    slow_print("You heard something\n", 35, 0);
    slow_print("In the bushes nearby there was something making noises\n", 35, 0);
    slow_print("The creature slowly, reveals itself as it walks towards you,\n", 35, 0);
    slow_print("letting the moonlight reveal it's form, you see that it walks on all fours\n", 35, 0);
    slow_print("it is covered in fluff from head to tail, unlike you.\n\n", 35, 0);
    slow_print("As you were admiring it, it spotted you\n", 35, 0);
    slow_print("Slowly, the creature approaches you with curiosity\n", 35, 0);
    slow_print("The creature doesnt seem to pose any threat to you, but rather has interest in you\n", 35, 0);
    slow_print("You can feel air coming coming out of it snouts as it sniffes you\n", 35, 0);
    // Narasi pikiran (gunakan warna atau tanda kurung berbeda agar menarik)
    printf("\n( \"This creature is awesome...\" you think )\n\n");
    
    // --- PILIHAN ---
    printf("What would you do?\n");
    printf("[1] Eat this creature (Changes shape in order to look familiar)\n");
    printf("[2] Let this creature go (Stay in its original form)\n");
    printf("Your choice > ");
    
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        // --- Path: MAKAN ANJING ---
        printf("\n");
        slow_print("You choose to eat this dog...\n", 40, 0);
        slow_print("Maybe by eating this dog I can transform into something\n", 30, 0);
        slow_print("something more familiar to humans...\n\n", 30, 0);

        slow_print("Your body expands and silently envelops the dog.\n", 50, 0);
        slow_print("The dog then disappears and is gone.\n", 40, 0);
        slow_print("You then transform into the dog...\n", 40, 0);

        // Update Game State
        state->hasEatenDog = 1;

        slow_print("\n[You get access to this dog's memory.]\n", 20, 0);
        slow_print("You see a small house, a boy,\n", 30, 0);
        slow_print("and something big that is ambiguous and seems dangerous...\n", 30, 0);

    } else {
        // --- Path: TIDAK MAKAN (Wujud Asli) ---
        printf("\n");
        slow_print("You let the dog go.\n", 30, 0);
        slow_print("You feel your true form is good enough.\n", 30, 0);

        // Update Game State
        state->hasEatenDog = 0;
    }

    // Aslinya akan dipanggil di chapter 2
    if (state->hasEatenDog == 0) {
    slow_print("The man's eyes widened at your terrifying true form...\n", 20, 0);
    slow_print("\"WHAT THE HELL ARE YOU?\" he shouted, aiming the shotgun.\n", 20, 0);
    slow_print("BANG!!\n", 10, 0);

    trigger_game_over("You were shot because you were still in Monster form.");
    }

    printf("\nPress ENTER to continue your journey");
    dot_animation();
    printf("\n\n");
    getchar();
}