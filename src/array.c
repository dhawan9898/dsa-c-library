/*
 * array.c
 * Implementation file for array data structure.
 * Author: Dhawan
 * Year: 2023
 * 
 * For more details, see the GNU General Public License:
 * <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

Array* create_array(size_t capacity) {
    Array* arr = (Array*)malloc(sizeof(Array));
    if (arr) {
        arr->data = (int*)malloc(capacity * sizeof(int));
        if (arr->data) {
            arr->size = 0;
            arr->capacity = capacity;
        } else {
            free(arr);
            arr = NULL;
        }
    }
    return arr;
}

void destroy_array(Array* arr) {
    if (arr) {
        free(arr->data);
        free(arr);
    }
}

void resize_array(Array* arr, size_t new_capacity) {
    if (arr && new_capacity > arr->capacity) {
        int* new_data = (int*)realloc(arr->data, new_capacity * sizeof(int));
        if (new_data) {
            arr->data = new_data;
            arr->capacity = new_capacity;
        }
    }
}

int get_element_at_index(const Array* arr, size_t index) {
    if (arr && index < arr->size) {
        return arr->data[index];
    }
    // Handle error or return a default value (e.g., -1) for invalid index.
    return -1;
}

void set_element_at_index(Array* arr, size_t index, int value) {
    if (arr && index < arr->size) {
        arr->data[index] = value;
    }
}

bool is_empty(const Array* arr) {
    return arr ? (arr->size == 0) : true;
}

size_t get_size(const Array* arr) {
    return arr ? arr->size : 0;
}

size_t get_capacity(const Array* arr) {
    return arr ? arr->capacity : 0;
}

bool insert_at_index(Array* arr, size_t index, int value) {
    if (!arr || index > arr->size || arr->size == arr->capacity) {
        return false;
    }

    // Shift elements to the right to make space for the new element
    for (size_t i = arr->size; i > index; --i) {
        arr->data[i] = arr->data[i - 1];
    }

    // Insert the new element
    arr->data[index] = value;
    arr->size++;

    return true;
}

bool delete_at_index(Array* arr, size_t index) {
    if (!arr || index >= arr->size) {
        return false;
    }

    // Shift elements to the left to remove the element
    for (size_t i = index; i < arr->size - 1; ++i) {
        arr->data[i] = arr->data[i + 1];
    }

    // Decrement the size
    arr->size--;

    return true;
}
