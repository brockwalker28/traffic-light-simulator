#ifndef TRAFFIC_H
#define TRAFFIC_H

typedef enum { RED, YELLOW, GREEN } LightState;

typedef struct {
    // Straight lights
    LightState north_straight;
    LightState south_straight;
    LightState east_straight;
    LightState west_straight;

    // Left turn arrows
    LightState north_left;
    LightState south_left;
    LightState east_left;
    LightState west_left;
} TrafficLights;

// Functions
void initLights();
void updateLights(int time);
void displayLights();

#endif
