#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int SALESPEOPLE = 4;
    const int PRODUCTS = 5;
    double sales[PRODUCTS][SALESPEOPLE] = {0};
    char choice;

    do {
        int salesperson, product;
        double amount;
        char moreData;

        // Input section
        do {
            cout << "Enter salesperson number [1-4]: ";
            cin >> salesperson;
            cout << "Enter product number [1-5]: ";
            cin >> product;
            cout << "Enter amount sold: ";
            cin >> amount;

            if (salesperson >= 1 && salesperson <= SALESPEOPLE &&
                product >= 1 && product <= PRODUCTS && amount >= 0) {
                sales[product - 1][salesperson - 1] += amount;
            } else {
                cout << "Invalid input. Please try again.\n";
            }

            cout << "Enter another sales record? (Y/N): ";
            cin >> moreData;
            cout << endl;

        } while (moreData == 'Y' || moreData == 'y');

        // Display table
        cout << setw(12) << "Product";
        for (int s = 0; s < SALESPEOPLE; s++) {
            cout << setw(12) << "Salesperson " << s + 1;
        }
        cout << setw(12) << "Total" << endl;

        double salespersonTotal[SALESPEOPLE] = {0};
        double grandTotal = 0;

        for (int p = 0; p < PRODUCTS; p++) {
            cout << setw(12) << p + 1;
            double productTotal = 0;

            for (int s = 0; s < SALESPEOPLE; s++) {
                cout << setw(12) << fixed << setprecision(2) << sales[p][s];
                productTotal += sales[p][s];
                salespersonTotal[s] += sales[p][s];
            }

            cout << setw(12) << fixed << setprecision(2) << productTotal << endl;
            grandTotal += productTotal;
        }

        // Totals per salesperson
        cout << setw(12) << "Total";
        for (int s = 0; s < SALESPEOPLE; s++) {
            cout << setw(12) << fixed << setprecision(2) << salespersonTotal[s];
        }
        cout << setw(12) << fixed << setprecision(2) << grandTotal << endl;

        // Ask if user wants to run again
        cout << "\nDo you want to run the program again? (Y/N): ";
        cin >> choice;
        cout << endl;

        // Reset sales data if running again
        if (choice == 'Y' || choice == 'y') {
            for (int i = 0; i < PRODUCTS; ++i)
                for (int j = 0; j < SALESPEOPLE; ++j)
                    sales[i][j] = 0;
        }

    } while (choice == 'Y' || choice == 'y');

    cout << "Program terminated.\n";
    return 0;
}
