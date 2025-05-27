## Conjugate Gradient Method

### Introduction
* The ___Conjugate Gradient Method___ is an __Iterative Algorithm__ for solving systems of __Linear Equations__ of the form __Ax = b__.
* __A__: is a __Symmetric Positive-Definite Matrix__,
* __x__: is the Vector of unknowns to be found,
* __b__: is the right-hand side Vector of data/observations.
* The __Conjugate Gradient Method__ is particularly efficient for __Large, Sparse Systems__ arising in __Scientific Computing__, such as in the __Finite Element__ & __Finite Difference Methods__.

### Theory: How does it Work?
* TODO.

### Requirements
* __Compiler__: `g++ 13.1.0`.
* __OS__: `Ubuntu 20.04`.
* `Eigen Template Library`.
* `CMake`.

### Getting and Running the Software
* `$ git clone https://github.com/MRLintern/Conjugate_Gradient_Method.git`
* `$ cd Conjugate_Gradient_Method`
* `$ mkdir build -p && cd build`
* `$ cmake ..`
* `$ cmake --build .`
