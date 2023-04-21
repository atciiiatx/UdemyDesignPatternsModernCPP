#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum class Color
{
    red,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large,
    xlarge,
    xxlarge,
    xxxxlarge
};

struct Product
{
    std::string name;
    Color color;
    Size size;

    Product(std::string nameIn, Color colorIn, Size sizeIn)
    {
        this->name = nameIn;
        this->color = colorIn;
        this->size = sizeIn;
    }
};

struct ProductFilter
{
    std::vector<Product *> byColor(std::vector<Product *> items, Color color)
    {
        std::vector<Product *> result;
        for (auto &item : items)
        {
            if (item->color == color)
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

int main()
{
    std::cout << "OpenClosed" << std::endl;

    Product apple{"Apple", Color::red, Size::small};
    Product frog{"Frog", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::xxlarge};

    std::vector<Product *> items = {&apple, &frog, &tree, &house};
    ProductFilter pf;
    const auto greenThings = pf.byColor(items, Color::green);
    for (const auto &item : greenThings)
    {
        std::cout << item->name << " is green" << std::endl;
    }

    return 0;
}