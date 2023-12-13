#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool sub_in_string(char* sub,char* string){
    int n = strlen(string);
    int m = strlen(sub);
    /*
     * получаем в переменные n,m  длины строки и подстроки.
     * Если длина строки меньше, то в ней точно нету подстроки,
     * потому возвращаем false
     *
     * Если длина строки равна длине подстроки, то возвращаем
     * да , если строки равна, иначе - нет.
     */
    if(n < m) return false;
    if(n == m) strcmp(sub,string) == 0;

    /*
     * если длина строки больше длины подстроки ,то проверяем все подстроки строки
     * на равенство с данной подстрокой
     * Если есть подстрока, равная данной, то возвращаем true и заканчиваем т.к. больше искать смысла нет
     *
     * Если ни одну такуб подстроку не нашли, то возвращаем false
     */
    for(int i = 0;i <= n - m;++i){
        if(string[i] == sub[0]){
            bool b = true;
            for(int j = i + 1;j < i + m;j++){
                if(string[j] != sub[j - i]){
                    i = j;
                    b = false;
                    break;
                }
            }
            if(b){
                return true;
            }
        }
    }
    return false;
}
void task_2(char* c,char* sub){
    //подключаемся к файлу.
    ifstream f(c);
    if(!f){
        cout << "error:file hasn't been openned";
        return;
    }
    bool flag = false;
    char* c1;
    /*
     * пока файл на закончится, считываем строки и проверяем их на наличие данной подстроки
     *
     */
    while(!f.eof()){
        c1 = new char[256];
        f.getline(c1,256);
        if(sub_in_string(sub,c1)) {
            cout << c1 << endl;
            flag = true;
        }
    }
    //закрываем поток считывания, очищаем кэш
    f.close();
    delete[] c1;
    //если ни одной строки не было найдено, то пишем, что их нет.
    if(!flag){
        cout << "There're no strings in file with substring " << sub << endl;
    }
}