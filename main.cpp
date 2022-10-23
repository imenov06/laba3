#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;


int main() {
    string path = "/home/ganstar816/CLionProjects/laba3/hello.txt";
    string text;
    string first = "hello";
    string second = "world";


    ifstream fin;
    fin.open(path);

    if (!fin.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    } else {
        cout << "Файл открыт" << endl;
        string str;
        while (!fin.eof()) {
            str = "";
            getline(fin, str);
            text += str + " ";

        }
    }

    list<string> arr;

    string a;

    for (char ch: text) {
        if (ch != ' ' && ch != '.') {
            a += ch;

        } else if (ch == ' ') {
            arr.push_back(a);
            a = "";
        } else {
            arr.push_back(a);
            a = "";
            arr.push_back(".");
        }
    }

    string ans = "";
    string strArr[arr.size()];
//    for (string elem: arr) {
//        cout<<elem<<" ";
//    }

    int i = 0;
    for (string elem: arr) {

        strArr[i] = elem;
        i++;

    }

    for (int j = 0; j < arr.size(); j++) {
        if (strArr[j] == first) {
            strArr[j] = second;
            break;
        }
    }
    for (int j = arr.size(); j > 0; --j) {
        if (strArr[j] == second) {
            strArr[j] = first;
            break;
        }
    }
    for (int j = 0; j < arr.size(); ++j) {
        if (!(strArr[j] == "")) {
            cout << strArr[j] <<" ";
        }
    }


    fin.close();
    return 0;
}