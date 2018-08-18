#ifndef WORDSEARCH_DIR
#define WORDSEARCH_DIR

enum direction {
    DIRECTION_N,
    DIRECTION_NE,
    DIRECTION_E,
    DIRECTION_SE,
    DIRECTION_S,
    DIRECTION_SW,
    DIRECTION_W,
    DIRECTION_NW
};

#define NUM_DIRECTIONS 8

int get_direction(int simple);

#endif
