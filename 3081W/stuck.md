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

### Assignment
sometimes when assigning one object to another, you are only doing a shallow copy where the assignment simply points the second object at the assigned object. In this case, you can run into double free errors.  
do a deep copy to remedy this, overload the assignment operator and inside the new definition, manually assign the object parameters and allocate new memory for anything. Each non-pointer member is copied directly from source member to destination member. For each pointer member, new memory is allocated, the source's referenced data is copied to the new memory, and a pointer to the new member is assigned as the destination member.
