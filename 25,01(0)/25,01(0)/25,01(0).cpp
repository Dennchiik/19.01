#include <iostream>
#include <ctime>
#include <cstdlib>

class SlotMachine {
public:
    SlotMachine();
    void spinDrums();
    int checkCombination();
    void displayState() const;

private:
    char drumSymbols[5];
    char drums[3][5];
};

SlotMachine::SlotMachine() {
    srand(time(0));
    drumSymbols[0] = 'A';
    drumSymbols[1] = 'B';
    drumSymbols[2] = 'C';
    drumSymbols[3] = 'D';
    drumSymbols[4] = 'E';

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            drums[i][j] = drumSymbols[j];
        }
    }
}

void SlotMachine::spinDrums() {
    for (int i = 0; i < 3; ++i) {
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

int SlotMachine::checkCombination() {
    if (drums[0][0] == drums[1][0] && drums[1][0] == drums[2][0]) {
        return 100;
    }
    return 0;
}

void SlotMachine::displayState() const {
    std::cout << "Current state of drums:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << drums[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    SlotMachine slotMachine;

    slotMachine.displayState();
    slotMachine.spinDrums();
    slotMachine.displayState();

    int winnings = slotMachine.checkCombination();
    std::cout << "\nWinnings: " << winnings << std::endl;

    return 0;
}
