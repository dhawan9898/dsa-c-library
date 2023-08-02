/*
 * array.h
 * Header file for array data structure.
 * Author: Dhawan
 * Year: 2023
 * 
 * For more details, see the GNU General Public License:
 * <https://www.gnu.org/licenses/>.
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Array;

Array* create_array(size_t capacity);
void destroy_array(Array* arr);

void resize_array(Array* arr, size_t new_capacity);

int get_element_at_index(const Array* arr, size_t index);
void set_element_at_index(Array* arr, size_t index, int value);

bool is_empty(const Array* arr);
size_t get_size(const Array* arr);
size_t get_capacity(const Array* arr);

bool insert_at_index(Array* arr, size_t index, int value);
bool delete_at_index(Array* arr, size_t index);

#endif /* ARRAY_H */