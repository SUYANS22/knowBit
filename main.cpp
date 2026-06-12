#include <iostream>
#include <cstdlib>
bool runLoginGUI();
void Dashboard();
int main() {
    std::cout << "Starting knowBit System...\n";
    bool loginSuccess = runLoginGUI();
    if (loginSuccess) {
        system("clear");
        Dashboard();
    } else {
        std::cout << "\n[SYSTEM]: Login cancelled or failed. Exiting program.\n";
    }
return 0;
}