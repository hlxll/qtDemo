#include "widget.h"
#include "qtcoreclass.h"
#include <QApplication>
#include "coreclass.h"
#include <QMainWindow>
#include <QPaintEvent>
#include <QRect>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Widget继承自QWidget，所有这里就相当于创建了一个QWidget窗口
//    Widget *wid = new Widget(nullptr);
//    wid->CreateControlHtml(wid);

//    QMainWindow *wid = new QMainWindow(nullptr, 0x00000000);
    Widget *obj = new Widget(nullptr);
    obj->show();

    return app.exec();
}
