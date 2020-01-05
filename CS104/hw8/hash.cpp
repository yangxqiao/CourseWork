#include "hash.h"
using namespace std;

unsigned int calculateHash(string mystring)
{
  /* add your code here */
	unsigned long long value_after_translation = mystring[0];
	for(unsigned int i = 1; i < mystring.size(); i++)
	{
		value_after_translation = mystring[i] + 128*value_after_translation;
	}

	unsigned int significant_bits[4];
	for(int i = 0; i < 4; i++)
	{
		significant_bits[i] = 0;
	}

	int pos = 4;
	while(value_after_translation > 65521)
	{
		unsigned int temp_bits = value_after_translation % 65521;
		value_after_translation = value_after_translation / 65521;
		significant_bits[pos] = temp_bits;
		pos -= 1;
	}
	significant_bits[pos] = value_after_translation;

	return (45912 * significant_bits[1] + 
		35511 * significant_bits[2] + 
		65169 * significant_bits[3] + 
		4625 * significant_bits[4]) % 65521;
}
