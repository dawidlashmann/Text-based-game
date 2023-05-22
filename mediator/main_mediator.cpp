#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    const char *map, *status, *orders;
    float limitCzasowy = 5.0f;
    if (argc == 5)
    {
        const char *lim = argv[4];
        limitCzasowy = std::stof(lim);
    }
    else if (argc != 4)
    {
        std::cout << "Wrong input\nExiting...";
        return 1;
    }
    map = argv[1];
    status = argv[2];
    orders = argv[3];

    return 0;
}