// CastLabs_W32Con.cpp : Defines the entry point for the console application.
//
// kep remember to do returns & deallocate memory
// kep  use typedef for BYTE
//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&                                                                    &&&&&
//&&&&&           Preprocessor Includes, Defines & Typedefs etc.           &&&&&
//&&&&&____________________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <iomanip>

#include <bitset> 
#include <math.h>

#include "CastLabs_W32Con.h"

#include "box.h"
//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define MAX_LETTERS_BOXTYPE 4 
#define MAX_ELEMENT_INDEX_BOXTYPE 3
//______________________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// An unsigned char can store 1 Bytes (8bits) of data (0-255)
typedef unsigned char BYTE;

using namespace std;


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&                   __ __    __    _   __  _    _   _                &&&&&
//&&&&&                  |  V  |  /  \  | | |  \| |  / | | \               &&&&&
//&&&&&                  | \_/ | | /\ | | | | | ' | ( (   ) )              &&&&&
//&&&&&                  |_| |_| |_||_| |_| |_|\__|  \_| |_/               &&&&&
//&&&&&____________________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

int _tmain(int argc, _TCHAR* argv[])
{
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//&&&&&                      LOCALS                        &&&&&
	//&&&&&            Declare, Define & Initialize            &&&&&
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

	//******************* To read & print ONE Byte/char at a time & treat as UN-SIGNED 
	unsigned char cuCharRead= 0;  
	char cCharRead = 0; 
//	char ccc;
	unsigned char cLastCharRead = 0;  

	//******************* Box Types & variables used to find box types
	int iNumBoxesFound = 0; 

	int iCurrentLengthOfType = 4; 
	char * szAllTypes[] = {"moof", "mfhd", "traf", "tfhd", "trun", "uuid", "mdat"};

	//********************  indexes & counters
	int i = 0;
	int kk = 0;
	
	//********************* Bytes
	int iCurrentByte = 0;
	int iLastByte = 0;

	int iNumBytesInBox= 0;

	int index = 0;
	int iNumContigCharsFound = 0;

	char* pcTempType = "temp";

	FilePositioning filePos = { 1, 1, MAX_LETTERS_BOXTYPE+1, MAX_LETTERS_BOXTYPE+4, 0, 0, 0,  -99, -99, -99, -99, -99 };

	//  ;-.  .                             ,-.                  
	//  |  ) |         o                   |  )                 
	//  |-'  | ,-: . . . ;-. ,-:   , , ,   |-<  ,-. . , ,-. ,-. 
	//  |    | | | | | | | | | |   |/|/    |  ) | |  X  |-' `-. 
	//  '    ' `-` `-| ' ' ' `-|   ' '     `-'  `-' ' ` `-' `-' 
	//             `-'       `-'                       
	//************************************************************* Create Box Objext
	Box Box1( "test", MAX_LETTERS_BOXTYPE, 99);

	//************************************************************* GetBoxType()
	pcTempType  = Box1.GetBoxType();
	cout << "main Box1 : Box1 Type string returned from Box1.GetBoxType() = " << pcTempType << endl;

	//************************************************************* GET # LETTERS IN Box Type String
	iCurrentLengthOfType = static_cast< int > ( strlen( pcTempType ) );

	//************************************************************* GET # Bytes in Box
	iNumBytesInBox = Box1.GetLength_InBytes();
	cout << "main Box1 : Box1 bytes = " << iNumBytesInBox << endl << endl;

	//*****        . . . . .-. .-. .   .-. .-. 
	//*****        |\|  |  |(  |(  |   |-  `-. 
	//*****        ' `  `  `-' `-' `-' `-' `-' 
	//*****     __________________________________________
	myNibble.lowestNibble = 7;
	myNibble.highestNibble = 0;
	printNibblesInBinary(myNibble);

	//*****      .-. .-. .-. . .   .-. .-. .   .-. 
	//*****      | | |-' |-  |\|   |-   |  |   |-  
	//*****      `-' '   `-' ' `   '   `-' `-' `-' 
	//*****    
	ifstream myFile("c:\\akareen\\text0.mp4", ios::binary | ios::in);

	if ( (myFile.rdstate() & std::ifstream::failbit ) != 0 ){
		 std::cerr << "Error opening input file.\n";
		 return 0;
	}
	else cout << "\n\nSuccessfully loaded file http://demo.castlabs.com/tmp/text0.mp4 \n\n";


	//**********************************************************************************    
	//*****       ,-.            .    ,   ,-.      .         .     .   ,--.  ,-.  ,--. 
	//*****       |  )           |   '|   |  )     |         |   o |   |    /   \ |    
	//*****       |-<  ,-. ,-: ,-|    |   |-<  . . |-  ,-.   |-  . |   |-   |   | |-   
	//*****       |  \ |-' | | | |    |   |  ) | | |   |-'   |   | |   |    \   / |    
	//*****       '  ' `-' `-` `-'    '   `-'  `-| `-' `-'   `-' ' '   `--'  `-'  '    
	//*****-----------------------------------------------------------------------------     
	//**********************************************************************************
	char Type[MAX_ALLOCATE_BOXTYPE] = "&&&&";
	cout << "  Reading file ........................................\n\n";
	cout << "  :::::::::::::::::::::::::::::::::::::::::::::::::::::  \n\n";
	cout << "                                                         \n";
	cout << "   .oPYo.                    8     ooooo  o 8            \n";
	cout << "   8   `8                    8     8        8            \n";
    cout << "   o8YooP' .oPYo. .oPYo. .oPYo8    o8oo   o 8  .oPYo.    \n";
	cout << "   8   `b  8oooo8  oooo8 8    8    8      8 8  8oooo8    \n";
	cout << "   8    8  8.     8    8 8    8    8      8 8  8.        \n"; 
	cout << "   8    8  `Yooo' `YooP8 `YooP'    8      8 8  `Yooo'    \n";
	cout << "  :..:::..:.....::.....::.....::::..:::::....:.....::::  \n";
	cout << "  :::::::::::::::::::::::::::::::::::::::::::::::::::::  \n";
	cout << "  :::::::::::::::::::::::::::::::::::::::::::::::::::::  \n\n";


	while (myFile.good() && !myFile.eof() && iCurrentByte <= 200 ) // kep
	{
		//*****      .-. .-. . . .-.   .-. .-. .-. .-. .-. .-. .-. . . .-. 
		//*****      `-. |-| | | |-    |-' | | `-.  |   |   |  | | |\| `-. 
		//*****      `-' ` ' `.' `-'   '   `-' `-' `-'  '  `-' `-' ' ` `-' 
		//*****                                                            
		filePos.positionb4Read	= myFile.tellg();
		
		//*****      ,-.            .   ,-.      .       
		//*****      |  )           |   |  )     |       
		//*****      |-<  ,-. ,-: ,-|   |-<  . . |-  ,-. 
		//*****      |  \ |-' | | | |   |  ) | | |   |-' 
		//*****      '  ' `-' `-` `-'   `-'  `-| `-' `-' 
		//*****                              `-'             MAIN LOOP to Read Byte
		cuCharRead = myFile.get();
		filePos.position = myFile.tellg(); // after get() position is the NEXT position to be read
		filePos.positionAfterType = myFile.tellg();
		
		cCharRead = cuCharRead;

		//*****         .-. .-.   . . .-. .   .-. .-.   .-. . . .-. .-.   . .   .-. . . .-. .-. 
		//*****          |  |-    | | |-| |    |  |  )  |   |-| |-| |(    `-|    |   |  |-' |-  
		//*****         `-' '     `.' ` ' `-' `-' `-'   `-' ' ` ` ' ' '     '    '   `  '   `-' 
		
		unsigned char c = cuCharRead;  // used to shorten next line for readability

		if (c=='a' || c=='d' || c=='f' || c=='h' || c=='i' || c=='m' || c=='n'|| c=='o'|| c=='r'|| c=='t'|| c=='u')
		{
			//****** filePos.positionAlphaFound = streampos of alphabetic char found last
    		filePos.positionAlphaFound = filePos.positionb4Read;

			//*****        .-. .-.   .-. .   .-. . . .-.     .-. .-. .-. 
			//*****         |  |-    |-| |   |-' |-| |-|     |(  | | |-  
			//*****        `-' '     ` ' `-' '   ' ` ` '     `-' `-' '   
			//*****        FYI: In this particular case, This code should be unused
			if (filePos.positionAlphaFound == filePos.positionBegin )
			{
				Type[index++] = cuCharRead;
                filePos.positionLastAlphaFound = filePos.positionBegin;
				iNumContigCharsFound++;
				Type[index] = NULL; // terminate string
			}

			//*****          .-. .-.   .-. .   .-. . . .-.   .   .-. .-. .-. 
			//*****           |  |-    |-| |   |-' |-| |-|   |   |(  | | |-  
			//*****          `-' '     ` ' `-' '   ' ` ` '   .   `-' `-' '       
			//*****      if character found is NOT at Beg of file
			if (filePos.positionAlphaFound > filePos.positionBegin)
			{
				//******************** if characters found are in contiguous bytes OR
				//********************     No Char found yet = filePos.positionFlag AND 
				//********************     still room for one more contig char in Type 

				//*****        .-. .-.   .-. .-. . . .-. .-. .-. . . .-. . . .-. 
				//*****         |  |-    |   | | |\|  |   |  |.. | | | | | | `-. 
				//*****        `-' '     `-' `-' ' `  '  `-' `-' `-' `-' `-' `-' 
				if( ( (filePos.positionLastAlphaFound == (filePos.positionAlphaFound - filePos.positionOffset1))  \
					||   (index == 0) ) && (iNumContigCharsFound < MAX_LETTERS_BOXTYPE )  )
				{
					//	cout << "\nALPHA FOUND >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ALPHA = " << ccc << endl;
					
					//************************* Fill Type array with letters found 
					Type[index++] = cuCharRead;
					Type[index] = '\0';  //terminate string so I can find length

					//	cout << "IS CONTIGUOUS >>>>>>>>>>>>>>>>>>>  TYPE = " << Type << endl << endl;
					
					filePos.positionLastAlphaFound = filePos.positionAlphaFound; //another alpha is found in beg of loop
					iNumContigCharsFound++;
					//cout << "INum contig chars found = " << iNumContigCharsFound << endl;
				}
				else
				{
					//*****       . . .-. .-.   .-. .-. . . .-. .-. .-. . . .-. . . .-. 
					//*****       |\| | |  |    |   | | |\|  |   |  |.. | | | | | | `-. 
					//*****       ' ` `-'  '    `-' `-' ' `  '  `-' `-' `-' `-' `-' `-' 
					//Alphas found are not contiguous, resetting to find next box type
					iNumContigCharsFound = 1;
					filePos.positionLastAlphaFound = filePos.positionAlphaFound; 
					index = 0;
					Type[index++] = cuCharRead;
					Type[index] = '\0'; //terminate
				}

			}
		
 			//*****       .-. . . . . .-.   .   .-. .-. .-. .-. .-. .-. 
 			//*****       |-  |\| | | |-    |   |-   |   |  |-  |(  `-. 
 			//*****       `-' ' ` `-' '     `-' `-'  '   '  `-' ' ' `-' 
 			
			iCurrentLengthOfType = static_cast< int > ( strlen( Type ) );

			if ( iCurrentLengthOfType == ( MAX_LETTERS_BOXTYPE ) )
			{
				const char * checkType = "moof";
				const char * typeFound = Type;

				bool foundRealBox = false;
				size_t is_equal = 999;

				//*****:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
				//*****    .-.                       .---.              .-.                         
				//*****    : :                       : .; :            .' `.                        
				//*****    : :    .--.  .--. .---.   :   .' .--. .-.,-.`. .'.-..-..---.  .--.  .--. 
				//*****    : :__ ' .; :' .; :: .; `  : .; :' .; :`.  .' : : : :; :: .; `' '_.'`._-.'
				//*****    :___.'`.__.'`.__.': ._.'  :___.'`.__.':_,._; :_; `._. ;: ._.'`.__.'`.__.'
				//*****                      : :                             .-. :: :               
				//*****                      :_;                             `._.':_;         
				//*****:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
				//*****         iterate through all box types stored in szAllTypes[]
				
				int  iiBoxType = 0; 
				char * cTypeRead = Type;
				char * cStoredBoxType = szAllTypes[iiBoxType];
				int iLetter = MAX_LETTERS_BOXTYPE; // For counting backwards when comparing all the letters in type 

				//***************************** printing
				//cout << ",\t cTypeRead=" << cTypeRead << ",\t  cStoredBoxType=" << cStoredBoxType << endl;

				//************************ Check to see if it's a real box string, iterate through 7 box types
				//************************ Beg of this while loop iiBoxType=0 and is_equal != 0
				//************************ Campare SzAllTypes[iiBoxType] with 4 letter string found in file
				//************************      if not go through loop (iiBoxType) and check next stored box type 
				//	cout << "\n<><><><><><><><><><><><><> LOOP thru szAllTypes[] - Box Type Read from file = "<< Type << end;
				//	cout << "Comparing to Valid Types = " << cStoredBoxType << endl;

				while ( (iiBoxType < 7)  && (is_equal !=  0))
				{				
					cStoredBoxType = szAllTypes[iiBoxType];
					cTypeRead = Type;

					iLetter = MAX_LETTERS_BOXTYPE; // For counting backwards when comparing boxytpes
					while ( *cStoredBoxType++ == *cTypeRead++ &&   iLetter-- > 0 )
						;

					cTypeRead = Type; 

					//*********************** if we iterated through the max # letters in a BoxType string & 
					//***********************    ALL letters found match the current type string stored in szAllTypes[]
					if( iLetter <= 0 )
					{
						is_equal = 0; 
						foundRealBox = true;
					}

					iiBoxType++;
				} // end of loop through box types

				iiBoxType = 0; // reset Box Type number to compare string in next loop
				
                //*****      . . .-. .-.   .-. .-. .-. .     .-. .-. .  . 
                //*****      |\| | |  |    |(  |-  |-| |     |(  | |  )(  
                //*****      ' ` `-'  '    ' ' `-' ` ' `-'   `-' `-' '  ` 
                //*****                                                   
					
				//shift characters read in  and then re-process this character; 
				if ( foundRealBox == false)
				{
					Type[0] = Type[1];
					Type[1] = Type[2];
					Type[2] = Type[3];
					Type[3] = '\0';
					iNumContigCharsFound = 3; 
					index = 2; 
					iCurrentLengthOfType = 3;
					filePos.positionLastAlphaFound = filePos.positionAlphaFound;
					filePos.positionAlphaFound = filePos.positionAlphaFound - filePos.positionOffset1;
				}
				else
				{
					//*****    .-. .-. . . . . .-.   .-. .-. .-. .     .-. .-. .  . 
					//*****    |-  | | | | |\| |  )  |(  |-  |-| |     |(  | |  )(  
					//*****    '   `-' `-' ' ` `-'   ' ' `-' ` ' `-'   `-' `-' '  ` 
					//*****                                                         

					iNumBoxesFound++; 
		            
					//***:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  
					//***     .--.       .-.   .---.        .-.              .-.        .---.             
					//***    : .--'     .' `.  : .; :      .' `.             : :        : .; :            
					//***    : : _  .--.`. .'  :   .'.-..-.`. .'.--.  .--.   : :,-.,-.  :   .' .--. .-.,-.
					//***    : :; :' '_.': :   : .; :: :; : : :' '_.'`._-.'  : :: ,. :  : .; :' .; :`.  .'
					//***    `.__.'`.__.':_;   :___.'`._. ; :_;`.__.'`.__.'  :_;:_;:_;  :___.'`.__.':_,._;
					//***____________________________ .-. :_________________________________________________           
					//***:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  
					char * cTempBoxType = "mdat";
					bool isTypeMdat = false;
					iLetter = MAX_LETTERS_BOXTYPE;
					while ( *cTypeRead++  == *cTempBoxType++ && (iLetter--)>0 ) 
						;                                                   
					if (iLetter <= 0)
						isTypeMdat = true;

					streampos positionGetBytes = filePos.position - filePos.positionOffsetForWord;
					//streampos positionGetBytes =  filePos.position - filePos.positionOffset_2findBytesInBox - filePos.positionOffset1;
					//filePos.positionOffset_2findBytesInBox = filePos.position - filePos.positionOffset_2findBytesInBox;

					myFile.seekg(positionGetBytes);

					//*****      ,-.            .   ,-.      .       
					//*****      |  )           |   |  )     |       
					//*****      |-<  ,-. ,-: ,-|   |-<  . . |-  ,-. 
					//*****      |  \ |-' | | | |   |  ) | | |   |-' 
					//*****      '  ' `-' `-` `-'   `-'  `-| `-' `-' 
					//*****                              `-'         
					double dNumBytesInBox=0;

					for (int ibyte=1; ibyte <= 4; ibyte++)
					{
						filePos.positionTemp = myFile.tellg();

						//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
						//&&&&&            READ             &&&&&
						//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
						cuCharRead = myFile.get(); // re-read character for # Bytes in Box

						filePos.position = myFile.tellg();

						//cout << "Adding bytes to determine box size -- this is byte # " << ibyte << endl;
						unsigned int uInt = (int)  cuCharRead;

						double weAdded=0; 

						if (ibyte == 4)
							weAdded =  Byte2Decimal_perByte( uInt, 7 );
						else if (ibyte == 3)
							weAdded =  Byte2Decimal_perByte( uInt, 15 );
						else if (ibyte == 2)
							weAdded =  Byte2Decimal_perByte( uInt, 23 );
						else if (ibyte == 1)
							weAdded =  Byte2Decimal_perByte( uInt, 31 );

						dNumBytesInBox = dNumBytesInBox + weAdded;

						//PrintCurrentByte_inBinary( cuCharRead, filePos.positionTemp);
					}

 					cout << "Found box of type " << Type << " and size " << dNumBytesInBox << endl;

				//*****    .-. .-. .-. .-. .-. .-. .-. .-. .-. . . 
				//*****    |(  |-  |-' | | `-.  |   |   |  | | |\| 
				//*****    ' ' `-' '   `-' `-' `-'  '  `-' `-' ' ` 
				//*****----------------------------------------------- Move back to original filePos.position after Type  
				myFile.seekg(filePos.positionAfterType); 

				//*************************** done with this box, now clear out & start over
				iNumContigCharsFound = 0;
				filePos.positionLastAlphaFound = filePos.positionAlphaFound; // still valid since there was a char, just not contig
				index = 0;
				cStoredBoxType = szAllTypes[0];
				cTypeRead = Type;
				iLetter = MAX_LETTERS_BOXTYPE; // For counting backwards when comparing all the letters in type 
				foundRealBox = false;		
				is_equal = 999;

				filePos.position = filePos.positionAfterType;
				//cout << "\nYou found a VALID Box Type!\n"; 
				} // end if foundRealBoxd = true
			} // end if 4 letters in a row
		} // end  if Letter? 

		iCurrentByte++;
	} 
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//&&&&&           END of While Loop for Reading Bytes      &&&&&
	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&	
	cout << "\n#####################################################################################\n";
	cout << "#####     dPTTb8 88      dP'Yb  .dP'Y8 888888 8888b.      888888 88 88     888888  ##\n"; 
	cout << "#####    dP   `  88     dP   Yb `Ybo.' 88__    8I  Yb     88__   88 88     88__    ##\n";
	cout << "#####    Yb      88  .o Yb   dP o.`Y8b 88TT    8I  dY     88TT   88 88  .o 88TT    ##\n";
	cout << "#####     .boodP 88ood8  YbodP  8bodP' 888888 8888Y'      88     88 88ood8 888888  ##\n";
	cout << "#####oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo##\n";

	myFile.close();
	cout << "\nTOTAL NUMBER OF BOXES FOUND = " << iNumBoxesFound << endl << endl;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout << "$$$                                                       $$$\n";
    cout << "$$$   #######                  ####### #     # ######     $$$\n";
    cout << "$$$      #    #    # ######    #       ##    # #     #    $$$\n";
    cout << "$$$      #    #    # #         #       # #   # #     #    $$$\n";
    cout << "$$$      #    ###### #####     #####   #  #  # #     #    $$$\n";
    cout << "$$$      #    #    # #         #       #   # # #     #    $$$\n";
    cout << "$$$      #    #    # #         #       #    ## #     #    $$$\n";
    cout << "$$$      #    #    # ######    ####### #     # ######     $$$\n";
    cout << "$$$                                                       $$$\n";
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

	cout << "\nPress the ANY Key and <ENTER> to Continue.\n";

    cin >> cuCharRead;
	return 0;

	} 
