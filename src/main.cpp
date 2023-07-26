#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    if ( argc != 2 )
    {
        std::cout << "Usage: ./executable <number>\n";
        return 1;
    }

    int number = std::atoi(argv[1]);
    std::string file_path = "src/problems/euler" + std::to_string(number) + ".cpp";
    std::string command = "g++ -std=c++17 -O3 -march=native -o executable " + file_path;

    int result = std::system(command.c_str());

    if ( result == 0 )
    {
        std::cout << "Running Euler problem " << number << "...\n";
        std::system("./executable");
    }
    else
    {
        std::cout << "Error: Failed to compile " << file_path << "\n";
    }

    return 0;
}
