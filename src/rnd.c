#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "rnd.h"

/* https://www.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html */

#define ALPHABET_SIZE 26
#define RND_MAXINT 10000

struct letter_frequency {
    int p;			/* pegged to 10000 rather than 1 */
    char c;
} letter_frequencies[] = {
    {
        7, 'Z'
    }, {
        10, 'J'
    }, {
        11, 'Q'
    }, {
        17, 'X'
    }, {
        69, 'K'
    }, {
        111, 'V'
    }, {
        149, 'B'
    }, {
        182, 'P'
    }, {
        203, 'G'
    }, {
        209, 'W'
    }, {
        211, 'Y'
    }, {
        230, 'F'
    }, {
        261, 'M'
    }, {
        271, 'C'
    }, {
        288, 'U'
    }, {
        398, 'L'
    }, {
        432, 'D'
    }, {
        592, 'H'
    }, {
        602, 'R'
    }, {
        628, 'S'
    }, {
        695, 'N'
    }, {
        731, 'I'
    }, {
        768, 'O'
    }, {
        812, 'A'
    }, {
        910, 'T'
    }, {
        1202, 'E'
    },
};

/* from http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c */
int random_number(int min_num, int max_num) {
    static int initialised = 0;
    int result = 0;
    int low_num = 0;
    int hi_num = 0;
    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;	// this is done to include max_num in output.
    } else {
        low_num = max_num + 1;	// this is done to include max_num in output.
        hi_num = min_num;
    }
    if (!initialised) {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        // srand(time(NULL));
        srand(tv.tv_usec);
        initialised = 1;
    }
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

char get_random_letter() {
    int rnd = random_number(0, RND_MAXINT);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (rnd < letter_frequencies[i].p) {
            return letter_frequencies[i].c;
        }
        rnd -= letter_frequencies[i].p;
    }
    return '\0';
}

#ifdef DEBUG_RND_MAIN
#include <stdio.h>
#include <assert.h>
int main() {
    int n = 10000;
    while (--n > 0) {
        // printf("%c", get_random_letter());
        int r = random_number(0,10);
        assert(r >= 0);
        assert(r <= 10);
    }
    return 0;
}

#endif
