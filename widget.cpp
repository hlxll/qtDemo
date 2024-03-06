#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::CreateControlHtml(QWidget* mainWindow){
    mainWindow->setWindowTitle("first Window");
    mainWindow->setGeometry(QRect(100, 100, 800, 600));

    QCheckBox checkbox("Checkbox Label", mainWindow);
    checkbox.setCheckable(true);
    checkbox.setChecked(true);
    checkbox.setStyleSheet("QCheckBox { background-color: red; }");
}

