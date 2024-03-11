#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QCheckBox>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void CreateControlHtml(QWidget* mainWindow);
    void isoverClass();

    void createMainWindow();
signals:
//自定义信号，不需要实现，可以重载
    void hungrl();
    void hungrl(QString food);
public slots:
    //早起QT，槽需要写到public slots下，最新的可以直接写在public下,需要声明和实现，
    void treat();
    void treat(QString food);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
