# Google Styleguide for C++

### Header Files
- Every .cc file should have a corresponding header .h file except for the .cc with main()
- Use #define guards
```
#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_

// if the path to the header file from the full path is foo/src/bar/baz.h
```
- The alternative to using #define is to use a forward declaration with #include. This is to be used when using a function that's defined in a header. These headers should be included in the order: related header, C system headers, C++ std libraries. Separate each group with a newline
```
#include baz.h
```
- Inline functions should only be used for functions of 10 lines or less. Usually for accessors or mutators. 

### Scoping
- Namespaces divide the global scope into named partitions to prevente name collisions in the global space.
- No need to indent within a namespace
```
// In the .h file
namespace mynamespace {
class MyClass {
 public:
  ...
  void Foo();
};
}
```
```
// In the .cc file
namespace mynamespace {
void MyClass::Foo() {
  ... // actually defined
}
}  // namespace mynamespace
```
- Definitions that don't need to be used outside the file can be placed in an unnamed namespace
```
namespace {
...
}
```
# Google Tests
Automated testing patterns  
if we modify an existing class then we have to do regression testing, to avoid this, we should write classes that we will not need to change  



