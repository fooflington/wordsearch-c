#ifndef WORDSEARCH_GRID
#define WORDSEARCH_GRID
#include "dir.h"

#define WORDSEARCH_MAXTRIES 500

char **make_grid(char **words, int height, int width, int simple, int count);

typedef struct bounds {
    int min_y;
    int max_y;
    int min_x;
    int max_x;
} bounds;

/* returns NULL if cannot fit word; caller needs to free() the response */
bounds *get_bounds(int height, int width, enum direction direction, int length);

char** place_word(char *word, char **grid, int height, int width, int simple);

char **init_grid(char** old, int height, int width);
void free_grid(char** grid, int height);
int move_x(int x, enum direction d);
int move_y(int y, enum direction d);
void print_grid(char** grid, int height);

#endif
