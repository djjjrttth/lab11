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
        throw std::out_of_range("Ошибка: выход за пределы буфера");
    }
    else *it = new_str;
    
}

//добавление строки по индексу
void add(int position, std::string new_str){
    auto it = buffer.begin() + position-1;
    if (!(buffer.begin() <= it && it <= buffer.end())){
        throw std::out_of_range("Ошибка: выход за пределы буфера");
    }
    else
        buffer.insert(it, new_str);

}

void remove(int position){
    auto it = buffer.begin() + position - 1;
    if (!(buffer.begin() <= it && it <= buffer.end())){
        throw std::out_of_range("Ошибка: выход за пределы буфера");
    }
    else
        buffer.erase(it);
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
    int choice;
    
        try{
            while (choice != 7){
            std::cout << "\n===Текстовый редактор===\n";
            std::cout << "1. Открыть файл\n";
            std::cout << "2. Сохранить в файл\n";
            std::cout << "3. Изменить строку\n";
            std::cout << "4. Добавить строку\n";
            std::cout << "5. Вывести на экран\n";
            std::cout << "6. Удалить строку\n";
            std::cout << "7. Выйти\n";
            std::cout << "Выберите вариант работы: ";
            std::cin >> choice;
            if (choice == 1){
                std::string filename;
                std::cout << "Введите имя файла: ";
                std::cin >> filename;
                read(filename);
            }
            else if (choice == 2){
                std::string filename;
                std::cout << "Введите имя файла: ";
                std::cin >> filename;
                save(filename);
            }
            else if(choice == 3){
                int pos;
                std::string new_string;
                std::cout << "Введите позицию для изменения: ";
                std::cin >> pos;
                std::cout << "Введите новую строку: ";
                std::cin >> new_string;
                change(pos, new_string);
            }
            else if (choice == 4){
                int pos;
                std::string new_string;
                std::cout << "Введите позицию для добавления: ";
                std::cin >> pos;
                std::cout << "Введите новую строку: ";
                std::cin >> new_string;
                add(pos, new_string);
            }
            else if(choice == 5){
                show();
            }
            else if (choice == 6){
                int pos;
                std::cout << "Введите позицию для удаления: ";
                std::cin >> pos;
                remove(pos);
            }
            else if(choice == 7){
                exit(0);
            }
        }
        }
        catch(std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    
    return 0;
}