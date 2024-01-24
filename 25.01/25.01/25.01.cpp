#include <iostream>
#include <ctime>
#include <cstdlib>

void spinDrums(char drums[][5], int size) {
    for (int i = 0; i < size; ++i) {
        int steps = rand() % 5;
        char temp;
        for (int j = 0; j < steps; ++j) {
            temp = drums[i][0];
            for (int k = 0; k < 4; ++k) {
                drums[i][k] = drums[i][k + 1];
            }
            drums[i][4] = temp;
        }
    }
}

int checkCombination(char drums[][5], int size) {
    if (drums[0][0] == drums[1][0] && drums[1][0] == drums[2][0]) {
        return 100;
    }
    return 0;
}

int main() {
    srand(time(0));

    char drumSymbols[5] = { 'A', 'B', 'C', 'D', 'E' };

    char drums[3][5];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            drums[i][j] = drumSymbols[j];
        }
    }

    std::cout << "Initial state of drums:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << drums[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    spinDrums(drums, 3);

    std::cout << "\nState of drums after spinning:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << drums[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    int winnings = checkCombination(drums, 3);
    std::cout << "\nWinnings: " << winnings << std::endl;

    return 0;
}
