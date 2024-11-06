/*
 * main.cpp
 *
 *  Created on: Oct 28, 2024
 *      Author: Naj
 */
#include <iostream>
#include <unistd.h>
#include "ceasar.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	int shift;
	char mode;
	char opt;
	string inputFile;
	string outputFile;
	int eflag, dflag, iflag, oflag;

	eflag = 0;
	dflag = 0;
	iflag = 0;
	oflag = 0;

	while( (opt = getopt(argc, argv, "i:o:ed")) != -1) {
		switch(opt) {
		case 'i':
			iflag = 1;
			inputFile = optarg;
			break;
		case 'o':
			oflag = 1;
			outputFile = optarg;
			break;
		case 'e':
			eflag = 1;
			mode = 'e';
			break;
		case 'd':
			dflag = 1;
			mode = 'd';
			break;
		default:
			cout << "Unknown option" << argv[0] << endl;

		}
	}

	if (argc != 6 || (iflag == 0) || (oflag == 0) || (eflag == dflag)) {
		cout << "Error!" << endl;
		}

	cout << "Welcome to the Caesar Cipher" << endl;

	if (eflag == 1) {
		cout << "Selected Mode: Encrypt" << endl;
	}
	else if (dflag == 1) {
		cout << "Selected Mode: Decrypt" << endl;
	}

	cout << "Input File: " << inputFile << endl;
	cout << "Output File: " << outputFile  << endl;
	cout << "Please enter the shift value (1-25): " << endl;
	cin >> shift;

	caesarCipher(mode, inputFile, outputFile, shift);

	if (eflag == 1) {
		cout << "Encrypted ciphertext binary file created: " << outputFile;
	}
	else if (dflag == 1) {
		cout << "Decrypted plaintext file created: " << outputFile;
	}


	return 0;
}

