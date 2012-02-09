/*	Better Oblivion Sorting Software
	
	A "one-click" program for users that quickly optimises and avoids 
	detrimental conflicts in their TES IV: Oblivion, Nehrim - At Fate's Edge, 
	TES V: Skyrim, Fallout 3 and Fallout: New Vegas mod load orders.

    Copyright (C) 2009-2011    BOSS Development Team.

	This file is part of Better Oblivion Sorting Software.

    Better Oblivion Sorting Software is free software: you can redistribute 
	it and/or modify it under the terms of the GNU General Public License 
	as published by the Free Software Foundation, either version 3 of 
	the License, or (at your option) any later version.

    Better Oblivion Sorting Software is distributed in the hope that it will 
	be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Better Oblivion Sorting Software.  If not, see 
	<http://www.gnu.org/licenses/>.

	$Revision: 3184 $, $Date: 2011-08-26 20:52:13 +0100 (Fri, 26 Aug 2011) $
*/

#include "Common/Globals.h"

namespace boss {
	using namespace std;

	BOSS_COMMON_EXP const string boss_release_date = "X Y 2012";

	BOSS_COMMON_EXP fs::path data_path			= fs::path("..") / "Data";
	BOSS_COMMON_EXP const fs::path boss_path			= fs::path(".");
	BOSS_COMMON_EXP const fs::path bosslog_html_path	= boss_path / "BOSSlog.html";
	BOSS_COMMON_EXP const fs::path bosslog_text_path	= boss_path / "BOSSlog.txt";
	BOSS_COMMON_EXP fs::path masterlist_path	= boss_path / "masterlist.txt";
	BOSS_COMMON_EXP fs::path userlist_path		= boss_path / "userlist.txt";
	BOSS_COMMON_EXP const fs::path curr_modlist_path	= boss_path / "modlist.txt";
	BOSS_COMMON_EXP const fs::path prev_modlist_path	= boss_path / "modlist.old";
	BOSS_COMMON_EXP const fs::path ini_path			= boss_path / "BOSS.ini";
	BOSS_COMMON_EXP const fs::path debug_log_path		= boss_path / "BOSSDebugLog.txt";

	//Command line variables
	BOSS_COMMON_EXP string proxy_host		= "none";
	BOSS_COMMON_EXP string proxy_user		= "";
	BOSS_COMMON_EXP string proxy_passwd		= "";
	BOSS_COMMON_EXP uint32_t proxy_port			= 0;
	BOSS_COMMON_EXP uint32_t log_format		= HTML;	// what format the output should be in.
	BOSS_COMMON_EXP uint32_t game				= AUTODETECT;		// What game's mods are we sorting? 1 = Oblivion, 2 = Fallout 3, 3 = Nehrim, 4 = Fallout: New Vegas, 5 = Skyrim.
	BOSS_COMMON_EXP uint32_t revert              = 0;		// what level to revert to
	BOSS_COMMON_EXP uint32_t debug_verbosity     = 0;		// log levels above INFO to output
	BOSS_COMMON_EXP bool update				= true;		// update the masterlist?
	BOSS_COMMON_EXP bool update_only        = false;	// only update the masterlist and don't sort currently.
	BOSS_COMMON_EXP bool silent             = false;	// silent mode?
	BOSS_COMMON_EXP bool skip_version_parse = false;	// enable parsing of mod's headers to look for version strings
	BOSS_COMMON_EXP bool debug_with_source  = false;	// whether to include origin information in logging statements
	BOSS_COMMON_EXP bool show_CRCs			= false;	// whether or not to show mod CRCs.
	BOSS_COMMON_EXP bool trial_run			= false;	// If true, don't redate files.
	BOSS_COMMON_EXP bool log_debug_output		= false;  //If true, logs the Logger output in BOSSDebugLog.txt.
	BOSS_COMMON_EXP bool do_startup_update_check	= true;	// Whether or not to check for updates on startup.

	//GUI variables
	BOSS_COMMON_EXP uint32_t run_type					= 1;  // 1 = sort mods, 2 = only update, 3 = undo changes.
	BOSS_COMMON_EXP bool use_user_rules_editor		= false;		//Use the User Rules Editor or edit userlist.txt directly?
}