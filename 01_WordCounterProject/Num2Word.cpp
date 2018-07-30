#include "Num2Word.h"

using namespace NumberTransformation;


//Class implementation
Num2Words::Num2Words()
{
	std::cout << "Create a wordCreator"<<std::endl;
	buffer = new int[maxSize];

	//Initialize buffer
	for (int i = 0 ; i<maxSize; i++)
	{
		buffer[i]=0;
	}
}

Num2Words::~Num2Words()
{
	std::cout << "destroying created objects" << std::endl; 
	delete [] buffer;
}

const char* Num2Words::words(uint64_t number)
{
	//Clear buffer and Message
	clearBufferAndMessage();

	if(number == 0) return strncat(message,"zero", messageSize );
	if(number > this->_maxNumber) return strncat(message,"N.A", messageSize );
	//Fill Buffer
	fillBuffer(number);
	
	for(int i = 0; i<maxSize/3; i++)
	{
		int idx = i*3;
		getTripelDigit (message, buffer[idx], buffer[idx+1], buffer[idx+2]);
		if(buffer[idx]!=0 || buffer[idx+1]!=0 || buffer[idx+2]!= 0 )
		{
			strncat(message,_powers[i], messageSize );
			strncat(message,", ", messageSize );
	
		} 
	}
	
	return message;

}

void Num2Words::fillBuffer (uint64_t number)
{
	for(int i = maxSize-1; i>=0; i--)
	{
		buffer[i] = number % 10;
		number /= 10;
	}

}
void Num2Words::clearBufferAndMessage()
{
	for(int i = 0; i<maxSize; i++) buffer[i] = 0;
	for(int i = 0; i<messageSize; i++) message[i] = 0;
}

void Num2Words::printBuffer()
{
	for (int i = 0 ; i<maxSize; i++)
	{
		std::cout << buffer[i] << ',';
	}
	std::cout << std::endl;
}

void Num2Words::getTripelDigit (char * str, int firstDigit, int secondDigit, int thirdDigit)
{
	int index;
	
	
	if (firstDigit != 0)
	{
		
		index = firstDigit;

		strncat(str,_firstNumbers[index], messageSize );
		strncat(str,_space, messageSize );
		strncat(str,_hundred, messageSize );
		strncat(str,_space, messageSize );
	}

	if(secondDigit == 1 || secondDigit == 0)
	{
		index = secondDigit*10 + thirdDigit;
		strncat(str,_firstNumbers[index], messageSize );
		strncat(str,_space, messageSize );
	}
	else 
	{
		index = secondDigit;
		int secondIndex = thirdDigit;

		strncat(str,_tens[index], messageSize );
		if (thirdDigit !=0) strncat (str, _hyphen, messageSize);
		strncat (str, _firstNumbers[secondIndex], messageSize);
		
	}
	
}