/*
 * array_example.c
 * Example usage of the array data structure.
 * Author: Dhawan
 * Year: 2023
 * 
 * For more details, see the GNU General Public License:
 * <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include "array.h"

int main() {
    // Create an array with a capacity of 5
    Array* arr = create_array(5);
    
    // Insert elements at specific indices
    insert_at_index(arr, 0, 10);
    insert_at_index(arr, 1, 20);
    insert_at_index(arr, 2, 30);
    
    // Get and print elements
    printf("Element at index 0: %d\n", get_element_at_index(arr, 0));
    printf("Element at index 1: %d\n", get_element_at_index(arr, 1));
    printf("Element at index 2: %d\n", get_element_at_index(arr, 2));
    
    // Update an element
    set_element_at_index(arr, 1, 25);
    printf("Modified element at index 1: %d\n", get_element_at_index(arr, 1));
    
    // Delete an element
    delete_at_index(arr, 0);
    printf("After deletion, element at index 0: %d\n", get_element_at_index(arr, 0));
    
    // Resize the array
    resize_array(arr, 3);
    printf("New capacity: %zu\n", get_capacity(arr));
    
    // Clean up
    destroy_array(arr);
    
    return 0;
}
