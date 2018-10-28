# Cpp-Stream-Cipher-Functions

This project provides a simple class used for generating key streams, then using it to encrypt and decrypt std::strings.

## Usage

To use this class, create a new StreamCipher object. This requires an integer seed (Used to generate your keystream, so decide on it carefully) and length. In this case, the length should be equal to the length of the message.

Now just call the SteamCipher object's encryption and decryption on the message string passed to it, and returns the resulting message.

See the example demonstrated in the main for practicle use.

## Brief Explanation

A steam cipher works by taking one set of bytes, the message. Then using the bitwise Xor operation on it with another set of bytes of preferably equal length, the keystream.
The original message will then be incomperhensible and only return its original, meaningful information if Xored again with the same keystream.

So the secrecy of this method comes from the keystream. If the keystream is discovered, then the secrecy is lost.
Brute forcing a stream cipher is not realistically possible if the message is reasonably long. The stream cipher can be deduced using human intuition if the keystream is used more than once, across multiple messages.

A detailed explaination for this is covered here: https://www.cs.usfca.edu/~ejung/courses/686/lectures/03stream.pdf

If the keystream covers the whole message, and is not reused. Perfect secrecy is achieved.

## Things to work on
In the StreamCipher class, a very simple method of generating a key stream is defined. This is your PRNG(pseudo random number generator). If anybody found out this was how you generated your keystream, they would just have to brute force all possible seeds. Which may be a feasible number for an attack.

Apparently the stream cipher is only as secure as your PRNG for keystream generating. So you may wish to adjust this function. This may be as simple as adding some constant to each value generated or more complex techniques. Just to avoid anybody trying to guess and replicate your keystream generation and bruteforce the seed.

## To-Do

* Handle the use if a smaller keystream is used than message length - Will loop back to beginning of keystream when reaches end. Currently breaks.