#pragma once //DO NOT DELETE
/**
* Utilities file - MASTER VERSION
* @author Madeleine Woolley
* Last updated 9/29/2024
*/

#include <fstream>
#include <iostream>

namespace util {
	/** Flush istringstream buffer */
	void flushInput();

	/**
	* Return an integer as a string with commas, e.g. 1234 -> "1,234".
	* @param n Number as integer
	* @return Number as string with commas
	*/
	std::string intWithCommas(int n);

	/**
	* Check whether a given integer is positive.
	* @param num Number to check
	* @return Returns true if number is positive (incl. 0), false if negative
	*/
	bool checkPositiveInt(int num);

	/**
	* Check whether a given double is positive.
	* @param num Number to check
	* @return Returns true if number is positive (incl. 0), false if negative
	*/
	bool checkPositiveDouble(double num);

	/**
	* Read the entire contents of a file and output to the console.
	* @param filename Name of file to read/output
	*/
	void printFile(std::string filename);

	/**
	* Check if a given input file stream is open. If not, indicate file is not open (found) and terminate program.
	* @param inFS Input file stream
	*/
	void checkFileOpen(std::ifstream& inFS);

	/**
	* Check if a given input file stream is open. If not, indicate file is not open (found) and terminate program. Prints name of unopened file from input parameter.
	* @param inFS Input file stream
	* @param filename Name of file
	*/
	void checkFileOpen(std::ifstream& inFS, std::string filename);

	/**
	* Check if a given output file stream is open. If not, indicate file is not open (found) and terminate program.
	* @param outFS Output file stream
	*/
	void checkFileOpen(std::ofstream& outFS);

	/**
	* Check if a given output file stream is open. If not, indicate file is not open (found) and terminate program. Prints name of unopened file from input parameter.
	* @param outFS Output file stream
	* @param filename Name of file
	*/
	void checkFileOpen(std::ofstream& outFS, std::string filename);

	/**
	* Convert a string to all lowercase characters. Ignores punctuation.
	* @param input String to convert
	* @return Lowercase string
	*/
	std::string toLower(const std::string& input);

	/**
	* Convert a string to all uppercase characters. Ignores punctuation.
	* @param input String to convert
	* @return Uppercase string
	*/
	std::string toUpper(const std::string& input);

	/**
	* Removes all punctuation from the string (as defined by current C locale).
	* @param String to convert
	* @return String without punctuation
	*/
	std::string removePunct(const std::string& input);

	/**
	* Compare two strings, ignoring letter casing. Otherwise functions the same as std::string::compare, where two equal strings produces ouptut of 0, the first string bring first alphabetically produces output of < 0, and the first string being last alphabetically produces output of > 0. Also ignores punctuation.
	* @param string1 First string to compare
	* @param string2 Second string to compare
	* @return Returns 0 if equal, < 0 if string1 is first alphabetically, and > 0 if string2 is first alphabetically.
	* @see std::string::compare
	*/
	int compareDictOrder(const std::string& string1, const std::string& string2);

	/** Gets valid integer input from the user. Prompt should be in the format "Enter <integer info>: ".
	* @param prompt Prompt shown to user
	* @return Valid integer input
	*/
	int getInteger(std::string prompt);

	/** Gets valid integer input from the user.
	* @return Valid integer input
	*/
	int getInteger();

	/** Gets valid integer input from the user. Prompt should be in the format "Enter <integer info>: ".
	* User input should be within the minimum to maximum range (including bounds).
	* @param prompt Prompt shown to user
	* @param minValue Minimum valid integer
	* @param maxValue Maximum valid integer
	* @return Valid integer input
	*/
	int getInteger(std::string prompt, int minValue, int maxValue);

	/** Gets a valid double input from the user. Prompt should be in the format "Enter <double info>: ".
	* @param prompt Prompt shown to user
	* @return Valid double input
	*/
	double getDouble(std::string prompt);

	/** Gets a valid double input from the user.
	* @return Valid double input
	*/
	double getDouble();

	/** Gets valid double input from the user. Prompt should be in the format "Enter <double info>: ".
	* User input should be within the minimum to maximum range (including bounds).
	* @param prompt Prompt shown to user
	* @param minValue Minimum valid double
	* @param maxValue Maximum valid double
	* @return Valid double input
	*/
	double getDouble(std::string prompt, double minValue, double maxValue);

	/** Gets a line of string input from the user. Prompt should be in the format "Enter <integer info>: ".
	* @param prompt Prompt shown to user
	* @return String input
	*/
	std::string getStringLine(std::string prompt);

	/** Gets a line of string input from the user. */
	std::string getStringLine();

	/** Searches the first string for an instance of the second string, ignoring letter casing.
	* @param bigString String to be searched
	* @param subString String to search for in bigString
	* @return True if lowercase subString is in lowercase bigString
	*/
	bool containsIgnoreCase(const std::string& bigString, const std::string& subString);

	/** Prints a menu line using a given char of a given length.
	* Default char is '-', and default length is 30.
	* The method accepts 0-2 arguments.
	* @param length Length of the menu line
	* @param lineChar Character used for menu line
	*/
	void printMenuLine(int length = 30, char lineChar = '-');

	/** Prompts user to press enter to continue. */
	void pressEnter();

	/** Converts a specified integer to its ordinal value, e.g. 1 -> "1st".
	* @param num Integer to be converted
	* @return Ordinal value
	*/
	std::string intToOrdinal(int num);
}