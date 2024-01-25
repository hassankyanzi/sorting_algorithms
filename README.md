# 0x1B. C - Sorting algorithms & Big O
C - Algorithm & Data structure

## <p align="center">![nice](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/248/willy-wonka.png)</p>

## General objectives
* To know at least four different sorting algorithms
* To know what the ``Big O notation`` is, and how to evaluate the ``time complexity`` of an ``algorithm``
* To know how to select the best sorting algorithm for a given input
* To know what ``stable sorting algorithm`` is

### Resources
- [Sorting algorithm](https://alx-intranet.hbtn.io/rltoken/-j5MKLBlzZAC2RfJ5DTBIg) || [Big O notation](https://alx-intranet.hbtn.io/rltoken/WRvrE2BaNVQFssHiUATTrw)|| [Sorting algorithms animations](https://alx-intranet.hbtn.io/rltoken/ol0P7NbYVb5R31iOv4Q40A) || [15 sorting algorithms in 6 minutes](https://alx-intranet.hbtn.io/rltoken/_I0aEvhfJ66Xyob6dd9Utw)

## General Requirements
- Allowed editors: ``vi``, ``vim``, ``emacs``
- All files was compiled on Ubuntu 20.04 LTS using gcc, using the options ``-Wall -Werror -Wextra -pedantic -std=gnu89``
- All files end with a new line
- There is a README.md file at the root of the folder of the project
- The codes used the ``Betty`` style, and were checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- Global variables were not allowed
- No more than 5 functions per file
- The prototypes of all functions used are included in the header file called ``sort.h``
- All header files are include guarded
- A list/array does not need to be sorted if its size is less than 2.
**GitHub**

## More Info/lnstructions
**Data Structure and Functions**<br>
- For this project you are given the following ``print_array``, and ``print_list functions``:

```text
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```
```text
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```
- Our files ``print_array.c`` and ``print_list.c`` (containing the ``print_array`` and ``print_list`` functions) will be compiled with your functions during the correction.
- Please declare the prototype of the functions ``print_array`` and ``print_list`` in your ``sort.h`` header file
- Please use the following data structure for doubly linked list:
```text
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```
Please, note this format is used for Quiz and Task questions.

- ``O(1)``
- ``O(n)``
- ``O(n!)``
- n square -> ``O(n^2)``
- log(n) -> ``O(log(n))``
- n + k -> ``O(n+k)``
- …
Please use the “short” notation (don’t use constants). Example: ``O(nk)`` or ``O(wn)`` should be written ``O(n)``. If an answer is required within a file, all your answers files must have a newline at the end.

## Tests
Here is a quick tip to help you test your sorting algorithms with big sets of random integers: [Random.org](https://alx-intranet.hbtn.io/rltoken/YR-VWQbICB59wZs1eAaI3w)

## Files & Description
| S/N   |       Files          |        Description  |
|:-----:|--------------------|:-------------------|
| 1. |[0-bubble_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/0-bubble_sort.c), <br> [0-O](https://github.com/Dikachis/sorting_algorithms/blob/main/0-O) | A function that sorts an array of integers in ascending order using the [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm |
|2. | [1-insertion_sort_list.c](https://github.com/Dikachis/sorting_algorithms/blob/main/1-insertion_sort_list.c), <br> [1-O](https://github.com/Dikachis/sorting_algorithms/blob/main/1-O) | A function that sorts a doubly linked list of integers in ascending order using the [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) algorithm |
|3. | [2-selection_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/2-selection_sort.c), <br> [2-O](https://github.com/Dikachis/sorting_algorithms/blob/main/2-O)| A function that sorts an array of integers in ascending order using the [Selection sort](https://en.wikipedia.org/wiki/Selection_sort) algorithm |
| 4. |[3-quick_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/3-quick_sort.c), <br> [3-O](https://github.com/Dikachis/sorting_algorithms/blob/main/3-O) | A function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm |
|5. | [100-shell_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/100-shell_sort.c) | A function that sorts an array of integers in ascending order using the [Shell sort](https://en.wikipedia.org/wiki/Shellsort) algorithm, using the ``Knuth sequence`` |
|6. | [101-cocktail_sort_list.c](https://github.com/Dikachis/sorting_algorithms/blob/main/101-cocktail_sort_list.c), <br> [101-O](https://github.com/Dikachis/sorting_algorithms/blob/main/101-O)| A function that sorts a doubly linked list of integers in ascending order using the [Cocktail shaker sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort) algorithm |
| 7. |[102-counting_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/102-counting_sort.c), <br> [102-O](https://github.com/Dikachis/sorting_algorithms/blob/main/102-O) | A function that sorts an array of integers in ascending order using the [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) algorithm |
|8. | [103-merge_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/103-merge_sort.c), <br> [103-O](https://github.com/Dikachis/sorting_algorithms/blob/main/103-O) | A function that sorts an array of integers in ascending order using the [Merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm |
|9. | [104-heap_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/104-heap_sort.c), <br> [104-O](https://github.com/Dikachis/sorting_algorithms/blob/main/104-O)| A function that sorts an array of integers in ascending order using the [Heap sort](https://en.wikipedia.org/wiki/Heapsort) algorithm |
|10. | [105-radix_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/105-radix_sort.c) | A function that sorts an array of integers in ascending order using the [Radix sort](https://en.wikipedia.org/wiki/Radix_sort) algorithm |
| 11. |[106-bitonic_sort.c](https://github.com/Dikachis/sorting_algorithms/blob/main/106-bitonic_sort.c), <br> [106-O](https://github.com/Dikachis/sorting_algorithms/blob/main/106-O) | A function that sorts an array of integers in ascending order using the [Bitonic sort](https://en.wikipedia.org/wiki/Bitonic_sorter) algorithm |
|12. | [107-quick_sort_hoare.c](https://github.com/Dikachis/sorting_algorithms/blob/main/107-quick_sort_hoare.c), <br> [107-O](https://github.com/Dikachis/sorting_algorithms/blob/main/107-O) | A function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm |
|Folder| [tests](tests)|   Contains the main.c files command argv used to test run the codes|                     |
