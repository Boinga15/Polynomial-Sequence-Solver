#include<cstdio>
#include<vector>

#include "pSolver.h"

int main(int argc, char *argv[]) {
	bool isDone = false;
	std::vector<int> sequence;

	while (!isDone) {
		printf("Enter a number to be added to the sequence. Enter something invalid to finish.");
		printf("\nCurrent numbers:\n");
		for (int i = 0; i < sequence.size(); i++) {
			printf("%i\n", sequence[i]);
		}
		int op = 0;
		printf("\n\nNumber: ");
		if (scanf_s("%d", &op) != 1) {
			isDone = true;
		}
		else {
			sequence.push_back(op);
		}
		system("cls");
	}

	solvePolynomialSequence(sequence);

	return 0;
}