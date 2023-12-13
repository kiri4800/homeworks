#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char* true_sym = " .,!?:;";
//функция для проверки, являтся ли данный символ символом - разделителем
bool eq(char c){
    int n = 7;
    for(int i = 0; i < n;++i){
        if(true_sym[i] == c)return true;
    }
    return false;
}
int count_4_chars(char* c){
    int count = 0;
    int n = strlen(c);
    for(int i = 0;i < n;++i){ // пробегаемся по всем символам строки
        /*
         * если символ не является разделителем, то считаем его началом нового слова.
         * используя while, шагаем через строки после данной и добавляем их, если они не разделители
         * и пока у нас есть символы,иначе процесс прерываем.
         */
        if(!eq(c[i])){
            int current = i;
            bool is_alright = true;
            while(!eq(c[current]) && current < n){
                if(!isalpha(c[current])){
                    if(eq(c[current])){
                        break;
                    }
                    else{
                        is_alright = false;
                    };
                }
                current++;
            }
            /*
             * после операции описанной выше получаем набор символов
             * если набор является словом(состоит ТОЛЬКО из букв) и размером <= 4,то счетчик увеличиваем на 1
             */
            if(0 < current - i <= 4 && is_alright) {
                count++;
                for(int j = i;j < current;j++){
                    cout << c[j];
                }
                cout << endl;
            }
            i = current;
        }
    }
    //очищаем кэш и возвращаем полученное количество
    delete[] c;
    return count;
}

int task_1(char* c){
    ifstream f(c);
    if(!f){ // если не открылся, то завершаем
        cout << "sorry, file hasn't been openned" << endl;
        return 0;
    }
    char* c1 = new char[256]; //переменная для считывания строк файла
    int current = 0;
    /*
     * пока файл не закончился,считываем строку и проверяем кол-во слов с кол-вом букв <= 4
     */
    while(!f.eof()){
        f.getline(c1,256);
        current += count_4_chars(c1);
    }
    f.close(); // закрываем файл
    //очищаем кэш
    delete[] c1;
    delete[] c;
    return current;
}