// ACS130 Open Ended Assignment  - Mohammad Askari
// Registration Number: 200122252
// Submitted on 09/05/22

//CODE SUMMARY:

//For my assignment, I chose to write a Choose Your Own Adventure game, similar to the adventure books/interactive fiction stories from the 1980s and 90s, or the episode ‘Bandersnatch’ from Netflix’s Black Mirror series.
//The code itself is a large series of nested loops, containing all the possible choices the player can make, from opening their inventory, finding items, fighting enemies and continuing on in their adventure. (I attempted to boil this down to a function that I could simply repeat each time a choice needed to be made, but was unsuccessful).
//To increase efficiency, I created a number of functions in my code, for the purpose of opening text files of ASCII art, displaying the player’s inventory, stats and weapons etc.
//Using the struct command, I also created a number of ‘objects’ to be used in the code, such as enemies, items and weapons. My plan is to continue developing the code and adding new enemies and items as I develop the story. Currently only Episode 1 is playable.
//Thanks, and I hope you enjoy the game!


//THE CODE:

// INCLUDING LIBRARIES TO USE:
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

//DEFINING STRUCTURES:

// Defines enemy structure
struct enemy{
   int ehealth;
   int eattack;
   int eblock;
   char name[30];
   char attackname[30];
};

// Defines inventory structure
struct inventory{
   char weapon1[30];
   char weapon2[30];
   char weapon3[30];
   char weapon4[30];
   char item1[30];
   char item2[30];
   char item3[30];
   char item4[30];
   char item5[30];
};

// Defines weapon structure
struct weapon{
   int wdurability;
   int wattack;
   int wblock;
   char name[30];
   char attackname[30];
   char wdesc[80]
};

// Defines item structure
struct item{
   char name[30];
   char idesc[80];
};

// DEFINING FUNCTIONS
void fullScreen();
void fileDisplay();
void uiDisplay(int *health, int *block, int *attack, int *agility, int *gems);
void refreshUI();
void estatDisplay(name);
void checkInv(struct inventory, int *health, int *block, int *attack, int *agility, int *gems, int *drank);
void weaponDisplay (name);

// MAIN FUNCTION
void main(){

fullScreen();
fileDisplay("poaasciiart.txt");
// Sets the variables for characters stats back to normal
int newgame, newsave, cont;
int health = 20, *healthPtr = &health;
int block = 1, *blockPtr = &block;
int attack = 1, *attackPtr = &attack;
int agility = 1, *agilityPtr = &agility;
int gems = 0, *gemsPtr = &gems;
int drank = 0, *drankPtr =&drank;

// Creating enemies:

//Blob:
struct enemy blob;
blob.ehealth=10;
blob.eattack=randNum(3,4);
blob.eblock=1;
strcpy(blob.name, "Blob");
strcpy(blob.attackname, "3-4");

// Creating weapons:
struct weapon saxe;
saxe.wdurability = 7;
saxe.wattack = randNum(5,7);
saxe.wblock = 0;
strcpy(saxe.name, "Steel Axe");
strcpy(saxe.attackname, "5-7");

struct weapon lshield;
lshield.wdurability = 7;
lshield.wattack = 0;
lshield.wblock = 3;
strcpy(lshield.name, "Leather Shield");
strcpy(lshield.wdesc, "A rugged shield, not much more than a pot lid, when you think about it.");


// Creating items:
struct item hpotion;
strcpy(hpotion.name, "Health Potion");
strcpy(hpotion.idesc, "Restores 10 points of health.");

// Creating inventory bag:
struct inventory bag;
strcpy(bag.weapon1, "None");
strcpy(bag.weapon2, "None");
strcpy(bag.weapon3, "None");
strcpy(bag.weapon4, "None");
strcpy(bag.item1, "None");
strcpy(bag.item2, "None");
strcpy(bag.item3, "None");
strcpy(bag.item4, "None");
strcpy(bag.item5, "None");


// Begin game choices:
int number = 100;
do{
    scanf("%d",&newgame);
    if (newgame == 2) // Ends game if the user chooses to exit
        {
        system("cls");
        fileDisplay("poaasciiart.txt");
        printf("\n\n                                                                                                           Thanks for playing!\n\n");
            return;
        }
    if (newgame == 1) // Starts a new game
        {
        printf("\nBeginning new  game...");
        printf("\n                                                                                                              Select episode: \n\n");
        printf("                                                                                            |=====================|     |=====================|\n");
        printf("                                                                                            |  Play Episode 1 (1) |     |  Play Episode 2 (2) |\n");
        printf("                                                                                            |=====================|     |=====================|\n");
            do{
                scanf("%d",&newsave);
                if (newsave == 1){ // Begins episode 1
                    printf("                                                                                                \nLoading Episode 1...");
                    printf("\n\n                                                             You're standing in front of a dungeon. Smoke and rumbling escape from the gloomy entrance. You wonder what's inside.");
                    printf("\n                                                     Suddenly, a voice booms out from the sky. 'Hello there! My name is Story. I travel alongside adventurers and narrate all their heroics.'");
                    printf("\n                                                       'Sure, maybe it can get pretty annoying, but I guess you're stuck with me now. Why don't we have a look inside that dungeon?'\n");

                    printf("\n                                                                                                        |====================|");
                    printf("\n                                                                                                        |  Enter dungeon(1)  |");
                    printf("\n                                                                                                        |====================|\n");
                    do{
                        scanf("%d",&cont);
                        if (cont == 1){
                            refreshUI(); // refreshes the screen, displaying just the title art
                            uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                            printf("\n\n As you enter, a user interface appears on your screen, painted with 5 different symbols.");
                            printf("\n\n You hear the voice from the sky again. 'The first symbol, the heart, represents your LIFE. You may get into as much trouble as you want, but you must keep this one above 0. Promise me you will do that.'\n");
                            printf("\n|====================|");
                            printf("\n|    I promise.(1)   |");
                            printf("\n|====================|\n");
                            do{
                                    cont = 0;
                                    scanf("%d",&cont);
                                        if (cont == 1){
                                            printf("\n\n 'Thank you. I care greatly about the heroes whose stories I narrate.'");
                                            printf("\n\n 'The second symbol, the shield, represents your defense. It's the amount of damage absorbed from things like enemy attacks, before taking health.\n");
                                            printf("\n|====================|");
                                            printf("\n|     Continue(1)    |");
                                            printf("\n|====================|\n");
                                            do{
                                                cont = 0;
                                                scanf("%d",&cont);
                                                if (cont == 1){
                                                    refreshUI(); // refreshes the screen, displaying just the title art
                                                    uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                    fileDisplay("gate.txt"); // Displays an ASCII art file
                                                    printf("\n\n A metal gate blocks the way. ");
                                                    printf("\n\n You notice three pressure plates in front of it, each with a symbol on it. You wonder which one to press first.\n");
                                                    printf("\n|====================|      |====================|      |====================|");
                                                    printf("\n|   Plate 1 (1)      |      |    Plate 2 (2)     |      |    Plate 3 (3)     |");
                                                    printf("\n|====================|      |====================|      |====================|\n");
                                                    cont = 0;
                                                        do{
                                                            scanf("%d",&cont);
                                                            if ((cont == 1)||(cont == 2)||(cont == 3)){
                                                                refreshUI(); // refreshes the screen, displaying just the title art
                                                                uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                fileDisplay("gate.txt"); // Displays an ASCII art file
                                                                printf("\n\nA chunk of wall to your left moves aside and reveals a Heal Potion!");
                                                                printf("\n\n+Heal Potion");
                                                                strcpy(bag.item1,"Heal Potion"); // Labels item 1 in the players inventory "Heal Potion"
                                                                printf("\n\nThings that you find are added to your Inventory, which you can check throughout your quest.\n");
                                                                printf("\nTwo unpressed plates are now before you. You have a bad feeling the next one you press won't be as kind.\n");
                                                                printf("\n|====================|      |====================|      |====================|");
                                                                printf("\n|    Plate 1 (1)     |      |    Plate 2 (2)     |      |    Inventory(3)    |");
                                                                printf("\n|====================|      |====================|      |====================|\n");
                                                                cont = 0;
                                                                    do{
                                                                        scanf("%d",&cont);
                                                                        if (cont == 3){
                                                                            checkInv(bag,&health,&block,&attack,&agility,&gems,&drank); // Uses a function to check the player's inventory
                                                                            refreshUI(); // refreshes the screen, displaying just the title art
                                                                            uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                            printf("\nYou close the rucksack and return, ready for your adventure ahead.\n");
                                                                            if (drank == 1)
                                                                                {
                                                                                strcpy(bag.item1,"None");
                                                                                }
                                                                            fileDisplay("gate.txt"); // Displays an ASCII art file
                                                                            printf("\nTwo unpressed plates are now before you. You have a bad feeling the next one you press won't be as kind.\n");
                                                                            printf("\n|====================|      |====================|      |====================|");
                                                                            printf("\n|    Plate 1 (1)     |      |    Plate 2 (2)     |      |    Inventory(3)    |");
                                                                            printf("\n|====================|      |====================|      |====================|\n");
                                                                            cont = 0;
                                                                            }
                                                                        if ((cont == 1)||(cont == 2)){
                                                                                health = health-2;
                                                                            refreshUI(); // refreshes the screen, displaying just the title art
                                                                            uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                            fileDisplay("gate.txt"); // Displays an ASCII art file
                                                                            printf("\n\nA small hidden pipe shoots a dart that hits you right in the neck!\n");
                                                                            printf("\nYou take 2 points of damage.\n");
                                                                            printf("\nThe voice calls out again. 'Adventurer! Take a look at the heart symbol again - you sustained some damage, so your health decreased.\n");
                                                                            printf("\nThere will be many such troubles on your travels. Make sure to keep an eye on that number!'\n");
                                                                                printf("\nThe last plate remains.\n");
                                                                            printf("\n|====================|      |====================|");
                                                                            printf("\n|    Plate 1 (1)     |      |    Inventory(2)    |");
                                                                            printf("\n|====================|      |====================|\n");
                                                                            cont = 0;
                                                                                do{
                                                                                    scanf("%d",&cont);
                                                                                    if (cont==2){
                                                                                        checkInv(bag,&health,&block,&attack,&agility,&gems,&drank); // Uses a function to check the player's inventory
                                                                                        refreshUI(); // refreshes the screen, displaying just the title art
                                                                                        uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                        printf("\nYou close the rucksack and return, ready for your adventure ahead.\n\n");
                                                                                    if (drank == 1)
                                                                                        {
                                                                                        strcpy(bag.item1,"None");
                                                                                        }
                                                                                    fileDisplay("gate.txt"); // Displays an ASCII art file
                                                                                    printf("\n\nThe last plate remains.\n");
                                                                                    printf("\n|====================|      |====================|");
                                                                                    printf("\n|    Plate 1 (1)     |      |    Inventory(2)    |");
                                                                                    printf("\n|====================|      |====================|\n");
                                                                                    cont = 0;
                                                                                }
                                                                                if (cont == 1){
                                                                                    printf("\n\nChains rattle as the gate slowly opens.\n");
                                                                                    printf("\n|====================|");
                                                                                    printf("\n|    Continue (1)    |");
                                                                                    printf("\n|====================|\n");
                                                                                    cont = 0;
                                                                                        do{
                                                                                            scanf("%d",&cont);
                                                                                            if (cont == 1){
                                                                                                refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                printf("\n\nDid you hear that? I thought I heard something squelch.\n");
                                                                                                printf("\nAnyway, that third  symbol, the axe, represents your attack. That's the amount of damage you can do.\n");
                                                                                                printf("\nThe fourth, the boot symbol, stands for Agility. During combat, each point of agility you have increases your chance to dodge attacks.\n");
                                                                                                printf("\n|====================|");
                                                                                                printf("\n|    Continue (1)    |");
                                                                                                printf("\n|====================|\n");
                                                                                                cont = 0;
                                                                                                    do{
                                                                                                    scanf("%d",&cont);
                                                                                                        if (cont == 1){
                                                                                                            printf("\nSuddenly, the squelching gets louder, and louder, until you see a strange creature with spindly arms and legs start to scurry towards you in the darkness...\n");
                                                                                                            printf("I knew it! There's a blob coming your way! You'll have to fight!\n\n");
                                                                                                            fileDisplay("blob.txt"); // Displays an ASCII art file
                                                                                                            printf("\n");
                                                                                                            printf("\n|====================|");
                                                                                                            printf("\n|     Fight! (1)     |");
                                                                                                            printf("\n|====================|\n");
                                                                                                            cont = 0;
                                                                                                                do{
                                                                                                                scanf("%d",&cont);
                                                                                                                    if (cont == 1){
                                                                                                                        estatDisplay(&blob); // Display stats of the blob
                                                                                                                        printf("\nYou jump at the blob for the first attack...");
                                                                                                                        printf("Normally, this would be the time to strike.");
                                                                                                                        printf(" But without a weapon you don't stand a chance! You'll have to flee...");
                                                                                                                        printf("\nAttack with:");
                                                                                                                        weaponDisplay(bag); // Shows the player what weapons they can currently attack with
                                                                                                                        printf("\n|====================|");
                                                                                                                        printf("\n|      Flee! (1)     |");
                                                                                                                        printf("\n|====================|\n");
                                                                                                                        cont = 0;
                                                                                                                            do{
                                                                                                                            scanf("%d",&cont);
                                                                                                                                if (cont == 1){
                                                                                                                                    health = health-2;
                                                                                                                                    refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                                                    uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                                                    fileDisplay("blob.txt"); // Displays an ASCII art file
                                                                                                                                    printf("\nYou start running, but your enemy rushes forward to deliver a final blow.");
                                                                                                                                    printf("The blob strikes (3 damage), and you block it slightly.");
                                                                                                                                    printf("\nYou take 2 points of damage.\n");
                                                                                                                                    printf("\nYou escape, leaving the monster and it's fury behind.\n");
                                                                                                                                    printf("\nWell done! After all, adventuring is not about slaying monsters - it's about not being slayed yourself.");
                                                                                                                                    printf("\nLet's continue down this dungeon.\n");
                                                                                                                                    printf("\n|====================|");
                                                                                                                                    printf("\n|  Go further in (1) |");
                                                                                                                                    printf("\n|====================|\n");
                                                                                                                                    cont = 0;
                                                                                                                                        do{
                                                                                                                                        scanf("%d",&cont);
                                                                                                                                            if (cont == 1){
                                                                                                                                                gems = gems+25;
                                                                                                                                                refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                                                                uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                                                                fileDisplay("candles.txt"); // Displays an ASCII art file
                                                                                                                                                printf("\n\nYou enter a room lit by candles.\n");
                                                                                                                                                printf("\nOn a ruby-inlaid platform lies a heap of treasure, a Steel Axe and a Leather shield!\n");
                                                                                                                                                printf("\nYou pick up 25 gems.");
                                                                                                                                                printf("\n+Steel Axe");
                                                                                                                                                printf("\n+Leather Shield");
                                                                                                                                                strcpy(bag.weapon1, &saxe.name); // Sets the player's first weapon slot to "Steel Axe"
                                                                                                                                                strcpy(bag.weapon2, &lshield.name); // Sets the player's second weapon slot to "Leather Shield"
                                                                                                                                                printf("\n\nGot to love adventure! One moment you're at the edge of doom - the other you're bathing in wealth.");
                                                                                                                                                printf("\nThe fifth symbol on your screen represents Treasure. You can buy things with it, or keep it and take it home after your adventure is over.\n");
                                                                                                                                                printf("\n|====================|");
                                                                                                                                                printf("\n|     Continue (1)   |");
                                                                                                                                                printf("\n|====================|\n");
                                                                                                                                                cont = 0;
                                                                                                                                                    do{
                                                                                                                                                    scanf("%d",&cont);
                                                                                                                                                        if (cont == 1){
                                                                                                                                                            refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                                                                            uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                                                                            printf("\n\n");
                                                                                                                                                            fileDisplay("axe.txt"); // Displays an ASCII art file
                                                                                                                                                            printf("\n\n");
                                                                                                                                                            fileDisplay("shield.txt"); // Displays an ASCII art file
                                                                                                                                                            printf("\n\nSome weapons at last!");
                                                                                                                                                            printf("\nEvery weapon has it's own stats: Attack, Block and Agility.");
                                                                                                                                                            printf("\nWhen you use a weapon, those stats are a bonus on top of your own stats.");
                                                                                                                                                            printf("\nUse weapons sparingly though; they wear and eventually break apart.");
                                                                                                                                                            printf("\n|====================|");
                                                                                                                                                            printf("\n|   Go back out (1)  |");
                                                                                                                                                            printf("\n|====================|\n");
                                                                                                                                                            cont = 0;
                                                                                                                                                                do{
                                                                                                                                                                scanf("%d",&cont);
                                                                                                                                                                    if (cont == 1){
                                                                                                                                                                        refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                                                                                        uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                                                                                        printf("\n\n");
                                                                                                                                                                        fileDisplay("blob.txt"); // Displays an ASCII art file
                                                                                                                                                                        printf("\nThere it is again, the Blob! But this time we're ready for it!");
                                                                                                                                                                        printf("\nWell, apart from your health, perhaps. I think this is a good moment to use that Heal Potion!");
                                                                                                                                                                        printf("\n|====================|      |====================|");
                                                                                                                                                                        printf("\n|      Fight (1)     |      |    Inventory(2)    |");
                                                                                                                                                                        printf("\n|====================|      |====================|\n");
                                                                                                                                                                        cont = 0;
                                                                                                                                                                            do{
                                                                                                                                                                            scanf("%d",&cont);
                                                                                                                                                                                if (cont == 1){
                                                                                                                                                                                    refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                                                                                                    uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                                                                                                    fileDisplay("blob.txt"); // Displays an ASCII art file
                                                                                                                                                                                    estatDisplay(&blob); //Display's the enemy stats
                                                                                                                                                                                    printf("\n\nYou jump at the blob for the first attack...");
                                                                                                                                                                                    printf("\nLet's see what that Axe can do!\n");
                                                                                                                                                                                    weaponDisplay(bag); //Shows what the player can use to attack
                                                                                                                                                                                    printf("\n|====================|      |====================|");
                                                                                                                                                                                    printf("\n|   Axe: 5-7 dmg (1) |      |    Inventory(2)    |");
                                                                                                                                                                                    printf("\n|====================|      |====================|\n");
                                                                                                                                                                                    cont = 0;
                                                                                                                                                                                        do{
                                                                                                                                                                                        scanf("%d",&cont);
                                                                                                                                                                                            if (cont == 1){
                                                                                                                                                                                                int totattack = saxe.wattack+attack; //Sets the player's attack stat to the base stat plus the weapon stat
                                                                                                                                                                                                printf("\nTotal player damage: %d \n",totattack);
                                                                                                                                                                                                int blobhit1 = totattack-blob.eblock; //Sets the damage done to the enemy as the total attack minus the enemy block
                                                                                                                                                                                                printf("\nTotal damage dealt to Blob: %d \n",blobhit1);
                                                                                                                                                                                                blob.ehealth = blob.ehealth-blobhit1; //Decreases the enemy health
                                                                                                                                                                                                refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                                                                                                                uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                                                                                                                fileDisplay("blob.txt"); // Displays an ASCII art file
                                                                                                                                                                                                estatDisplay(&blob); //Display's the enemy stats
                                                                                                                                                                                                printf("\nYou strike (%d damage) and the Blob blocks it slightly.\n",totattack);
                                                                                                                                                                                                printf("\nBlob Health -%d\n",blobhit1);
                                                                                                                                                                                                printf("\nYou prepare to defend...\n");
                                                                                                                                                                                                printf("\nRemember, you have a shield now. Use it to increase your block!\n");
                                                                                                                                                                                                printf("\nYou prepare to defend...\n");
                                                                                                                                                                                                printf("\nDefend with:");
                                                                                                                                                                                                weaponDisplay(bag); //Shows the player what weapons they can defend with
                                                                                                                                                                                                printf("\n|===============================|      |====================|");
                                                                                                                                                                                                printf("\n|   Leather Shield: 4 block (1) |      |    Inventory(2)    |");
                                                                                                                                                                                                printf("\n|===============================|      |====================|\n");
                                                                                                                                                                                                cont = 0;
                                                                                                                                                                                                    do{
                                                                                                                                                                                                    scanf("%d",&cont);
                                                                                                                                                                                                        if (cont == 1){
                                                                                                                                                                                                            int etotattack = randNum(3,4); //Sets the enemy attack as a random number between 3 and 4
                                                                                                                                                                                                            printf("\nTotal blob damage: %d \n",etotattack);
                                                                                                                                                                                                            int blobstrike1 = (etotattack-(block+lshield.wblock)); //Calculates the enemy damage dealt by subtracting the base block and weapon block from the enemy attack
                                                                                                                                                                                                            printf("\nTotal damage dealt by blob to player: %d \n",blobstrike1);
                                                                                                                                                                                                            if (blobstrike1<=0) // If the enemy hits for less than 0 damage, it does 0 damage (removes the negative)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                health = health;
                                                                                                                                                                                                                }
                                                                                                                                                                                                            if (blobstrike1>0)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                health = health-blobstrike1;
                                                                                                                                                                                                                }
                                                                                                                                                                                                            refreshUI(); // refreshes the screen, displaying just the title art
                                                                                                                                                                                                            uiDisplay(health, block, attack, agility, gems); // Uses a function to display the user interface, with the player's stats
                                                                                                                                                                                                            fileDisplay("blob.txt"); // Displays an ASCII art file
                                                                                                                                                                                                            estatDisplay(&blob); // Displays enemy stats
                                                                                                                                                                                                            printf("\nThe blob strikes (%d damage) and you block it!\n",etotattack);
                                                                                                                                                                                                            printf("\nYou take %d points of damage.\n",blobstrike1);
                                                                                                                                                                                                            printf("\nYou prepare to attack again!\n");
                                                                                                                                                                                                            weaponDisplay(bag); // Shows the player what weapons are available to attack
                                                                                                                                                                                                            printf("\n|====================|      |====================|");
                                                                                                                                                                                                            printf("\n|   Axe: 5-7 dmg (1) |      |    Inventory(2)    |");
                                                                                                                                                                                                            printf("\n|====================|      |====================|\n");
                                                                                                                                                                                                            cont = 0;
                                                                                                                                                                                                                do{
                                                                                                                                                                                                                scanf("%d",&cont);
                                                                                                                                                                                                                    if (cont == 1){
                                                                                                                                                                                                                        //Calculates total damage dealt
                                                                                                                                                                                                                        int totattack = saxe.wattack+attack;
                                                                                                                                                                                                                        printf("\nTotal player damage: %d \n",totattack);
                                                                                                                                                                                                                        int blobhit1 = totattack-blob.eblock;
                                                                                                                                                                                                                        printf("\nTotal damage dealt to Blob: %d \n",blobhit1);
                                                                                                                                                                                                                        blob.ehealth = blob.ehealth-blobhit1;
                                                                                                                                                                                                                        refreshUI();
                                                                                                                                                                                                                        uiDisplay(health, block, attack, agility, gems);
                                                                                                                                                                                                                        fileDisplay("blob.txt");
                                                                                                                                                                                                                        estatDisplay(&blob);
                                                                                                                                                                                                                        printf("\nYou strike (%d damage) and the Blob blocks it slightly.\n",totattack);
                                                                                                                                                                                                                        printf("\nBlob Health -%d\n",blobhit1);
                                                                                                                                                                                                                        printf("\nThat proves to be your victory!\n");
                                                                                                                                                                                                                        printf("\n|====================|");
                                                                                                                                                                                                                        printf("\n|     Continue (1)   |");
                                                                                                                                                                                                                        printf("\n|====================|\n");
                                                                                                                                                                                                                        cont = 0;
                                                                                                                                                                                                                            do{
                                                                                                                                                                                                                            scanf("%d",&cont);
                                                                                                                                                                                                                                if (cont == 1){
                                                                                                                                                                                                                                    printf("\nYour first victory! A memorable experience.\n");
                                                                                                                                                                                                                                    printf("\nFrom the pool of experience rises an Elixir of Growth!");
                                                                                                                                                                                                                                    printf("\nYou're a quick learner indeed! An Elixir of Growth improves a stat of choice and fully restores health!\n");
                                                                                                                                                                                                                                    printf("\nAlthough, after today's little expedition, I'm sure you're all tuckered out. Let's head back outside of this strange place.\n");
                                                                                                                                                                                                                                    printf("\n|====================|");
                                                                                                                                                                                                                                    printf("\n|  Leave dungeon (1) |");
                                                                                                                                                                                                                                    printf("\n|====================|\n");
                                                                                                                                                                                                                                    cont = 0;
                                                                                                                                                                                                                                        do{
                                                                                                                                                                                                                                        scanf("%d",&cont);
                                                                                                                                                                                                                                            if (cont == 1){
                                                                                                                                                                                                                                                refreshUI();
                                                                                                                                                                                                                                                uiDisplay(health, block, attack, agility, gems);
                                                                                                                                                                                                                                                printf("\nWell done, my friend! Now, there's a lot more to adventuring than this, but I'm sure you'll learn the rest along the way.\n");
                                                                                                                                                                                                                                                printf("\nFor now, we rest. Tomorrow, it will be time for me to show you the real deal. The Path of Adventure.\n");
                                                                                                                                                                                                                                                printf("\nIt has proven a challenge for many a young hero like yourself in the past, and if you are to have any chance reaching the end, and the fated Castle of Doom...you will need to be ready.\n");
                                                                                                                                                                                                                                                fileDisplay("castleofdoom.txt");
                                                                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                                                                printf("\n|========================|");
                                                                                                                                                                                                                                                printf("\n|  Exit to main menu (1) |");
                                                                                                                                                                                                                                                printf("\n|========================|\n");
                                                                                                                                                                                                                                                cont = 0;
                                                                                                                                                                                                                                                    do{
                                                                                                                                                                                                                                                    scanf("%d",&cont);
                                                                                                                                                                                                                                                        if (cont == 1){
                                                                                                                                                                                                                                                            system("cls"); // Clears the console
                                                                                                                                                                                                                                                            fileDisplay("poaasciiart.txt");
                                                                                                                                                                                                                                                            printf("\n\n                                                                                                           Thanks for playing!\n\n");
                                                                                                                                                                                                                                                            return;
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                    }while (cont != 1);
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                            if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                printf("Please enter another character.(20)");
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                            if(number = 0){break;}
                                                                                                                                                                                                                                        }while (cont != 1);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                    printf("Please enter another character.(19)");
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                if(number = 0){break;}
                                                                                                                                                                                                                            }while (cont != 1);
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                    if (cont == 2){
                                                                                                                                                                                                                        checkInv(bag,&health,&block,&attack,&agility,&gems,&drank);
                                                                                                                                                                                                                        refreshUI();
                                                                                                                                                                                                                        uiDisplay(health, block, attack, agility, gems);
                                                                                                                                                                                                                        printf("\nYou close the rucksack and return, ready for your adventure ahead.\n");
                                                                                                                                                                                                                        if (drank == 1)
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                        strcpy(bag.item1,"None");
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                        printf("\n");
                                                                                                                                                                                                                        fileDisplay("blob.txt");
                                                                                                                                                                                                                        estatDisplay(&blob);
                                                                                                                                                                                                                        printf("\nYou prepare to attack again!\n");
                                                                                                                                                                                                                        weaponDisplay(bag);
                                                                                                                                                                                                                        printf("\n|====================|      |====================|");
                                                                                                                                                                                                                        printf("\n|   Axe: 5-7 dmg (1) |      |    Inventory(2)    |");
                                                                                                                                                                                                                        printf("\n|====================|      |====================|\n");
                                                                                                                                                                                                                        cont = 0;
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                    if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1)&&(cont != 2))
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                        printf("Please enter another character.(18)");
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                    if(number = 0){break;}
                                                                                                                                                                                                                }while((cont != 1)&&(cont != 2));
                                                                                                                                                                                                        }
                                                                                                                                                                                                        if (cont == 2){
                                                                                                                                                                                                            if(number = 0){break;}
                                                                                                                                                                                                            checkInv(bag,&health,&block,&attack,&agility,&gems,&drank);
                                                                                                                                                                                                            refreshUI();
                                                                                                                                                                                                            uiDisplay(health, block, attack, agility, gems);
                                                                                                                                                                                                            printf("\nYou close the rucksack and return, ready for your adventure ahead.\n");
                                                                                                                                                                                                            if (drank == 1)
                                                                                                                                                                                                            {
                                                                                                                                                                                                            strcpy(bag.item1,"None");
                                                                                                                                                                                                            }
                                                                                                                                                                                                            printf("\n");
                                                                                                                                                                                                            fileDisplay("blob.txt");
                                                                                                                                                                                                            estatDisplay(&blob);
                                                                                                                                                                                                            printf("\nYou prepare to defend...\n");
                                                                                                                                                                                                            printf("\nDefend with:");
                                                                                                                                                                                                            weaponDisplay(bag);
                                                                                                                                                                                                            printf("\n|===============================|      |====================|");
                                                                                                                                                                                                            printf("\n|   Leather Shield: 4 block (1) |      |    Inventory(2)    |");
                                                                                                                                                                                                            printf("\n|===============================|      |====================|\n");
                                                                                                                                                                                                            cont = 0;
                                                                                                                                                                                                            }
                                                                                                                                                                                                        if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1)&&(cont != 2))
                                                                                                                                                                                                            {
                                                                                                                                                                                                            printf("Please enter another character.(17)");
                                                                                                                                                                                                            }
                                                                                                                                                                                                        if(number = 0){break;}
                                                                                                                                                                                                    }while ((cont != 1)&&(cont != 2));
                                                                                                                                                                                                    if(number = 0){break;}
                                                                                                                                                                                            }
                                                                                                                                                                                            if (cont == 2){
                                                                                                                                                                                                checkInv(bag,&health,&block,&attack,&agility,&gems,&drank);
                                                                                                                                                                                                refreshUI();
                                                                                                                                                                                                uiDisplay(health, block, attack, agility, gems);
                                                                                                                                                                                                printf("\nYou close the rucksack and return, ready for your adventure ahead.\n");
                                                                                                                                                                                                if (drank == 1)
                                                                                                                                                                                                    {
                                                                                                                                                                                                    strcpy(bag.item1,"None");
                                                                                                                                                                                                    }
                                                                                                                                                                                                printf("\n");
                                                                                                                                                                                                fileDisplay("blob.txt");
                                                                                                                                                                                                estatDisplay(&blob);
                                                                                                                                                                                                if(number = 0){break;}
                                                                                                                                                                                                printf("\n\nYou jump at the blob for the first attack...");
                                                                                                                                                                                                printf("\nLet's see what that Axe can do!\n");
                                                                                                                                                                                                weaponDisplay(bag);
                                                                                                                                                                                                printf("\n|====================|      |====================|");
                                                                                                                                                                                                printf("\n|   Axe: 5-7 dmg (1) |      |    Inventory(2)    |");
                                                                                                                                                                                                printf("\n|====================|      |====================|\n");
                                                                                                                                                                                                cont = 0;
                                                                                                                                                                                                }
                                                                                                                                                                                            if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1)&&(cont != 2))
                                                                                                                                                                                                {
                                                                                                                                                                                                printf("Please enter another character.(16)");
                                                                                                                                                                                                }
                                                                                                                                                                                            if(number = 0){break;}
                                                                                                                                                                                        }while ((cont != 1)||(cont != 2));
                                                                                                                                                                                        if(number = 0){break;}
                                                                                                                                                                                }
                                                                                                                                                                                if (cont == 2){
                                                                                                                                                                                    checkInv(bag,&health,&block,&attack,&agility,&gems,&drank);
                                                                                                                                                                                    refreshUI();
                                                                                                                                                                                    uiDisplay(health, block, attack, agility, gems);
                                                                                                                                                                                    printf("\nYou close the rucksack and return, ready for your adventure ahead.\n");
                                                                                                                                                                                    if (drank == 1)
                                                                                                                                                                                        {
                                                                                                                                                                                        strcpy(bag.item1,"None");
                                                                                                                                                                                        }
                                                                                                                                                                                    printf("\n");
                                                                                                                                                                                    fileDisplay("blob.txt");
                                                                                                                                                                                    estatDisplay(&blob);
                                                                                                                                                                                    printf("\nThere it is again, the Blob! But this time we're ready for it!");
                                                                                                                                                                                    printf("\n|====================|      |====================|");
                                                                                                                                                                                    printf("\n|      Fight (1)     |      |    Inventory(2)    |");
                                                                                                                                                                                    printf("\n|====================|      |====================|\n");
                                                                                                                                                                                    cont = 0;
                                                                                                                                                                                }
                                                                                                                                                                                if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1)&&(cont != 2))
                                                                                                                                                                                    {
                                                                                                                                                                                    printf("Please enter another character.(15)");
                                                                                                                                                                                    }
                                                                                                                                                                                if(number = 0){break;}
                                                                                                                                                                            }while ((cont != 1)&&(cont != 2));
                                                                                                                                                                            if(number = 0){break;}
                                                                                                                                                                    }
                                                                                                                                                                    if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                                                                                        {
                                                                                                                                                                        printf("Please enter another character.(14)");
                                                                                                                                                                        }
                                                                                                                                                                    if(number = 0){break;}
                                                                                                                                                                }while (cont != 1);
                                                                                                                                                        }
                                                                                                                                                        if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                                                                            {
                                                                                                                                                            printf("Please enter another character.(13)");
                                                                                                                                                            }
                                                                                                                                                        if(number = 0){break;}
                                                                                                                                                    }while (cont != 1);
                                                                                                                                            }
                                                                                                                                            if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                                                                {
                                                                                                                                                printf("Please enter another character.(12)");
                                                                                                                                                }
                                                                                                                                            if(number = 0){break;}
                                                                                                                                        }while (cont != 1);
                                                                                                                                }
                                                                                                                                if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                                                    {
                                                                                                                                    printf("Please enter another character.(11)");
                                                                                                                                    }
                                                                                                                                if(number = 0){break;}
                                                                                                                            }while (cont != 1);
                                                                                                                    }
                                                                                                                    if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                                        {
                                                                                                                        printf("Please enter another character.(10)");
                                                                                                                        }
                                                                                                                    if(number = 0){break;}
                                                                                                                }while (cont != 1);
                                                                                                        }
                                                                                                        if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                            {
                                                                                                            printf("Please enter another character.(9)");
                                                                                                            }
                                                                                                        if(number = 0){break;}
                                                                                                    }while (cont != 1);
                                                                                            }
                                                                                            if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                                {
                                                                                                printf("Please enter another character.(8)");
                                                                                                }
                                                                                            if(number = 0){break;}
                                                                                        }while (cont != 1);
                                                                                }
                                                                                if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                                                    {
                                                                                    printf("Please enter another character.(7)");
                                                                                    }
                                                                                if(number = 0){break;}
                                                                            }while (cont != 1);
                                                                        }
                                                                        if((!isspace(cont)&& getchar()!= '\n')||(cont != 1)&&(cont != 2)&&(cont != 3))
                                                                        {
                                                                        printf("Please enter another character.(5)");
                                                                        }
                                                                        if(number = 0){break;}
                                                                    }while ((cont != 1)&&(cont != 2));
                                                            }
                                                            if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                            {
                                                            printf("Please enter another character.(6)");
                                                            }
                                                            if(number = 0){break;}
                                                        }while (cont != 1);
                                                }
                                                if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                                    {
                                                    printf("Please enter another character.(5)");
                                                    }
                                                    if(number = 0){break;}
                                            }while (cont != 1);

                                        }
                                        if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                                            {
                                            printf("Please enter another character.(4)");
                                            }
                                            if(number = 0){break;}
                            }while (cont != 1);
                        }
                        if((!isspace(cont)&& getchar()!= '\n')&&(cont != 1))
                            {
                            printf("Please enter another character.(3)");
                            }
                            if(number = 0){break;}
                    }while (cont != 1);
                }
                if (newsave == 2){
                    printf("\This part of the game isn't finished yet - sorry.");
                    return 0;
                    }
                    if(number = 0){break;}
                if((!isspace(newsave)&& getchar()!= '\n')&&(newsave != 1 && newsave != 2))
                    {
                    printf("Please enter another character.(2)");
                    }
                    if(number = 0){break;}
            }while (newsave != 1 && newsave != 2);
        }
    if((!isspace(newgame)&& getchar()!= '\n')||(newgame != 1 || newgame != 2))
        {
        printf("Please enter another character.(1)");
        }
        if(number = 0){break;}
}while (newgame != 1 || newgame != 2);
printf("End of the code!");
}



// Function to put the console in full screen
void fullScreen(){
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c,0,0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

//Function to display ASCII art files
void fileDisplay(char *file_name){
    FILE *fin = fopen(file_name, "r");      // open the specified file
    if (fin != NULL){
        INT c;
        while ((c = fgetc(fin)) != EOF)
            putchar(c);                   // output character
        fclose(fin);
        }
}

// Function to display the user interface
void uiDisplay(int *health, int *block, int *attack, int *agility, int *gems){
    printf("\n");
    fileDisplay("UI.txt");
    printf("\n\n              Health: %d/20",&*health);
    //displayHealth(healthvalue);
    printf("                                    Block: %d",&*block);
    printf("                                          Attack: %d",&*attack);
    printf("                                             Agility: %d",&*agility);
    printf("                                         Gems: %d\n",&*gems);
    printf("\n -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

//Function to refresh the console with the title art
void refreshUI(){
    system("cls");
    fileDisplay("poatitle.txt");
    printf("\n\n");
}

//Function to randomly generate stats for attack and block
void randNum(lower,upper){
int low = lower, up = upper;
srand(time(0));
int num = (rand() % (up - low + 1)) + low;
return num;
}

//Function to show the enemy stats
void estatDisplay(struct enemy name){
    printf("\n%s \n", name.name);
    printf("Health: %d ", name.ehealth);
    printf("\t Attack: %s ", name.attackname);
    printf("\t Block: %d \n", name.eblock);
 }

 //Function to check the player's inventory (removing items that they use such as the heal potion)
void checkInv(struct inventory name,int *health, int *block, int *attack, int *agility, int *gems,int *drank){
    int cont = 0;
    printf("\nYou quickly rummage through the contents of your rucksack, and find:\n");
    printf("\n\nInventory:");
    printf("\nWeapon 1: %s ", name.weapon1);
//        printf("\t Description: %s ", name.wdesc);
    printf("\nWeapon 2: %s ", name.weapon2);
    printf("\nWeapon 3: %s ", name.weapon3);
    printf("\nWeapon 4: %s ", name.weapon4);
    printf("\nItem 1: %s ", name.item1);
//        printf("\t Description: %s ", name.idesc);
    printf("\nItem 2: %s ", name.item2);
    printf("\nItem 3: %s ", name.item3);
    printf("\nItem 4: %s ", name.item4);
    printf("\nItem 5: %s \n", name.item5);
    if (strcmp(name.item1,"Heal Potion")==0)
        {
            printf("\n|============================|        |=======================|");
            printf("\n|   Drink Health Potion (1)  |        |   Exit Inventory (2)  |");
            printf("\n|============================|        |=======================|\n");
            int cont = 0;
                do{
                    scanf("%d",&cont);
                    if (cont ==1 ){
                    *health=*health+10;
                    if (*health >20)
                        {
                        *health = 20;
                        }
                    refreshUI();
                    uiDisplay(*health, *block, *attack, *agility, *gems);
                    printf("\nYou down the bottle of blood-coloured liquid, and feel reinvigorated.");
                    printf("\n+10 Health Points\n");
                    //strcpy(name.item1,"None");
                    *drank = 1;
                    printf("\n|=======================|");
                    printf("\n|   Exit Inventory (1)  |");
                    printf("\n|=======================|\n");
                    cont = 0;
                        do{
                        scanf("%d",&cont);
                            if (cont == 1)
                                {
                                printf("\nYou close the rucksack and return, ready for your adventure ahead.");
                                return;
                                }
                            if((!isspace(cont)&& getchar()!= '\n')||(cont != 1))
                                {
                                    printf("| INPUT 606 NOT RECOGNISED, PLEASE TRY AGAIN. | ");
                                }
                            }while (cont != 1);
                    }
                    if (cont == 2)
                        {
                        return;
                        }
                    if((!isspace(cont)&& getchar()!= '\n')||(cont != 1)||(cont != 2))
                            {
                            printf("| INPUT 404 NOT RECOGNISED, PLEASE TRY AGAIN. | ");
                            }
                }while ((cont != 1)||(cont!=2));
        }
    printf("\n|=======================|");
    printf("\n|   Exit Inventory (1)  |");
    printf("\n|=======================|\n");
    cont = 0;
    do{
            scanf("%d",&cont);
            if (cont == 1){
                printf("\nYou close the rucksack and return, ready for your adventure ahead.");
                return;
                }
            if((!isspace(cont)&& getchar()!= '\n')||(cont != 1))
            {
            printf("| INPUT 606 NOT RECOGNISED, PLEASE TRY AGAIN. | ");
            }
        }while (cont != 1);
}

//Function to display weapons available to use in battle
void weaponDisplay (struct inventory name)
    {
    printf("\n====================");
    printf("\nWeapon 1: %s ", name.weapon1);
    printf("\nWeapon 2: %s ", name.weapon2);
    printf("\nWeapon 3: %s ", name.weapon3);
    printf("\nWeapon 4: %s ", name.weapon4);
    printf("\n====================\n");
    }
