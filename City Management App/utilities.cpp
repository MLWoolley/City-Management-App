#include "utilities.h"
#include <iomanip>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

void util::flushInput() {
    cin.clear(); //clear the error flags on cin
    cin.ignore(10000, '\n'); //clear the stream
}

string util::intWithCommas(int n) {
    string result = std::to_string(n);
    bool isNegative = false;

    int currPos = result.length() - 3; //stores current index to insert comma at

    int frontPos = (n >= 0) ? 0 : 1; //frontPos = 1 if n < 0, otherwise frontPos = 0
    while (currPos > frontPos) {
        result.insert(currPos, ",");
        currPos -= 3;
    }

    return result;
}

bool util::checkPositiveInt(int num) {
    if (num >= 0) {
        return true;
    }
    return false;
}

bool util::checkPositiveDouble(double num) {
    if (num >= 0) {
        return true;
    }
    return false;
}

void util::printFile(string filename) {
    ifstream infile;
    string line;

    infile.open(filename);

    if (!infile.is_open()) {
        cout << "ERROR: File not found. Print failed." << endl;
        return;
    }

    while (std::getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
}

void util::checkFileOpen(ifstream& inFS) {
    if (!inFS.is_open()) {
        cout << "ERROR: File not open. Program terminating..." << endl;
        exit(0);
    }
}

void util::checkFileOpen(ifstream& inFS, string filename) {
    if (!inFS.is_open()) {
        cout << "ERROR: " << filename << " not open. Program terminating..." << endl;
        exit(0);
    }
}

void util::checkFileOpen(ofstream& outFS) {
    if (!outFS.is_open()) {
        cout << "ERROR: File not open. Program terminating..." << endl;
        exit(0);
    }
}

void util::checkFileOpen(ofstream& outFS, string filename) {
    if (!outFS.is_open()) {
        cout << "ERROR: " << filename << " not open. Program terminating..." << endl;
        exit(0);
    }
}

string util::toLower(const string& input) {
    string result = "";

    for (char c : input) {
        result += tolower(c);
    }
    return result;
}

string util::toUpper(const string& input) {
    string result = "";

    for (char c : input) {
        result += toupper(c);
    }
    return result;
}

string util::removePunct(const string& input) {
    string result = "";
    size_t length = input.size();

    for (size_t i = 0; i < length; i++) {
        if (!ispunct(input[i])) {
            result += input[i];
        }
    }
    return result;
}

int util::compareDictOrder(const string& string1, const string& string2) {
    string copy1 = removePunct(string1);
    copy1 = toLower(copy1);
    string copy2 = removePunct(string2);
    copy2 = toLower(copy2);

    return copy1.compare(copy2);
}

int util::getInteger(string prompt) {
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

int util::getInteger() {
    return getInteger("Enter an integer: ");
}

int util::getInteger(string prompt, int minValue, int maxValue) {
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

double util::getDouble(std::string prompt) {
    double x = 0;

    cout << prompt;
    cin >> x;

    while (cin.fail()) {
        cout << "Invalid input. Please enter a valid double." << endl;
        flushInput();
        cout << prompt;
        cin >> x;
    }
    return x;
}

double util::getDouble() {
    return getDouble("Enter a double: ");
}

double util::getDouble(std::string prompt, double minValue, double maxValue) {
    double x = 0;
    bool valid = false;

    do {
        cout << prompt;
        cin >> x;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid double." << endl;
            flushInput();
        }
        else if (x < minValue || x > maxValue) {
            cout << "Input outside of bounds [" << minValue << " to ";
            cout << maxValue << "]. Please enter a valid double." << endl;
        }
        else
            valid = true;
    } while (!valid);
    return x;
}

string util::getStringLine(string prompt) {
    string input = "";
    flushInput(); //completely clears previous input
    cout << prompt;
    getline(cin, input);
    return input;
}

string util::getStringLine() {
    return getStringLine("Enter a string: ");
}

bool util::containsIgnoreCase(const string& bigString, const string& subString) {
    string lowerBig = toLower(bigString);
    string lowerSub = toLower(subString);
    bool found = false;
    if (lowerBig.find(lowerSub) != string::npos) {  //.find() returns position of the string found
        found = true;
    }
    return found;
}

void util::printMenuLine(char lineChar, int length) {
    cout << std::setfill(lineChar) << std::setw(length) << "" << endl;
    cout << std::setfill(' '); //reset fill char
}

void util::printMenuLine() {
    printMenuLine('-', 30);
}

void util::printMenuLine(int length) {
    printMenuLine('-', length);
}

void util::pressEnter() {
    flushInput();
    cout << "Press enter to continue. ";
    flushInput();
}

string util::intToOrdinal(int num) {
    string ordinal = std::to_string(num);
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