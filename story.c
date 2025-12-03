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
    //Memakai warna atau tanda kurung berbeda agar menarik)
    printf("\n( \"This creature is awesome...\" you think )\n\n, 35, 0");
    
    // --- PILIHAN ---
    printf("What would you do?\n");
    printf("[1] Eat this creature (Changes shape in order to look familiar)\n, 35, 0");
    printf("[2] Let this creature go (Stay in its original form)\n, 35, 0");
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
    
        printf("\nPress ENTER to continue your journey");
        dot_animation();
        printf("\n\n");
        getchar();

    }
void play_chapter_house(GameState *state) {
    clear_screen();

    if (state->hasEatenDog == 1) {

    slow_print("Following the dog's memory, you found your way out of the forest.\n", 35, 0);
    slow_print("You see a small house, just like in the vision.\n", 35, 0);
    slow_print("You approach the front door and scratch it like a dog.\n\n", 35, 0);
    
    printf("... *SCRATCH* *SCRATCH* ...\n\n");
    #ifdef _WIN32
    Sleep(1000);
    #else
    sleep(1);
    #endif

    slow_print("The door opens.\n", 40, 0);
    slow_print("A large man appears, holding a SHOTGUN in his hand.\n", 40, 0);
    slow_print("He smells of alcohol and sweat. An unpleasant scent.\n", 35, 0);
    } else if (state->hasEatenDog == 0) {

        slow_print("You following the dog to found your way out of the forest.\n", 35, 0);
        slow_print("You see a small house\n", 35, 0);
        slow_print("The Dog approach the front door and scratch it.\n\n", 35, 0);

        printf("... *SCRATCH* *SCRATCH* ...\n\n");
        #ifdef _WIN32
        Sleep(1000);
        #else
        sleep(1);
        #endif

        slow_print("The door opens.\n", 40, 0);
        slow_print("A large man appears, holding a SHOTGUN in his hand.\n", 40, 0);
        slow_print("He smells of alcohol and sweat. An unpleasant scent.\n", 35, 0);
        slow_print("THE MAN WATCHES YOU FROM A DISTANCE !.\n", 35, 0);
        slow_print("The man's eyes go wide seeing your shapeless form !\n", 20, 0);
        slow_print("\"WHAT THE HELL ARE YOU?!\" he screams.\n", 20, 0);
        slow_print("He aims the shotgun at your head.\n", 30, 0);
        slow_print("BANG!!!\n", 10, 0);     
        
        trigger_game_over("You approached a human in Monster form and got shot.");
        return;
    }

    slow_print("The man looks down at you.\n", 35, 0);
    slow_print("\"Stupid dog... finally came home?\" he grumbles.\n", 35, 0);
    slow_print("He lowers the shotgun and lets you in.\n\n", 35, 0);

    printf("Press ENTER to enter the house...");
    getchar();
    clear_screen();

    // Masuk Rumah 
    slow_print("Inside, the house is a mess.\n", 35, 0);
    slow_print("Empty bottles are scattered everywhere.\n", 35, 0);
    slow_print("Among the chaos, you see the little boy from the memory.\n\n", 35, 0);

    // Pertemuan dengan Sang Anak 
    slow_print("\"DEXTER!\" the boy shouts.\n", 35, 0);
    slow_print("He runs to you and hugs you tightly.\n", 35, 0);
    slow_print("You feel his relief. A memory flashes in your mind...\n", 35, 0);
    slow_print("(You see this boy playing happily with a woman with beautiful long hair.)\n", 35, 0);
    printf("( \"Who is she?\" you wonder. )\n\n");

    // Interaksi dengan Ayah 
    slow_print("The moment is ruined by the man's sharp voice.\n", 35, 0);
    slow_print("\"Stupid dog. Don't disappear at night again!\"\n", 35, 0);
    
    // Ayah menendang (tidak sakit tapi membingungkan)
    slow_print("The man kicks you slightly.\n", 35, 0); 
    slow_print("It didn't hurt much, but you are confused.\n", 35, 0);
    slow_print("The boy goes silent, afraid to speak back.\n", 35, 0);
    slow_print("You realize: This man is the 'dangerous thing' from the dog's memory.\n\n", 35, 0);

    printf("Press ENTER to follow the boy...");
    getchar();
    clear_screen();

    // Di Kamar Dexter 
    slow_print("The boy leads you to his room to avoid the man.\n", 35, 0);
    slow_print("\"We better stay away... he is not okay right now,\" the boy whispers.\n\n", 35, 0);
    
    slow_print("\"Where were you? I don't want to lose anything else...\"\n", 35, 0);
    slow_print("\"...ever since Mom died.\"\n\n", 40, 0);

    printf("( \"Mom?\" You don't have a clear idea who that is. )\n\n");

    slow_print("\"Let's just sleep for tonight. We can play tomorrow, okay?\"\n", 35, 0);
    slow_print("\"We can't be too loud.\"\n\n", 35, 0);

    slow_print("You obey the boy's request and curl up on the floor.\n", 35, 0);
    slow_print("This is your first night in the human world.\n", 35, 0);

    printf("\nPress ENTER to Sleep...");
    getchar();
}