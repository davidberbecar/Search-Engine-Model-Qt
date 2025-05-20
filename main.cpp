#include<iostream>
#include<QApplication>

#include "gui.h"
using namespace std;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    Service service;
    gui w{nullptr,service};
    w.show();
    return a.exec();
}