#include <iostream>
 #include <string>
 #include <array>
 #include <sstream>
 #include "tree.h"
 #include <queue>
#include <fstream>

 using namespace std;

 void enicode(string text);
 string instructions = " ";
 tree mores_code;
 queue<char> mores_code_in_order;


 void main() {
	 queue<string> instructions;

	 ifstream fin;
	 fin.open("morse.txt");
	 if (!fin.good()) throw "I/O error";

	 // these are to get thee root to be space
	 mores_code_in_order.push(' ');
	 instructions.push(" ");

	 // reads the file and seperates the char and the instructions
	 while (fin.good()) {
		 string line;
		 getline(fin, line);
		 mores_code_in_order.push(line[0]);
		 instructions.push(line.substr(1));
	 }

	 // read the queue letter by letter to insert into the tree
	 while (mores_code_in_order.empty() != true) {
	 mores_code.tree::insert(mores_code_in_order.front(), instructions.front(), mores_code.root);
	 mores_code_in_order.pop();
	 instructions.pop();

	}


 //menu system
 cout << "would you like to encode or decode a message?(decode/d or encode / e)" << endl;
 string menu_input;
 while (true) {

 // get input safely
	if (!(cin >> menu_input)) {
	cin.clear();
	cin.ignore(10000, '\n');
	}

 //decode function: if input is decode we go here and get a morse code string
 if (menu_input == "decode" || menu_input == "DECODE" || menu_input ==
 "D" || menu_input == "d") {
 cout << "Decodeing - please enter your code(\"_\"/\".\")" << endl;
 cin.clear();
 cin.ignore(10000, '\n');
 string text;
 getline(cin, text);


 //this reads the decode string word by word and sends it to the decoder function
 for (int i = 0; i < text.size();i++) {
	 if (text[i] == ' ') {
		 mores_code.tree::print(text.substr(0,i));
		 text.erase(0, i);
		 i = 0;
	 }

 };


 mores_code.tree::print(text);


 //output menu system again
 cout << endl;
 cout << "would you like to encode or decode a message?(decode/d or encode / e)" << endl;

	}


 //encode function: if input is encode we go here and get a string input 
 else if (menu_input == "encode" || menu_input == "ENCODE" ||
 menu_input == "e" || menu_input == "E") {
 cout << "Encodeing - please enter your string" << endl;
 cin.clear();
 cin.ignore(10000, '\n');
 string text;
 getline(cin, text);
 enicode(text);
 cout << endl;
 cout << "would you like to encode or decode a message?(decode/d or encode / e)" << endl;


	}


 //error message
 else cout << "Im sorry, i didn't understand that. Please enter \"E\" or\"D\". ";


	}

 system("PAUSE");
 return;

	}

 // encoding fuction - convet to map method (assosiated array)
 void enicode(string text) {

 char morse[27][5] = { "._", "_...", "_._.", "_..", ".", ".._.", "__.",
 "....", "..", ".___", "_._", "._..", "__", "_.", "___", ".__.",
 "__._", "._.", "...", "_", ".._", "..._", ".__", "_.._", "_.__",
 "__..","  " };
 string alphabet = "abcdefghijklmnopqrstuvwxyz ";
 bool error = false;

 // check for character in the alphabet and its # location and assosiate that with the morse code #.
 for (int i = 0; i < text.size(); i++) {
 char current_letter = text[i];
 bool found = false;
 int alph_num = 0;
 while (found == false) {
 if (alph_num > 27) {
 cout << text[i];
 error = true;
 break;

	}
 if (tolower(text[i]) == alphabet[alph_num]) {
 cout << morse[alph_num] << " ";
 found = true;

	}
 else
 alph_num += 1;


	}

	}

 if (error == true) {
 cout << endl << "Symbol without a corresponding code entered.";


	}

	};
