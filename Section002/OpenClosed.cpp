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

struct Product {
    std::string name;
    Color color;
    Size size;
};

int main()
{
    return 0;
}