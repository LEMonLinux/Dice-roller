#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

const vector<vector<string>> diceArt = {
{ // 1
"┌─────┐",
"│     │",
"│ ●   │",
"│     │",
"└─────┘"
},
{ // 2
"┌─────┐",
"│ ●   │",
"│     │",
"│ ●   │",
"└─────┘"
},
{ // 3
"┌─────┐",
"│ ●   │",
"│ ●   │",
"│ ●   │",
"└─────┘"
},
{ // 4
"┌─────┐",
"│ ● ● │",
"│     │",
"│ ● ● │",
"└─────┘"
},
{ // 5
"┌─────┐",
"│ ● ● │",
"│ ●   │",
"│ ● ● │",
"└─────┘"
},
{ // 6
"┌─────┐",
"│ ● ● │",
"│ ● ● │",
"│ ● ● │",
"└─────┘"
}
};

void printDice(int roll) {
for (const auto& line : diceArt[roll - 1]) {
cout << line << "\n";
}
}

int main() {
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist;

cout << "Dice roll 1-6 made by LemOnLinux";
while (true) {
int dice, sides;
cout << "Number of dice (1-10): "; cin >> dice;
if (dice < 1 || dice > 10) break;
cout << "Sides per die (4-100): "; cin >> sides;
if (sides < 4 || sides > 100) break;

dist = uniform_int_distribution<int>(1, sides);
int total = 0;
for (int i = 0; i < dice; ++i) {
int roll = dist(rng);
total += roll;
if (sides == 6) {
printDice(roll);
} else {
cout << "Roll " << (i + 1) << ": " << roll << "\n";
}
}
cout << "Total: " << total << "\n";

cout << "Roll again? (y/n): ";
char c; cin >> c;
if (tolower(c) != 'y') break;
}
cout << "Thanks for playing! Goodbye.\n";
}
