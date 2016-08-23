// CastLabs_W32Con.h

#include <string> 
using namespace std;
//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&                                                                    &&&&&
//&&&&&     Struct to keep all file manip variables in one placey          &&&&&
//&&&&&____________________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
struct FilePositioning
{
	streampos position;   

	
	streamoff positionOffset1;

	streamoff positionOffset_2findBytesInBox;
	streamoff positionOffsetForWord; //to read a word b4 type string

	streampos positionBegin;
	streampos positionTemp; 

	streampos positionb4Read;

	streampos positionFlag;

	streampos positionAlphaFound;
	streampos positionLastAlphaFound; 
	
	streampos positionb4TypeString;
	streampos positionAfterType;
	
};



//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&                                                                    &&&&&
//&&&&&          88b 88 Yb  dP 88""Yb 88""Yb 88     888888 .dP"Y8          &&&&&
//&&&&&          88Yb88  YbdP  88__dP 88__dP 88     88__   `Ybo."          &&&&& 
//&&&&&          88 Y88   8P   88""Yb 88""Yb 88  .o 88""   o.`Y8b          &&&&&
//&&&&&          88  Y8  dP    88oodP 88oodP 88ood8 888888 8bodP'          &&&&&
//&&&&&____________________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
struct twoNibbles
	{
	unsigned char lowestNibble : 4;
	unsigned char highestNibble : 4;
	}myNibble;
//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&  ;-.            .    .  .     .   .   .         ,-.                     &&&
//&&  |  )     o     |    |\ |     |   |   |         |  ) o                  &&&
//&&  |-'  ;-. . ;-. |-   | \| . . |-. |-. | ,-. --- |-<  . ;-. ,-: ;-. . .  &&& 
//&&  |    |   | | | |    |  | | | | | | | | |-'     |  ) | | | | | |   | |  &&& 
//&&  '    '   ' ' ' `-'  '  ' `-| `-' `-' ' `-'     `-'  ' ' ' `-` '   `-|  &&& 
//&&                           `-'                                      `-'  &&& 
//&&                       printNibblesInBinary()                            &&&
//&&_________________________________________________________________________&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void printNibblesInBinary( twoNibbles n)
{
//	if (p->highestNibble < 0)
	// cout << endl << "\n******************************************************* Printing Nibbles\n";
	if (n.highestNibble < 0){
		cout << "Negative Nibble\n";
	}
	else
	{
		cout << "Highest Nibble in Binary = "; 
			for (int iBit = 3; iBit >=0; --iBit)
			{
				//************************** shift each bit into the 1's place (ie. divide by 2), then modulus for 1 or 0
				cout << (( n.highestNibble  >> iBit) % 2);
			}
		cout << endl;

		cout << "Lowest Nibble in Binary  = "; 
			for (int iBit = 3; iBit >=0; --iBit)
			{
				//************************** shift each bit into the 1's place (ie. divide by 2), then modulus for 1 or 0
				cout << (( n.lowestNibble  >> iBit) % 2);
			}

		cout << "\n******************************************************* End printing nibbles\n\n" << endl << endl;
	}
		
	return;
}

//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&                                                                    &&&&&
//&&&&&   _  , _, __, _  _, _ _, _,   _,_ _ _ _  _, _, ___ _  _, _, _  _,  &&&&&
//&&&&&   | / /_\ |_) | / \ | | (_    |_  | | |\ | / `  |  | / \ |\ | (_   &&&&&
//&&&&&   |/  | | | \ | \ / | | , )   |   | | | \| \ ,  |  | \ / | \| , )  &&&&&
//&&&&&   ~   ~ ~ ~ ~ ~  ~  `~'  ~    ~   `~' ~  ~  ~   ~  ~  ~  ~  ~  ~   &&&&&
//&&&&&____________________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//______________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                                                  
//&&&&&     ,-.      .       ,-.  ,-.                      .  , .   &&&&
//&&&&&     |  )     |          ) |  \         o           | /   \  &&&&
//&&&&&     |-<  . . |-  ,-.   /  |  | ,-. ,-. . ;-.-. ,-: | |   |  &&&&
//&&&&&     |  ) | | |   |-'  /   |  / |-' |   | | | | | | | \   /  &&&&
//&&&&&     `-'  `-| `-' `-' '--' `-'  `-' `-' ' ' ' ' `-` '  ` '   &&&&
//&&&&&          `-'                                                &&&& 
//&&&&&_____________________________________________________________&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
double Byte2Decimal_perByte(int iValueInput, int iBitNum2Start)
{
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//&&&&&                      LOCALS                        &&&&&
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	double answer = 0; 
	int arr[] = {0,0,0,0,0,0,0,0};

	int iBit; 
	int iBitsInByte = 7;

	int index=0, j=0;

	int dFinalValue=iValueInput;	
	double dPow=2; 

	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//&&&&&       Check Parameter Values passed to Functions   &&&&&
	//&&&&&                                                    &&&&&
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	if (iValueInput <0)
		cerr << "WARNING: Decimal value of Byte is Negative  = iValueInput = " << iValueInput << endl;
	
	if (iBitNum2Start < iBitsInByte)
	{
		//********************
		cerr << "Byte2Decimal_perByte() - BitNum2Start cannot be greater than iBitsInByte\n";
		cerr << "iBitNum2Start = " << iBitNum2Start << ",  iBitsInByte = " <<  iBitsInByte << endl;
		cerr << "Returning -99\n";
		return (-99);
	}

	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//&&&&&    Calculate & Fill Int Array with Binary Digits   &&&&&
	//&&&&&                                                    &&&&&
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//	cout << "\nCalculated & filled integer ARRAY arr[] with binary values:\n\n";
	index = 0;

	while (dFinalValue > 0) 
	{
		arr[index] = dFinalValue % 2;
//		cout << "arr[" << index << "] = " << arr[index] << endl;
		index++;
		dFinalValue = dFinalValue/2;
	}
	//**************************************************** PRINT
	for ( j=iBitsInByte; j>=0; j--)
		cout << arr[j];
	cout << endl;

	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//&&&&&             Calculate Value of this Byte           &&&&&
	//&&&&&     if higher byte, Exponent/iBit is 8 bits more   &&&&&
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	answer = 0; 
	double x=0; 
	int exponent2Start = iBitNum2Start; 
	int exponent2End   = exponent2Start - iBitsInByte; 
	int exponent = iBitNum2Start;
	int iBit2Start = iBitsInByte;
	int iBit2end = 0;
	
	for (iBit=7, exponent=exponent2Start; iBit>=0, exponent>=exponent2End; iBit--, exponent--)
	{
		if (arr[iBit] == 1)
		{
			x = pow(dPow, exponent);
			answer = answer + x;
		}
	}
//	cout << "Value of this Byte after Calculating from Binary = " << answer << endl;
	return answer;
}
//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&  ;-.            .     ,-.      .           ,-.                     &&&&&
//&&&&&  |  )     o     |     |  )     |           |  ) o                  &&&&&
//&&&&&  |-'  ;-. . ;-. |-    |-<  . . |-  ,-. --- |-<  . ;-. ,-: ;-. . .  &&&&& 
//&&&&&  |    |   | | | |     |  ) | | |   |-'     |  ) | | | | | |   | |  &&&&& 
//&&&&&  '    '   ' ' ' `-'   `-'  `-| `-' `-'     `-'  ' ' ' `-` '   `-|  &&&&& 
//&&&&&                              `-'                                `-'&&&&&
//&&&&&                  PrintCurrentByte_inBinary()                       &&&&&
//&&&&&____________________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void PrintCurrentByte_inBinary( char inChar, int iByteNum)
{                                                      
	cout << "\nByte # = " << iByteNum << endl << endl;

	cout << "      888b. w                                 " << endl;  
	cout << "      8wwwP w 8d8b. .d88 8d8b Yb  dP    wwww  " << endl;
	cout << "      8   b 8 8P Y8 8  8 8P    YbdP     wwww  " << endl;
	cout << "      888P' 8 8   8 `Y88 8      dP            " << endl;
	cout << "                               dP             " << std::bitset<8>(inChar) << std::endl << std::endl;
	cout << "                                    " << endl;

	return;
}

//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&  ;-.            .     ,-.                     .    ,-.      .       &&&&
//&&&&&  |  )     o     |    /                        |    |  )     |       &&&&
//&&&&&  |-'  ;-. . ;-. |-   |    . . ;-. ;-. ,-. ;-. |-   |-<  . . |-  ,-. &&&&
//&&&&&  |    |   | | | |    \    | | |   |   |-' | | |    |  ) | | |   |-' &&&&
//&&&&&  '    '   ' ' ' `-'   `-' `-` '   '   `-' ' ' `-'  `-'  `-| `-' `-' &&&&
//&&&&&                also calls printCurrentByte_Binary       `-'         &&&&
//&&&&&_____________________________________________________________________&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void printCurrentByte(char inChar, int inCurrentByteNum)
{
	// Print bytes with value of  0 or NULL prints a blank space, so replacing with string "zero"
	
	int  iCharInDecimal= (int) inChar;

	if (inChar == 0)
	{
		cout << "\nByte # " << inCurrentByteNum << " =   ZERO     in ANY Base\n";
		// cout << "Btye # " << inCurrentByteNum << " in BINARY:\n";
		//PrintCurrentByte_inBinary( inChar, inCurrentByteNum); 
	}
	else
	{
		cout << "\nByte # " << inCurrentByteNum << " = (  CHAR  )  " << inChar << endl;
		cout << "Byte # " << inCurrentByteNum << " = ( DECIMAL)  " << iCharInDecimal << endl;
		cout << "Byte # " << inCurrentByteNum << " = (   HEX  )  " << hex << iCharInDecimal << dec << endl;
		//cout << "Byte # " << inCurrentByteNum << " in BINARY:\n";
		//PrintCurrentByte_inBinary( inChar, inCurrentByteNum); 
	}

return;
}
//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&           ,     ,              . ,-.      .        , .             &&&&&
//&&&&&           |     |              | |  )     |       /   \            &&&&&
//&&&&&           | ,-. |    ,-. ,-: ,-| |-<  . . |-  ,-. |   |            &&&&& 
//&&&&&           | `-. |    |-' | | | | |  ) | | |   |-' \   /            &&&&&
//&&&&&           ' `-' `--' `-' `-` `-' `-'  `-| `-' `-'  ` '             &&&&&
//&&&&&                                   `-'                              &&&&&
//&&&&&____________________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

int IsLeadByte( twoNibbles n)
{
//	if (p->highestNibble < 0)
	// cout << endl << "\n******************************************************* Printing Nibbles\n";
	int iLengthOfUtf = 0;

	if (n.highestNibble < 0){
		cout << "Negative Nibble\n";
	}
	else
	{
		cout << "Highest Nibble in Binary = "; 
			for (int iBit = 3; iBit >=0; --iBit)
			{
				if (iBit == 3 && ((n.highestNibble >> iBit) & 2) == 1)
					cout << "\nLEAD BYTE FOUND" << endl;
				
				//************************** shift each bit into the 1's place (ie. divide by 2), then modulus for 1 or 0
				cout << (( n.highestNibble  >> iBit) % 2);
			}
		cout << endl;

		cout << "Lowest Nibble in Binary  = "; 
			for (int iBit = 3; iBit >=0; --iBit)
			{
				//************************** shift each bit into the 1's place (ie. divide by 2), then modulus for 1 or 0
				cout << (( n.lowestNibble  >> iBit) % 2);
			}

	//	cout << "\n******************************************************* End printing nibbles\n\n" << endl << endl;
	}
		
		return (1);
}