#include "traffic.h"
#include <stdio.h>

static TrafficLights lights;

void initLights() {
    // Initial state
    lights.north_straight = GREEN;
    lights.south_straight = GREEN;
    lights.east_straight  = RED;
    lights.west_straight  = RED;

    // Turn arrows initially red
    lights.north_left = RED;
    lights.south_left = RED;
    lights.east_left  = RED;
    lights.west_left  = RED;
}

void updateLights(int time) {
    int cycle = time % 20; // 20-second total cycle

    // N/S straight green with N/S left turn arrow
    if (cycle < 6) {
        lights.north_straight = GREEN;
        lights.south_straight = GREEN;
        lights.east_straight  = RED;
        lights.west_straight  = RED;

        lights.north_left = GREEN;
        lights.south_left = GREEN;
        lights.east_left  = RED;
        lights.west_left  = RED;
    }
    // N/S straight yellow, left arrows red
    else if (cycle < 8) {
        lights.north_straight = YELLOW;
        lights.south_straight = YELLOW;
        lights.east_straight  = RED;
        lights.west_straight  = RED;

        lights.north_left = RED;
        lights.south_left = RED;
        lights.east_left  = RED;
        lights.west_left  = RED;
    }
    // E/W straight green with E/W left turn arrow
    else if (cycle < 14) {
        lights.north_straight = RED;
        lights.south_straight = RED;
        lights.east_straight  = GREEN;
        lights.west_straight  = GREEN;

        lights.north_left = RED;
        lights.south_left = RED;
        lights.east_left  = GREEN;
        lights.west_left  = GREEN;
    }
    // E/W straight yellow, left arrows red
    else {
        lights.north_straight = RED;
        lights.south_straight = RED;
        lights.east_straight  = YELLOW;
        lights.west_straight  = YELLOW;

        lights.north_left = RED;
        lights.south_left = RED;
        lights.east_left  = RED;
        lights.west_left  = RED;
    }
}

void displayLights() {
    const char* names[] = {"RED", "YELLOW", "GREEN"};

    printf("\n--- Traffic Light Status ---\n");
    printf("NORTH: Straight %s, Left %s\n", names[lights.north_straight], names[lights.north_left]);
    printf("SOUTH: Straight %s, Left %s\n", names[lights.south_straight], names[lights.south_left]);
    printf("EAST : Straight %s, Left %s\n", names[lights.east_straight], names[lights.east_left]);
    printf("WEST : Straight %s, Left %s\n", names[lights.west_straight], names[lights.west_left]);
}
