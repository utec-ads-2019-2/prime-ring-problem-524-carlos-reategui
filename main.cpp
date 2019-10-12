#include <iostream>
using namespace std;

const size_t ringSize = 20;

class PrimeRingProblem {
private:
    unsigned int caseCount = 0, cases{}, circle[ringSize]{};
    bool usedNumber[ringSize]{};
    short unsigned int isPrime[32] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                                       0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};

    void printSolution() const {
        for (int i = 0; i < cases; i++) cout << circle[i] << (i == cases - 1 ? "" : " ") << (i == cases - 1 ? "\n" : "");
    }

    void recursiveBacktracking(int number) {
        if (isPrime[circle[cases - 1] + circle[cases]] and number == cases - 1) {
            printSolution();
            return;
        }

        for (unsigned int i = 2; i <= cases; ++i)
            if (!usedNumber[i] && isPrime[circle[number] + i]) {
                usedNumber[i] = true;
                circle[number + 1] = i;
                recursiveBacktracking(number + 1);
                usedNumber[i] = false;
            }
    }

    void initializeCircle() { circle[0] = circle[cases] = 1; }

public:
    PrimeRingProblem() = default;

    void run() {
        while(cin >> cases) {
            if(caseCount++ > 0) putchar('\n');
            initializeCircle();
            cout << "Case " << caseCount << ":\n";
            recursiveBacktracking(0);
        }
    }
};

int main() {
    PrimeRingProblem primeRingProblem;
    primeRingProblem.run();
    return EXIT_SUCCESS;
}
