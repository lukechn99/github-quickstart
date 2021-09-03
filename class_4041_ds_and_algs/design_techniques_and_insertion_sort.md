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
   return array
```
This sorting algorithm uses *i* as the index of the first unsorted element while *j* is the last sorted element. The while loop moves down the sorted portion until it finds a number in the sorted portion that is bigger than or equal to *cur_el* and inserts *cur_el* there.  

### proof
The three steps that must be proven are (1) initialization, (2) maintenance, and (3) termination.  
(1) invariant is true before outer loop executes, like proving a base case true
(2) prove that the invariant holds from iteration to iteration  
(3) when it terminates, the invariant should tell us the loop did what it's supposed to  
  
Our invariant here should be something along the lines of "for index *i* starting from 0 and ending at the length of the array, the sub-array [0...i] is always sorted." This is true during initialization because array[0] is *5* and 5 by itself is sorted. This invariant is maintained through each step because at the end of the first iteration, we are looking at [2, 5] which is sorted. Finally, the algorithm terminates at *i* = array.length and the entire array is sorted.  

### time complexity
Assuming a theoretical machine with no memory heirarchy, a uni-processor, and each instruction taking constant time, then insertion sort takes O(n^2) time.  
```
n = array.length                            | Cost |Repeats
--------------------------------------------+------+-----+
insertion_sort(array)                       | 0    | 1
   for i = 1 to array.length                | c1   | n
      cur_el = array[i]                     | c2   | n - 1
      j = i - 1                             | c3   | n - 1
      while j >= 0 and array[j] > cur_el    | c4   | sum(j, 2, n)
         array[j + 1] = array[j]            | c5   | sum(j - 1)
         j = j - 1                          | c6   | sum(j - 1)
      array[j + 1] = cur_el                 | c7   | n - 1
   return array                             | c8   | 1
```

# Divide and Conquer with Merge Sort
### divide and conquer
- divide a problem into *n* smaller problems where *n* often equals 2
- solve each smaller problem
- combine the solutions of the subproblems  
  
### merge sort
```
head(li)
   return li[0]
```

```
tail(li)
   return li[1:]
```

```
mergesort(li)
   if li == [] or tail(li) == []
      return li
   else
      l = []
      r = []
      
      // dividing up the list
      while li != [] and tail(li) != []
         l = l + [head(li)]
         li = tail(li)
         r = r + [head(li)]
         li = tail(li)
      l = l + li
      l = mergesort(l)
      r = mergesort(r)
      s = []
      
      // sorting
      while l != [] and r != []
         if head(l) <= head(r)
            s = s + [head(l)]
            l = tail(l)
         else
            s = s + [head(r)]
            r = tail(r)
      s = s + l + r
   return s 
```
