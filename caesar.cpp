/*
 * ceasar.cpp
 *
 *  Created on: Oct 28, 2024
 *      Author: Naj
 */
#include "caesar.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string caesarCipher(char mode, string input, string output, int shift) {
	char base;
	char shifted;
	string result = "";

	shift = shift % 26; // Sets shift base between 0 and 25

	string line;

	fstream inFile (input, ios::in);
	fstream outFile (output, ios::out);


	if (inFile.is_open()) {
		while (getline (inFile, line)) {
			result = "";

			for (char c : line) {
					if (isalpha(c)) {
						base = islower(c) ? 'a' : 'A'; // Determine the case of the given letter

						if (mode == 'e') {

						shifted = (c - base + shift) % 26 + base;
						}
					else if (mode == 'd') {
						shifted = (c - base - shift + 26) % 26 + base;

						}
							result += shifted;

					}
					else {
						result += c; // Non-alphanumeric characters stay the same


					}


				}
			if (outFile.is_open()) {
					outFile << result << "\n";
			}
			else
				cout << "Unable to open " << output << endl;
		}


	}
	else {
		cout << "Unable to open " << input << endl;
	}
	inFile.close();
	outFile.close();

 return "done";
}


