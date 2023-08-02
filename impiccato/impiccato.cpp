//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

using namespace std;

string randomWord(vector<string>, int);


int main()
{
    string parola;
    string plainWord;
    ifstream file("parole.txt");

    vector<string>* parole = new vector<string>;
    

    
    
    for (string i;  getline(file, parola);) {
        parole->push_back(parola);
    }


    int lenFile = parole->size();
    
    plainWord = randomWord(*parole, lenFile);
    delete parole;

    int lenWord = plainWord.size();

    

    string cipherWord(lenWord , '#');

     return 0;
}


string randomWord(vector<string> parole, int size) {
    uniform_int_distribution<> distribuzione(0, size - 1);
    random_device rd;
    mt19937 gen(rd());
    int random = distribuzione(gen);

    return parole[random];
}

