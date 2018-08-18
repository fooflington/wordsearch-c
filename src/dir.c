#include "dir.h"
#include "rnd.h"

int directions[] = {
    DIRECTION_N,
    DIRECTION_NE,
    DIRECTION_E,
    DIRECTION_SE,
    DIRECTION_S,
    DIRECTION_SW,
    DIRECTION_W,
    DIRECTION_NW
};

int get_direction(int simple) {
    if (simple) {
        if (random_number(0, 1) == 0) {
            return DIRECTION_E;
        } else {
            return DIRECTION_S;
        }
    } else {
        return directions[random_number(0, NUM_DIRECTIONS)];
    }
}

#ifdef DEBUG_DIR_MAIN
#include <stdio.h>

int main() {
    int n = 32;
    while (--n > 0) {
        printf("%d\n", get_direction(1));
    }
    return 0;
}
#endif
