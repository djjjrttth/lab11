#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// список строк
std::vector<std::string> buffer;

// считывание в список 
void read(std::string filename){
    std::string s;

    std::ifstream in;
    in.open(filename);

    while (in >> s){
        buffer.push_back(s);
    }

    in.close();
}


// сохранение в файл
void save(std::string filename){
    std::ofstream out;
    out.open(filename);

    auto it = buffer.begin();
    while (it != buffer.end()){
        out << *it << " ";
        it++;
    }
    out.close();

}
// Изменение файла по индексу
void change(int position, std::string new_str){

    
    auto it = buffer.begin() + position - 1;
    if (!(buffer.begin() <= it && it <= buffer.end())){
        throw "Ошибка: выход за пределы буфера";
    }
    else *it = new_str;
    
}

//добавление строки по индексу
void add(int position, std::string new_str){
    auto it = buffer.begin() + position;
    buffer.insert(it, new_str);

}
// Вывод на экран
// Символ `` используется для того, чтобы видеть какие слова хранятся как один элемент в списке
void show(){
    for (auto it = buffer.begin(); it != buffer.end(); it++){
        std::cout << '`'<< *it << "` ";
    }
    std::cout << std::endl;
}


int main(){

    std::string filename_in = "input.txt";
    read(filename_in);
    std::string filename_out = "output.txt";
    save(filename_out);


    show();
    std::cout << std::endl;
    add(0, "qwe");
    
    show();
    change(3, "World qwe");
    show();
    filename_out = "output2.txt";
    save(filename_out);

    return 0;
}