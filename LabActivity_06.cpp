#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    float grade;
};

void input(Student obj[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, obj[i].name);
        cout << "Enter age: ";
        cin >> obj[i].age;
        cout << "Enter grade: ";
        cin >> obj[i].grade;
    }
}

void display(Student obj[], int n) {
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name : " << obj[i].name << endl;
        cout << "Age  : " << obj[i].age << endl;
        cout << "Grade: " << obj[i].grade << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student obj[n];

    input(obj, n);
    display(obj, n);

    return 0;
}
