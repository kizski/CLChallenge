#include "stdafx.h"
#include <stdio.h>
#include "box.h"

#define MAX_LETTERS_BOXTYPE 4

using namespace std;


//___________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&           __   __          __             __   __       &&&&&
//&&&&&          |__) /  \ \_/    /  ` |     /\  /__` /__`      &&&&&
//&&&&&          |__) \__/ / \    \__, |___ /~~\ .__/ .__/      &&&&&
//&&&&&______________________ METHODS __________________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


//*******************************************************
//** .-. .-. . . .-. .-. .-. . . .-. .-. .-. .-.      ***
//** |   | | |\| `-.  |  |(  | | |    |  | | |(       ***
//** `-' `-' ' ` `-'  '  ' ' `-' `-'  '  `-' ' '      ***
//** with Default Parameters for Complete Definition  ***  kep
//*******************************************************

Box::Box( char * inB_szBoxType = "dflt", int inB_iLengthOf_inB_szBoxType = MAX_LETTERS_BOXTYPE, int inB_iBoxSize_bytes = 0 ) : BoxType( inB_szBoxType, inB_iLengthOf_inB_szBoxType )
{
	//******************** Initialize members 

	//kep - may not work in linux, need to revert to char *'s 
	m_iBoxSizeInBytes	= inB_iBoxSize_bytes;
	string mystring(inB_szBoxType);
	const char * temp = mystring.c_str();
	mSzBoxType = _strdup(temp);
}

//*******************************************************
//**    _, __, ___ __,  _, _  , ___ , _ __, __, / \   ***
//**   / _ |_   |  |_) / \ '\/   |  \ | |_) |_  | |   ***
//**   \ / |    |  |_) \ /  /\   |   \| |   |   | |   ***
//**    ~  ~~~  ~  ~    ~  ~  ~  ~    ) ~   ~~~ \ /   ***
//**_____________________________________________________

// INHERITED

char * Box::GetBoxType()
{
	//char * temp = new char[ MAX_ALLOCATE_BOXTYPE ];

	// this would go in set boxtype
	//	strcpy_s( temp, m_LettersIn_mSzBoxType, mSzBoxType);

	return mSzBoxType;
	//****kep need to delete! 
}
