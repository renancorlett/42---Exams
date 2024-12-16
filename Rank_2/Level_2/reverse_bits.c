/*
Assignment name: reverse_bits
Expected files: reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char result;

	while (i--)
	{
		result <<= 1;
		result |= (octet & 1);
		octet >>= 1;
	}
	return (result);
}
