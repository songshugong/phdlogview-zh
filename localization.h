#ifndef PHDLOGVIEW_LOCALIZATION_H
#define PHDLOGVIEW_LOCALIZATION_H

#include <wx/string.h>

enum class AppLanguage
{
    English,
    SimplifiedChinese,
    French,
};

void InitAppLanguage();
AppLanguage GetAppLanguage();
wxString GetAppLanguageCode();
void SetAppLanguage(AppLanguage lang);

wxString L10n(const wxString& zh, const wxString& en, const wxString& fr);
wxString TranslateLogText(wxString s);

#endif
