// conjugate gradient method solver class

#pragma once

#include <iostream>
#include <vector>
#include <Eigen/Dense>

// class to solve Ax = b using the conjugate gradient method
class CGSolver {

private:

	// convergence tolerance; accepted level of error
	double tolerance_{0.0};

	// maximum number of iterations to perform
	int maxIterations_{0};

public:

	// constructor for initialising tolerance and max. number of iterations
	CGSolver(double tolerance = 1e-10, int maxIterations = 1000);

	// compute x from Ax = b
	Eigen::VectorXd solve(const Eigen::MatrixXd& A, const Eigen::VectorXd& b);

};
