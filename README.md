## Conjugate Gradient (CG) Method

### Introduction
* The ___Conjugate Gradient Method___ is an __Iterative Algorithm__ for solving systems of __Linear Equations__ of the form __Ax = b__.
* __A__: is a __Symmetric Positive-Definite Matrix__,
* __x__: is the Vector of unknowns to be found,
* __b__: is the right-hand side Vector of data/observations.
* The __Conjugate Gradient Method__ is particularly efficient for __Large, Sparse Systems__ arising in __Scientific Computing__, such as in the __Finite Element__ & __Finite Difference Methods__.

### Theory: How does it Work?
* The __Conjugate Gradient Method__ is a ___Gradient-Based Optimization Method___.
* It minimizes the __Quadratic Form__:
    * `f(x) = 1/2x^TAx - b^Tx`.
* The function `f(x)` has its __minimum__ at the solution of `Ax = b`, because:
    * `grad f(x) = Ax - b`.
* Setting the __Gradient__ to 0 gives the solution.

#### Key Concepts
* __Residual__: `r_k = b - Ax_k`, the __error at iteration k__.
* __Search Direction__: A `Vector p_k` along which we search for the solution.
* __Conjugacy__: Instead of using __Steepest Decent Direction__, __CG__ uses directions that are ___A-Conjugate___: `p_i^T*A*p_j`, for `i != j`.

#### Algorithm Steps
* Given an initial guess, `x_0` (often `x_0 = 0`):
    1. Compute __Initial Residual__ `r_0 = b - A*x_0`;
    2. Set __Initial Search Direction__: `p_0 = r_0`.
    3. For `k = 0, 1, 2, ...`:
         * Compute __step size__: `alpha_k = r_k^T*r_k / p_k^T*Ap_k`.
         * Update __solution__: `x_k+1 = x_k + alpha_k*p_k`.
         * Update __residual__: `r_k+1 = r_k - alpha_k*Ap_k`.
         * Check for __convergence__: `||r_k+1||` is small enough.
         * Compute `beta_k` to __maintain conjugacy__: `beta_k = r_k+1^T*r_k+1 / r_k^T*r_k`.
         * Update __direction__: `p_k+1 = r_k+1 + beta_k*p_k`.
* This continues until __convergence__ (__residual norm is below a set tolerance__) or a __maximum number of iterations is reached__.

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
