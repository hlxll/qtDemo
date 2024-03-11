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

    QPushButton *pushBtn = new QPushButton("点击按钮", mainWindow);
    connect(pushBtn, &QPushButton::click, this, &QWidget::close);

    // lamband,直接使用方法，内部不能访问外部变量，需要传递，=值传递所有变量，&引用传递所有变量，也可以单个变量传递
    [pushBtn](){

    }()
    //将lamband函数使用在槽中
    //mutable关键字定义是拷贝传递变量，不是本体
    connect(pushBtn, &QPushButton::click, this, []()mutable{QDebug<< "lamband函数使用在槽中，自定义方法"l});


}
void Widget::treat(){
    qDebug()<< "请老师吃饭";
}
void Widget::treat(QString food){
    qDebug()<< "请老师吃饭" + food;
}
void Widget::isoverClass(){
    //触发hungrl事件
    emit this.hungrl();
}
//connect在重载后的函数写法就有区别了，信号和槽不能直接写函数名
// void(Widget:: *send)(QString) = &widget::hungrl
// void(Widget:: *slot)(QString) = &widget::treat
// connect(this, &widget::hungrl, this, &widget::treat)
// connect(this, send, this, slot)
//QT4的connect，信号和槽是不同的，SIGNAL(hunglr())， 槽SLOT(treat(QString)),参数直观，类型不检测


void Widget::createMainWindow(){
    QMainWindow *mainWin = new QMainWindow();

    QMenuBar *menuBar = new MenuBar();
    QMenu *FileMenu = menuBar->addMenu("文件");
    mainWin->setMenuBar(menuBar);
}