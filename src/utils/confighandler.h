// Copyright(c) 2017-2019 Alejandro Sirgo Rica & Contributors
//
// This file is part of Flameshot.
//
//     Flameshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Flameshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Flameshot.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "src/widgets/capture/capturetoolbutton.h"
#include <QSettings>
#include <QStringList>
#include <QVariant>
#include <QVector>

class ConfigHandler
{
public:
    explicit ConfigHandler();

    QVector<CaptureToolButton::ButtonType> getButtons();
    void setButtons(const QVector<CaptureToolButton::ButtonType>&);

    QVector<QColor> getUserColors();

    QString savePath();
    void setSavePath(const QString&);

    bool savePathFixed();
    void setSavePathFixed(bool);

    QColor uiMainColorValue();
    void setUIMainColor(const QColor&);

    QColor uiContrastColorValue();
    void setUIContrastColor(const QColor&);

    QColor drawColorValue();
    void setDrawColor(const QColor&);

    bool showHelpValue();
    void setShowHelp(const bool);

    bool showSidePanelButtonValue();
    void setShowSidePanelButton(const bool);

    bool desktopNotificationValue();
    void setDesktopNotification(const bool);

    QString filenamePatternValue();
    void setFilenamePattern(const QString&);

    bool disabledTrayIconValue();
    void setDisabledTrayIcon(const bool);

    int drawThicknessValue();
    void setDrawThickness(const int);

    bool keepOpenAppLauncherValue();
    void setKeepOpenAppLauncher(const bool);

    bool checkForUpdates();
    void setCheckForUpdates(const bool);

    bool verifyLaunchFile();
    bool startupLaunchValue();
    void setStartupLaunch(const bool);

    bool showStartupLaunchMessage();
    void setShowStartupLaunchMessage(const bool);

    int contrastOpacityValue();
    void setContrastOpacity(const int);

    bool copyAndCloseAfterUploadEnabled();
    void setCopyAndCloseAfterUploadEnabled(const bool);
    bool historyConfirmationToDelete();
    void setHistoryConfirmationToDelete(const bool save);
    bool saveAfterCopyValue();
    void setSaveAfterCopy(const bool);

    bool copyPathAfterSaveEnabled();
    void setCopyPathAfterSaveEnabled(const bool);

    bool useJpgForClipboard() const;
    void setUseJpgForClipboard(const bool);

    void setDefaultSettings();
    void setAllTheButtons();

    void setIgnoreUpdateToVersion(const QString& text);
    QString ignoreUpdateToVersion();

    QVector<QStringList> shortcuts();
    void setShortcutsDefault();
    bool setShortcut(const QString&, const QString&);
    const QString& shortcut(const QString&);

    QString configFilePath() const;

    void setValue(const QString& group,
                  const QString& key,
                  const QVariant& value);
    QVariant& value(const QString& group, const QString& key);

private:
    QString m_strRes;
    QVariant m_varRes;
    QSettings m_settings;
    QVector<QStringList> m_shortcuts;

    bool normalizeButtons(QVector<int>&);

    QVector<CaptureToolButton::ButtonType> fromIntToButton(
      const QVector<int>& l);
    QVector<int> fromButtonToInt(
      const QVector<CaptureToolButton::ButtonType>& l);
};
