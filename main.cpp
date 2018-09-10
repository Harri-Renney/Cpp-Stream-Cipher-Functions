#include <iostream>
#include <sstream>
#include <String>
#include <random>

std::string generateKeyStream(int seed, int length)
{
	std::default_random_engine generator(seed);
	std::string ret;
	for (int i = 0; i != length; ++i)
	{
		ret += generator.output_l;
	}
	return ret;
}

std::string xorStrings(std::string s1, std::string s2)
{
	std::string ret;
	for (int i = 0; i != s1.length(); ++i)
	{
		char byte = s1.at(i) ^ s2.at(i);
		ret += byte;
	}
	return ret;
}

int main()
{
	int seed;
	std::cout << "Enter your seed: ";
	std::cin >> seed;
	std::cin.ignore();

	std::string message;
	std::cout << "Enter a message:";
	std::getline(std::cin, message);

	std::string keyStream = generateKeyStream(seed, message.length());

	std::cout << "key stream = " << keyStream << std::endl;
	std::string encrypt = xorStrings(message, keyStream);
	std::cout << "Encrypted message = " << encrypt << std::endl;
	std::string decrypt = xorStrings(encrypt, keyStream);
	std::cout << "Decrypted message = " << decrypt << std::endl;

	char halt;
	std::cin >> halt;

	return 0;
}