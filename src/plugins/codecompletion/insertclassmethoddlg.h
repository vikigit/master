#ifndef INSERTCLASSMETHODDLG_H
#define INSERTCLASSMETHODDLG_H

#include <wx/arrstr.h>
#include <wx/dialog.h>
#include <wx/string.h>

class Parser;
class Token;
class wxCheckListBox;
class wxCommandEvent;

class InsertClassMethodDlg : public wxDialog
{
	public:
		InsertClassMethodDlg(wxWindow* parent, Parser* parser, const wxString& filename);
		virtual ~InsertClassMethodDlg();

        wxArrayString GetCode() const; // return an array of checked methods
	private:
        void FillClasses();
        void FillMethods();
        void DoFillMethodsFor(wxCheckListBox* clb,
                                Token* parentToken,
                                const wxString& ns,
                                bool includePrivate,
                                bool includeProtected,
                                bool includePublic);
        void OnClassesChange(wxCommandEvent& event);
        void OnCodeChange(wxCommandEvent& event);
        void OnFilterChange(wxCommandEvent& event);
s
        Parser* m_pParser;
        bool m_Decl;
        wxString m_Filename;
        DECLARE_EVENT_TABLE();
};

#endif // INSERTCLASSMETHODDLG_H

