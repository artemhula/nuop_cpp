#include <iostream>

class Tree {
private:
    float height;
    float diameter;
    const bool isEverGreen;
    bool leafPresence;
    bool healthy;

public:
    Tree() : height(0.0), diameter(0.0), isEverGreen(false), leafPresence(false), healthy(true) {}

    Tree(float h, float d, bool ieg, bool l, bool hl) : height(h), diameter(d), isEverGreen(ieg), leafPresence(l),
                                                        healthy(hl) {}

    Tree(const Tree &other) : height(other.height), diameter(other.diameter), isEverGreen(other.isEverGreen),
                              leafPresence(other.leafPresence), healthy(other.healthy) {}

    ~Tree() {
        std::cout << "Tree removed" << std::endl;
    }

    void grow(float heightIncrease, float diameterIncrease) {
        height += heightIncrease;
        diameter += diameterIncrease;
    }

    void generateOxygen() {
        std::cout << "Tree is generating oxygen." << std::endl;
    }

    void shedLeaves() {
        if (isEverGreen) {
            std::cout << "Can`t shed leaves." << std::endl;
        } else {
            leafPresence = false;
            std::cout << "Leaves shed." << std::endl;
        }
    }

    void growLeaves() {
        if (isEverGreen) {
            std::cout << "Can`t grow leaves." << std::endl;
        } else {
            leafPresence = true;
            std::cout << "Leaves grown." << std::endl;
        }

    }

    void markHealthy() {
        healthy = true;
        std::cout << "Tree marked as healthy." << std::endl;
    }

    void markSick() {
        healthy = false;
        std::cout << "Tree marked as sick." << std::endl;
    }

    void print() {
        std::cout << "Height: " << height << " meters" << std::endl;
        std::cout << "Diameter: " << diameter << " meters" << std::endl;
        std::cout << "Is evergreen: " << (isEverGreen ? "Yes" : "No") << std::endl;

        std::cout << "Leaf Presence: " << (leafPresence ? "Yes" : "No") << std::endl;
        std::cout << "Healthy: " << (healthy ? "Yes" : "No") << std::endl;
    }
};

int main() {
    Tree tree1(5.0, 0.3, false, true, true);

    Tree tree2(tree1);

    tree1.print();
    tree1.generateOxygen();
    tree1.grow(10, 0.1);
    tree1.shedLeaves();
    tree1.print();

    tree2.markSick();
    tree2.shedLeaves();
    tree2.growLeaves();
    tree2.print();

    return 0;
}
