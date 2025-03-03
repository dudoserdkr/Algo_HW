#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <cmath>

struct Node {
    std::string word{};
    Node *next_word = nullptr;
};

class HashSet {
    long int size{};
    Node **arr = nullptr;
    long int word_count = 0;

    void rehash() {
        long int old_size = this->size;
        Node **old_arr = this->arr;

        int new_size = this->nextPrime(2 * this->size + 1);

        this->arr = new Node*[new_size]();
        this->size = new_size;
        this->word_count = 0;

        for (int i = 0; i < old_size; i++) {
            Node* current = old_arr[i];
            while (current) {
                this->add(current->word);
                Node* temp = current;
                current = current->next_word;
                delete temp;
            }
        }
        delete[] old_arr;
    }

public:
    HashSet(long int size) {
        this->size = this->nextPrime(size);
        this->arr = new Node*[this->size]();
    }

    ~HashSet() {
        for (int i = 0; i < this->size; i++) {
            Node* current = this->arr[i];
            while (current) {
                Node *temp = current;
                current = current->next_word;
                delete temp;
            }
        }
        delete[] this->arr;
    }

    void add(std::string word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (this->word_count * 0.7 >= this->size) {
            this->rehash();
        }

        long int hash = hashFunction(word);

        if (this->arr[hash] == nullptr) {
            this->arr[hash] = new Node{word, nullptr};
        }
        else {
            Node *current = this->arr[hash];
            while (current->next_word && current->word != word) {
                current = current->next_word;
            }
            if (current->word == word) {
                return;
            }
            current->next_word = new Node{word, nullptr};
        }
        this->word_count++;
    }

    void erase(std::string word) {
        long int hash = this->hashFunction(word);
        Node *current_word = this->arr[hash];
        Node *previous_word = nullptr;

        if (!current_word) {
            std::cerr << "There is no word: '" << word << "'" << std::endl;
            return;
        }
        if (current_word->word == word) {
            this->arr[hash] = current_word->next_word;
            delete current_word;
            this->word_count--;
            return;
        }
        while (current_word && (current_word->word != word)) {
            previous_word = current_word;
            current_word = current_word->next_word;
        }
        if (!current_word) {
            std::cerr << "There is no word: '" << word << "'" << std::endl;
            return;
        }
        previous_word->next_word = current_word->next_word;
        delete current_word;
        this->word_count--;
    }

    bool contains(std::string word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        long int hash = this->hashFunction(word);

        Node *element = arr[hash];
        while (element) {
            if (element->word == word) {
                return true;
            }
            element = element->next_word;
        }
        return false;
    }

    long int getWordCount() {
        return this->word_count;
    }

    long int nextPrime(long int n) {
        while (!isPrime(n)) {
            if (n % 2 == 0) {
                n++;
                continue;
            }
            n += 2;
        }
        return n;
    }

    static long int isPrime(const long int& n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2 or n == 3 or n == 5) {
            return true;
        }
        if (n % 2 == 0 or n % 3 == 0 or n % 5 == 0) {
            return false;
        }
        else {
            for (long int i = 7; i <= static_cast<long int>(std::sqrt(n)) + 1; i += 2) {
                if (n % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }

     long int hashFunction(std::string &word) const {
        unsigned int long h = 0;
        for (size_t i = 0; i < word.length(); i++) {
            h = h * 31 + static_cast<int>(word[i]);
        }
        return h % this->size;
    }
};

int main() {
    int N, M;
    std::cin >> N >> M;

        HashSet dictionary(N);
    std::string word;
    for (int i = 0; i < N; i++) {
        std::cin >> word;
        dictionary.add(word);
    }
    std::cin.ignore();

    HashSet usedWords(100);

    bool unknownFound = false;

    for (int i = 0; i < M; i++) {
        std::string sentence;
        std::getline(std::cin, sentence);
        std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
        std::regex word_regex("([a-z]+)");
        std::sregex_iterator words_begin(sentence.begin(), sentence.end(), word_regex);
        std::sregex_iterator words_end;

        for (auto it = words_begin; it != words_end; ++it) {
            std::string txt_word = it->str();
            if (!dictionary.contains(txt_word)) {
                unknownFound = true;
            } else {
                usedWords.add(txt_word);
            }
        }
    }

    if (unknownFound) {
        std::cout << "Some words from the text are unknown." << std::endl;
    } else if (usedWords.getWordCount() < dictionary.getWordCount()) {
        std::cout << "The usage of the vocabulary is not perfect." << std::endl;
    } else {
        std::cout << "Everything is going to be OK." << std::endl;
    }
}