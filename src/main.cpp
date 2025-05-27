// driver for CGSolver

#include <iostream>
#include <Eigen/Dense>
#include "CGSolver.hpp"

int main() {

	// 3x3 symmetric positive definite matrix
	Eigen::MatrixXd A {

		{4, 1, 0},
		{1, 3, 0},
		{0, 0, 2},
	};

	// RHS data vector
	Eigen::VectorXd b {{1, 2, 3}};

	// create solver object with tolerance and max. number of iterations
	CGSolver solver(1e-10, 100);

	// solve the system Ax = b
	Eigen::VectorXd x = solver.solve(A, b);

	// output solution for x
	std::cout<<"Solution x:\n"<<x<<"\n";

	// output residual norm to check accuracy of solution
	std::cout<<"Residual ||Ax - b|| = "<<(A * x - b).norm()<<"\n";
	
}
