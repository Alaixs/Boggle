//TODO : Implemnter chrono, finir avec les regles du jeu, ajouter déco si possbile, a la fin montrer le nombre de mot possible avec la configuration de la grille
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <random>
using namespace std;
string tryWord, line;
int offset, score, found, j;
int row = 0;
int const MIN = 0;
int const MAX = 5;
char boggle[16][6]= {
    {'E', 'T', 'U', 'K', 'N', 'O'},
    {'E', 'V', 'G', 'T', 'I', 'N'},
    {'D', 'E', 'C', 'A', 'M', 'P'},
    {'I', 'E', 'L', 'R', 'U', 'W'},
    {'E', 'H', 'I', 'F', 'S', 'E'},
    {'R', 'E', 'C', 'A', 'L', 'S'},
    {'E', 'N', 'T', 'D', 'O', 'S'},
    {'O', 'F', 'X', 'R', 'I', 'A'},
    {'N', 'A', 'V', 'E', 'D', 'Z'},
    {'E', 'I', 'O', 'A', 'T', 'A'},
    {'G', 'L', 'E', 'N', 'Y', 'U'},
    {'B', 'M', 'A', 'Q', 'J', 'O'},
    {'T', 'L', 'I', 'B', 'R', 'A'},
    {'S', 'P', 'U', 'L', 'T', 'E'},
    {'A', 'I', 'M', 'S', 'O', 'R'},
    {'E', 'N', 'H', 'R', 'I', 'S'},
};

using namespace std;


int main()
{
    //init the random engine
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);


    cout << "Bienvenu dans le jeu du boggle, dans ce jeu vous aurez une grille avec plusieurs lettres, votre but est de trouver des mots avec les mots à condition d'etre colle a ses derniers" <<endl;

    cout << "Lorsque vous cliquerez sur un bouton le jeu se lancera et vous aurez 3 minutes pour trouver le plus de mot possible" <<endl;
//continue to the game in function of OS
#ifdef __linux__
    system("read");
    system("clear");
#elif _WIN32
    system("pause");
    system("cls");

#endif
    //Show grid with random module
    for (int col = 0; col < 4; ++col) {

        for (int row = 0; row < 4; ++row) {

            cout << boggle[j][distr(eng)]<<' ';
            j++;
        }
        cout <<endl;
    }
    cout <<endl<<endl;

    //Start the game
    for(auto runUntil = chrono::system_clock::now() + chrono::seconds(180);
        chrono::system_clock::now() < runUntil;)
    {
        found = 0;
        ifstream dictionnary ("dico.txt");
        //Ask for a word
        cin >> tryWord;
        //Check if the word is higher than 3 letters
        while(tryWord.length() < 3)
        {
            cout << "les mots de moins de trois lettres sont interdits" <<endl<<endl;
            cin >> tryWord;
        }
            do{
                //if the word is in the dictionnary
                if(tryWord == line)
                {
                    switch(tryWord.length()) { //add score in function of the length of the word
                        case 3 :
                        score += 1;
                        case 4 :
                        score += 1;
                        break;
                        case 5:
                        score += 2;
                        case 6:
                        score += 3;
                        case 7:
                        score += 5;
                        case 8:
                        score += 11;
                        break;}

                    cout << "Le mot " << tryWord << " est correct!" <<endl;
                    cout << "Le score est de " << score << " points !" <<endl<<endl;
                    found = 1;
                }

            }
            while ( getline (dictionnary,line) );
            //if the word is not in the dictionnary
            if(found == 0)
            {

                cout << tryWord << " est un mot non valide" <<endl<<endl;
            }

            }

            cout << "jeu fini ! Vous avez " << score << " points !";
    return 0;
}

