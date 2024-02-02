#include "monty.h"

/**
 * _calloc_custom - allocates memory for an array, initializes it with zeros
 * @element_count: number of elements
 * @element_size: size of each element
 * Return: pointer to the allocated memory
 */
void *_calloc_custom(unsigned int element_count, unsigned int element_size)
{
    void *allocated_ptr = NULL;
    unsigned int index;

    if (element_count == 0 || element_size == 0)
        return NULL;

    allocated_ptr = malloc(element_count * element_size);
    if (allocated_ptr == NULL)
        return NULL;

    for (index = 0; index < (element_count * element_size); index++)
        *((char *)(allocated_ptr) + index) = 0;

    return allocated_ptr;
}

/**
 * _realloc_custom - reallocates a memory block, copying the previous content
 * @original_ptr: pointer to the memory block to be reallocated
 * @old_size: old size of the memory block
 * @new_size: new size of the memory block
 * Return: pointer to the reallocated memory block
 */
void *_realloc_custom(void *original_ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_allocated_ptr = NULL;
    unsigned int index;

    if (new_size == old_size)
        return original_ptr;

    if (original_ptr == NULL)
    {
        new_allocated_ptr = malloc(new_size);
        if (!new_allocated_ptr)
            return NULL;
        return new_allocated_ptr;
    }

    if (new_size == 0 && original_ptr != NULL)
    {
        free(original_ptr);
        return NULL;
    }

    new_allocated_ptr = malloc(new_size);
    if (!new_allocated_ptr)
        return NULL;

    for (index = 0; index < (old_size < new_size ? old_size : new_size); index++)
        new_allocated_ptr[index] = *((char *)original_ptr + index);

    free(original_ptr);
    return new_allocated_ptr;
}
