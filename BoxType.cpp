#include "stdafx.h"
#include <iostream>
#include "box.h"

#define MAX_LETTERS_BOXTYPE 4

using namespace std;
//___________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&  .__ .__.\  /  .___..   ,.__ .___   __ .   .__. __. __. &&&&&
//&&&&&  [__)|  | ><     |   \./ [__)[__   /  `|   [__](__ (__  &&&&&
//&&&&&  [__)|__|/  \    |    |  |   [___  \__.|___|  |.__).__) &&&&&
//&&&&&                       METHODS                           &&&&&
//&&&&&_________________________________________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//******************************************************
//**    .-. .-. . . .-. .-. .-. . . .-. .-. .-. .-.  ***
//**    |   | | |\| `-.  |  |(  | | |    |  | | |(   ***
//**    `-' `-' ' ` `-'  '  ' ' `-' `-'  '  `-' ' '  ***
//******************************************************    
BoxType::BoxType( char * in_szType="dflt", int in_szType_Len=4 ) 
{
		//******************** Get length of string passed in 
	int iLen =  static_cast< int >( strlen( in_szType ) );
	if (iLen > MAX_LETTERS_BOXTYPE) cerr << "Box Type name length is too long, truncating\n";

	//******************** Check to make sure length of string passed ! > the # chars allocated for the member string
	if (in_szType_Len > MAX_LETTERS_BOXTYPE || in_szType_Len <= 0 ) 
	{
		cerr << "\n<< ERROR >> # Letters in BoxType must be >0 and < " <<  MAX_LETTERS_BOXTYPE  << endl;
		cerr << "     Box Type name length passed to Box Type Ctor = " << in_szType_Len << endl << endl;
		cerr << "Setting to " << MAX_LETTERS_BOXTYPE << endl;
		
		m_LettersIn_mSzBoxType = iLen;
	}
	else 
		m_LettersIn_mSzBoxType = in_szType_Len;
		
	//******************************************************
	//****************************************************** Now do the assignment

	mSzBoxType = new char[m_LettersIn_mSzBoxType];
	
	string mystring(in_szType);

	const char * temp = mystring.c_str();
	mSzBoxType = _strdup(temp);

}


//*******************************************************
//**      .-. .-. .-. .-. .-. . . .-. .-. .-. .-      ***
//**      |  )|-  `-.  |  |(  | | |    |  | | |(      ***
//**      `-' `-' `-'  '  ' ' `-' `-'  '  `-' ' '     ***
//******************************************************* 

BoxType::~BoxType()
{
	delete [] mSzBoxType; 
}