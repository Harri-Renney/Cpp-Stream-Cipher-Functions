#ifndef STREAM_CHIPHER_H
#define STREAM_CIPHER_H

#include <string>

namespace sc
{
	class StreamCipher
	{
	private:
		std::string keyStream;

		std::string generateKeyStream(int seed, int length);
		std::string xorStrings(std::string s1, std::string s2);
	public:
		StreamCipher(int seed, int length);
		
		//Use keystream to encrypt + decrypt messages//
		std::string encryptString(std::string s);
		std::string decryptString(std::string s);
	};
}

#endif