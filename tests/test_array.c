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
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

// Function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to check if two arrays are equal
bool are_arrays_equal(const Array* arr1, const Array* arr2) {
    if (get_size(arr1) != get_size(arr2) || get_capacity(arr1) != get_capacity(arr2)) {
        return false;
    }

    for (size_t i = 0; i < get_size(arr1); ++i) {
        if (get_element_at_index(arr1, i) != get_element_at_index(arr2, i)) {
            return false;
        }
    }

    return true;
}

int main() {
    srand(time(NULL)); // Initialize the random number generator

    Array* arr = create_array(5);

    // Test insert_at_index and get_element_at_index with random values
    for (size_t i = 0; i < get_capacity(arr); ++i) {
        int value = random_int(1, 100);
        insert_at_index(arr, i, value);
    }

    // Test get_element_at_index
    size_t index_to_get = random_int(0, get_size(arr) - 1);
    printf("Element at index %zu: %d\n", index_to_get, get_element_at_index(arr, index_to_get));

    // Test set_element_at_index with a random value
    size_t index_to_set = random_int(0, get_size(arr) - 1);
    int new_value = random_int(101, 200);
    set_element_at_index(arr, index_to_set, new_value);
    printf("Modified element at index %zu: %d\n", index_to_set, get_element_at_index(arr, index_to_set));

    // Test delete_at_index with a random index
    size_t index_to_delete = random_int(0, get_size(arr) - 1);
    delete_at_index(arr, index_to_delete);
    printf("After deletion, element at index %zu: %d\n", index_to_delete, get_element_at_index(arr, index_to_delete));

    // Test resize_array with a random new capacity
    size_t new_capacity = random_int(3, 10);
    resize_array(arr, new_capacity);
    printf("New capacity: %zu\n", get_capacity(arr));

    // Create a copy of the original array for comparison
    Array* arr_copy = create_array(new_capacity);
    for (size_t i = 0; i < get_size(arr); ++i) {
        set_element_at_index(arr_copy, i, get_element_at_index(arr, i));
    }

    // Test equality of the original and copy arrays
    printf("Arrays are equal: %s\n", are_arrays_equal(arr, arr_copy) ? "Yes" : "No");

    destroy_array(arr);
    destroy_array(arr_copy);

    return 0;
}
