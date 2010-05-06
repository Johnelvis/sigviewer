#ifndef MAIN_WINDOW_MODEL_IMPL_H
#define MAIN_WINDOW_MODEL_IMPL_H

#include "base/user_types.h"
#include "file_context.h"
#include "tab_context.h"
#include "file_handling/event_manager.h"
#include "file_handling/channel_manager.h"
#include "gui/signal_visualisation_model.h"
#include "gui/main_window_model.h"

#include <QObject>
#include <QStringList>
#include <QString>
#include <QSharedPointer>
#include <QTabWidget>

#include <map>

class QAction;

namespace BioSig_
{

class MainWindow;

//-------------------------------------------------------------------------
class MainWindowModelImpl : public QObject, public MainWindowModel
{
    Q_OBJECT
public:
    //-------------------------------------------------------------------------
    MainWindowModelImpl ();

    //-------------------------------------------------------------------------
    virtual  ~MainWindowModelImpl() {}

    void setMainWindow(MainWindow* main_window);
    void loadSettings();
    void saveSettings();

    //-------------------------------------------------------------------------
    virtual QSharedPointer<SignalVisualisationModel> createSignalVisualisation (QSharedPointer<ChannelManager> channel_manager);

    //-------------------------------------------------------------------------
    virtual QSharedPointer<SignalVisualisationModel> createSignalVisualisationOfFile (QSharedPointer<FileContext> file_ctx);

    //-------------------------------------------------------------------------
    virtual void closeCurrentFileTabs ();

    //-------------------------------------------------------------------------
    virtual QSharedPointer<SignalVisualisationModel> getCurrentSignalVisualisationModel ();

public slots:
    //-------------------------------------------------------------------------
    void tabChanged (int tab_index);

    //-------------------------------------------------------------------------
    void closeTab (int tab_index);

    //-------------------------------------------------------------------------
    void recentFileActivated(QAction* recent_file_action);

    //-------------------------------------------------------------------------
    void recentFileMenuAboutToShow();


private:
    //-------------------------------------------------------------------------
    int createSignalVisualisationImpl (QSharedPointer<ChannelManager> channel_manager,
                                       QSharedPointer<EventManager> event_manager);

    //-------------------------------------------------------------------------
    void storeAndInitTabContext (QSharedPointer<TabContext> context, int tab_index);

    static int const NUMBER_RECENT_FILES_;

    MainWindow* main_window_;
    QTabWidget* tab_widget_;
    QStringList recent_file_list_;
    std::map<int, QSharedPointer<SignalVisualisationModel> > browser_models_;
    std::map<int, QSharedPointer<TabContext> > tab_contexts_;

    //-------------------------------------------------------------------------
    // not allowed
    MainWindowModelImpl(const MainWindowModelImpl&);
    const MainWindowModelImpl& operator=(const MainWindowModelImpl&);

};

} // namespace BioSig_

#endif
