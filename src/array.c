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
#include <stdio.h>
#include "array.h"

// Define a constant for the initial capacity of the array
#define INITIAL_CAPACITY 10

// Structure for the array
struct Array {
    int* data;
    size_t size;
    size_t capacity;
};

// Function to create a new array
Array* create_array(size_t capacity) {
    if (capacity == 0) {
        fprintf(stderr, "Error: Invalid capacity. Capacity must be greater than zero.\n");
        return NULL;
    }

    Array* arr = (Array*)malloc(sizeof(Array));
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    arr->data = (int*)malloc(capacity * sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    arr->size = 0;
    arr->capacity = capacity;

    return arr;
}

// Function to destroy the array and free its memory
void destroy_array(Array* arr) {
    if (arr == NULL) {
        return;
    }

    free(arr->data);
    free(arr);
}

// Function to get the current size of the array
size_t get_size(const Array* arr) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Array is NULL.\n");
        return 0;
    }

    return arr->size;
}

// Function to get the current capacity of the array
size_t get_capacity(const Array* arr) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Array is NULL.\n");
        return 0;
    }

    return arr->capacity;
}

// Function to insert a new element at a specified index in the array
void insert_at_index(Array* arr, size_t index, int value) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Array is NULL.\n");
        return;
    }

    if (index > arr->size) {
        fprintf(stderr, "Error: Invalid index. Index is out of bounds.\n");
        return;
    }

    if (arr->size == arr->capacity) {
        size_t new_capacity = arr->capacity * 2;
        int* new_data = (int*)realloc(arr->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed.\n");
            return;
        }
        arr->data = new_data;
        arr->capacity = new_capacity;
    }

    for (size_t i = arr->size; i > index; --i) {
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = value;
    arr->size++;
}

// Function to get the element at a specified index in the array
int get_element_at_index(const Array* arr, size_t index) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Array is NULL.\n");
        return 0;
    }

    if (index >= arr->size) {
        fprintf(stderr, "Error: Invalid index. Index is out of bounds.\n");
        return 0;
    }

    return arr->data[index];
}

// Function to set the element at a specified index in the array
void set_element_at_index(Array* arr, size_t index, int value) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Array is NULL.\n");
        return;
    }

    if (index >= arr->size) {
        fprintf(stderr, "Error: Invalid index. Index is out of bounds.\n");
        return;
    }

    arr->data[index] = value;
}

// Function to delete the element at a specified index from the array
void delete_at_index(Array* arr, size_t index) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Array is NULL.\n");
        return;
    }

    if (index >= arr->size) {
        fprintf(stderr, "Error: Invalid index. Index is out of bounds.\n");
        return;
    }

    for (size_t i = index; i < arr->size - 1; ++i) {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;

    // Resize the array to half of its capacity if the size becomes less than or equal to one-fourth of the capacity
    if (arr->size <= arr->capacity / 4 && arr->capacity > INITIAL_CAPACITY) {
        size_t new_capacity = arr->capacity / 2;
        int* new_data = (int*)realloc(arr->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed.\n");
            return;
        }
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
}

// Function to resize the array to a new capacity
void resize_array(Array* arr, size_t new_capacity) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Array is NULL.\n");
        return;
    }

    if (new_capacity == 0) {
        fprintf(stderr, "Error: Invalid capacity. Capacity must be greater than zero.\n");
        return;
    }

    int* new_data = (int*)realloc(arr->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Error: Memory reallocation failed.\n");
        return;
    }
    arr->data = new_data;
    arr->capacity = new_capacity;

    // Adjust the size to the new capacity if the current size exceeds the new capacity
    if (arr->size > new_capacity) {
        arr->size = new_capacity;
    }
}
