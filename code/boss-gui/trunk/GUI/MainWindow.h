/*	General User Interface for BOSS (Better Oblivion Sorting Software)
	
	Providing a graphical frontend to BOSS's functions.

    Copyright (C) 2011 WrinklyNinja & the BOSS development team.
    http://creativecommons.org/licenses/by-nc-nd/3.0/

	$Revision: 2188 $, $Date: 2011-01-20 10:05:16 +0000 (Thu, 20 Jan 2011) $
*/

#ifndef __MAIN__HPP__
#define __MAIN__HPP__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#       include "wx/wx.h"
#endif

#include <wx/hyperlink.h>
#include <wx/progdlg.h>
#include <wx/thread.h>

//Main frame class.
class MainFrame : public wxFrame {
public:
	MainFrame(const wxChar *title, int x, int y, int width, int height);
	void Update(std::string updateVersion);
	void OnOpenSettings(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
	void OnRunBOSS(wxCommandEvent& event);
	void OnOpenFile(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnRunTypeChange(wxCommandEvent& event);
	void OnFormatChange(wxCommandEvent& event);
	void OnGameChange(wxCommandEvent& event);
	void OnRevertChange(wxCommandEvent& event);
	void OnLogDisplayChange(wxCommandEvent& event);
	void OnUpdateChange(wxCommandEvent& event);
	void OnVersionDisplayChange(wxCommandEvent& event);
	void OnCRCDisplayChange(wxCommandEvent& event);
	void OnTrialRunChange(wxCommandEvent& event);
	void OnUpdateCheck(wxCommandEvent& event);
	void OnEditUserRules(wxCommandEvent& event);
	void OnClose(wxCloseEvent& event);
	DECLARE_EVENT_TABLE()
private:
	wxMenuBar *MenuBar;
	wxMenu *FileMenu;
	wxMenu *EditMenu;
	wxMenu *HelpMenu;
	wxButton *RunBOSSButton;
	wxButton *OpenBOSSlogButton;
	wxButton *EditUserRulesButton;
	wxCheckBox *ShowLogBox;
	wxCheckBox *VersionBox;
	wxCheckBox *CRCBox;
	wxCheckBox *UpdateBox;
	wxCheckBox *TrialRunBox;
	wxChoice *FormatChoice;
	wxChoice *GameChoice;
	wxChoice *RevertChoice;
	wxRadioButton *SortOption;
	wxRadioButton *UpdateOption;
	wxRadioButton *UndoOption;
	wxStaticText *GameText;
	wxStaticText *RevertText;
};

//Program class.
class BossGUI : public wxApp {
public:
	virtual bool OnInit();
	void CheckForUpdate(MainFrame *frame);
};
#endif