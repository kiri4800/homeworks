#include<iostream>
#include "header.h"
#include <fstream>
#include <cstring>
#include "windows.h"
using namespace std;
signed main(){
    /*
     * первые строки реализуют красивую работу алгоритма.
     *
     */
    cout << "list of requests:" << endl;
    cout << "1 - how many words, which length <= 4" << endl;
    cout << "2 - print all strings, that has this string as substring , else -1" << endl;
    cout << "3 - continue Fibonachi's sequence" << endl;
    cout << "4 - swap content of two files" << endl;
    cout << "5 - change all digits to their names" << endl;
    cout << "0 - stop programm" << endl;
    int request = -1;
    char* c;
    char* c1;
    /*
     * разберем каждый запрос
     */
    while(request != 0){
        cin >> request;
        switch(request){
            case 1:
                cout << "print filename(it must be in the project)" << endl;
                c = new char[256]; // переменная, в которой будет лежать путь к файлу
                cin.ignore(); // используется, чтобы после cin использовать cin.getline
                cin.getline(c,256); // считывание пути файла
                cout << task_1(c) << endl; //вывод результата работы
                cout << "Done" << endl;
                delete[] c; // очищение кэша
                break;
            case 2:
                cin.ignore(); //см. строку 32
                cout << "print filename(it must be in the project)" << endl;
                c = new char[256]; // переменная, которая хранит в себе путь к файлу
                c1 = new char[256]; // переменная , которая хранит в себе подстроку, которую мы будем искать
                cin.getline(c,256);
                cout << "print string" << endl;
                cin.getline(c1,256);
                task_2(c,c1);
                delete[] c; //очищение кэша
                delete[] c1;
                cout << "Done" << endl;
                break;
            case 3:
                cout << "print filename" << endl;
                cin.ignore();
                c = new char[256];
                cin.getline(c,256);
                cout << "print, how many need to add" << endl;
                int kol;
                cin >> kol;
                task_3(c,kol);
                cout << "Done" << endl;
                break;
            case 4:
                cout << "print filenames of 2 files" << endl;
                c = new char[256]; //переменная, которая хранит в себе путь к первому файлу
                c1 = new char[256]; // переменная,котороая хранит в себе путь ко второму файлу
                cin.ignore(); // см. строку 32
                cin.getline(c,256);
                cin.getline(c1,256);
                task_4(c,c1);
                delete[]c; //очищение кэша
                delete[] c1;
                cout << "Done" << endl;
                break;
            case 5:
                cout << "print filename" << endl;
                c = new char[256]; //переменная, которая хранит в себе путь к файлу
                cin.ignore();
                cin.getline(c,256);
                task_5(c);
                cout << "Done" << endl;
                break;
            case 0: // код для остановки через две секунды
                cout << "Stopping programm..." << endl;
                Sleep(2000);
                return 0;
            default:
                cout << "Wrong request" << endl;
        }
    }
    delete[] c;
    delete[] c1;
}