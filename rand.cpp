#include <iostream>
#include <cstdlib>
#include <ctime> // time ko lagi 

using namespace std;

int main() {
    srand(time(0)); // ensure everytime new value aauxa 

    int a, b, answer, correct;
    char op;
    int score = 0;

    while (true) {
        a = rand() % 10 + 1; // 1st random value 
        b = rand() % 10 + 1; // 2nd random value 
        int choice = rand() % 4; // chosing random operator 

        if (choice == 0) {
            op = '+';
            correct = a + b;
        } else if (choice == 1) {
            op = '-';
            correct = a - b;
        } else if (choice == 2){
            op = '*';
            correct = a * b;
        }
         else {
            op = '/';

            // Make division exact
            correct = a;
            b = rand() % 9 + 1;   // b ≠ 0
            a = correct * b;      // a divisible by b
        }

        cout << "What is " << a << " " << op << " " << b << "? ";
        cin >> answer;

        if (answer == correct) {
            cout << "Correct!\n\n";
            score++;
        } else {
            cout << "Wrong answer \n";
            cout << "Correct answer was: " << correct << endl;
            break;
        }
    }

    cout << "Your final score: " << score << endl;
    return 0;
}
