#include <iostream>
#include <fstream>
using namespace std;

void put(ifstream &f1,ofstream &f2){
    /*
     * данная функция перемещает данные из одного файла в другой
     */
    char*c;
    while(!f1.eof()){
        c = new char[256];
        f1.getline(c,256);
        f2 << c << endl;
        cout << c << " ";
    }
    delete[] c;
    cout << endl;
}
void task_4(char* c,char* c1){
    /*
     * перемещаем все строки первого файла в вспомогательный файл
     * потом перемещаем все строки второго файла в первый
     * потом - из вспомогательного во второй
     * Итог: мы поменяли данные двух файлов
     */
    ifstream f(c,ios::in);
    ofstream f2_("doesn'texist.txt");
    put(f,f2_);
    ifstream f1(c1,ios::in);
    ofstream f_(c);
    put(f1,f_);
    ifstream f2("doesn'texist.txt");
    ofstream f1_(c1);
    put(f2,f1_);

    /*
     * после все потоки считывания и передачи закрываем
     */
    f.close();
    f_.close();
    f1.close();
    f1_.close();
    f2.close();
    f2_.close();
}