#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <string>

namespace tbontb
{
	using namespace std;

	struct Parameters
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
			clog << message;
		}

		void trace(const string& message)
		{
			clog << message;
		}
	}

	std::string GenerateRandomMember(unsigned int length)
	{
		auto member = string(length,' ');
		auto lambda = [=](){ return 'a';};
		std::generate_n(back_inserter(member), length, lambda);
		return member;
	}

	void go()
	{
		auto parameters = Parameters {100,.5,.5};

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
		//auto* iterator = back_inserter(population);
		/*
		std::generate_n(
				//iterator, 
				back_inserter(population),
				parameters.PopulationSize, 
				[=](){GenerateRandomMember(parameters.MemberLength);});
		*/


		do
		{

		}
		while(true);
	}
}


int main(int argc, char** argv)
{
	tbontb::go();
}
