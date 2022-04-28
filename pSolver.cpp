#include "pSolver.h"
#include<cstdio>
#include<cmath>
#include<vector>

int factorial(int n) {
	if (n > 1) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}

int exponent(int base, int exponential) {
	int exp = exponential;
	int result = 1;
	while (exp > 0) {
		result *= base;
		--exp;
	}

	return result;
}

std::vector<int> solvePolynomialSequence(std::vector<int> sequence) {
	printf("Solving (may take a while)...\n");

	int itterationLoop = 0;
	bool isDone = false;
	bool quickRelease = false;
	std::vector<int> values;
	std::vector<int> wSequence = sequence;

	while (!isDone) {
		// First, work through the sequence until we reach a repeating number.
		bool foundRep = false;
		int repNum = 0;
		int layers = 0;
		std::vector<int> cSequence = wSequence;
		while (!foundRep) {
			std::vector<int> nSequence;
			layers += 1;
			foundRep = true;
			if (cSequence.size() - 1 > 1) {
				for (int i = 0; i < cSequence.size() - 1; i++) {
					nSequence.push_back(cSequence[i+1] - cSequence[i]);
					if (i > 0) {
						if (nSequence[i] != nSequence[i - 1]) {
							foundRep = false;
						}
						else {
							repNum = nSequence[i];
						}
					}
				}
				cSequence = nSequence;
			}
			else {  // Not enough data to finish steps. Abort.
				printf("Not enough data is available. Aborting step...\n");
				bool isDone = true;
				foundRep = true;
				quickRelease = true;
			}
		}

		if (quickRelease) {
			break;
		}

		if (itterationLoop == 0) { // Find the polynomial degree.
			printf("Polynomial degree: %i\n", (layers));
			for (int i = 0; i < layers + 1; i++) {
				values.push_back(0);  // Assign dud values for later.
			}
		}
		if (layers <= 1) { // Find the final polynomial parts
			values[itterationLoop] = cSequence[0];
			values[itterationLoop + 1] = wSequence[0] - cSequence[0];
			isDone = true;
			printf("Constant of x = %i\n", values[itterationLoop]);
			printf("Constant at end = %i\n", values[itterationLoop + 1]);
		}
		else {
			int constantVal = factorial(layers);
			int curVal = cSequence[0] / constantVal;
			values[itterationLoop] = curVal;
			printf("Constant of x^%i = %i\n", (values.size() - itterationLoop - 1), curVal);
			for (int i = 0; i < sequence.size(); i++) {
				wSequence[i] = wSequence[i] - (curVal * exponent((i + 1), (values.size() - itterationLoop - 1)));
			}
		}
		itterationLoop++;
	}

	return {};
}