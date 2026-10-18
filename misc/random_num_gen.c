#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

void generate_partially_sorted(int count, int min, int max, double sorted_ratio) {
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

    // Accept either 0.8 or 80 for 80%
    if (sorted_ratio > 1.0)
        sorted_ratio /= 100.0;
    if (sorted_ratio < 0.0 || sorted_ratio > 1.0) {
        fprintf(stderr, "Error: Sorted ratio must be between 0 and 1 (or 0 and 100).\n");
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

    // Partial Fisher-Yates shuffle: the first 'count' elements become
    // a random selection of unique values in random order
    for (int i = 0; i < count; i++) {
        int j = i + rand() % (range_size - i);
        int temp = pool[i];
        pool[i] = pool[j];
        pool[j] = temp;
    }

    // Sort only the first 'sorted_count' elements; the rest stay shuffled
    int sorted_count = (int)(count * sorted_ratio + 0.5);
    qsort(pool, sorted_count, sizeof(int), compare_ints);

    // Print separated by whitespace
    for (int i = 0; i < count; i++) {
        printf("%d ", pool[i]);
    }
    printf("\n");

    free(pool);
}

int main(void) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Configuration parameters
    int count = 500;           // Number of integers to generate
    int min = 0;               // Minimum value (inclusive)
    int max = 10000;           // Maximum value (inclusive)
    double sorted_ratio = 0.8; // Portion sorted from the start (0.8 or 80)

    generate_partially_sorted(count, min, max, sorted_ratio);

    return 0;
}