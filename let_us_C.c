#include <stdio.h>
#include <string.h>

// --- Character Struct ---
struct Character {
    char name[20];
    int speed;
};

// Function to make character run
void run(struct Character *c) {
    printf("%s is running at speed %d\n", c->name, c->speed);
}

// Function to simulate chase
void chase(struct Character *chaser, struct Character *target) {
    printf("%s is chasing %s\n", chaser->name, target->name);
    if (chaser->speed > target->speed)
        printf("%s caught %s!\n", chaser->name, target->name);
    else
        printf("%s escaped!\n", target->name);
}

// --- Trap "base" struct using function pointer ---
struct Trap {
    void (*activate)(struct Trap*, struct Character*);
    char name[20];
};

// --- MouseTrap derived behavior ---
void activateMouseTrap(struct Trap *trap, struct Character *target) {
    printf("A %s snaps near %s!\n", trap->name, target->name);
    if (target->speed < 6)
        printf("%s gets caught by the trap!\n", target->name);
    else
        printf("%s dodges the trap!\n", target->name);
}

// --- BananaPeel derived behavior ---
void activateBananaPeel(struct Trap *trap, struct Character *target) {
    printf("%s slips on a %s!\n", target->name, trap->name);
    printf("%s's speed is reduced!\n", target->name);
    target->speed -= 1;
}

// --- Trap activation helper ---
void placeTrap(struct Trap *trap, struct Character *target) {
    printf("Tom places a %s for %s...\n", trap->name, target->name);
    trap->activate(trap, target);
}

int main() {
    struct Character tom = {"Tom", 5};
    struct Character jerry = {"Jerry", 7};

    run(&tom);
    run(&jerry);
    chase(&tom, &jerry);

    // Create MouseTrap
    struct Trap mouseTrap;
    strcpy(mouseTrap.name, "MouseTrap");
    mouseTrap.activate = activateMouseTrap;

    // Create BananaPeel
    struct Trap bananaPeel;
    strcpy(bananaPeel.name, "BananaPeel");
    bananaPeel.activate = activateBananaPeel;

    // Place traps for Jerry
    placeTrap(&mouseTrap, &jerry);
    placeTrap(&bananaPeel, &jerry);

    // Try chasing again after trap effects
    chase(&tom, &jerry);

    return 0;
}
