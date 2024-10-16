#pragma once //DO NOT DELETE
/**
* Utilities file - MASTER VERSION
* @author Madeleine Woolley
* Last updated 9/29/2024
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/** Flush istringstream buffer */
void flushInput() {
    cin.clear(); //clear the error flags on cin
    cin.ignore(10000, '\n'); //clear the stream
}

/**
* Return an integer as a string with commas, e.g. 1234 -> "1,234".
* @param n Number as integer
* @return Number as string with commas
*/
string intWithCommas(int n) {
    string result = to_string(n);

    // Loop to insert commas for thousands separators in the string
    for (size_t i = result.size() - 3; i > 0; i -= 3) {
        result.insert(i, ","); // Insert a comma after every three digits from the end
    }

    return result;
}

/**
* Check whether a given integer is positive.
* @param num Number to check
* @return Returns true if number is positive (incl. 0), false if negative
*/
bool checkPositiveInt(int num) {
    if (num >= 0) {
        return true;
    }
    return false;
}

/**
* Check whether a given double is positive.
* @param num Number to check
* @return Returns true if number is positive (incl. 0), false if negative
*/
bool checkPositiveDouble(double num) {
    if (num >= 0) {
        return true;
    }
    return false;
}

/**
* Read the entire contents of a file and output to the console.
* @param filename Name of file to read/output
*/
void printFile(string filename) {
    ifstream infile;
    string line;

    infile.open(filename);
    
    if (!infile.is_open()) {
        cout << "ERROR: File not found. Print failed.";
        return;
    }
    
    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
}

/**
* Check if a given input file stream is open. If not, indicate file is not open (found) and terminate program.
* @param inFS Input file stream
*/
void checkFileOpen(ifstream& inFS) {
    if (!inFS.is_open()) {
        cout << "ERROR: File not open. Program terminating..." << endl;
        exit(0);
    }
}

/**
* Check if a given input file stream is open. If not, indicate file is not open (found) and terminate program. Prints name of unopened file from input parameter.
* @param inFS Input file stream
* @param filename Name of file
*/
void checkFileOpen(ifstream& inFS, string filename) {
    if (!inFS.is_open()) {
        cout << "ERROR: " << filename << " not open. Program terminating..." << endl;
        exit(0);
    }
}

/**
* Check if a given output file stream is open. If not, indicate file is not open (found) and terminate program.
* @param outFS Output file stream
*/
void checkFileOpen(ofstream& outFS) {
    if (!outFS.is_open()) {
        cout << "ERROR: File not open. Program terminating..." << endl;
        exit(0);
    }
}

/**
* Check if a given output file stream is open. If not, indicate file is not open (found) and terminate program. Prints name of unopened file from input parameter.
* @param outFS Output file stream
* @param filename Name of file
*/
void checkFileOpen(ofstream& outFS, string filename) {
    if (!outFS.is_open()) {
        cout << "ERROR: " << filename << " not open. Program terminating..." << endl;
        exit(0);
    }
}
 
/**
* Convert a string to all lowercase characters. Ignores punctuation.
* @param input String to convert
* @return Lowercase string
*/
string toLower(const string& input) {
    string result = "";
    
    for (char c : input) {
        result += tolower(c);
    }
    return result;
}

/**
* Convert a string to all uppercase characters. Ignores punctuation.
* @param input String to convert
* @return Uppercase string
*/
string toUpper(const string& input) {
    string result = "";

    for (char c : input) {
        result += toupper(c);
    }
    return result;
}

/**
* Removes all punctuation from the string (as defined by current C locale).
* @param String to convert
* @return String without punctuation
*/
string removePunct(const string& input) {
    string result = "";
    size_t length = input.size();

    for (size_t i = 0; i < length; i++) {
        if (!ispunct(input[i])) {
            result += input[i];
        }
    }
    return result;
}

/**
* Compare two strings, ignoring letter casing. Otherwise functions the same as std::string::compare, where two equal strings produces ouptut of 0, the first string bring first alphabetically produces output of < 0, and the first string being last alphabetically produces output of > 0. Also ignores punctuation.
* @param string1 First string to compare
* @param string2 Second string to compare
* @return Returns 0 if equal, < 0 if string1 is first alphabetically, and > 0 if string2 is first alphabetically.
* @see std::string::compare
*/
int compareDictOrder(const string& string1, const string& string2) {
    string copy1 = removePunct(string1);
    copy1 = toLower(copy1);
    string copy2 = removePunct(string2);
    copy2 = toLower(copy2);
    
    return copy1.compare(copy2);
}

/** Gets valid integer input from the user. Prompt should be in the format "Enter <integer info>: ".
* @param prompt Prompt shown to user
* @return Valid integer input
*/
int getInteger(string prompt) {
    int x = 0;

    cout << prompt;
    cin >> x;

    while (cin.fail()) {
        cout << "Invalid input. Please enter a valid integer." << endl;
        flushInput();
        cout << prompt;
        cin >> x;
    }
    return x;
}

/** Gets valid integer input from the user.
* @return Valid integer input
*/
int getInteger() {
    return getInteger("Enter an integer: ");
}

/** Gets valid integer input from the user. Prompt should be in the format "Enter <integer info>: ". User input should be within the minimum to maximum range (including bounds).
* @param prompt Prompt shown to user
* @param minValue Minimum valid integer
* @param maxValue Maximum valid integer
* @return Valid integer input
*/
int getInteger(string prompt, int minValue, int maxValue) {
    int x = 0;
    bool valid = false;

    do {
        cout << prompt;
        cin >> x;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer." << endl;
            flushInput();
        }
        else if (x < minValue || x > maxValue) {
            cout << "Input outside of bounds [" << minValue << " to ";
            cout << maxValue << "]. Please enter a valid integer." << endl;
        }
        else
            valid = true;
    } while (!valid);
    return x;
}

/** Gets a line of string input from the user. Prompt should be in the format "Enter <integer info>: ".
* @param prompt Prompt shown to user
* @return String input
*/
string getStringLine(string prompt) {
    string input = "";
    cout << prompt;
    flushInput(); //completely clears previous input
    getline(cin, input);
    return input;
}

/** Gets a line of string input from the user. */
string getStringLine() {
    return getStringLine("Enter a string: ");
}

/** Searches the first string for an instance of the second string, ignoring letter casing.
* @param bigString String to be searched
* @param subString String to search for in bigString
* @return True if lowercase subString is in lowercase bigString
*/
bool containsIgnoreCase(const string& bigString, const string& subString) {
    string lowerBig = toLower(bigString);
    string lowerSub = toLower(subString);
    bool found = false;
    if (lowerBig.find(lowerSub) != string::npos) {  //.find() returns position of the string found
        found = true;
    }
    return found;
}

/** Prints a menu line using a given char of a given length.
* @param lineChar Character used for menu line
* @param length Length of the menu line
*/
void printMenuLine(char lineChar, int length) {
    cout << setfill(lineChar) << setw(length) << "" << endl;
}

/** Prints a menu line using '-' of length 30. */
void printMenuLine() {
    printMenuLine('-', 30);
}

/** Prints a menu line using '-' of a given length.
* @param length Length of the menu line
*/
void printMenuLine(int length) {
    printMenuLine('-', length);
}

/** Prompts user to press enter to continue. */
void pressEnter() {
    flushInput();
    cout << "Press enter to continue. ";
    flushInput();
}

/** Converts a specified integer to its ordinal value, e.g. 1 -> "1st".
* @param num Integer to be converted
* @return Ordinal value
*/
string intToOrdinal(int num) {
    string ordinal = to_string(num);
    int remainder = num % 10;

    if (num < 1)
        cout << "Invalid ordinal number." << endl;
    else if (remainder == 1)
        ordinal += "st";
    else if (remainder == 2)
        ordinal += "nd";
    else if (remainder == 3)
        ordinal += "rd";
    else
        ordinal += "th";
    return ordinal;
}