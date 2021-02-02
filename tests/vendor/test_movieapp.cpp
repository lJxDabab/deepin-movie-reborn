#include <gtest/gtest.h>
#include <QtTest>
#include <QTest>
#include <QTestEventList>
#include <QTimer>
#include "application.h"
#include <unistd.h>
#include "src/vendor/movieapp.h"

using namespace dmr;

#ifndef __mips__
TEST(MovieApp, testMprisapp)
{
    MainWindow* w = new MainWindow();
    Settings::get().settings()->setOption("base.play.emptylist", true); //退出时清空播放列表
//    w->show();

//    MovieApp *movieapp = dApp->initMovieApp(w);

//    QTimer::singleShot(1000,[=]{movieapp->show();});
    QTest::qWait(300);
    w->testMprisapp();
}
#endif
