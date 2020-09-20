### Google Styleguide for C++
- Every .cc file should have a corresponding header .h file except for the .cc with main()
- Use #define guards
```
#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_

// if the path to the header file from the full path is foo/src/bar/baz.h
```
