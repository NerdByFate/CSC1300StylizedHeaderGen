//this file is part of notepad++
//Copyright (C)2003 Don HO <donho@altern.org>
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "PluginDefinition.h"
#include "menuCmdID.h"

FuncItem funcItem[nbFunc];

NppData nppData;

void pluginInit(HANDLE /*hModule*/)
{
}

void pluginCleanUp()
{
}

void commandMenuInit()
{
	ShortcutKey* _sKey = new ShortcutKey;
	_sKey->_isAlt = true;
	_sKey->_isCtrl = false;
	_sKey->_isShift = false;
	_sKey->_key = 0x48; //h ASCII hex
	
	setCommand(0, TEXT("CSC1300 Stylized Header Gen"), outputStylizedHeader, _sKey, false);
}

void commandMenuCleanUp()
{
	delete(funcItem[0]._pShKey);
}

bool setCommand(size_t index, TCHAR *cmdName, PFUNCPLUGINCMD pFunc, ShortcutKey *sk, bool check0nInit) 
{
    if (index >= nbFunc)
        return false;

    if (!pFunc)
        return false;

    lstrcpy(funcItem[index]._itemName, cmdName);
    funcItem[index]._pFunc = pFunc;
    funcItem[index]._init2Check = check0nInit;
    funcItem[index]._pShKey = sk;

    return true;
}

void outputStylizedHeader()
{
    //Get the current scintilla
    int which = -1;
    ::SendMessage(nppData._nppHandle, NPPM_GETCURRENTSCINTILLA, 0, (LPARAM)&which);
    if (which == -1)
        return;
    HWND curScintilla = (which == 0)?nppData._scintillaMainHandle:nppData._scintillaSecondHandle;
	
	//Get the current time
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	//Get the name of the open file
	TCHAR fileName[MAX_PATH];
	::SendMessage(nppData._nppHandle, NPPM_GETFILENAME, 0, (LPARAM)fileName);
	int encoding = (int)::SendMessage(curScintilla, SCI_GETCODEPAGE, 0, 0);
	char fileNameC[MAX_PATH];
	WideCharToMultiByte(encoding, 0, fileName, -1, fileNameC, MAX_PATH, NULL, NULL);

    //Scintilla control has no Unicode mode, so we use (char *) here
    ::SendMessage(curScintilla, SCI_SETTEXT, 0, ((LPARAM)("/*\n\tTitle:   " + (std::string)fileNameC + "\n\tAuthor:  Cherokee Parker\n\tDate:    " + getMonth(now->tm_mon) + " " + std::to_string(now->tm_mday) + ", " + std::to_string(now->tm_year + 1900) + "\n\tPurpose: \n*/").c_str()));
}

std::string getMonth(int asInt) {
	switch (asInt) {
	case 0:
		return "January";
		break;
	case 1:
		return "February";
		break;
	case 2:
		return "March";
		break;
	case 3:
		return "April";
		break;
	case 4:
		return "May";
		break;
	case 5:
		return "June";
		break;
	case 6:
		return "July";
		break;
	case 7:
		return "August";
		break;
	case 8:
		return "September";
		break;
	case 9:
		return "October";
		break;
	case 10:
		return "November";
		break;
	default:
		return "ERROR";
	}
}
