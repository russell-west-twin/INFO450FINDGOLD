// The objective is to keep guessing until you find the gold. The user have 5 guesses and earns a point for each time he or she finds gold. If they find BOMB, the game is over. I added extra logic to where if the user find Gold, they get an extra guess.

 

#include <iostream>

#include <time.h> // Used for seeding

#include <iomanip> 

 

using namespace std;

 

// public (global) vairables

int GUESS = 5; // Instantiate GUESS to the number 5 since it's the max guess a player can get.

const int ROWS = 8; //8 rows

const int COLUMNS = 8; //8 columns

 

 

int main()

{

            // Declaring methods

    int gameFlow(char pickArray[ROWS][COLUMNS]);

            int callArray(char pickArray[ROWS][COLUMNS]);

            int storeArray(char pickArray[ROWS][COLUMNS]);

    int showArray(char pickArray[ROWS][COLUMNS]);

            int rules();

 

            char array[ROWS][COLUMNS];

            char choice; // User's choice on whether they want to play or not

 

            do //Performing a do-while loop to at least execute the loop at least once while their answer is valid. Also, having a condition where guesses goes back to 5 if the user wants to play the game again.

            {

        gameFlow(array);

                        callArray(array);

                        storeArray(array);

                        showArray(array);

                        rules();

 

                        cout << "Play again?? If so, kindly enter either 'Y' or 'y'" << endl;

                        cin >> choice;

 

                        if (choice == 'Y' || choice == 'y')

                        {

                                    GUESS=5; // If the user pick 'Y' or 'y', then reset the GUESS count back to 5.

                        }

 

            } while (choice=='Y' || choice== 'y'); // While the choice is one of the options

    return 0;

}

 

// Game Flow

int gameFlow(char array[ROWS][COLUMNS])

{

            int score = 0;

            int col, row;

 

            do

            {

                        // Ask for the user to enter the coordinates

                        cout << "Enter an X coordinate between 1 and 8:  ";

                        cin >> row;

 

                        //While case where if the user doesnt put an integer, asks he or she to try again. Also, has a case if the numbers are outside of the range.

                        while (!cin || row > 8 || row < 1)

                        {

                                    cout << "Integer will need to be between 1 and 8:  ";

                                    cin >> row;

                        }

 

                        row--; // Arrays start at 0, so I am subtracting 1 here.

                        cout << endl;

                        cout << "Enter a Y coordinate between 1 and 8:  ";

                        cin >> col;

 

                        //While case where if the user doesnt put an integer, asks he or she to try again. Also, has a case if the numbers are outside of the range.

                        while (!cin || col > 8 || col < 1)

                        {

                                    cout << "Integer will need to be between 1 and 8:  ";

                                    cin >> col;

                        }

 

                        col--; // Arrays start at 0, so I am subtracting 1 here.

                        cout << endl;

 

                        // Whenever the user finds gold, add an extra point.

                        if (array[row][col] == 'G')

                        {

                                    cout << "Congrats, you just found gold! You now have 1 extra guess. You have " << GUESS << " guesses left!";

                                    score += 1; // Adding one point

                                    cout << endl;

                                    cout << endl;

                                    continue; // Once this condition is met, go back to beginning of the loop.

                        }

                        // If the user finds a bomb, end the game by putting break.

                        else if (array[row][col] == 'B')

                        {

                                    cout << endl;

                                    cout << "You found the BOMB. Game over!" << endl; // This is where the user will see he or she has lost the game. Sooner or later, the game will exit itself.

                                    break; // Termniate the game since the user found the bomb.

                        }

                        // If the user didn't find Gold on a given try, 1 guess will be subtracted.

                        else

                        {

                                    cout << "Nope, there's no gold here." << endl;

                                    GUESS--; // Number of guesses has decreased by 1.

                                    cout << "You have " << GUESS << " guesses left!" << endl;

                        }

 

            } while (GUESS > 0); // Continue to perform this Do While loop WHILE the number of user's guesses is greater than 0.

 

            cout << "You have " << score << " points!" << endl;

            cout << "Come back next time...if you want too." << endl;

            cout << "Your board:" << endl; // Showing below where the hidden gold and bomb was.

 

            // Showing below where the hidden gold and bomb was.

            for (col = 0; col < COLUMNS; col++)

            {

                        cout << col + 1; // Arrays are at 0, so we add 1.

            }

            cout << endl;

            cout << "  " << "----------------" << endl; //spacing purposes

 

            for (row = 0; row < ROWS; row++)

            {

                        cout << " " << row + 1 << "|"; // Arrays are at 0, so we add 1.

                        for (col = 0; col < COLUMNS; col++)

                        {

                                    cout << array[row][col]; // displaying the array

                        }

                        cout << endl;

            }

            cout << "  " << "-----------------" << endl; //spacing purposes

            return 0;

}

 

int callArray(char array[ROWS][COLUMNS]) //iterating through the array

{

            int row, column;

 

            GUESS = 5; // Once the array is instantiated, number of guess will need to go back to 5.

 

            // Start going and iterating through the array. Adding empty string.

            for (row = 0; row < ROWS; row++)

            {

                        for (column = 0; column < COLUMNS; column++)

                        {

                                    array[row][column] = '';

                        }

            }

            return 0;

}

 

// Putting the bomb and gold in the array. Keep in mind they can't be displayed since the user will have to guess where the Gold is on their own.

int storeArray(char array[ROWS][COLUMNS])

 

{

            int bomb = 0;

            int x, y;

            int gold = 0;

            srand(time(NULL)); // Do everything random.

 

            // Putting the gold in a random coordinate.

            do {

                        x = rand() % ROWS; // Fetch a random row number.

                        y = rand() % COLUMNS; // Fetch a random column number.

 

                        if (array[x][y] != 'G')

                        {

                                    array[x][y] = 'G'; // Put 'G' for Gold at the random (X,Y) Coordinate

                                    gold++; //Increment gold once it is found.

                        }

 

            } while (gold < 5); //while gold is less than 5.

 

   // Adds a bomb at a random (X,Y) coordinate

            do

            {

                        x = rand() % ROWS; // Fetch a random row number.

                        y = rand() % COLUMNS; // Fetch a random row number.

 

                        if (array[x][y] != 'G') // Making sure the random row and column number doesn't fall in the same place where the gold is at.

                        {                       // I had to add this condition cause I kept getting this wrong.   

                                    array[x][y] = 'B'; // After finding a random spot that doesnt have the gold in it, place the bomb in the random coordinates.

                                    bomb++;

                        }

            } while (bomb < 1); //Perform this while 1 is more than the bomb count.

 

            return 0;

}

 

// Display the array

int showArray(char array[ROWS][COLUMNS])

 

{

            int row, column;

            cout << endl;

            for (column = 0; column < COLUMNS; column++)

            {

                        cout << column + 1; // Since arrays start at 0, we add 1

            }

            cout << endl;

 

            for (row = 0; row < ROWS; row++)

            {

                        cout << " " << row + 1; // Since arrays start at 0, we add 1. Adds an empty string.

                        for (column = 0; column < COLUMNS; column++)

                        {

                                    cout << array[row][column]; // Display the array

                        }

                        cout << endl;

            }

            return 0;

 

}

 

// Here are the rules to the game.

int rules()

{

            cout << "**" << " ********************* " << "**" << endl;

    cout << "**" << "                       " << "**" << endl;

            cout << "**" << "      Find Gold!       " << "**" << endl;

            cout << "**" << "  You have 5 guesses,  " << "**" << endl;

            cout << "**" << "   5 pieces of gold,   " << "**" << endl;

            cout << "**" << "     and 1 bomb.       " << "**" << endl;

    cout << "**" << "                       " << "**" << endl;

    cout << "**" << "      Good Luck!       " << "**" << endl;

            cout << "**" << "                       " << "**" << endl;

    cout << "**" << "       Also,           " << "**" << endl;

            cout << "**" << "  You Can Earn an      " << "**" << endl;

    cout << "**" << "  extra guess if       " << "**" << endl;

            cout << "**" << "  you can find gold!   " << "**" << endl;

    cout << "**" << "                       " << "**" << endl;

            cout << "**" << " ********************* " << "**" << endl;

            cout << endl;

 

            return 0;

}
