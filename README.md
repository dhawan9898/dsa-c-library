# dsa-c-library
The DSA Standard Library for C: Open-source collection of efficient data structures &amp; algorithms, fostering easy integration &amp; reliable coding. Join us!

## Array Data Structure and Functions Implementation

### Introduction

The array data structure is a collection of elements of the same type, stored in contiguous memory locations. Each element can be accessed using its index, starting from 0.

This repository provides a basic implementation of an array data structure in C, along with various functions to manipulate and work with arrays.

### Functions

#### 1. `Array* create_array(size_t capacity)`

Creates a new array with the specified capacity.

#### 2. `void destroy_array(Array* arr)`

Frees the memory occupied by the array.

#### 3. `void resize_array(Array* arr, size_t new_capacity)`

Resizes the array to the new specified capacity.

#### 4. `int get_element_at_index(const Array* arr, size_t index)`

Returns the element at the specified index in the array.

#### 5. `void set_element_at_index(Array* arr, size_t index, int value)`

Sets the value of the element at the specified index in the array.

#### 6. `bool is_empty(const Array* arr)`

Checks if the array is empty.

#### 7. `size_t get_size(const Array* arr)`

Returns the current size (number of elements) of the array.

#### 8. `size_t get_capacity(const Array* arr)`

Returns the current capacity of the array.

#### 9. `bool insert_at_index(Array* arr, size_t index, int value)`

Inserts an element with the given value at the specified index in the array.

#### 10. `bool delete_at_index(Array* arr, size_t index)`

Deletes the element at the specified index in the array.
