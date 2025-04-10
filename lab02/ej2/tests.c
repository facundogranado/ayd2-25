#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 5

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
        { {8}, 1, true },
        { {1,2,3,2,1}, 5, true },
        { {1,2,3,4,5}, 5, false },
        { {-2,-1,0,1,2}, 5, false },
        { {8,-3,9,10,25}, 5, false },
        { {8,-3,10,9,3,10,25}, 7, false },
        { {8,-3,9,10,25,10,304,532,12,34}, 10, false },
        { {-5,-4,-3,-2,-1,0,-1,-2,-3,-4}, 10, true },
        { {1,15,2,10,4,1}, 6, false },
        { {1,5,6,10,4,1}, 6, true },

    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },
        { {1,2,3,2,1}, 5, 2 },
        { {-5,-4,-3,-2,-1,0,-1,-2,-3,-4}, 10, 5 },
        { {1,5,6,10,4,1}, 6, 3 },
        { {1,5,6,10,4,1,-1,-4}, 8,3 },

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
