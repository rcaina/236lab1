#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctype.h>
//#include <fstream>
#include "Lexer.h"
#include "Tokens.h"

using namespace std;

Lexer::Lexer(char* readMe) {
    

	ifstream myfile;
	myfile.open(readMe);

	char item;
	int line_num = 1;
	int hold_num = 0;
	//char hold;
	string currentString = "";
	string temp;
	Tokens t;
	
	while (myfile.get(item)) {
	    
        cout << item;
        cout << "stuck1?\n";
        
        
		if (isalpha(item)) {

			while (isalnum(item)) {
			    
				currentString = currentString + item;
				myfile.get(item);
			}
			if (currentString == "Queries")
			{
				t = Tokens("QUERIES", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else if (currentString == "Rules")
			{
				t = Tokens("RULES", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else if (currentString == "Facts")
			{
				t = Tokens("FACTS", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else if (currentString == "Schemes")
			{
				t = Tokens("SCHEMES", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else if (item != '\''){
			    t = Tokens("ID", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}

			//myfile.putback(item);
		//	myfile.get(item);
		}

       // else {
			switch (item) {
                  cout <<"66";
			case '+':
			cout << "stuck2?\n";
				t = Tokens("ADD", "+", line_num);
				myTokens.push_back(t);

				cout << "stuck3?\n";
				break;
			case '*':
			cout << "stuck4?\n";
				t = Tokens("MULTIPLY", "*", line_num);
				myTokens.push_back(t);

				cout << "stuck5?\n";
				break;
			case ':':
			
			    if (myfile.peek()== '-'){
				t = Tokens("COLON_DASH", ":-", line_num);
					myTokens.push_back(t);
					myfile.get(item);
				}
				else {

				t = Tokens("COLON", ":", line_num);
				myTokens.push_back(t);
				}

				break;
			case '(':
			cout << "stuck8?\n";
				t = Tokens("LEFT_PAREN", "(", line_num);
				myTokens.push_back(t);

				cout << "stuck9?\n";
				break;
			case ')':
			cout << "stuck10?\n";

				t = Tokens("RIGHT_PAREN", ")", line_num);
				myTokens.push_back(t);

				cout << "stuck11?\n";
				break;
			case '?':
			cout << "stuck13?\n";
				t = Tokens("Q_MARK", "?", line_num);
				myTokens.push_back(t);

				cout << "stuck14?\n";
				break;
			case '.':
			cout << "stuck15?\n";
				t = Tokens("PERIOD", ".", line_num);
				myTokens.push_back(t);

				cout << "stuck6?\n";
				break;
			case ',':
			cout << "stuck17?\n";
				t = Tokens("COMMA", ",", line_num);
				myTokens.push_back(t);

				cout << "stuck18?\n";
				break;
			case '#':
			 cout << "stuck20?\n";
				if (myfile.peek() == '|') {
                       
                        cout << "stuck22?\n";
					while (item != '|' && myfile.peek() != '#') {
						 cout << "stuck23?\n";
						 
						if (item == '\n') {
						    currentString = currentString + item;
						    
							cout << "stuck24?\n";
						}
						else {
						    currentString = currentString + item;
						    cout << "stuck25?\n";
		
						}
						myfile.get(item);
					} 
                    
					currentString = currentString + item;
					myfile.get(item);
			        line_num++;
					currentString = currentString + item;
                     cout << "stuck28?\n";
					t = Tokens("BLOCK_COMMENT", currentString, line_num);
					myTokens.push_back(t);
					currentString = "";
					cout << currentString;
					break;
				}
				else {

					while ( item != '\n') {

						currentString = currentString + item;
						myfile.get(item);
						cout << "stuck31?\n";
					}
			
				    cout << "stuck32?\n";
					t = Tokens("COMMENT", currentString, line_num);
					myTokens.push_back(t);
					currentString == "";
					currentString.clear();
					cout << "stuck33?\n";
					cout << item;
					line_num++;
					break;
				}
				cout << "stuck40?\n";

            case '\'':
                currentString = currentString + item;
				myfile.get(item);
				hold_num = line_num;
				if(item == '\n'){
					line_num++;
				}
                while(item !='\''){
                    currentString = currentString + item;
					myfile.get(item);
					if(item == '\n'){
					    	line_num++;
					    }
					else if(item =='\'' && myfile.peek() == '\''){
						currentString = currentString + item;
					    myfile.get(item);
					    currentString = currentString + item;
					    myfile.get(item);
					}
					else if(item == '\''){
				    	currentString = currentString + item;
				    }
                }
                myfile.get(item);
                t = Tokens("STRING", currentString, hold_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
				myfile.putback(item);
                break;

			case '\n':
				line_num++;
				
				break;
			case ' ':
				break;
			case '\t':
				break;
			default :
					    currentString = currentString + item;
			            
			            t = Tokens("UNDEFINED", currentString, line_num);
						myTokens.push_back(t);
						currentString = "";
						cout << currentString;
				break;
			}

       cout << "stuckwhile?\n";
	}
        t = Tokens("EOF", "", line_num);
    	myTokens.push_back(t);

        int k = myTokens.size();
        for(int i = 0; i < k; i++){
        	
        myTokens[i].toString();
        
        }

        cout << "Total Tokens = " << k << "\n";
}





