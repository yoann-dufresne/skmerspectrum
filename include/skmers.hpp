#include <string>

#include "hash.hpp"


template<class H>
class SkmerStreamer
{
public:
	uint64_t minimizer_size;
	uint64_t current_position;
	H h;
	std::string & sequence;

	SkmerStreamer(std::string & sequence, uint64_t k, uint64_t m)
										: minimizer_size(m)
										, current_position(0)
										, h(k)
										, sequence(sequence)
	{}

	Skmer next()
	{
		return 0;
	}
}