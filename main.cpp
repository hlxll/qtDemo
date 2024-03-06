#include "widget.h"
#include "qtcoreclass.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Widget继承自QWidget，所有这里就相当于创建了一个QWidget窗口
    Widget *wid = new Widget(nullptr);
    wid->show();
    wid->CreateControlHtml(wid);

    return a.exec();
}
