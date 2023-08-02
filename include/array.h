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

#include <stddef.h>

typedef struct Array Array;

Array* create_array(size_t capacity);
void destroy_array(Array* arr);
size_t get_size(const Array* arr);
size_t get_capacity(const Array* arr);
void insert_at_index(Array* arr, size_t index, int value);
int get_element_at_index(const Array* arr, size_t index);
void set_element_at_index(Array* arr, size_t index, int value);
void delete_at_index(Array* arr, size_t index);
void resize_array(Array* arr, size_t new_capacity);

#endif /* ARRAY_H */
