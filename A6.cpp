#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int countPrimesInFile() {
    ifstream file("NUMS.TXT");
    int num;
    int count = 0;

    if (!file) {
        cout << "Error opening NUMS.TXT" << endl;
        return 0;
    }

    while (file >> num) {
        if (isPrime(num)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    cout << "Number of prime numbers in NUMS.TXT: "
         << countPrimesInFile() << endl;

    return 0;
}
