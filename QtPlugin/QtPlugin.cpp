#include "QtPlugin.h"
#include "PluginDialog.h"
#include "PluginTabWidget.h"
#include "pluginmain.h"

static PluginDialog* pluginDialog;
static PluginTabWidget* pluginTabWidget;

static QWidget* getParent()
{
    return QWidget::find((WId)Plugin::hwndDlg);
}

void QtPlugin::Init()
{
}

void QtPlugin::Setup()
{
    QWidget* parent = getParent();
    pluginDialog = new PluginDialog(parent);
    pluginDialog->show();
    pluginTabWidget = new PluginTabWidget(parent);
    GuiAddQWidgetTab(pluginTabWidget);
}

void QtPlugin::Stop()
{
    GuiCloseQWidgetTab(pluginTabWidget);
    delete pluginDialog;
    delete pluginTabWidget;
}

void QtPlugin::ShowTab()
{
    GuiShowQWidgetTab(pluginTabWidget);
}
