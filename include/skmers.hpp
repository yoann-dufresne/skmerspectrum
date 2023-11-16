#include <string>

#include "hash.hpp"


class SkmerStreamer
{
public:
	uint64_t minimizer_size;
	uint64_t current_position;
	Hash h;
	std::string & sequence;

	SkmerStreamer(std::string & sequence, uint64_t m, Hash h)
										: minimizer_size(m)
										, current_position(0)
										, sequence(sequence)
	{}

	Skmer next()
	{
		return 0;
	}
}