#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

typedef struct Parameters
{
    unsigned int PopulationSize;
    float MutationRate;
    float CrossoverRate;
    unsigned int MemberLength;
};

// couldnt keep things simple
// wanted to have levels and timestamps
namespace log
{
    void info(const string& message)
    {
        std::clog << message;
    }
    
    void trace(const string& message)
    {
        std::clog << message;
    }
}

string GenerateRandomMember(unsigned int length)
{
    auto member = string(length);
    auto lambda = [](){ return 'a';};
    std::generator(member, length, lambda);
    return member;
}

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
    
    log::info("initializing population");
    
    // i was going to use a for-loop
    // but why when i have the stl
    auto* iterator = back_inserter(population);
    std::generate(iterator, parameters.PopulationSize, [=](){GenerateRandomMember(parameters.MemberLength);});
     
    do
    {
        
    }
    while(true);
}
