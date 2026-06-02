#include "localization.h"

#include "LogViewApp.h"

static AppLanguage s_language = AppLanguage::SimplifiedChinese;

void InitAppLanguage()
{
    wxString code = Config ? Config->Read("/Language", "zh-Hans") : "zh-Hans";
    if (code == "en")
        s_language = AppLanguage::English;
    else if (code == "fr")
        s_language = AppLanguage::French;
    else
        s_language = AppLanguage::SimplifiedChinese;
}

AppLanguage GetAppLanguage()
{
    return s_language;
}

wxString GetAppLanguageCode()
{
    switch (s_language)
    {
    case AppLanguage::English:
        return "en";
    case AppLanguage::French:
        return "fr";
    default:
        return "zh-Hans";
    }
}

void SetAppLanguage(AppLanguage lang)
{
    s_language = lang;
    if (Config)
    {
        Config->Write("/Language", GetAppLanguageCode());
        Config->Flush();
    }
}

wxString L10n(const wxString& zh, const wxString& en, const wxString& fr)
{
    switch (s_language)
    {
    case AppLanguage::English:
        return en;
    case AppLanguage::French:
        return fr;
    default:
        return zh;
    }
}

wxString TranslateLogText(wxString s)
{
    struct Replacement
    {
        const wxChar *from;
        const wxChar *zh;
        const wxChar *fr;
    };

    static const Replacement replacements[] = {
        { wxT("Guiding Begins at"), wxT("导星开始时间"), wxT("Début du guidage") },
        { wxT("Calibration Begins at"), wxT("校准开始时间"), wxT("Début de la calibration") },
        { wxT("Calibration complete"), wxT("校准完成"), wxT("Calibration terminée") },
        { wxT("Guiding Ends"), wxT("导星结束"), wxT("Fin du guidage") },
        { wxT("Equipment Profile"), wxT("设备配置"), wxT("Profil d'équipement") },
        { wxT("Dither scale"), wxT("抖动比例"), wxT("Échelle de dithering") },
        { wxT("Dither"), wxT("抖动"), wxT("Dithering") },
        { wxT("both axes"), wxT("双轴"), wxT("deux axes") },
        { wxT("RA only"), wxT("仅 RA"), wxT("RA seulement") },
        { wxT("Image noise reduction"), wxT("图像降噪"), wxT("Réduction du bruit") },
        { wxT("Guide-frame time lapse"), wxT("导星帧延时"), wxT("Délai entre images de guidage") },
        { wxT("Server enabled"), wxT("服务器已启用"), wxT("Serveur activé") },
        { wxT("Server disabled"), wxT("服务器已禁用"), wxT("Serveur désactivé") },
        { wxT("Pixel scale"), wxT("像素比例"), wxT("Échantillonnage") },
        { wxT("Binning"), wxT("合并像素"), wxT("Binning") },
        { wxT("Focal length"), wxT("焦距"), wxT("Longueur focale") },
        { wxT("Search region"), wxT("搜索区域"), wxT("Zone de recherche") },
        { wxT("Star mass tolerance"), wxT("星点亮度容差"), wxT("Tolérance de masse stellaire") },
        { wxT("Multi-star mode"), wxT("多星模式"), wxT("Mode multi-étoiles") },
        { wxT("single-star mode"), wxT("单星模式"), wxT("Mode étoile unique") },
        { wxT("list size"), wxT("列表数量"), wxT("taille de liste") },
        { wxT("Camera"), wxT("相机"), wxT("Caméra") },
        { wxT("full size"), wxT("全幅尺寸"), wxT("taille complète") },
        { wxT("have dark"), wxT("有暗场"), wxT("dark disponible") },
        { wxT("no dark"), wxT("无暗场"), wxT("pas de dark") },
        { wxT("dark dur"), wxT("暗场曝光"), wxT("durée du dark") },
        { wxT("no defect map"), wxT("无坏点图"), wxT("pas de carte de défauts") },
        { wxT("have defect map"), wxT("有坏点图"), wxT("carte de défauts disponible") },
        { wxT("pixel size"), wxT("像元尺寸"), wxT("taille des pixels") },
        { wxT("Exposure"), wxT("曝光"), wxT("Exposition") },
        { wxT("Mount"), wxT("赤道仪"), wxT("Monture") },
        { wxT("connected"), wxT("已连接"), wxT("connecté") },
        { wxT("disconnected"), wxT("未连接"), wxT("déconnecté") },
        { wxT("guiding enabled"), wxT("导星已启用"), wxT("guidage activé") },
        { wxT("guiding disabled"), wxT("导星已禁用"), wxT("guidage désactivé") },
        { wxT("parity"), wxT("方向奇偶性"), wxT("parité") },
        { wxT("Norm rates RA"), wxT("标准速率 RA"), wxT("Vitesses nominales RA") },
        { wxT("ortho.err."), wxT("正交误差"), wxT("erreur ortho.") },
        { wxT("X guide algorithm"), wxT("X 轴导星算法"), wxT("Algorithme de guidage X") },
        { wxT("Y guide algorithm"), wxT("Y 轴导星算法"), wxT("Algorithme de guidage Y") },
        { wxT("Hysteresis"), wxT("滞后"), wxT("Hystérésis") },
        { wxT("Resist Switch"), wxT("抗切换"), wxT("Résistance au basculement") },
        { wxT("Predictive PEC"), wxT("预测 PEC"), wxT("PEC prédictif") },
        { wxT("Minimum move"), wxT("最小移动"), wxT("Mouvement minimal") },
        { wxT("Aggression"), wxT("激进度"), wxT("Agressivité") },
        { wxT("FastSwitch"), wxT("快速切换"), wxT("Basculement rapide") },
        { wxT("Backlash comp"), wxT("回差补偿"), wxT("Compensation du jeu") },
        { wxT("pulse"), wxT("脉冲"), wxT("impulsion") },
        { wxT("Max RA duration"), wxT("RA 最大脉冲"), wxT("Durée RA max") },
        { wxT("Max DEC duration"), wxT("Dec 最大脉冲"), wxT("Durée Dec max") },
        { wxT("DEC guide mode"), wxT("Dec 导星模式"), wxT("Mode de guidage Dec") },
        { wxT("RA Guide Speed"), wxT("RA 导星速率"), wxT("Vitesse de guidage RA") },
        { wxT("Dec Guide Speed"), wxT("Dec 导星速率"), wxT("Vitesse de guidage Dec") },
        { wxT("Cal Dec"), wxT("校准 Dec"), wxT("Dec de calibration") },
        { wxT("Last Cal Issue"), wxT("最近校准问题"), wxT("Dernier problème de calibration") },
        { wxT("Timestamp"), wxT("时间戳"), wxT("Horodatage") },
        { wxT("Hour angle"), wxT("时角"), wxT("Angle horaire") },
        { wxT("Pier side"), wxT("中天侧"), wxT("Côté du pilier") },
        { wxT("Rotator pos"), wxT("旋转器位置"), wxT("Position du rotateur") },
        { wxT("Lock position"), wxT("锁定位置"), wxT("Position de verrouillage") },
        { wxT("Star position"), wxT("星点位置"), wxT("Position de l'étoile") },
        { wxT("Settling complete"), wxT("稳定完成"), wxT("Stabilisation terminée") },
        { wxT("Settling started"), wxT("开始稳定"), wxT("Stabilisation démarrée") },
        { wxT("Settling start"), wxT("开始稳定"), wxT("Début de stabilisation") },
        { wxT("Settling failed"), wxT("稳定失败"), wxT("Échec de stabilisation") },
        { wxT("Settling fail"), wxT("稳定失败"), wxT("Échec de stabilisation") },
        { wxT("DITHER by"), wxT("抖动位移"), wxT("Dithering de") },
        { wxT("DITHER"), wxT("抖动"), wxT("Dithering") },
        { wxT("SET LOCK POS"), wxT("设置锁定位置"), wxT("Définir position verrouillée") },
        { wxT("Timestamp jumped backwards"), wxT("时间戳回跳"), wxT("Horodatage revenu en arrière") },
        { wxT("Frame dropped"), wxT("帧丢失"), wxT("Image perdue") },
        { wxT("Guiding parameter change"), wxT("导星参数变化"), wxT("Changement de paramètre de guidage") },
        { wxT("Star lost"), wxT("丢星"), wxT("Étoile perdue") },
        { wxT("enabled"), wxT("已启用"), wxT("activé") },
        { wxT("disabled"), wxT("已禁用"), wxT("désactivé") },
        { wxT("Auto"), wxT("自动"), wxT("Auto") },
        { wxT("None"), wxT("无"), wxT("Aucun") },
        { wxT("none"), wxT("无"), wxT("aucun") },
        { wxT("West"), wxT("西侧"), wxT("Ouest") },
        { wxT("East"), wxT("东侧"), wxT("Est") },
    };

    if (s_language == AppLanguage::English)
        return s;

    for (const auto& r : replacements)
        s.Replace(r.from, s_language == AppLanguage::French ? r.fr : r.zh, true);
    return s;
}
