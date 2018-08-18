/*
 ============================================================================
 Name        : wordsearch.c
 Author      : Matthew Slowe
 Version     :
 Copyright   : MIT
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grid.h"
#include <ctype.h>

#define strtoupper(X) for(char* c=X; *c=toupper(*c); ++c)

int main(int argc, char **argv) {

    // Reading parameters
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <height> <width> [ words ... ]\n", argv[0]);
        exit(1);
    }
    int width, height;
    height = atoi(argv[1]);
    width = atoi(argv[2]);

    char *words[argc-3];
    int words_count = argc-3;
    for(int i=0; i<words_count; i++) {
        words[i] = malloc(strlen(argv[i+3]));
        strcpy(words[i], argv[i+3]);
        strtoupper(words[i]);
    }
//	if(argc > 2) {
//
//	} else {
//		char *words[4] = { "test", "word", "longer", "verylong" };
//	}

    char **grid = make_grid(words, height, width, 0, words_count);
    print_grid(grid, height);
    free_grid(grid, height);
}
