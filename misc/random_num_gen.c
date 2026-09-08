#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_unique_randoms(int count, int min, int max) {
    int range_size = max - min + 1;

    // Validate inputs
    if (count <= 0) {
        fprintf(stderr, "Error: Count must be greater than 0.\n");
        return;
    }
    if (min > max) {
        fprintf(stderr, "Error: Minimum cannot be greater than maximum.\n");
        return;
    }
    if (count > range_size) {
        fprintf(stderr, "Error: Cannot generate %d unique numbers from a range of size %d.\n", count, range_size);
        return;
    }

    // Allocate array for the range pool
    int *pool = malloc(range_size * sizeof(int));
    if (!pool) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }

    // Fill pool with values from min to max
    for (int i = 0; i < range_size; i++) {
        pool[i] = min + i;
    }

    // Partial Fisher-Yates shuffle: shuffle only 'count' elements
    for (int i = 0; i < count; i++) {
        int j = i + rand() % (range_size - i);
        
        // Swap pool[i] and pool[j]
        int temp = pool[i];
        pool[i] = pool[j];
        pool[j] = temp;

        // Print directly separated by whitespace
        printf("%d ", pool[i]);
    }
    printf("\n");

    free(pool);
}

int main(void) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Configuration parameters
    int count = 500; // Number of integers to generate
    int min = 0;    // Minimum value (inclusive)
    int max = 10000;   // Maximum value (inclusive)

    generate_unique_randoms(count, min, max);

    return 0;
}