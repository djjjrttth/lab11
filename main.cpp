#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> buffer;

void read(std::string filename){
    std::string s;

    std::ifstream in;
    in.open(filename);

    while (std::getline(in, s)){
        buffer.push_back(s);
    }

    in.close();
}

void print(std::string filename){
    std::ofstream out;
    out.open(filename);

    auto it = buffer.begin();
    while (it != buffer.end()){
        out << *it << " ";
        it++;
    }
    out.close();

}

int main(){

    std::string filename_in = "file.txt";
    read(filename_in);
    std::string filename_out = "file1.txt";
    print(filename_out);
    return 0;
}