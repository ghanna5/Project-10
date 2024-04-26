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
    double result;

    std::array<int, 13> actual = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::array<double, 13> expected = {0,0,2.778,5.556,8.333,11.111,13.889,16.667,
                                       13.889,11.111,8.333,5.556,2.778};

    while (total --> 0)
    {
        random1 = rand() %6 + 1;
        random2 = rand() %6 + 1;

        actual[random1 + random2]++;
    }

    std::cout << "\nSum        " << 
                 "Total        " <<
                 "Expected      " << 
                 "Actual       " << std::endl;
    
    for (int i = 2; i <= 12; i++)
    {
        result = ((double)actual.at(i) / (double)600000) * 100;

        result = round(result * 1000.0 ) / 1000.0;

        std::cout << std::setw(2) << i << std::setw(14) << actual.at(i) << std::setw(14) << 
        expected.at(i)<< "%" << std::setw(12) << result << "%" << std::endl;
    }

    std::cout << std::endl;

    return 0;
}