#include <stdio.h>
#include <iostream>
int main() {
	printf("ababababcccababbababbbbababab\n");
	printf("Find all triple ab's print their index, PUNK\n");
	printf("You should get 0; 2; ~23\n");

	char myString[] = "ababababcccababbababbbbababab";
	int length = sizeof(myString) / sizeof(myString[0]); //char is size 1
	char mySubString[] = "ababab";
	int sLength = sizeof(mySubString) / sizeof(mySubString[0]);
	std::cout << myString << " has " << length << " characters.\n" << mySubString << " has " << sLength << "\n";

	int jp = 0;

	/*For each character in char array myString: check if it matches the first character in substring if it does;
	* enter inner loop that will check the next substring character with the next real string character EXIT this loop if they don't match OR if you have gone the length of the substring
	* Now check if you found each character by counting the 'matches' if the number of matched characters is the same as the # of chars in the SubString then by golly, we have found it
	* Print the outer loop index i which is the index where we started the inner loop match check
	* Move on to next RealString character; repeat the outer loop process until the end of the string.
	*/
	for (int i = 0; i < length - 1; i++) {
		jp = 0;
		if (myString[i] == mySubString[jp]) {
			while ((jp < sLength - 1) && (myString[i + jp] == mySubString[jp])) {
				++jp;
			}
			if (jp == sLength - 1) {
				std::cout << "Found it at: " << i << "\n";
			}
		}
	}

	std::cout << "\nHealing takes time\n";
	return 0;
}