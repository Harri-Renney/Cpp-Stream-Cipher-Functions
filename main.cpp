#include <iostream>
#include <sstream>
#include <String>
#include <random>

#include "StreamCipher.h"

int main()
{
	int seed;
	std::cout << "Enter your seed: ";
	std::cin >> seed;
	std::cin.ignore();

	std::string message;
	std::cout << "Enter a message:";
	std::getline(std::cin, message);

	sc::StreamCipher streamCipher(seed, 2);

	std::string encryptedMessage = streamCipher.encryptString(message);
	std::cout << "Encrypted message = " << encryptedMessage << std::endl;
	std::string decrypt = streamCipher.decryptString(encryptedMessage);
	std::cout << "Decrypted message = " << decrypt << std::endl;

	char halt;
	std::cin >> halt;

	return 0;
}