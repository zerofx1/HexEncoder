#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

void greeting() {
    std::cout << "Привет! Это кодирование/декодирование текста в Hex.\n\n";
    std::cout << "Выбери то, что тебе надо:" << std::endl;
    std::cout << "1. Кодирование" << std::endl;
    std::cout << "2. Декодирование" << std::endl;
}

std::string textToHex(const std::string& text) {
    std::stringstream hexStream;

    for (unsigned char c : text) {
        hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }

    return hexStream.str();
}

std::string hexToText(const std::string& hex) {
    std::string text;

    if (hex.length() % 2 != 0) throw std::invalid_argument("ERROR: длина должна быть четной");

    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);

        char c = static_cast<char>(std::stoi(byteString, nullptr, 16));
        text += c;
    }

    return text;
}

std::string textToHexFormatted(const std::string& text) {
    std::stringstream hexStream;

    for (size_t i = 0; i < text.length(); i++) {
        hexStream << std::hex << std::setw(2) << std::setfill('0')
            << static_cast<int>(static_cast<unsigned char>(text[i]));
        if (i < text.length() - 1) {
            hexStream << " ";
        }
    }

    return hexStream.str();
}

int main() {
    setlocale(LC_ALL, "Russian");

    greeting();

    int choice;
    std::cin >> choice;
    std::cin.ignore(); 

    if (choice == 1) {
        std::string text;
        std::cout << "Напиши текст: ";
        std::getline(std::cin, text);

        std::cout << "HEX результат: " << textToHex(text) << std::endl;
    }
    else if (choice == 2) {
        std::string hex;
        std::cout << "Напиши HEX строку: ";
        std::cin >> hex;

        try {
            std::string textResult = hexToText(hex);
            std::cout << "Текст результат: " << textResult << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

    }
    else {
        std::cout << "Я тебя не понимать" << std::endl;
    }

    system("pause");

    return 0;
}