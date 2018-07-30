#include <iostream>
#include <string.h>

#ifndef _NUM2WORDS_

#define _NUM2WORDS_

#define _BW_NUMWORD_MAXSTR 2048

//nine hundred ninty-nine trillion nine hundred ninty-nine billion nine hundred ninty-nine million nine hundred ninty-nine thousand nine hundred ninty-nine
#define _BW_MAXNUM 999999999999999
#define _BUFFER_MAX 15

namespace NumberTransformation 
{
	static const char * _firstNumbers[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
   	"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};
	static const char * _tens[] = {
	    "error","error","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty",
	};

	static const char * _hundred = "hundred";
	static const char * _hyphen = "-";
	static const char * _space = " ";
	static const char * _zero = "zero";

	static const char * _powers[] = {
	     "trillion","billion", "million","thousand",""
	};

	static const char * _singles[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	static const char * _teens [] = {
	    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};


	class Num2Words 
	{
	private:
		uint64_t _maxNumber = _BW_MAXNUM;
		const int messageSize =  _BW_NUMWORD_MAXSTR;
		char message[_BW_NUMWORD_MAXSTR];
		int* buffer;
		const int maxSize = _BUFFER_MAX;

		void fillBuffer(uint64_t number);
		void printBuffer();
		void getTripelDigit (char * str, int firstDigit, int secondDigit, int thirdDigit); 
		void clearBufferAndMessage();

	public:
		
		Num2Words ();
		~Num2Words();
		const char* words (uint64_t number);

		

	};


};

#endif /*_NUM2WORDS_*/