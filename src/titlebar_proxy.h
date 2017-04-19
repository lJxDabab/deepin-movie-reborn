#ifndef _DMR_TITLEBAR_PROXY_H
#define _DMR_TITLEBAR_PROXY_H 

#include <DPlatformWindowHandle>
#include <DBlurEffectWidget>
#include "dmr_titlebar.h"

DWIDGET_USE_NAMESPACE

namespace dmr {

class EventMonitor;
class EventRelayer;

/**
 * TitlebarProxy is a toplevel blurred window that should be bound with main 
 * window. It needs to keep as top level to utilize deepin-wm's blurring 
 * facility.
 */
class TitlebarProxy: public DBlurEffectWidget {
    Q_OBJECT
public:
    TitlebarProxy(QWidget *mainWindow);
    virtual ~TitlebarProxy();
    DMRTitlebar* titlebar() { return _titlebar; }
    void populateMenu();

protected slots:
    void toggleWindowState();
    void closeWindow();
    void showMinimized();

    void updatePosition(const QPoint& p);

protected:
    void resizeEvent(QResizeEvent* ev) override;
    void showEvent(QShowEvent*) override;
    void mousePressEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    DPlatformWindowHandle *_handle {nullptr};
    DMRTitlebar *_titlebar {nullptr};
    QWidget *_mainWindow {nullptr};
    EventMonitor *_evMonitor {nullptr};
    EventRelayer *_evRelay {nullptr};
};
}

#endif /* ifndef _DMR_TITLEBAR_PROXY_H */
