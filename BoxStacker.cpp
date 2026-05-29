#include<iostream>
#include<algorithm>
using namespace std;

/*
Crane Cargo Management Game (often resembling puzzles like Cargo-Bot).
Game Overview
The player controls a robotic crane that moves horizontally across a series of stacks to reorganize cargo boxes. The objective is to manipulate the heights of various cargo stacks based on a sequence of input commands.
Key Game Mechanics
The Grid (
 Stacks): The game world consists of 
 vertical stacks of boxes arranged in a row. Each stack has a current number of boxes and a maximum allowable height (
).
The Crane: A crane moves left and right above the stacks. It can hold exactly one box at a time.
The Commands: The game processes a string of numeric instructions to control the crane's actions.
Control System (Input Commands)
The crane executes actions based on five specific numeric inputs:
1 (Move Left): Moves the crane one position to the left. It cannot move past the first stack (Position 0).
2 (Move Right): Moves the crane one position to the right. It cannot move past the last stack (Position 

).
3 (Pick Up Box): If the crane is empty (

) and the current stack has at least one box, the crane picks up the top box. Stack height decreases by one.
4 (Drop Box): If the crane is holding a box (

) and the current stack has not reached its maximum height limit (
), the crane drops the box. Stack height increases by one.
0 (Quit/Exit): Immediately stops the simulation.
Game Output
Once the command sequence finishes or the quit command is triggered, the game outputs the final heights of all 
 cargo stacks from left to right.
*/

int main()
{
    long long int n, h, j = 0, k = 0;
    int a[100000], b[100000];
    string str;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin.ignore();
    getline(cin, str);
    int x = str.length();
    for (int i = 0; i < x; i++) {
        switch (str[i]) {
        case '1':
            j = max(j - 1, 0);
            break;
        case '2':
            j = min(j + 1, n - 1);
            break;
        case '3':
            if (k == 0 && a[j] > 0) {
                a[j]--;
                k = 1;
            }
            break;
        case '4':
            if (k == 1 && a[j] < h) {
                a[j]++;
                k = 0;
            }
            break;
        case '0':
            goto end;
        }
    }
    end:
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
