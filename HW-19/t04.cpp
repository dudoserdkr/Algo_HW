#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

struct Item {
    std::string id;
    int priority;
    int time;

    bool operator<(const Item& other) const {
        if (priority != other.priority) return priority > other.priority;
        return time < other.time;
    }
};

class PriorityQueue {
public:
    void add(const std::string& id, int priority) {
        Item item{id, priority, timestamp++};
        elements.insert(item);
        index[id] = item;
    }

    void pop() {
        auto it = elements.begin();
        std::cout << it->id << " " << it->priority << "\n";
        index.erase(it->id);
        elements.erase(it);
    }

    void change(const std::string& id, int newPriority) {
        auto it = index.find(id);
        if (it != index.end()) {
            elements.erase(it->second);
            Item item{id, newPriority, timestamp++};
            elements.insert(item);
            index[id] = item;
        }
    }

private:
    std::set<Item> elements;
    std::unordered_map<std::string, Item> index;
    int timestamp = 0;
};

int main() {
    PriorityQueue queue;
    std::string command;
    while (std::cin >> command) {
        if (command == "ADD") {
            std::string id;
            int pr;
            std::cin >> id >> pr;
            queue.add(id, pr);
        } else if (command == "POP") {
            queue.pop();
        } else if (command == "CHANGE") {
            std::string id;
            int pr;
            std::cin >> id >> pr;
            queue.change(id, pr);
        }
    }
}