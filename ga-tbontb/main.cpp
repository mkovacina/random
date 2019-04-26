#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <random>
#include <chrono>

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
			clog << message << endl;
		}

		void trace(const string& message)
		{
			clog << message << endl;
		}

		void debug(const string& message)
		{
			clog << message << endl;
		}
	}

	std::string GenerateRandomMember(unsigned int length)
	{
		// https://stackoverflow.com/questions/21842849/how-to-generate-a-random-string-in-c
		// C++ inspiration from the above
		const std::string VALID_CHARS = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		// i want to move this to being state
		// http://www.cplusplus.com/reference/random/linear_congruential_engine/linear_congruential_engine/
		// good enough for now
		// this will be fed in later
		// also the generator defaults to a seed of 1
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distribution(0,VALID_CHARS.size() - 1);

		auto member = string(length,' ');
		auto lambda = [&]()
		{
			return VALID_CHARS[distribution(generator)];
		};

		std::generate_n(back_inserter(member), length, lambda);
		return member;
	}

	string test() { return "";}

	void go()
	{
		auto parameters = Parameters {100,.5,.5, 18};

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
		auto lambda = [=]()
		{
			// turns out you need to actually "return" something
			// if you get an error about not finding a '=' for void
			// or a C2679 error...check that your lambda actually returns
			//  when it is supposed to.
			return GenerateRandomMember(parameters.MemberLength);
		};
		
		log::trace("about to generate population");
		std::generate_n(
			back_inserter(population),
			parameters.PopulationSize, 
			lambda);

		for( auto x : population )
		{
			log::debug(x);
		}


		do
		{

		}
		while(true);
	}
}


int main(int argc, char** argv)
{
	tbontb::go();
	//auto x = tbontb::GenerateRandomMember(18);
	//std::cout << x;
	//auto goal = std::string("TO BE OR NOT TO BE");
}
