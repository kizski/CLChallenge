// Box.h

#include "BoxType.h"


//___________________________________________________________________
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&           __   __          __             __   __       &&&&&
//&&&&&          |__) /  \ \_/    /  ` |     /\  /__` /__`      &&&&&
//&&&&&          |__) \__/ / \    \__, |___ /~~\ .__/ .__/      &&&&&
//&&&&&______________________ DECLARATION ______________________&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

class Box : public BoxType 
{
	protected:
		int		m_iBoxSizeInBytes;  // The value of Box Size is read from the input video file (text
									//     preceding the bytes that define the box type
		char * mSzBoxType;  

	public:
		//*************************************************
		//   ,--. .                   .-,--.  .          **
		//  | `-' |- ,-. ,-.   ,.     ' |   \ |- ,-. ,-. **
		//  |   . |  | | |     >-:,   , |   / |  | | |   **
		//  `--'  `' `-' '     `-'`   `-^--'  `' `-' '   **
		//*************************************************   
		Box(  char *, int, int );

		~Box()
		{
			//cout << "\nIn Box Class Dtor\n";
		}
		//*************************************************
		//**    ,,--. .  .            .-,--'             ** 
		//**    |`, | |- |-. ,-. ,-.   \|__ ,-. ,-.      **
		//**    |   | |  | | |-' |      |   | | `-.      **
		//**    `---' `' ' ' `-' '     `'   ' ' `-'      **
		//*************************************************
		
		// ******************************************* getSize()
		//kep	int GetLength_InBytes() const  --- use const? 
		int GetLength_InBytes() 
		{	return m_iBoxSizeInBytes;	}

		// ******************************************** getType()
		//kep		char * GetBoxType() const
		char * GetBoxType();

};