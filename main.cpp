#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Game {
private:
    int num;
    string name, yes, key;
    int digits, addthis, result;
public:
    int comp_num1 , comp_num2 ;

    Game(string _name) {
        name = _name;
    }
    void start() {
        cout << "--ENTER ANY NUMBER : " << endl;
        cin >> num;
        system("color 0D");
        string number = to_string(num);

        for (digits = 0; number[digits] != '\0'; digits++);

        char add[100];

        for (int j = 0; j <= digits; j++) {
            if (j == 0) {
                add[j] = '1';
            }
            else if (j == digits) {
                add[j] = '8';
            }
            else
                add[j] = '9';
        }

        addthis = atoi(add);

        result = num + addthis;

        key = to_string(result);

        cout << endl << "--ARE YOU READY TO REVEAL THE KEY-- " << endl;
        cin >> yes;
        system("color 0E");
        cout << "\n " << name << " YOUR KEY IS :" << endl;
        cout << "    KEY  :  ";

        for (int k = digits; k >= 0; k--) {
            cout << key[k];
        }
        cout << endl;
    }
    void play() {
        int num1, num2;
        system("color 0A");
        cout << endl << "--ENTER ANY  NUMBER WITH THE SAME DIGITS AGAIN -- \nYOU  : ";
        cin >> num1;

        findnum(&digits);

        comp_num1 = COMPUTER(num1, &digits,comp_num1);
        cout << "COMPUTER : " << comp_num1;
        system("color 0B");

        cout << endl << "--ENTER AGAIN: ANY NUMBER WITH THE SAME NO. OF DIGITS  -- \nYOU  : ";
        cin >> num2;

        comp_num2 = COMPUTER(num2, &digits,comp_num2);
        cout << "COMPUTER : " << comp_num2;
        system("color 0C");

        cout << endl << "\n\t--ADD ALL THE NUMBERS--\n----THE ANSWER WILL BE THE REVERSE OF THE KEY -----\n";
        cout << endl <<num<<"\n"<<num1<<"\n"<<comp_num1<<"\n"<<num2<<"\n"<<comp_num2;
        cout << endl << "____________";
    }
    void findnum(int* num) {
        char full[15];
        for (int j = 0; j < *num; j++)
        {
            full[j] = '9';
        }

        int tothis = atoi(full);
        *num = tothis;
    }
    int COMPUTER(int num, int* ptr, int comp_numx) {
        int res = 0;
        for (int z = 0; z <= *ptr; z++) {
            res = 0;
            res = num + z;
            if ((num + z) == *ptr) {
                comp_numx = z;
                break;
            }
        }
        return comp_numx;
    }
};

int main() {
    char runagain;
    do {
        string name;
        cout << "--ENTER YOUR NAME TO START THE GAME-- " << endl;
        cin >> name;

        Game game(name);
        game.start();
        game.play();

        cout<< endl << "--DO YOU WANT TO PLAY AGAIN--(y/n)" << endl;
        cin >> runagain;
        if(runagain == 'y' || runagain == 'Y')
        { system("cls"); }
        else
        {
            system("cls");
            cout<< endl << "--GAME TERMINATED--\n--THANK YOU FOR PLAYING--" << endl;
        }
    }while(runagain == 'y' || runagain == 'Y');
    return 0;
}