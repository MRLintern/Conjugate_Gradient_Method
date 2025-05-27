// implement CGSolver

#include <cmath>
#include "CGSolver.hpp"

// implement solver; initialise tolerance and max. number of iterations
CGSolver::CGSolver(double tolerance, int maxIterations)

	: tolerance_(tolerance), maxIterations_(maxIterations) {}

// solve Ax = b using conjugate gradient method
Eigen::VectorXd CGSolver::solve(const Eigen::MatrixXd& A, const Eigen::VectorXd& b) {

	// dimension of the system
	const int n = A.rows();

	// initial guess for x; x0 = 0
	Eigen::VectorXd x = Eigen::VectorXd::Zero(n);

	// initial residual: r0 = b - A*x0
	Eigen::VectorXd r = b - A * x;

	// initial search direction
	Eigen::VectorXd p = r;

	// will hold A * p at each step
	Eigen::VectorXd Ap(n);

	// rTr; square norm of residual
	double rs_old = r.dot(r);

	// iterative loop
	for (int i{0}; i < maxIterations_; ++i) {

		// compute A * p
		Ap = A * p;

		// compute step size: alpha = rTr/pTAp
		double alpha = rs_old / p.dot(Ap);

		// update solution vector x
		x += alpha * p;

		// update residual
		r -= alpha * Ap;

		// compute new residual norm squared
		double rs_new = r.dot(r);

		// check for convergence
		if (std::sqrt(rs_new) < tolerance_) {

			std::cout<<"Converged in "<<i + 1<<" Iterations.\n";

			break;
		}

		// update search direction
		p = r + (rs_new / rs_old) * p;

		// update old residual
		rs_old = rs_new;
	}

	// return computed vector x
	return x;
}
