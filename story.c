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

    slow_print("\"Lets go upstairs Dexter\" says the little human \n\n", 25, 0);

    printf("Press ENTER to follow the little human...");
    getchar();
    clear_screen();

    // Di Kamar Dexter
    slow_print("\"Yea Go to your room you useless bratt, it's better if you are not here anyway\" shout the man", 35, 0); 
    dot_animation();
    printf("\n\n");

    slow_print("The little human leads you to his room to avoid the man.\n", 35, 0);
    slow_print("\"We better stay away... he is not okay right now,\" the boy whispers.\n\n", 35, 0);
    
    slow_print("\"Where were you? I don't want to lose anything else...\"\n", 35, 0);
    slow_print("\"...ever since Mom died.\"\n\n", 40, 0);

    printf("( \"Mom?\" You don't have a clear idea who that is. But the man sure refer to this little human as boy. )\n\n");

    slow_print("\"Lets just sleep for tonight. We can play tomorrow, okay?\"\n", 35, 0);
    slow_print("\"We can't be too loud.\"\n\n", 35, 0);

    slow_print("You obey the boy's request and curl up on the floor.\n", 35, 0);
    slow_print("This is your first night in the human world.\n", 35, 0);

    printf("\nPress ENTER to Sleep...");
    getchar();
    clear_screen();

}

void play_chapter_TheFields(GameState *state){
    slow_print("The night has passed", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("\"Wake up Dexter", 30, 0);
    dot_animation();
    printf("\"\n\n");

    slow_print("You heard the boy called your name.\n", 35, 0);
    slow_print("You wake up as a response.\n\n", 35, 0);

    slow_print("\"Lets go play dexter", 25, 0);
    dot_animation();
    printf("\"\n\n");

    slow_print("Play?.. PLAY?!.. Finally this is the time you have been waiting for,\n", 35, 0);
    slow_print("You can finally play with someone after years of loneliness.\n", 35, 0);
    slow_print("You act excited like how any dog would. \n\n", 35, 0);

    printf("... *HOP* *HOP* *HOP* ...\n\n");

    slow_print("\"Wow you are excited too ?\"\n", 25, 0);
    slow_print("\"Lets head to our playing field then buddy\"\n", 25, 0);
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
    slow_print("the edge of the forest is right infront of you", 35, 0);
    dot_animation();
    printf("\n\n");

    printf("press enter to jump through...");
    getchar();
    clear_screen();

    //the fields
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
    slow_print("( Faster... )\n", 35, 0);
    slow_print("( FASTER!!!!!!!!!!!!!)\n\n", 15, 0);

    slow_print("The vision stopped", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("\"Dexter...\" called the confused boy\n\n", 25, 0);

    slow_print("You were spacing out a little there\n", 35, 0);
    slow_print("This cause your suspicion bar to increase a little\n\n", 35, 0);
    
    animate_suspicion_meter(&state->suspicionMeter, 15);

    slow_print("\"What's wrong dexter? Lets play...\"\n\n", 25, 0);

    slow_print("You start acting excited like a normal dog again and started playing with the little boy\n\n", 35, 0);

    slow_print("But", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("You don't know how to play exactly.\n", 35, 0);
    slow_print("When the boy asked you to play chase you didn't chase him untuill he tells you to.\n", 35, 0);
    slow_print("When the boy wanted to play fetch you stared at him untill he explains you how to play it\n\n", 35, 0);
    slow_print("It seems that you can only recall the dog's crucial memory\n\n", 35, 0);

    slow_print("Staying silent and observing first is the right decision rather than guessing how the game works.\n", 35, 0);
    
    animate_suspicion_meter(&state->suspicionMeter, 25);
    
    slow_print("As you were playing fetch and you were bringing back the stick to the boy.\n", 35, 0);
    slow_print("The boy said...\n\n", 35, 0);
    
    slow_print("\"He should be out by now...\"\n", 30, 0);
    slow_print("\"He's always like that, I hate him now, every day he would wake up and go to the bar until night\"\n\n", 30, 0);
   
    slow_print("Listening, to the little man words, you realized that the boy dislike this man,\n", 35, 0);
    slow_print("You feel like you should protect this little man from him.\n\n", 35, 0);

    slow_print("\"Now that he is not here, go ahead Dexter, get your favourite toy\"\n\n", 30, 0);

    slow_print("( \"My... Favourite... Toy... ?\" )\n\n", 50, 0);

    slow_print("You don't have a clear idea about that \"thing\",\n", 35, 0);
    slow_print("but you must, or the boy will become more suspicious of you.\n", 35, 0);
    slow_print("Maybe if you just go to your house and look for it you'll get a flash back", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("you dashed back towards the house,\n", 35, 0);
    slow_print("passing through the same bush, and the same trees.\n", 35, 0);
    slow_print("Until", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("there it is, the house", 35, 0);
    dot_animation();
    printf("\n\n");

    printf("press enter to enter the house...");
    getchar();
    clear_screen();

    //getting toy
    slow_print("You have entered the house\n", 35, 0);
    slow_print("Inside, you no longer feel that man presence, he is gone\n", 35, 0);
    slow_print("Time to start looking for your toy", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("In the first room you are in after entering the house.\n", 35, 0);
    slow_print("There is a round shaped object that is quite huge and it is brightly colorfull.\n", 35, 0);
    slow_print("( \"Maybe this is my favourite toy\" ) You thought\n\n", 35, 0);

    slow_print("But you are not just going to pick a decision based on one object that you assume is the toy.\n", 35, 0);
    slow_print("Lets look for more...\n\n", 35, 0);

    slow_print("You continued to search arround the house, and encountered a room.\n", 35, 0);
    slow_print("The stench of this room is soo foul.\n", 35, 0);
    slow_print("On the sides of the room there are a lot of cupboards, filled with strange items to you.\n", 35, 0);
    slow_print("In the middle of the room there is a huge table that has 3 objects ontop of it, the objects are white and somewhat shiny.\n", 35, 0);
    slow_print("But among those items, one in particular stood out, a flat item that is super shiny and kinda shaped like a triangle \n", 35, 0);
    slow_print("( \"Maybe this is my favourite toy\" ) You thought\n\n", 35, 0);

    slow_print("But no you are not done looking yet there might be more.\n", 35, 0);
    slow_print("Lets continue...\n\n", 35, 0);

    slow_print("You are now upstairs, inside the boy's room.\n", 35, 0);
    slow_print("There are 2 Items that piqued your interest.", 35, 0);
    slow_print("One item is a flat circle shaped with a bright red color,\n", 35, 0);
    slow_print("the second item is a long object that has 2 balls on each end,\n", 35, 0);
    slow_print("the item is not stiff though, and the balls are seem to be made from the item tied to itself", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("That should be enough items, now which one are you going to choose: \n", 35, 0);
    printf("[1] The round colorfull object.\n");
    printf("[2] The flat super shiny triangular object.\n");
    printf("[3] The flat circle shaped red object.\n");
    printf("Your choice >");

    int choice = 0;
    scanf("%d", &choice);
    getchar();

    while (choice < 1 || choice > 4){

        printf("Invalid input, please re enter\n"); 
        printf("Your choice >");
        scanf("%d", &choice);
        getchar();
        printf("\n");

    }

    printf("\n\n");

    if(choice == 1){
            state->hasBall = 1;
            slow_print("You have chosen the round colorfull object.\n", 35, 0); 
            slow_print("It's gotta be this one, it is very colorfull and kinda big to just hit arround\n", 35, 0);          
        }

        else if(choice == 2){
            state->hasKnife = 1;
            slow_print("You have chosen the flat and super shiny triangular object.\n", 35, 0);
            slow_print("It's gotta be this one it's shiny and pretty easy to wield on your mouth \n\n", 35, 0);
        }

        else if(choice == 3){
            state->hasFrisbee = 1;
            slow_print("You have chosen the flat and red colored circular object.\n", 35, 0);
            slow_print("It's gotta be this one, even though you don't know why you feel like this is the toy\n\n", 35, 0);
        }

    printf("press enter to continue...");
    getchar();
    clear_screen();

    slow_print("You got the item, now it's time to return to the boy", 35, 0);
    dot_animation();
    printf("\n\n");

    slow_print("Running through the same woods, you have arrived on the fields\n", 35, 0);

    if(state->hasBall == 1){
        slow_print("the boy is waiting under the tree,\n", 35, 0);
        slow_print("You run towards the boy bringing the round and brightly colorfull object", 35, 0);
        dot_animation();
        printf("\n\n");
        slow_print("\"Dexter!!.. You brought a beach ball?...\"\n", 35, 0);
        slow_print("\"I didn't know you like to play with this thing before\"\n", 35, 0);
        slow_print("\"I guess you want to play with this today, right ? Lets just play\n\n", 35, 0);

        animate_suspicion_meter(&state->suspicionMeter, 55);

        slow_print("You Realized you probably just made a mistake, but the deed has been done.\n", 35, 0);
        slow_print("You still will play with the boy using the beach ball and having fun,\n", 35, 0);
        slow_print("But the boy probably has his eyes on you.\n\n", 35, 0);
        
        slow_print("Both of you played untill the sun is starting to set.", 35, 0);
    }
    
    else if(state->hasKnife == 1){
        slow_print("the boy is waiting under the tree,\n", 35, 0);
        slow_print("You run towards the boy bringing the flat shiny and triangular object ", 35, 0);
        dot_animation();
        printf("\n\n");
        slow_print("\"Dexter", 35, 0);
        dot_animation();
        slow_print(" DEXTER!!!!! \n", 25, 0);
        slow_print("\"DEXTER.. WHY ARE YOU BRINGING A KNIFE HERE!?\"\n", 25, 0);
        slow_print("\"DROP IT BOY!! DROP IT!!\"\n\n", 25, 0);

        slow_print("You messed up... you know it, now there is no way for this kid to trust you anymore\n\n", 40, 0);

        slow_print("\"You were spacing out when i called your name here.\"\n", 35, 0);
        slow_print("\"You somehow seem to forget how to play the games we always plays here.\"\n", 35, 0);
        slow_print("\"Who are you", 50, 0);
        dot_animation();
        printf("\"\n");

        animate_suspicion_meter(&state->suspicionMeter, 100);

        trigger_game_over("You brought the absolute worst object");
        return;
    }

    else if(state->hasFrisbee == 1){
        slow_print("the boy is waiting under the tree,\n", 35, 0);
        slow_print("You run towards the boy bringing the flat and bright red object", 35, 0);
        dot_animation();
        printf("\n\n");

        slow_print("\"Dexter!!.. You brought... the frisbee?...\"\n\n", 35, 0);
        dot_animation();
        printf("\n\n");
        slow_print("What happened?", 45, 0);
        dot_animation();
        printf("\n\n");
        slow_print("did you brought the right toy?", 45, 0);
        dot_animation();
        printf("\n\n");

        slow_print("\"oop.. Sorry Dexter I was spacing out there,\"\n", 35, 0);
        slow_print("\"it's just that, mom used to play with this frisbee with you a lot before", 35, 0);
        dot_animation();
        printf("\"\n\n");

        slow_print("( Again, who is mom ? ) you thought.\n", 40, 0);
        slow_print("Your thought process was interupted by the boy's words.\n", 40, 0);
        slow_print("\"Lets just continue to play Dexter\"\n", 40, 0);
        slow_print("\"It's not good to just keep remembering the past,\"\n", 40, 0);
        slow_print("\"no matter how much I wish it didn't went like this, it wouldn't change anything\"\n", 40, 0);
        slow_print("\"Atleast i still have you Dexter", 40, 0);
        dot_animation();
        printf("\"\n\n");

        slow_print("Based on that respond, maybe you have made the right decision,\n", 35, 0);

        animate_suspicion_meter(&state->suspicionMeter, 0);

        slow_print("\"Catch Dexter...\" Shouts the boy\n", 35, 0);
        slow_print("The boy then throw the frisbee up to the sky,\n", 35, 0);
        slow_print("You ran after the thrown frisbee, the spin of the frisbee tears through the air...\n", 35, 0);
        slow_print("It seems like it would never land. Knowing that you jump to catch the frisbee with your mouth.\n\n", 35, 0);
        
        printf("... *HOP* ... *CLACK* ...\n\n");

        slow_print("\"GOOD JOB DEXTER!\"\n\n", 35, 0);

        slow_print("You got it, now to just bring the toy back to the boy.\n", 35, 0);
        slow_print("The boy had such joy in his face as you brought the toy back.\n", 35, 0);

        slow_print("This is it", 35, 0);
        dot_animation();
        printf("\n\n");

        slow_print("This is what it means to live with humans side by side", 35, 0);
        dot_animation();
        printf("\n\n");

        slow_print("Both of you were having so much fun playing untill you realize the sun is starting to set\n\n", 35, 0);
    }

    slow_print("\"It's getting late Dexter, lets go back home\"\n", 35, 0);
    slow_print("Is it finally over? you were just having so much fun\n", 35, 0);
    slow_print("Well it's getting dark anyways so let's just get back home\n\n", 35, 0);

    printf("Press enter to follow the boy home...");
    getchar();
}

void play_chapter_conflict(GameState *state) {
    clear_screen();
    
    slow_print("The walk home was quiet, but peaceful.\n", 35, 0);
    slow_print("However, as you approach the house, you see a car parked in front.\n", 35, 0);
    slow_print("The man is back.\n\n", 35, 0);

    printf("Press ENTER to go inside...");
    getchar();
    clear_screen();

    slow_print("As you enter, the atmosphere is heavy.\n", 35, 0);
    slow_print("The man is standing there, swaying. He looks very unhealthy.\n", 35, 0);
    slow_print("He glares at the boy and you.\n\n", 35, 0);

    slow_print("Without a word, he walks fast towards the boy.\n", 30, 0);
    slow_print("He grabs Dexter's arm and drags him inside roughly!\n", 25, 0);
    slow_print("\"COME HERE YOU USELESS BRAT!\"\n\n", 20, 0);

    slow_print("He reaches for his belt.\n", 35, 0);
    slow_print("Dexter is crying, looking at you with pleading eyes.\n\n", 35, 0);

    printf("What will you do?\n");
    printf("[1] Do nothing (Watch)\n");
    printf("[2] Bark and Protect Dexter (Intervene)\n");
    printf("Your choice > ");

    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        slow_print("\nYou chose to stay silent.\n", 40, 0);
        slow_print("The man beats the boy mercilessly.\n", 40, 0); 
        slow_print("Eventually, the man gets tired and passes out on the sofa.\n", 35, 0); 
        slow_print("Dexter crawls to his room, bruised and crying.\n\n", 35, 0);
        animate_suspicion_meter(&state->suspicionMeter, 75);
        printf("Press ENTER to rest...");
        getchar();
        clear_screen();
    } else if (choice == 2) {

    printf("\n");
    slow_print("ROAAAAAR!!!\n", 10, 0);
    slow_print("You lunge at the man, barking ferociously!\n", 20, 0);
    
    slow_print("The man is startled, but he kicks you hard!\n", 20, 0);
    slow_print("You fly across the room and hit a table.\n", 20, 0);
    printf("\nCRASH!!\n\n");
    
    slow_print("A framed photo falls from the table and shatters on the floor.\n", 35, 0);
    slow_print("The man freezes.\n", 50, 0);
    slow_print("He looks at the photo... it's a family photo. Him, the boy, and the woman with long hair.\n", 35, 0);
    
    slow_print("Silence fills the room.\n", 40, 0);
    slow_print("The man drops his belt. He looks defeated.\n", 40, 0);
    slow_print("He turns around and walks to his room without saying a word.\n\n", 40, 0);

    slow_print("Dexter runs to you, crying.\n", 35, 0);
    slow_print("\"Dexter... thank you... lets go to my room...\"\n\n", 35, 0);
    
    printf("Press ENTER to rest...");
    getchar();
    clear_screen();
    }

    slow_print("Later that night...\n", 50, 0);
    slow_print("The door to the boy's room bursts open!\n", 10, 0);
    slow_print("It's the man. He has the SHOTGUN again.\n", 20, 0);
    
    slow_print("He grabs you by the neck and drags you outside.\n", 25, 0);
    slow_print("Dexter tries to stop him but is pushed aside.\n", 25, 0);
    
    slow_print("Outside, he throws you to the ground.\n", 25, 0);
    slow_print("He ties your legs and your muzzle tight.\n", 25, 0);
    slow_print("You can't move. You can't bark.\n\n", 35, 0);
    
    slow_print("He loads the shotgun.\n", 40, 0);
    slow_print("*CLACK-CLACK*\n", 20, 0);
    slow_print("He aims it at your head.\n", 40, 0);
    slow_print("Tears are streaming down his face. He is shaking.\n\n", 40, 0);

    // --- PEMILIHAN ENDING UTAMA ---
    printf("This is the end. What will you do?\n");
    printf("[1] Accept fate (Die as a Dog)\n");
    printf("[2] Eat Him (Reveal Monster Form)\n");
    printf("[3] Escape (Run away)\n");
    
    // Opsi Pacifist hanya muncul jika Suspicion RENDAH (< 40)
    if (state->suspicionMeter < 40) {
        printf("[4] Whimper and Lick his hand (Mercy)\n");
    }
    
    printf("Your choice > ");
    
    int finalChoice;
    scanf("%d", &finalChoice);
    getchar();

    if (finalChoice == 1) {
        slow_print("BANG!\n", 10, 0);
        trigger_game_over("You died as a loyal dog. Dexter is now alone.");
        return;
    } 

    else if (finalChoice == 3) {
        slow_print("You rip the ropes with your monster strength and run into the forest.\n", 30, 0);
        trigger_game_over("You survived, but you abandoned Dexter.");
        return;
    }
    
    else if (finalChoice == 4 && state->suspicionMeter < 40) {
        printf("\n");
        slow_print("You choose mercy.\n", 40, 0);
        slow_print("Despite the gun at your head, you nudge his hand gently.\n", 40, 0);
        slow_print("You let out a soft, sad whimper.\n\n", 40, 0);

        slow_print("The man pauses. His hand is shaking violently.\n", 40, 0);
        slow_print("\"Why...?\" he sobs.\n", 40, 0);
        slow_print("\"Why don't you bite me? I'm a monster...\"\n\n", 40, 0);

        slow_print("He drops the shotgun to the grass.\n", 35, 0);
        slow_print("He falls to his knees and hugs you, crying uncontrollably.\n", 35, 0);
        slow_print("Dexter runs out and joins the hug.\n\n", 35, 0);

        slow_print("That night, no blood was shed.\n", 35, 0);
        slow_print("It wasn't an instant fix. But it was a start.\n", 35, 0);
        slow_print("The man started to drink less. He started to smile more.\n", 35, 0);
        slow_print("And you? You watched over them. Not as a monster, but as a guardian.\n\n", 35, 0);

        printf("=========================================\n");
        printf("       P A C I F I S T   E N D I N G     \n");
        printf("           (The Family Reborn)           \n");
        printf("=========================================\n\n");
        printf("Press ENTER to finish.");
        getchar();
        exit(0);
    }

    else if (finalChoice == 2) {
        printf("\n");
        slow_print("You choose violence.\n", 35, 0);
        slow_print("Your body explodes into black liquid!\n", 25, 0);
        slow_print("The man screams as you engulf him completely.\n", 25, 0);
        slow_print("In seconds, he is dissolved. Nothing remains.\n\n", 35, 0);

        slow_print("You turn around to see Dexter standing there.\n", 35, 0);
        
        if (state->suspicionMeter > 55) {
            
            printf("\n(Suspicion > 55: Dexter knows you are dangerous!)\n\n");
            
            slow_print("Dexter is NOT crying. He is trembling with rage and fear.\n", 35, 0);
            slow_print("\"You... you ate him...\" he whispers.\n", 35, 0);
            slow_print("\"YOU ARE NOT A DOG!\"\n\n", 20, 0);

            slow_print("Dexter runs to the dropped SHOTGUN!\n", 20, 0);
            slow_print("He picks it up. It's too heavy for him, but he aims at you.\n", 30, 0);
            slow_print("\"DIE MONSTER!!\"\n", 15, 0);
            
            slow_print("BANG!\n", 10, 0);
            slow_print("The bullet grazes your liquid form. It hurts!\n", 20, 0);
            slow_print("Panic takes over your instinct.\n", 20, 0);
            
            slow_print("You lunge forward without thinking.\n", 20, 0);
            slow_print("You envelop the boy.\n", 40, 0);
            slow_print("His screams are cut short.\n\n", 50, 0);

            slow_print("...\n", 60, 0);
            slow_print("Silence returns to the forest.\n", 40, 0);
            slow_print("You have eaten everyone.\n", 40, 0);
            slow_print("You are alone again. Just like in the abyss.\n\n", 40, 0);

            printf("=========================================\n");
            printf("       G E N O C I D E   E N D I N G     \n");
            printf("           (Consumed by Hunger)          \n");
            printf("=========================================\n\n");
            printf("Press ENTER to finish.");
            getchar();
            exit(0);

        } else {
            
            slow_print("Dexter is pale. Terrified.\n", 35, 0);
            slow_print("He stumbles back and falls.\n", 20, 0);
            
            printf("( \"I did this for you...\" you think. )\n");

            slow_print("Dexter scrambles up and runs to his room, locking the door.\n", 30, 0);
            slow_print("You decide to sleep in the living room.\n\n", 35, 0);

            printf("Press ENTER for the next day...");
            getchar();
            clear_screen();

            slow_print("The next morning... Silence.\n", 40, 0);
            slow_print("You push the boy's door open.\n", 40, 0);
            
            dot_animation();
            printf("\n");
            
            slow_print("Dexter is hanging from the ceiling.\n\n", 60, 0);
            
            printf("=========================================\n");
            printf("           T R U E   E N D I N G         \n");
            printf("      (The Monster and The Silence)      \n");
            printf("=========================================\n\n");
            
            printf("Press ENTER to finish.");
            getchar();
            exit(0);
        }
    }
}