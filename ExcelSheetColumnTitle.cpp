#include <string>
#include <iostream>

std::string convertToTitle(int columnNumber) {
    std::string reversed_result{};

    while (columnNumber != 0) {
        columnNumber--;
        reversed_result += static_cast<char>((columnNumber % 26) + 'A');
        columnNumber /= 26;
    }

    std::string result{reversed_result.rbegin(), reversed_result.rend()};
    return result;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./a.out [number] \n";
    } else {
        std::cout << convertToTitle(atoi(argv[1])) << std::endl;
    }

    return 0;
}