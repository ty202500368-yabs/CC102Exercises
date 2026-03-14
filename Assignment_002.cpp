#include <iostream>
#include <iomanip>
using namespace std;

void analyzeGrades(int *grades, int students, int subjects) {
    int highest = *(grades + 0);

    cout << "\nGrade Matrix:\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << setw(6) << *(grades + i * subjects + j);
        }
        cout << endl;
    }

    cout << "\nAverage grade of each student:\n";
    for (int i = 0; i < students; i++) {
        int sum = 0;

        for (int j = 0; j < subjects; j++) {
            sum += *(grades + i * subjects + j);
        }

        double average = (double)sum / subjects;
        cout << "Student " << i + 1 << ": " << fixed << setprecision(2) << average << endl;
    }

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            if (*(grades + i * subjects + j) > highest) {
                highest = *(grades + i * subjects + j);
            }
        }
    }

    cout << "\nHighest grade in the matrix: " << highest << endl;
}

int main() {
    char c;
    do{
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[100][100];

    cout << "\nEnter grades:\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    analyzeGrades(&grades[0][0], students, subjects);

    cout << "Repeat: [Y/y]";
    cin >> c;
    }while(c == 'Y' || c == 'y');
    return 0;
}
