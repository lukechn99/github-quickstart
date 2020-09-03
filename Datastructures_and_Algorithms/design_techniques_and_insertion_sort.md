# Insertion Sort
### facts
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

### code  
```
insertion_sort(array)
   for i = 1 to array.length
      cur_el = array[i]
      j = i - 1
      while j >= 0 and array[j] > cur_el
         array[j + 1] = array[j]
         j = j - 1
      array[j + 1] = cur_el
```
This sorting algorithm uses *i* as the index of the first unsorted element while *j* is the last sorted element. The while loop moves down the sorted portion until it finds a number in the sorted portion that is bigger than or equal to *cur_el* and inserts *cur_el* there.  

### proof
The three steps that must be proven are (1) initialization, (2) maintenance, and (3) termination.  
(1) invariant is true before outer loop executes, like proving a base case true
(2) prove that the invariant holds from iteration to iteration  
(3) when it terminates, the invariant should tell us the loop did what it's supposed to  
  
Our invariant here should be something along the lines of "for index *i* starting from 0 and ending at the length of the array, the sub-array [0...i] is always sorted.
