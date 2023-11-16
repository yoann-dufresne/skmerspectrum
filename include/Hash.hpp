
using namespace std;

class Hash
{
public:
	/** Hash the next kmer.
	 * @param nucletide The next nucleotide in the sequence.
	 * 
	 * @return 64-bits hash value
	 **/
	virtual uint64_t next_hash(char nucleotide);
};


/** Hash class to extract only the 4-bits sequence encoding without any hash.
 * The forward encoding is A, C, T, G (for bit-trick purpose)
 **/
class StrEncoding : Hash
{
	// Max k is 31 due to 64-bits mask computation
	uint64_t k;
	uint64_t mask;

	uint64_t forward;
	uint64_t reverse;
public:
	StrEncoding(uint64_t k)
						: k(k)
						, forward(0)
						, reverse(0)
						, mask( (1ULL << (2*k)) - 1)
	{};

	/** Inheritance **/
	uint64_t next_hash(char nucleotide)
	{
		// Forward encoding
		uint64_t bit_nucl = (((uint64_t)nucleotide) >> 1) & 0b11;
		this->forward <<= 2;
		this->forward &= this->mask;
		this->forward |= bit_nucl;
		// Reverse encoding
		uint64_t bit_rev = ((bit_nucl + 2) & 0b11) << (2 * (k - 1));
		this->reverse >>= 2;
		this->reverse |= bit_rev;

		return std::min(this->forward, this->reverse);
	};
};