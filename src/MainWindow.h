#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include <QTimer>
#include <QNetworkInformation>
#include <QMap>
#include <QDateTime>

#include "TailRunner.h"
#include "TailSettings.h"
#include "TrayMenuManager.h"
#include "AccountsTabUiManager.h"
#include "TailFileReceiver.h"
#include "./ui_MainWindow.h"
#include "NetworkStateMonitor.h"

class AccountsTabUiManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

    void showSettingsTab();
    void showAccountsTab();
    void showAboutTab();
    void showNetworkStatusTab();

    void syncSettingsToUi() const;
    void syncSettingsFromUi();

    void userLoggedOut() { changeToState(TailState::NotLoggedIn); }

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<AccountsTabUiManager> accountsTabUi;
    std::unique_ptr<TrayMenuManager> pTrayManager;
    std::unique_ptr<TailRunner> pCurrentExecution;
    std::unique_ptr<TailStatus> pTailStatus;
    std::unique_ptr<TailFileReceiver> pFileReceiver;
    std::unique_ptr<NetworkStateMonitor> pNetworkStateMonitor;

    TailState eCurrentState;
    TailSettings settings;
    QList<TailAccountInfo> accounts;

    QMap<QString, QDateTime> seenWarnings;

private slots:
    void onAccountsListed(const QList<TailAccountInfo>& foundAccounts);
    void settingsClosed();
    void loginFlowCompleted() const;
    void onNetworkReachabilityChanged(QNetworkInformation::Reachability newReachability);

    void drivesListed(const QList<TailDriveInfo>& drives, bool error, const QString& errorMsg) const;

    // Tail drive
    void addTailDriveButtonClicked() const;
    void removeTailDriveButtonClicked() const;
    void selectTailDriveMountPath() const;
    void fixTailDriveDavFsSetup() const;

    // Send file
    void fileSentToDevice(bool success, const QString& errorMsg, void* userData) const;
    void startListeningForIncomingFiles();
    void onTailnetFileReceived(QString filePath) const;
    void onShowTailFileSaveLocationPicker();

    // Network reports
    void netCheckCompleted(bool success, const QMap<QString, QString>& results, QList<QPair<QString, float>>& latencies) const;

private:
    // Switch to the new state and return the prev (old) state back to caller
    TailState changeToState(TailState newState);
    void onTailStatusChanged(TailStatus* pNewStatus);

    static bool shallowCheckForNetworkAvailable();
    void setupNetworkCallbacks() const;

    [[nodiscard]] static bool isTailDriveFileAlreadySetup();
    void tailDrivesToUi() const;

protected:
    void showEvent(QShowEvent *event) override;
};

#endif // MAINWINDOW_H