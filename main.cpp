// Task 4
// ќставить в слове только первое вхождение последней буквы.(Сabc ababaТ->Тabc abbТ)

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{
    const int size = 256;
    char s1[size];
    ifstream fin("input.txt");      // открыли файл
    fin.getline(s1, size);          // прочитали строку
    fin.close();                    // закрыли
    ofstream fout("output.txt");
    cout << "line: <"<< s1 << ">" << endl;
    fout << "line: <"<< s1 << ">" << endl;

    string s(s1);
    //cout << s << endl;
    /* ƒана строка, может заканчиватьс€ точкой.
    ћежду словами, в начале строки и перед точкой могут сто€ть
    Ђлишниеї пробелы (более одного пробела между словами, пробелы в начале строки, пробелы между последним словом и точкой или в конце строки).
    1.	”далить лишние пробелы.
        A.	(2) »спользу€ функции библиотеки string.h
    */
    while( s[0]==' ') s.erase(0, 1);   // удалим начальные пробелы

    // удалим конечные пробелы
    while( s.back()==' ' || s.back()=='\n' || s.back()=='\r' )
        s.pop_back();

    // удалим пары пробелов
    while(s.find("  ") != string::npos)
        s.erase(s.find("  "), 1);

    // удалим пробел перед точкой
    while(s.find(" .") != string::npos)
        s.erase(s.find(" ."), 1);

    cout << "Remove extra space:   " << s << endl;
    fout << "Remove extra space:   " << s << endl;

    int pos;
    // ”далим слова, совпадающие с последним
    // Ќайдем последнее слово
    pos = s.rfind(' ');             // позици€ последнего пробела
    string LastW = s.substr(pos+1); // последнее слово
    if( LastW.back()=='.') LastW.pop_back();
    pos = 0;
    while(pos < s.size() ) {
        int pos1 = s.find_first_of(" ", pos);
        if(pos1==(int)string::npos) break;      // больше нет пробелов
        if( LastW == s.substr(pos, pos1-pos)) { // если слово совпало с последним
            s.erase(pos, pos1-pos+1);
        } else {
            pos = pos1+1;
        }
    }
    cout << "Remove words, wich equal to the last word:   " << s << endl;
    fout << "Remove words, wich equal to the last word:   " << s << endl;

    // ќставить в слове только первое вхождение последней буквы.(Сabc ababaТ->Тabc abbТ)
    string s3;              // результат
    int sLen = s.size();
    pos = 0;
    while(pos<sLen) {
        int pos1 = s.find_first_of(" .", pos);
        if(pos1==(int)string::npos) break;      // больше нет пробелов
        // Ќайдено слово в строке в позици€х pos..pos1
        char ch = s[pos1-1];                   // последн€€ буква в слове
        if( s3.size()>0) s3.push_back(' ');     // ≈сли s3 непусто, допишем туда пробел
        while(pos<pos1) {
            if( s[pos] != ch) s3.push_back(s[pos]);
            pos ++;
        }
        // упихали все символы, отличные от последней буквы в слове.
        s3.push_back(ch);                       // » еЄ тоже упихаем
        //cout << "-->" << s3 << endl;
        pos = pos1+1;
    }

    cout << "Extra task: <" << s3<<">" << endl;
    fout << "Extra task: <" << s3<<">" << endl;

    fout.close();

    return 0;
}
