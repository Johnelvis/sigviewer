#ifndef EVENT_EDITING_GUI_COMMAND_H
#define EVENT_EDITING_GUI_COMMAND_H

#include "../base/user_types.h"
#include "../gui/gui_action_command.h"
#include "../gui/gui_action_factory_registrator.h"

#include <QUndoCommand>

namespace BioSig_
{

class EventEditingGuiCommand : public GuiActionCommand
{
    Q_OBJECT
public:
    //-------------------------------------------------------------------------
    EventEditingGuiCommand ();

    //-------------------------------------------------------------------------
    virtual ~EventEditingGuiCommand ();

    //-------------------------------------------------------------------------
    virtual void init ();

public slots:
    //-------------------------------------------------------------------------
    void deleteSelectedEvent ();

    //-------------------------------------------------------------------------
    void changeTypeSelectedEvent ();

    //-------------------------------------------------------------------------
    void changeChannelSelectedEvent ();

    //-------------------------------------------------------------------------
    void toAllChannelsSelectedEvent ();

    //-------------------------------------------------------------------------
    void copyToChannelsSelectedEvent ();

    //-------------------------------------------------------------------------
    void insertEventOverSelectedEvent ();

    //-------------------------------------------------------------------------
    void showEventTableDialog ();

    //-------------------------------------------------------------------------
    void setEventCreationType ();

protected:
    //-------------------------------------------------------------------------
    virtual void evaluateEnabledness ();

private:
    void executeCommand (QUndoCommand* command);

    static QString const DELETE_;
    static QString const CHANGE_TYPE_;
    static QString const CHANGE_CHANNEL_;
    static QString const TO_ALL_CHANNEL_;
    static QString const COPY_TO_CHANNELS_;
    static QString const INSERT_OVER_;
    static QString const SET_EVENT_CREATION_TYPE_;
    static QString const SHOW_EVENT_TABLE_DIALOG_;
    static QStringList const ACTIONS_;

    static GuiActionFactoryRegistrator registrator_;
};

}

#endif // EVENT_EDITING_GUI_COMMAND_H