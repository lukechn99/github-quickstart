# Insertion Sort
- a sorted version of a sequence is just a permutation of it
- arrays of size 1 or 0 are always sorted
- in **insertion sort** the array is treated as two sections: sorted and unsorted
- insertion sort sorts **in place**, meaning it does not use extra space or make another array for sorting  

---
### example
section before the pointer is sorted
```
[5, 2, 4, 3]  
 ^
[2, 5, 4, 3]  
    ^
[2, 4, 5, 3]  
       ^
[2, 3, 4, 5]  
          ^
```
---
