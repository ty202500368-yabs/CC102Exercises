#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numStudents, numQuizzes;
    char choice;

    do {
        cout << "Enter number of students: ";
        cin >> numStudents;
        cout << "Enter number of quizzes: ";
        cin >> numQuizzes;
        cout << endl;

        double scores[numStudents][numQuizzes];
        double avg[numStudents];

        // Input quiz scores
        for (int i = 0; i < numStudents; i++) {
            cout << "Enter scores for Student " << i + 1 << ": ";
            for (int j = 0; j < numQuizzes; j++) {
                cin >> scores[i][j];
            }
        }

        // Compute average
        for (int i = 0; i < numStudents; i++) {
            double sum = 0;
            for (int j = 0; j < numQuizzes; j++) {
                sum += scores[i][j];
            }
            avg[i] = sum / numQuizzes;
        }

        // Display formatted output
        cout << endl << "Student";
        for (int j = 0; j < numQuizzes; j++) {
            cout << setw(8) << "Q" << j + 1;
        }
        cout << setw(10) << "Average" << endl;

        for (int i = 0; i < numStudents; i++) {
            cout << setw(7) << i + 1;
            for (int j = 0; j < numQuizzes; j++) {
                cout << setw(8) << fixed << setprecision(2) << scores[i][j];
            }
            cout << setw(10) << fixed << setprecision(2) << avg[i] << endl;
        }

        // Ask if user wants to run again
        cout << "\nDo you want to run the program again? (Y/N): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'Y' || choice == 'y');

    cout << "Program terminated.\n";
    return 0;
}
