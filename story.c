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
    
    print_title();
    #ifdef _WIN32
    Sleep(2000); // Sleep takes milliseconds
    #else
    sleep(2); // sleep takes seconds
    #endif

    slow_print("Deep beneath the surface of the earth, hidden away from the touch of sunlight,\n", 35, 0);
    slow_print("there existed a world of darkness unknown to mankind.\n", 35, 0);
    slow_print("In that forgotten place, a strange creature was born, a shapeless entity", 35, 0); //print story opening pertama 
    dot_animation();
    printf("\n\n");

    slow_print("It is you", 35, 0); 
    dot_animation();
    printf("\n\n");

    slow_print("You've lived alone for centuries, surrounded only by echoes and silence.\n", 35, 0);
    slow_print("Yet inside your heart, one dream never faded:\n", 35, 0);
    slow_print("to one day reach the surface, and live peacefully with the surface dwellers", 35, 0); 
    dot_animation();
    printf("\n\n");

    slow_print("humans", 35, 0); 
    dot_animation();
    printf("\n\n");

    slow_print("Every night you imagined warmth, laughter, and the feeling of being accepted.\n", 35, 0);
    slow_print("Even though you knew.. you were nothing like a human.\n\n", 35, 0);
    slow_print("Until one night, a crack in the earth opened,\n", 35, 0);
    slow_print("and the moonlight touched your body for the very first time.\n", 35, 0);
    slow_print("This was the moment you've been waiting for.", 35, 0); 
    printf("\n\n"); 

    printf("Press ENTER to continue...");
    getchar(); 
}
    
// Fungsi buat Chapter 1
void play_chapter_forest(GameState *state) {

    slow_print("\nYou crawled out of the abyss and was met with the sight of the surface,\n", 35, 0);
    slow_print("It is beautifull, stunning, nothing like you've ever seen, the moon light shines on your body,\n", 35, 0);
    slow_print("the wind of the night soothes your skin,\n", 35, 0);
    slow_print("it slithers through the pine trees, blessing your ears with such peacefull ambience.\n", 35, 0);
    slow_print("As you admire your soroundings\n\n", 35, 0);
    slow_print("You heard something", 35, 0);
    dot_animation();
    printf("\n\n");
    slow_print("In the bushes nearby there was something making noises\n", 35, 0);
    slow_print("The creature slowly, reveals itself as it walks towards you,\n", 35, 0);
    slow_print("letting the moonlight reveal it's form, you see that it walks on all fours\n", 35, 0);
    slow_print("it is covered in fluff from head to tail, unlike you.\n\n", 35, 0);
    slow_print("As you were admiring it, it spotted you\n", 35, 0);
    slow_print("Slowly, the creature approaches you with curiosity\n", 35, 0);
    slow_print("The creature doesnt seem to pose any threat to you, but rather has interest in you\n", 35, 0);
    slow_print("You can feel air coming coming out of it snouts as it sniffes you\n", 35, 0);
    //Memakai warna atau tanda kurung berbeda agar menarik)
    printf("\n( \"This creature is awesome...\" you think )\n\n", 35, 0);
    
    // --- PILIHAN ---
    printf("What would you do?\n");
    printf("[1] Eat this creature (Changes shape in order to look familiar)\n", 35, 0);
    printf("[2] Let this creature go (Stay in its original form)\n", 35, 0);
    printf("Your choice > ");
    
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        // --- Path: MAKAN ANJING ---
        printf("\n");
        slow_print("You choose to eat this dog...\n", 40, 0);
        slow_print("\"Maybe by eating this dog I can transform into something\"\n", 30, 0);
        slow_print("something more familiar to humans...\n\n", 30, 0);

        slow_print("Your body expands and rapidly envelops the dog.\n", 50, 0);
        slow_print("It struggled in vain and just in a second, it's gone", 40, 0);
        dot_animation();
        printf("\n");
        slow_print("You then transform into the dog\n", 40, 0);


        // Update Game State
        state->hasEatenDog = 1;

        slow_print("\n[You get access to this dog's memory.]\n", 20, 0);
        slow_print("(You see a small house, a small human like figure),\n", 30, 0);
        slow_print("(and something big that is ambiguous it seems dangerous)", 30, 0);
        dot_animation();
        printf("\n");

    } else {
        // --- Path: TIDAK MAKAN (Wujud Asli) ---
        printf("\n");
        slow_print("You let the dog go.\n", 30, 0);
        slow_print("You feel your true form is good enough.\n", 30, 0);

        // Update Game State
        state->hasEatenDog = 0;
    }
    
        printf("\nPress ENTER to continue your journey...");
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
    slow_print("A foul stench overwhelms your nose, it seems to be coming from him.\n", 35, 0);
    } else if (state->hasEatenDog == 0) {

        slow_print("You followed the dog to found your way out of the forest.\n", 35, 0);
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
        slow_print("Clothes rugged, eyes red, and his hair.. it's all over the place.\n", 35, 0);
        slow_print("THE MAN WATCHES YOU FROM A DISTANCE !.\n", 35, 0);
        slow_print("The man's eyes go wide seeing your shapeless form !\n\n", 20, 0);
        slow_print("\"WHAT THE HELL ARE YOU?!\" he screams.\n\n", 20, 0);
        slow_print("He aims the shotgun at you.\n\n", 30, 0);
        slow_print("BANG!!!\n", 10, 0);     
        
        trigger_game_over("You approached a human in Monster form and got shot.");
        return;
    }

    slow_print("The man looks down at you.\n\n", 35, 0);

    slow_print("\"Stupid dog... finally came home?\" he grumbles.\n\n", 35, 0);

    slow_print("He lowers the shotgun and lets you in.\n\n", 35, 0);

    printf("Press ENTER to enter the house...");
    getchar();
    clear_screen();

    // Masuk Rumah 
    slow_print("Inside, the house is a mess.\n", 35, 0);
    slow_print("Empty bottles are scattered everywhere.\n", 35, 0);
    slow_print("Among the chaos, you see the small human from the memory.\n\n", 35, 0);

    // Pertemuan dengan Sang Anak 
    slow_print("\"DEXTER!\" the little human shouts.\n", 35, 0);
    slow_print("He runs to you and hugs you tightly.\n", 35, 0);
    slow_print("You feel his relief. A memory flashes in your mind...\n", 35, 0);
    slow_print("(You see this little human playing happily with a figure that has a beautiful long hair.)\n", 35, 0);
    slow_print("( \"So beautifull\" you thought. )\n\n", 35, 0);

    // Interaksi dengan Ayah 
    slow_print("The moment is ruined by the man's sharp voice.\n\n", 35, 0);
    slow_print("\"Damn mutt. Dissapear one more time and i'm going to sell you to the furr farm!\n", 35, 0);
    slow_print("\"I TOLD YOU TO HANDLE THE DOG BOY!!\"\n\n", 35, 0);
    
    // Ayah menendang (tidak sakit tapi membingungkan)
    slow_print("\"The man kicks you slightly.\"\n\n", 35, 0); 
    slow_print("It didn't hurt much, but you are confused.\n", 35, 0);
    slow_print("The boy goes silent, afraid to speak back.\n", 35, 0);

    slow_print("At that moment, you realize", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("This man", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("That dangerous thing", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("Its him", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("\"Let's go upstairs Dexter\" says the little human \n\n", 25, 0);

    printf("Press ENTER to follow the little human...");
    getchar();
    clear_screen();

    // Di Kamar Dexter
    slow_print("\"Yea Go to your room you useless bratt, it's better if you are not here anyway\" shout the man\n", 35, 0); 

    slow_print("The little human leads you to his room to avoid the man.\n", 35, 0);
    slow_print("\"We better stay away... he is not okay right now,\" the boy whispers.\n\n", 35, 0);
    
    slow_print("\"Where were you? I don't want to lose anything else...\"\n", 35, 0);
    slow_print("\"...ever since Mom died.\"\n\n", 40, 0);

    printf("( \"Mom?\" You don't have a clear idea who that is. But the man sure refer to this little human as boy. )\n\n");

    slow_print("\"Let's just sleep for tonight. We can play tomorrow, okay?\"\n", 35, 0);
    slow_print("\"We can't be too loud.\"\n\n", 35, 0);

    slow_print("You obey the boy's request and curl up on the floor.\n", 35, 0);
    slow_print("This is your first night in the human world.\n", 35, 0);

    printf("\nPress ENTER to Sleep...");
    getchar();
    clear_screen();

    slow_print("The night has passed", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("\"Wake up Dexter", 30, 0);
    dot_animation();
    printf("\"\n\n");

    slow_print("You heard the boy called your name.\n", 35, 0);
    slow_print("You wake up as a response.\n\n", 35, 0);

    slow_print("\"Let's go play dexter", 25, 0);
    dot_animation();
    printf("\"\n\n");

    slow_print("Play?.. PLAY?!.. Finally this is the time you have been waiting for,\n", 35, 0);
    slow_print("You can finally play with someone after years of loneliness.\n", 35, 0);
    slow_print("You act excited like how any dog would. \n\n", 35, 0);

    printf("... *HOP* *HOP* *HOP* ...\n\n");

    slow_print("\"Wow you are excited too ?\"\n", 25, 0);
    slow_print("\"Let's head to our playing field then buddy\"\n", 25, 0);
    slow_print("\"Follow me", 25, 0);
    dot_animation();
    printf("\"\n\n");

    slow_print("You followed the boy's command and runs after him,\n", 35, 0);
    slow_print("Down stairs you see that the man is no longer here, you wonder where he is, maybe he is sleeping.\n", 35, 0);
    slow_print("after pausing for a moment to think about the man, you continued to follow the boy", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("As you follow the boy you finally can feel the light of the sun on your body,\n", 35, 0);
    slow_print("it is very warm...\n", 35, 0);
    slow_print("You continued to follow the boy through what seems a smal forrest,\n", 35, 0);
    slow_print("The sounds of the birds chirping are music to your ears", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("suddenly a bight light strucked you face\n", 35, 0);
    slow_print("the edge of the forest is right infront of you\n", 35, 0);
    slow_print("you continued to move forward", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("You jumped through the light", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("The other side", 35, 0);
    dot_animation();
    printf("\n");
    slow_print("It's beautifull", 35, 0);
    dot_animation();
    printf("\n");
    slow_print("It is a small open field in the middle of the forest,\n", 35, 0);
    slow_print("the field is covered in grass, golden like the ores you've seen underground,\n", 35, 0);
    slow_print("yet, it is more beautifull", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("In the middle of the golden fields, there is a singular tree that looks different than the others,\n", 35, 0);
    slow_print("There is a swing hanging on the tree", 35, 0);

    slow_print("as you are admiring the view a vision suddenly strucked\n\n", 35, 0);
    slow_print("( You see that this place is you and your boy's play ground, and below the tree you see that long haired figure again )\n", 35, 0);
    slow_print("( Who is this figure ) you wondered \n", 35, 0);
    slow_print("( You see the figure is stretching it's hand to the air as if signaling \"right here!\" )\n", 35, 0);
    slow_print("( When you look back you see, it's the man... He is walking towards you )\n", 35, 0);
    slow_print("( He walks faster...)\n", 35, 0);
    slow_print("( Faster... \n", 35, 0);
    slow_print("( FASTER!!!!!!!!!!!!!)\n\n", 15, 0);

    slow_print("The vision stopped", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("\"Dexter...\" called the confused boy\n\n", 25, 0);

    slow_print("You were spacing out a little there\n", 35, 0);
    slow_print("This cause your suspicion bar to increase a little\n\n", 35, 0);
    //suspicion increase by 15
    slow_print("\"What's wrong dexter? Lets play...\"\n\n", 25, 0);

    slow_print("You start acting excited like a normal dog again and started playing with the little boy\n\n", 35, 0);

    slow_print("But", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("You don't know how to play exactly.\n", 35, 0);
    slow_print("When the boy asked you to play chase you didn't chase him untuill he tells you to.\n", 35, 0);
    slow_print("When the boy wanted to play fetch you stared at him untill he explains you how to play it\n\n", 35, 0);
    slow_print("It seems that you can only recall the dog's crucial memory\n\n", 35, 0);

    slow_print("Staying silent and observing first is the right decision rather than guessing how the game works\n", 35, 0);
    //suspicion bar increase by 10
    slow_print("As you were playing fetch and you were bringing back the stick to the boy\n", 35, 0);
    slow_print("The boy said\n\n", 35, 0);
    
    slow_print("\"He should be out right now\"", 35, 0);






}