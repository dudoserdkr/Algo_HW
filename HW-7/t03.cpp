#include <iostream>
#include <cmath>

struct Node {
    long int element{};
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

        for (int i = 0; i < old_size; i++) {
            Node* current = old_arr[i];
            while (current) {
                this->add(current->element);
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
        for (int i=0; i < this->size; i++) {
            Node* current = this->arr[i];
            while (current) {
                Node *temp = current;
                current = current->next_word;
                delete temp;
            }
        }
        delete[] this->arr;
    }
    void add(long int n) {

        if (this->word_count * 0.7 >= this->size) {
            this->rehash();
        }

        long int hash = hashFunction(n);

        if (this->arr[hash] == nullptr) {
            this->arr[hash] = new Node{n, nullptr};
        }
        else {
            Node *current = this->arr[hash];
            while (current->next_word && current->element != n) {
                current = current->next_word;
            }
            if (current->element == n) {
                return;
            }
            current->next_word = new Node{n, nullptr};
        }
        this->word_count++;
    }

    void erase(long int n) {
        long int hash = this->hashFunction(n);
        Node *current_el = this->arr[hash];
        Node *previous_el = nullptr;

        if (!current_el) {
            std::cerr << "There is no word: " << n << std::endl;
        }
        if (current_el->element == n) {
            this->arr[hash] = current_el->next_word;
            delete current_el;
            this->word_count--;
            return;
        }
        while (current_el && (current_el->element != n)) {
            previous_el = current_el;
            current_el = current_el->next_word;
        }
        if (!current_el) {
            std::cerr << "There is no word: " << n << std::endl;
            return;
        }
        previous_el->next_word = current_el->next_word;
        delete current_el;
        this->word_count--;

    }

    bool contains(long int n) {
        long int hash = this->hashFunction(n);

        Node *element = arr[hash];
        while (element) {
            if (element->element == n) {
                return true;
            }
            element = element->next_word;
        }
        return false;
    }

    long int getElementCount() {
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

     inline long int hashFunction(const long int& n) const {
        return n % this->size;
    }
};


int main() {
    long int n;
    long int phone_number;

    std::cin >> n;
    HashSet hs(n);
    while (n--) {
        std::cin >> phone_number;
        hs.add(phone_number);
    }
    std::cout << hs.getElementCount();
}
