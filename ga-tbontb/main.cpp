#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <numeric>

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
			cout << message << endl;
		}

		void trace(const string& message)
		{
			cout << message << endl;
		}

		void debug(const string& message)
		{
			cout << message << endl;
		}

		void debug(unsigned int message)
		{
			cout << message << endl;
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

		auto member = string();
		//member.reserve(18);
		auto lambda = [&]()
		{
			return VALID_CHARS[distribution(generator)];
		};

		std::generate_n(back_inserter(member), length, lambda);
		return member;
	}

	string test() { return "";}

	void mutate

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

		auto target = string("TO BE OR NOT TO BE");
		auto compare = [](unsigned char c1, unsigned char c2) { return c1 == c2; };

		// 1. initialze the population
		// 2. evaluate the population
		// 3. generate a new population
		//
		for(auto generation = 0; generation < 1000; generation++)
		{
			auto maxScore = 0u;
			string* best;

			for( auto& x : population )
			{
				// so using transform and a vector of ints isn't "the best"
				// but i am exploring the stl and more functional programming
				// also i should switch to a bit vector
				// but turns out that bitset deoesn't have iterators...
				list<int> scores;
				log::debug(x);
				log::debug(target);
				transform(x.begin(), x.end(), target.begin(),
						back_inserter(scores), compare);
				auto score = accumulate(scores.begin(), scores.end(), 0);
				std::copy(scores.begin(), scores.end(), std::ostream_iterator<int>(std::cout));
				log::debug("");
				log::debug(score);
				if (score > maxScore)
				{
					maxScore = score;
					best = &x;
				}
			}

			log::info("----");
			log::debug(maxScore);
			log::info(*best);

			string bestCopy = *best;

			std::list<string> newPopulation;
			std::generate_n(
				back_inserter(newPopulation),
				parameters.PopulationSize, 
				lambda);			//jdo
			//{
			//	transform
			//}
			//while(true);
		}
	}
}


int main(int argc, char** argv)
{
	tbontb::go();
	//auto x = tbontb::GenerateRandomMember(18);
	//std::cout << x;
	//auto goal = std::string("TO BE OR NOT TO BE");
}
