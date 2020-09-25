### Pointers
```
// with non-pointers use .
Point point1;
point1.Print();

// with pointers use -> or *
Point point2;
point2->Print();
(*point2).Print();

```
### Delete
Can only be used on pointers that were created with *new*  
Delete does not set pointers to NULL  
Be careful of dangling pointers  
```
int *p;
p = new int(4);
int *q;
q = p;

delete p;
p = NULL;

// at this point, q is still pointing at "4" and is no longer tracked by the program. This can cause seg faults after many iterations of the program
```
