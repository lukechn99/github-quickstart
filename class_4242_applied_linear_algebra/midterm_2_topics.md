### Fundamental Matrix Subspaces
Given a matrix A where is m by n  
```
example
    |  1  5  0 |                     |  1  5  0 |
A = | -2  5  2 |       ---> ref(A) = |  0 15  2 |
    | -1 10  2 | m x n               |  0  0  0 |
```
Image: after finding the ref, the rows with pivots correspond to the columns in original matrix that form the basis for the img(A)  
Coimage: coimage also uses the positions of the pivots in ref form 
```
example
first pivot,  a(1,1) = 1                   | 1|  | 5|
second pivot, a(2,2) = 15 --->   img(A) = {|-2|, | 5|}
                                           |-1|  |10|
                                           
                                           | 1|  |-2|
                          ---> coimg(A) = {| 5|, | 5|}
                                           | 0|  | 2|
```  
Kernel: solve the matrix for Ax = 0  
Cokernel: solve the transpose of the matrix  
```
example
         |  1  5  0 || a|   | 0|      a   = -5b                           a = a                   |  1 |
ref(A) = |  0 15  2 || b| = | 0| ---> 15b = -2c ---> in terms of "a" ---> b = -1/5a ---> ker(A) = |-1/5|
         |  0  0  0 || c|   | 0|                                          c = 3/2a                | 3/2|
               |  1 -2 -1 |
transpose(A) = |  5  5 10 |
               |  0  2  2 |
                    |  1 -2 -1 |      |  1 -2 -1 |
ref(transpose(A)) = |  0 -5 15 | ---> |  0 -5 15 |
                    |  0  2  2 |      |  0  0  8 |          
|  1 -2 -1 || a|   | 0|      a = 2b + c
|  0 -5 15 || b| = | 0| ---> b = 3c
|  0  0  8 || c|   | 0|      c = 0
```

### Inner Products
Can be applied to vectors and functions
Can be used in norms

### The Famous Inequalities
Cauchy-Schwarz: | v * w | <= ||v|| * ||w||  
Orthogonal: 
Triangle: || v + w || <= ||v|| + ||w|| and they are equal if cv = w (v is a multiple of w)  

### Norms
Unit vectors
Equivalence of norms
Matrix norms

### Positive Definite Matrices
Gram matrices
What are properties?

### Completing the Square
The Cholesky factorization

### Orthogonal and Orthonormal Bases
How to compute
Please list the properties

### Gram-Schmidt Process
How to use

### Orthogonal Matrices
QR Factorization
Ill conditioned systems and Householder’s Method

### Orthogonal Projections and Orthogonal Subspaces
Orthogonal projection
Orthogonal Subspaces
Orthogonality of the Fundamental Matrix Subspaces and the Fredholm Alternative
