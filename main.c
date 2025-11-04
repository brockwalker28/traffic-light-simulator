#include "traffic.h"
#include <unistd.h> // for sleep()
#include <stdio.h>

int main() {
    initLights();

    for (int t = 0; t < 40; t++) { // 40-second simulation
        printf("\nTime: %d sec\n", t);
        updateLights(t);
        displayLights();
        sleep(1); // wait 1 second
    }

    return 0;
}
