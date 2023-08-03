//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

using namespace std;

string randomWord(vector<string>, int);
void play(string&, string, bool&);
bool _assertOp(string&, const string&);
//bool ischange(string, string);
//void _lose(bool&);
bool _win(string);


int main()
{
    bool isplay = true;
    string parola;
    string plainWord;
    ifstream file("parole.txt");

    vector<string>* parole = new vector<string>;
    

    
    
    for (string i;  getline(file, parola);) {
        parole->push_back(parola);
    }

    file.close();


    int lenFile = parole->size();
    
    plainWord = randomWord(*parole, lenFile);
    delete parole;

    int lenWord = plainWord.size();
    //cout << plainWord << endl;

    

    string cipherWord(lenWord , '#');


    while (isplay) {
        play(cipherWord, plainWord, isplay);
    }
     return 0;
}


string randomWord(vector<string> parole, int size) {
    uniform_int_distribution<> distribuzione(0, size - 1);
    random_device rd;
    mt19937 gen(rd());
    int random = distribuzione(gen);

    return parole[random];
}

void play(string& cipher, string blank, bool& playing) {
    int index = 6;

    cout << "la parola e " << cipher << " ed e lunga  " << cipher.size() << endl;

    while (index > 0) {

      
        if (_assertOp(cipher, blank)) {
            cout << cipher << endl;
            
            
        }
        else {
            index--;
   
        }

        if (index > 0) {
            cout << index << " tentativi rimanenti" << endl;
        }
        

        if (_win(cipher)) {
            playing = false;
            return;
        }
    }

    if (index == 0) {
        playing = false;
        cout << "hai perso :(";
        return;
    }


    
}

bool _assertOp(string& cipher, const string& blank) {
    cout << "Che lettera vuoi inserire?" << endl;
    char lettera;
    cin >> lettera;

    bool letteraTrovata = false;

    for (int i = 0; i < blank.size(); i++) {
        if (lettera == blank[i]) {
            cipher[i] = lettera;
            letteraTrovata = true;
        }
    }

    if (letteraTrovata) {
        cout << "La lettera " << lettera << " e presente nella parola!" << endl;
    }
    else {
        cout << "La lettera " << lettera << " non e presente nella parola." << endl;
    }

    return letteraTrovata;
}

/*
void _lose(bool& playing) {
    playing = false;
}

*/


bool _win(string cipher) {
    for (int i = 0; i < cipher.size(); i++) {
        if (cipher[i] == '#') {
            return false;
        }
    }


    cout << "hai vinto fratm";
    return true;
}