#include <random>

#include "StreamCipher.h"

/////////////////////
//Private functions//
/////////////////////
std::string sc::StreamCipher::generateKeyStream(int seed, int length)
{
	std::default_random_engine generator(seed);
	std::string ret;
	for (int i = 0; i != length; ++i)
	{
		ret += generator();
	}
	return ret;
}
std::string sc::StreamCipher::xorStrings(std::string s1, std::string s2)
{
	std::string ret;
	for (int i = 0; i != s1.length(); ++i)
	{
		char byte = s1.at(i) ^ s2.at(i);
		ret += byte;
	}
	return ret;
}

////////////////////
//Public functions//
////////////////////
sc::StreamCipher::StreamCipher(int seed, int length)
{
	keyStream = generateKeyStream(seed, length);
}
std::string sc::StreamCipher::encryptString(std::string s)
{
	return xorStrings(s, keyStream);
}
std::string sc::StreamCipher::decryptString(std::string s)
{
	return xorStrings(s, keyStream);
}