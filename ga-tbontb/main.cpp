#include <iostream>

typedef struct Parameters
{
    unsigned int PopulationSize;
    float MutationRate;
    float CrossoverRate;
};



int main(int argc, char** argv)
{
    auto parameters = {100,.5,.5};
    
    // this was initially a char[][]
    // then a string[] once inswitched
    //     to c++ becuase i amm not a complete savage
    // then a std::vector as a got my groove going
    // then a std::list since im going to be doing 
    //    a lot of manipulation
    // but in the end inwant tonmove back to 
    //    something constant without continued 
    //    allocation
    std::list<string> population;
    
    for( auto x = 0; x < parameters.PopulationSize; x++ )
    {
        auto member = "";
        list.emplace(member);
    }
    
    do
    {
        
    }
    while(true);
}
