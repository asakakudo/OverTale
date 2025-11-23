#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep() / usleep()

void print_title() { //printing the title
    printf("========================================================\n");
    printf("                     O V E R T A L E              \n");
    printf("========================================================\n\n");
}

void slow_print(const char *str, int delay, int charPosition) { //printing the characters 1by1 and on starting on which one
    while (str[charPosition] != '\0') {
        printf("%c", str[charPosition]);
        fflush(stdout);
        usleep(delay * 1000); // delay in ms
        str++;
    }
}

void dot_animation(){
    for(int i = 1; i <=3; i++){
        printf(". ");
        sleep(1);
    }
}

int main() {

    //variables

    int suspicion = 0; 
    const char storyOp1[] =
        "Deep beneath the surface of the earth, hidden away from the touch of sunlight,\n"
        "there existed a world of darkness unknown to mankind.\n"
        "In that forgotten place, a strange creature was born, a shapeless entity\0"
        "It is you\0"
        "You've lived alone for centuries, surrounded only by echoes and silence.\n"
        "Yet inside your heart, one dream never faded:\n"
        "to one day reach the surface, and live peacefully with the surface dwellers\0"
        "humans\0"
        "Every night you imagined warmth, laughter, and the feeling of being accepted.\n"
        "Even though you knew.. you were nothing like a human.\n\n"
        "Until one night, a crack in the earth opened,\n"
        "and the moonlight touched your body for the very first time.\n"
        "This was the moment you've been waiting for.\0";

    const char storyOp2[] = 
        "It crawled out of the abyss and was met with the sight of the surface,\n"
        "It is beautifull, stunning, nothing like it have ever seen, the moon light shines on it body\n"
        "the wind of the night soothing it's skin, and slithers through the pine trees, blessing it's ears with such peacefull ambiemce\n\n"
        "as it admires his soroundings";

    //main code

    print_title();//print title
    sleep(2);

    slow_print(storyOp1, 35, 0); //print story opening pertama 
    dot_animation();
    printf("\n\n");

    slow_print(storyOp1, 35, 206); //print pengenalan karakter
    dot_animation();
    printf("\n\n");

    slow_print(storyOp1, 35, 216); //print lanjutan opening story pertama
    dot_animation();
    printf("\n\n");

    slow_print(storyOp1, 35, 411); //print humans
    dot_animation();
    printf("\n\n");

    slow_print(storyOp1, 35, 418); //print lanjutan story pertama
    printf("\n\n");



    printf("Press ENTER to continue...");
    getchar(); // waits for ENTER
    printf("\n\n");
    
    slow_print(storyOp2, 35, 0); //print story opening kedua setelah title 

    return 0;
}