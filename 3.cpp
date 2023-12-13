#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
char digits[10]={'0','1','2','3','4','5','6','7','8','9'};
void get_to_last(int& first, int& second,char* c){
    int n = strlen(c);
    int current = n - 1;
    int pow1 = 1;
    first = 0;
    second = 0;
    while(c[current] != ' '){
        for(int i = 0;i < 10;++i){
            if(c[current] == digits[i]){
                second += i * pow1;
                pow1 *= 10;
                break;
            }
        }
        current --;
    }
    current -- ;
    pow1 = 1;
    while(c[current] != ' ' && current >= 0){
        for(int i = 0;i < 10;++i){
            if(c[current] == digits[i]){
                first += i * pow1;
                pow1 *= 10;
                break;
            }
        }
        current --;
    }
}
void put_n_fibbonachi(int first,int second, int count_of, char* c){
    ofstream f(c,ios::ate|ios::app);
    if(!f){
        cout << "ERROR:file not open" << endl;
        return;
    }
    for(int i = 0;i < count_of;++i){
        int current = first + second;
        f << " " << current;
        first = second;
        second = current;
    }
    f.close();
}
void task_3(char* path, int n){
    ifstream f(path);
    if(!f){
        cout << "ERROR:file not open" << endl;
        return;
    }
    char* c = new char[256];
    while(!f.eof()){
        f.getline(c,256);
    }
    int first,second;
    first = second = 0;
    get_to_last(first,second,c);
    put_n_fibbonachi(first,second,n,path);
    f.close();
}