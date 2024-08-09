# Merge Sort with Insertion Sort Optimization

This repository contains a C program that implements a hybrid sorting algorithm combining Merge Sort and Insertion Sort. The algorithm optimizes sorting performance by switching to Insertion Sort for smaller subarrays.

## Overview

The program sorts an array of integers and uses an auxiliary array (`link`) to manage the merging process without modifying the original array (`a`). The `link` array simulates a linked list structure, keeping track of the sorted order of elements.

## Global Variables

- **`a[MAX_SIZE]`**: The primary array storing the elements to be sorted.
- **`link[MAX_SIZE + 1]`**: An auxiliary array for managing the linked list structure. The extra element helps in managing list boundaries.

## Constants

- **`MAX_SIZE`**: Defines the maximum number of elements that the program can sort.
- **`THRESHOLD`**: Determines the switch point from Merge Sort to Insertion Sort. Subarrays smaller than `THRESHOLD` are sorted using Insertion Sort.

## Functions

### InsertionSort1

```c
void InsertionSort1(int a[], int n);
```

Sorts the array `a` of size `n` in nondecreasing order using Insertion Sort.

### Merge1

```c
int Merge1(int q, int r);
```

Merges two sorted linked lists starting at indices `q` and `r`. Returns the starting index of the merged linked list.

### MergeSort1

```c
void MergeSort1(int low, int high);
```

Recursively sorts the array `a` between indices `low` and `high` using Merge Sort. Switches to Insertion Sort for small subarrays.

## Main Function

The `main` function initializes the array with user input, calls `MergeSort1` to sort the array, and prints the sorted elements using the linked list structure indicated by `link`.

## Usage

### Compilation

To compile the program, use a C compiler such as `gcc`:

```sh
gcc -o mergesort mergesort.c
```

### Execution

Run the compiled executable:

```sh
./mergesort
```

### Input Format

1. First, enter the number of elements `n`.
2. Then, input the `n` integers to be sorted.

### Output

The program outputs the sorted array in nondecreasing order.

## Notes

- The `link` array is used to maintain the sorted order of elements without directly modifying the array `a`.
- The program supports sorting up to `MAX_SIZE` elements. If the input exceeds this limit, the program will terminate with an error.
- The `THRESHOLD` value can be fine-tuned for performance optimization based on the input data characteristics.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

---

This README provides a comprehensive guide to understanding, compiling, and running the hybrid sorting algorithm implemented in this repository.
