#include <iostream>
#include "LiteSH.hpp"

int main(int argc, char **argv) {
    string arg="";
    int pid,ppid,rez;
    if (argc>1)
        arg=(string)argv[1];

    /*if (RecvSignal(SIGINT) == 1) {
        cout << "Ошибка получения сигнала" << endl;
    }
    sleep(60);*/

    if ((arg=="--FileManager") || (arg=="-fm")) {
        filemanager("../lab2/main");
    } else if ((arg=="--CreateProcess") || (arg=="-cp")) {
        if (argc != 3) {
            cout << "Неверное количество аргументов" << endl;
            return 0;
        }
        if ((rez=createprocess(argv[2],&pid,&ppid)) == 0){
            cout << "Процесс не создан1" << endl;
        } else if(rez==1) {
            cout << "pid = " << pid << endl << "ppid = " << ppid << endl;
        }

    } else if ((arg=="--CreateBackProcess") || (arg=="-cbp")) {
        if (argc != 3) {
            cout << "Неверное количество аргументов" << endl;
            return 0;
        }
        if ((rez=createbackprocess(argv[2],&pid,&ppid)) == 0) {
            cout << "Фоновый процесс не создан";
        } else if(rez==1) {
            cout << "pid = " << pid << endl << "ppid = " << ppid << endl;
        }
    } else if ((arg=="--ReciveSignal") || (arg=="-rs")) {
        if (argc != 2) {
            cout << "Неверное количество аргументов" << endl;
            return 0;
        }
        if (!recivesignal()) {
            cout << "Сигнал не получен" << endl;
        }
    } else {
        cout << "Авторы: Сидоров Андрей, Скребнев Антон" << endl
             << "--FileManager || -fc - Вызов программы для работы с файловой системой" << endl
             << "--CreateProcess || -cp - Порождение процесса " << endl
             << "--CreateBackProcess || -cbp - Перевод процесса в фоновый режим" << endl
             << "--ReciveSignal || -rs - Получение сигнала от процесса";
    }

}
