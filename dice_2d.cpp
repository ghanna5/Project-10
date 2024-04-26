#include <iostream>
#include <ctime>
#include <array>
#include <iomanip>
#include <cmath>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int total = 600000;
    int random1;
    int random2;

    std::array<int, 6> array = {0,0,0,0,0,0};
    std::array<std::array<int, 6>, 6> actual = {array, array, array, array, array, array};

    while (total --> 0)
    {
        random1 = rand() %6 + 1;
        random2 = rand() %6 + 1;

        actual[random1 - 1][random2 - 1]++;
    }

    std::cout << "\n\t1              " 
              << "2              " 
              << "3              " 
              << "4              " 
              << "5              " 
              << "6              " << std::endl;

    for(int i = 0; i < 6; i++)
    {
        std::cout << i + 1 << std::setw(10);

        for(int j = 0; j < 6; j++)
        {
            std::cout << std::setw(10) << actual.at(i).at(j) << std::setw(5) << " ";
        }

        std::cout << std::endl;
   }

    std::cout << std::endl;

    return 0;
}