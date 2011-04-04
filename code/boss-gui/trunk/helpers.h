/*	General User Interface for BOSS (Better Oblivion Sorting Software)
	
	Providing a graphical frontend to BOSS's functions.

    Copyright (C) 2011 WrinklyNinja & the BOSS development team.
    http://creativecommons.org/licenses/by-nc-nd/3.0/

	$Revision: 2188 $, $Date: 2011-01-20 10:05:16 +0000 (Thu, 20 Jan 2011) $
*/

//Header file for some functions that are helpful or required for the GUI to work,
//but not actually GUI-based.

/*Libraries to include: 
For wxWidgets:
wxmsw29u_core.lib
wxbase29u.lib
comctl32.lib
rpcrt4.lib

For Curl:
libcurl.lib
wldap32.lib
ws2_32.lib

Other:
Version.lib
*/

#ifndef __HELPERS__HPP__
#define __HELPERS__HPP__

#ifndef _UNICODE
#define _UNICODE	// Tell compiler we're using Unicode, notice the _
#endif

#include <string>
#include "boost/filesystem.hpp"

namespace boss {
	using namespace std;
	namespace fs = boost::filesystem;

	//Version info.
	extern const string gui_version;
	extern const string gui_releaseDate;

	//Run type
	//The run type decides on which variables are applied, not all are appropriate for all run types.
	extern int run;				// 1 = sort mods, 2 = only update, 3 = undo changes.
	extern int format;			// what format the output should be in. 0 = HTML, 1 = plaintext.
	extern int verbosity;		// Command-line output verbosity.
	extern int game;			// Force what game? 0 = allow autodetection, 1 = Oblivion, 2 = Fallout 3, 3 = Nehrim, 4 = Fallout: New Vegas.
	extern int revert;			// what level to revert to
	extern bool showLog;		// Suppress BOSSlog opening?
	extern bool debug;			// Display debug info?
	extern bool update;			// update the masterlist
	extern bool showVersions;	// enable parsing of mod's headers to look for version strings
	extern bool showCRCs;		// whether or not to show mod CRCs.
	extern bool logCL;			// whether or not to log the command line output to BOSSDebugLog.txt.
	

	//Returns the name of the game that BOSS is currently running for.
	string GetGame();

	//Runs BOSS with arguments according to the settings of the run variables.
	void RunBOSS();

	//Opens the given file in the default system program.
	void OpenInSysDefault(fs::path& file);

	//Converts an integer to a string using BOOST's Spirit.Karma. Faster than a stringstream conversion.
	string IntToString(unsigned int n);

	//Get BOSS's version.
	int GetBOSSVersion();

	//Exception class for update checker.
	struct update_error: virtual exception, virtual boost::exception {};
	typedef boost::error_info<struct tag_errno,string> err_detail;

	//Checks if an update is available or not for the given item.
	//Valid items are 'BOSS', 'BOSS-GUI' and 'masterlist'.
	string IsUpdateAvailable(string subject);
}
#endif