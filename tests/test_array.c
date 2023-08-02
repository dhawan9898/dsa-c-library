/*
 * test_array.c
 * Unit test file for array data structure.
 * Author: Dhawan
 * Year: 2023
 * 
 * For more details, see the GNU General Public License:
 * <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "array.h"

#define MAX_ARRAY_SIZE 1000
#define MAX_VALUE 1000

// Function to generate a random array size between 1 and MAX_ARRAY_SIZE
size_t generate_random_size() {
    return rand() % MAX_ARRAY_SIZE + 1;
}

// Function to generate a random element value between 0 and MAX_VALUE
int generate_random_value() {
    return rand() % (MAX_VALUE + 1);
}

// Function to run the unit tests for the array
void run_array_tests() {
    srand(time(NULL));

    printf("Running Array Tests...\n");

    for (int i = 0; i < 100; i++) {
        size_t array_size = generate_random_size();
        Array* arr = create_array(array_size);

        assert(arr != NULL);
        assert(get_size(arr) == 0);
        assert(get_capacity(arr) >= array_size);

        for (size_t j = 0; j < array_size; j++) {
            int value = generate_random_value();
            insert_at_index(arr, j, value);
            assert(get_element_at_index(arr, j) == value);
            assert(get_size(arr) == (j + 1));
        }

        for (size_t j = 0; j < array_size; j++) {
            int value = generate_random_value();
            set_element_at_index(arr, j, value);
            assert(get_element_at_index(arr, j) == value);
        }

        for (size_t j = 0; j < array_size; j++) {
            delete_at_index(arr, 0);
        }
        assert(get_size(arr) == 0);

        size_t new_capacity = generate_random_size();
        resize_array(arr, new_capacity);
        assert(get_capacity(arr) == new_capacity);

        destroy_array(arr);
    }

    printf("All Array Tests Passed!\n");
}

int main() {
    run_array_tests();

    return 0;
}
