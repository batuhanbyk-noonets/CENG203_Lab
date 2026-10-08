#include <iostream>
#include "Labs/Labs.h" // Labs.h is in the Labs subfolder
using namespace std;
int main() // the ONLY main() of the project
{
int choice;
do {
cout << "\n===== CENG203 Data Structures Lab =====" << endl;
cout << " 2. Week 2 - Project structure test" << endl;
cout << " 0. Exit" << endl;
cout << "Your choice: ";
cin >> choice;
switch (choice) {
case 2: runWeek02(); break;
// case 3: runWeek03(); break; <- one new line per week
case 0: cout << "Bye!" << endl; break;
default: cout << "Invalid choice!" << endl;
}
} while (choice != 0);
return 0;
}