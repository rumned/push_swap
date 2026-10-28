/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_num_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 15:51:38 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/10/28 20:09:41 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    // Sort the selected values ascending; pool[0..count-1] is now the
    // list of values still available to place, smallest first
    qsort(pool, count, sizeof(int), compare_ints);

    // Number of inversions (pairs with a[i] > a[j], i < j) needed so that
    // disorder = inversions / total_pairs = 1 - sorted_ratio
    long total_pairs = (long)count * (count - 1) / 2;
    long target = (long)((1.0 - sorted_ratio) * total_pairs + 0.5);

    int *result = malloc(count * sizeof(int));
    if (!result) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(pool);
        return;
    }

    // Fill positions left to right. Picking the c-th smallest remaining
    // value puts exactly c smaller values after it, i.e. c inversions.
    // Every possible inversion (total_pairs of them) is accepted with
    // probability target / slots_left, so exactly 'target' are accepted
    // and they are spread evenly across all positions.
    long slots_left = total_pairs;
    int remaining = count;
    for (int i = 0; i < count; i++) {
        int c = 0;
        for (int s = 0; s < remaining - 1; s++) {
            if (rand() % slots_left < target) {
                c++;
                target--;
            }
            slots_left--;
        }

        result[i] = pool[c];
        // Remove the used value from the remaining list
        for (int j = c; j < remaining - 1; j++) {
            pool[j] = pool[j + 1];
        }
        remaining--;
    }

    // Print separated by whitespace
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(pool);
}

int main(void) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Configuration parameters
    int count = 500;           // Number of integers to generate
    int min = 0;               // Minimum value (inclusive)
    int max = 10000;           // Maximum value (inclusive)
    double sorted_ratio = 0; // 1 = ascending (disorder 0), 0 = descending (disorder 1)

    generate_partially_sorted(count, min, max, sorted_ratio);

    return 0;
}