#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

void reverseWord(const string& word) {
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    cout << "Слово задом наперед: " << reversedWord << endl;
}

void removeVowels(const string& word) {
    string result = word;
    result.erase(remove_if(result.begin(), result.end(), [](char c) {
        return tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u';
        }), result.end());
    cout << "Слово без гласных: " << result << endl;
}

void removeConsonants(const string& word) {
    string result = word;
    result.erase(remove_if(result.begin(), result.end(), [](char c) {
        return isalpha(c) && tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && tolower(c) != 'o' && tolower(c) != 'u';
        }), result.end());
    cout << "Слово без согласных: " << result << endl;
}

void shuffleLetters(const string& word) {
    string shuffledWord = word;
    mt19937 gen(static_cast<unsigned>(time(0)));
    shuffle(shuffledWord.begin(), shuffledWord.end(), gen);
    cout << "Рандомно раскиданные буквы: " << shuffledWord << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    string word;
    int choice;

    cout << "Введите слово: ";
    cin >> word;

    cout << "Выберите действие:" << endl;
    cout << "1. Слово выводится задом наперед" << endl;
    cout << "2. Вывести слово без гласных" << endl;
    cout << "3. Вывести слово без согласных" << endl;
    cout << "4. Рандомно раскидывать буквы заданного слова" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        reverseWord(word);
        break;
    case 2:
        removeVowels(word);
        break;
    case 3:
        removeConsonants(word);
        break;
    case 4:
        shuffleLetters(word);
        break;
    default:
        cout << "Неверный выбор" << endl;
        break;
    }

    return 0;
}
