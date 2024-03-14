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
    connect(pushBtn, &QPushButton::clicked, this, &QWidget::close);

    // lamband,直接使用方法，内部不能访问外部变量，需要传递，=值传递所有变量，&引用传递所有变量，也可以单个变量传递
    [pushBtn](){
        pushBtn->move(10, 10);
    }();


    QPushButton *SlotBtn = new QPushButton("插槽按钮", mainWindow);
    SlotBtn->move(100, 100);
    connect(SlotBtn, &QPushButton::clicked, this, &Widget::isoverClass);
    //将lamband函数使用在槽中
//    connect(this, &Widget::hungrl, this, &Widget::treat);
    //connect在重载后的函数写法就有区别了，信号和槽不能直接写函数名,不然无法区分是使用哪个方法
     void(Widget:: *send)(QString) = &Widget::hungrl;
     void(Widget:: *slot)(QString) = &Widget::treat;

     connect(this, send, this, slot);
    //QT4的connect，信号和槽是不同的，SIGNAL(hunglr())， 槽SLOT(treat(QString)),参数直观，类型不检测

    //mutable关键字定义是拷贝传递变量，不是本体
//    QPushButton *CopyBtn = new QPushButton("拷贝按钮", mainWindow);
//    connect(CopyBtn, &QPushButton::clicked, this, [=]()mutable{qDebug() << "lamband函数使用在槽中，自定义方法" << endl;});

}
void Widget::treat(){
    qDebug()<< "请老师吃饭";
}
void Widget::treat(QString food){
    qDebug()<< "请老师吃屎" ;
}
void Widget::isoverClass(){
    //触发hungrl事件
    qDebug() << "吃屎";
    //无参的无效了？？？？，老师不用吃饭了，待看视频
    emit this->hungrl("");
}



void Widget::createMainWindow(QMainWindow* mainWin){
    mainWin->resize(400, 400);
    QMenuBar *menuBar = new QMenuBar();
    QMenu *menuObj = menuBar->addMenu("文件");
    QAction *actionChild = menuObj->addAction("添加");
    actionChild->setIcon(QIcon(":/static/image/draw.svg"));
    menuObj->setIcon(QIcon(":/static/image/draw.svg"));
    menuBar->addMenu("视图");
    mainWin->setMenuBar(menuBar);

    QStatusBar *status = new QStatusBar();
    mainWin->setStatusBar(status);

    QDockWidget *dockWid = new QDockWidget();
    mainWin->addDockWidget(Qt::LeftDockWidgetArea, dockWid);

    QToolBar *toolbar = new QToolBar();
    mainWin->addToolBar(Qt::LeftToolBarArea, toolbar);

    //消息对话框
    QMessageBox *mesBox = new QMessageBox(mainWin);
    mesBox->setText("title");
    mesBox->exec();

    //颜色对话框
    QColor colorStr = QColorDialog::getColor(QColor(255, 0, 0));
    qDebug() << colorStr.red();
    mainWin->show();
}
void Widget::loadConfig(){
    QFile file(":/config.config");
    bool isOpen = file.open(QIODevice::ReadOnly);
    if(isOpen){
        QByteArray baData = file.readAll();
        QString strData = baData.toStdString().c_str();
        qDebug() << strData;
    }

}

