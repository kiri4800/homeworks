#include <iostream>
#include <fstream>
#include <cstring>
#include "header.h"
using namespace std;
char* a[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
char b[10] = {'0','1','2','3','4','5','6','7','8','9'};
char* from_digits_to_char(char* c) {
    char* c1 = new char[256];//вспомогательнай строка для перемещения не цифр из старой строки в новую
    strcpy(c1,"");
    char* l = new char[256];
    l[1] = 0; // терминальный ноль
    /*
     * пробегаемся по всем символам
     */
    int n = strlen(c);
    for (int i = 0; i < n; ++i) {
        /*
         * если встретили цифру, то ищем её пару и добавляем эту пару в новую строку
         */
        if (bool(isdigit(c[i]))) {
            for (int j = 0; j < 10; ++j) {
                if (b[j] == c[i]) {
                    strcat(c1,a[j]);
                    break;
                }
            }
        }
        /*
         * иначе просто добавляем исходный символ в новую строку.
         */
        else {
            l[0] = c[i];
            strcat(c1,l);
        }
    }
    //очищаем кэш и возвращаем обработанную строку.
    delete[] l;
    return c1;
}
void task_5(char* c){
    /*
     * подключаемся к исходному файлу
     * считываем строки, пока можем, заменяем в них цифры на их название
     * измененные строки кладем в вспомогательный файл
     *
     */
    ofstream f("result.txt",ios::out);
    ifstream f1(c,ios::in);
    char* c1;
    char* c2;
    if(!f1){
        cout << "there's no file with name " << c << endl;
        return;
    }
    while(!f1.eof()){
        c1 = new char[256];
        f1.getline(c1,256);
        c2 = from_digits_to_char(c1);
        f << c2 << endl;
    }
    /*
     * после , используя решение 4 задачи, меняем данные файлов местами
     * закрываем потоки считывания и записи и очищаем кэш.
     */
    f.close();
    f1.close();
    task_4(c,"result.txt");
    ofstream f4("result.txt",ios::out);
    f4.close();
    delete[] c1;
    delete[] c2;
}