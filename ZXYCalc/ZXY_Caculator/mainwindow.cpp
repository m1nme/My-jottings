#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    initButtonShadow();
    installButtonEventFilter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//获取mouse坐标,设置window坐标.
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mousePoint = event->globalPos();
        windowPoint = frameGeometry().topLeft();
    }
}
//使用MainWindow的move方法移动窗口
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //减去原来光标的坐标得到window坐标的变化量
    if(event->buttons() & Qt::LeftButton)
    {
        move(windowPoint + event->globalPos() - mousePoint);
    }
}

//最小化函数
void MainWindow::on_minimize_clicked()
{
    MainWindow::showMinimized();
}
//关闭函数
void MainWindow::on_close_clicked()
{
    exit(0);
}

//增加阴影效果
void MainWindow::addNumButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(true);
    button->setStyleSheet(
        "border:1px groove rgb(220,220,220);"
        "background-color:rgb(193,193,193);"
    );
}

void MainWindow::initButtonShadow(void)
{
    num0_shadow = new QGraphicsDropShadowEffect();
    num1_shadow = new QGraphicsDropShadowEffect();
    num2_shadow = new QGraphicsDropShadowEffect();
    num3_shadow = new QGraphicsDropShadowEffect();
    num4_shadow = new QGraphicsDropShadowEffect();
    num5_shadow = new QGraphicsDropShadowEffect();
    num6_shadow = new QGraphicsDropShadowEffect();
    num7_shadow = new QGraphicsDropShadowEffect();
    num8_shadow = new QGraphicsDropShadowEffect();
    num9_shadow = new QGraphicsDropShadowEffect();

    plus_shadow = new QGraphicsDropShadowEffect();
    minus_shadow = new QGraphicsDropShadowEffect();
    mutiply_shadow = new QGraphicsDropShadowEffect();
    divide_shadow = new QGraphicsDropShadowEffect();
    percent_shadow = new QGraphicsDropShadowEffect();
    pow_shadow = new QGraphicsDropShadowEffect();
    dot_shadow = new QGraphicsDropShadowEffect();
    equal_shadow = new QGraphicsDropShadowEffect();

    c_shadow = new QGraphicsDropShadowEffect();
    ce_shadow = new QGraphicsDropShadowEffect();
    brace_shadow = new QGraphicsDropShadowEffect();
    bracket_shadow = new QGraphicsDropShadowEffect();
    parentheses_shadow = new QGraphicsDropShadowEffect();
    space_shadow = new QGraphicsDropShadowEffect();
    backspace_shadow = new QGraphicsDropShadowEffect();

    QGraphicsDropShadowEffect * allShadow[] = {
        num0_shadow,num1_shadow,num2_shadow,num3_shadow,num4_shadow,num5_shadow,num6_shadow,
        num7_shadow,num8_shadow,num9_shadow,plus_shadow,minus_shadow,mutiply_shadow,divide_shadow,
        percent_shadow,pow_shadow,dot_shadow,equal_shadow,c_shadow,ce_shadow,brace_shadow,bracket_shadow,
        parentheses_shadow,space_shadow,backspace_shadow};
    for(int i=0;i<25;++i)
    {
        allShadow[i]->setBlurRadius(14);
        allShadow[i]->setOffset(-1,1);
        allShadow[i]->setColor(Qt::gray);
        allShadow[i]->setEnabled(false);
    }
}

void MainWindow::installButtonEventFilter(void)
{
    ui->num0->installEventFilter(this);
    ui->num1->installEventFilter(this);
    ui->num2->installEventFilter(this);
    ui->num3->installEventFilter(this);
    ui->num4->installEventFilter(this);
    ui->num5->installEventFilter(this);
    ui->num6->installEventFilter(this);
    ui->num7->installEventFilter(this);
    ui->num8->installEventFilter(this);
    ui->num9->installEventFilter(this);
    ui->plus->installEventFilter(this);
    ui->minus->installEventFilter(this);
    ui->mutiply->installEventFilter(this);
    ui->divide->installEventFilter(this);
    ui->percent->installEventFilter(this);
    ui->pow->installEventFilter(this);
    ui->equal->installEventFilter(this);
    ui->C->installEventFilter(this);
    ui->CE->installEventFilter(this);
    ui->backspace->installEventFilter(this);
    ui->dot->installEventFilter(this);
}

void MainWindow::setButtonShadow(void)
{
    ui->num0->setGraphicsEffect(num0_shadow);
    ui->num1->setGraphicsEffect(num1_shadow);
    ui->num2->setGraphicsEffect(num2_shadow);
    ui->num3->setGraphicsEffect(num3_shadow);
    ui->num4->setGraphicsEffect(num4_shadow);
    ui->num5->setGraphicsEffect(num5_shadow);
    ui->num6->setGraphicsEffect(num6_shadow);
    ui->num7->setGraphicsEffect(num7_shadow);
    ui->num8->setGraphicsEffect(num8_shadow);
    ui->num9->setGraphicsEffect(num9_shadow);

    ui->plus->setGraphicsEffect(plus_shadow);
    ui->minus->setGraphicsEffect(minus_shadow);
    ui->mutiply->setGraphicsEffect(mutiply_shadow);
    ui->divide->setGraphicsEffect(divide_shadow);
    ui->percent->setGraphicsEffect(percent_shadow);
    ui->pow->setGraphicsEffect(pow_shadow);
    ui->dot->setGraphicsEffect(dot_shadow);
    ui->equal->setGraphicsEffect(equal_shadow);
    ui->C->setGraphicsEffect(c_shadow);
    ui->CE->setGraphicsEffect(ce_shadow);
    ui->backspace->setGraphicsEffect(backspace_shadow);
}

bool MainWindow::eventFilter(QObject *object,QEvent *event)
{
    //
    if(event->type() == QEvent::HoverEnter)
    {
        if(object == ui->num0)
            addNumButtonEffect(ui->num0,num0_shadow);
        else if(object == ui->num1)
            addNumButtonEffect(ui->num1,num1_shadow);
        else if(object == ui->num2)
            addNumButtonEffect(ui->num2,num2_shadow);
        else if(object == ui->num3)
            addNumButtonEffect(ui->num3,num3_shadow);
        else if(object == ui->num4)
            addNumButtonEffect(ui->num4,num4_shadow);
        else if(object == ui->num5)
            addNumButtonEffect(ui->num5,num5_shadow);
        else if(object == ui->num6)
            addNumButtonEffect(ui->num6,num6_shadow);
        else if(object == ui->num7)
            addNumButtonEffect(ui->num7,num7_shadow);
        else if(object == ui->num8)
            addNumButtonEffect(ui->num8,num8_shadow);
        else if(object == ui->num9)
            addNumButtonEffect(ui->num9,num9_shadow);
    }
    else if(event->type() == QEvent::HoverLeave)
    {
        if(object == ui->num0)
            removeNumButtonEffect(ui->num0,num0_shadow);
        else if(object == ui->num1)
            removeNumButtonEffect(ui->num1,num1_shadow);
        else if(object == ui->num2)
            removeNumButtonEffect(ui->num2,num2_shadow);
        else if(object == ui->num3)
            removeNumButtonEffect(ui->num3,num3_shadow);
        else if(object == ui->num4)
            removeNumButtonEffect(ui->num4,num4_shadow);
        else if(object == ui->num5)
            removeNumButtonEffect(ui->num5,num5_shadow);
        else if(object == ui->num6)
            removeNumButtonEffect(ui->num6,num6_shadow);
        else if(object == ui->num7)
            removeNumButtonEffect(ui->num7,num7_shadow);
        else if(object == ui->num8)
            removeNumButtonEffect(ui->num8,num8_shadow);
        else if(object == ui->num9)
            removeNumButtonEffect(ui->num9,num9_shadow);
        else if(object == ui->plus)
            removeSignButtonEffect(ui->plus,plus_shadow);
        else if(object == ui->minus)
            removeSignButtonEffect(ui->minus,minus_shadow);
        else if(object == ui->mutiply)
            removeSignButtonEffect(ui->mutiply,mutiply_shadow);
        else if(object == ui->divide)
            removeSignButtonEffect(ui->divide,divide_shadow);
        else if(object == ui->percent)
            removeSignButtonEffect(ui->percent,percent_shadow);
        else if(object == ui->pow)
            removeSignButtonEffect(ui->pow,pow_shadow);
        else if(object == ui->equal)
            removeSignButtonEffect(ui->equal,equal_shadow);
        else if(object == ui->C)
            removeSignButtonEffect(ui->C,c_shadow);
        else if(object == ui->CE)
            removeSignButtonEffect(ui->CE,ce_shadow);
    }
}

void MainWindow::appendText(const QString &s)
{
    if(ui->box->text() == "0")
        ui->box->setText(s);
    else
        ui->box->setText(ui->box->text()+s);
}

void MainWindow::appendTextAndClearFocus(QPushButton *button, const QString &s)
{
    appendText(s);
    button->clearFocus();
}

void MainWindow::removeSignButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(false);
    button->setStyleSheet("border:1px groove rgb(220,220,220);background-color:rgb(222,222,222);");
}

void MainWindow::removeNumButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(false);
    button->setStyleSheet("border:1px groove rgb(220,220,220);background-color:rgb(243,243,243);");
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
        case Qt::Key_Plus:
        case Qt::Key_Minus:
        case Qt::Key_Asterisk:
        case Qt::Key_Slash:
        case Qt::Key_AsciiCircum:
        case Qt::Key_Percent:
        case Qt::Key_ParenLeft:
        case Qt::Key_ParenRight:
        case Qt::Key_BraceLeft:
        case Qt::Key_BraceRight:
        case Qt::Key_BracketLeft:
        case Qt::Key_BracketRight:
        case Qt::Key_Backspace:
        case Qt::Key_Space:
        case Qt::Key_Period:
        case Qt::Key_Escape:
        case Qt::Key_Equal:
        case Qt::Key_Return:
            removeNumButtonEffect(ui->num0,num0_shadow);
            removeNumButtonEffect(ui->num1,num1_shadow);
            removeNumButtonEffect(ui->num2,num2_shadow);
            removeNumButtonEffect(ui->num3,num3_shadow);
            removeNumButtonEffect(ui->num4,num4_shadow);
            removeNumButtonEffect(ui->num5,num5_shadow);
            removeNumButtonEffect(ui->num6,num6_shadow);
            removeNumButtonEffect(ui->num7,num7_shadow);
            removeNumButtonEffect(ui->num8,num8_shadow);
            removeNumButtonEffect(ui->num9,num9_shadow);
            removeSignButtonEffect(ui->plus,plus_shadow);
            removeSignButtonEffect(ui->minus,minus_shadow);
            removeSignButtonEffect(ui->mutiply,mutiply_shadow);
            removeSignButtonEffect(ui->divide,divide_shadow);
            removeSignButtonEffect(ui->pow,pow_shadow);
            removeSignButtonEffect(ui->percent,percent_shadow);
            removeSignButtonEffect(ui->backspace,backspace_shadow);
            removeSignButtonEffect(ui->C,c_shadow);
            removeSignButtonEffect(ui->equal,equal_shadow);
            removeSignButtonEffect(ui->dot,dot_shadow);
            break;
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_0:
        addNumButtonEffect(ui->num0,num0_shadow);
        appendText("0");
        break;
    case Qt::Key_1:
        addNumButtonEffect(ui->num1,num1_shadow);
        appendText("1");
        break;

    case Qt::Key_2:
        addNumButtonEffect(ui->num2,num2_shadow);
        appendText("2");
        break;

    case Qt::Key_3:
        addNumButtonEffect(ui->num3,num3_shadow);
        appendText("3");
        break;

    case Qt::Key_4:
        addNumButtonEffect(ui->num4,num4_shadow);
        appendText("4");
        break;

    case Qt::Key_5:
        addNumButtonEffect(ui->num5,num5_shadow);
        appendText("5");
        break;

    case Qt::Key_6:
        addNumButtonEffect(ui->num6,num6_shadow);
        appendText("6");
        break;

    case Qt::Key_7:
        addNumButtonEffect(ui->num7,num7_shadow);
        appendText("7");
        break;

    case Qt::Key_8:
        addNumButtonEffect(ui->num8,num8_shadow);
        appendText("8");
        break;

    case Qt::Key_9:
        addNumButtonEffect(ui->num9,num9_shadow);
        appendText("9");
        break;

    }
}
//淡入淡出
void MainWindow::fadeIn(void)
{
    QPropertyAnimation * changeOpacity = new QPropertyAnimation(this,"windowOpacity");
    changeOpacity->setStartValue(0);
    changeOpacity->setEndValue(0.87);
    changeOpacity->setDuration(1200);
    changeOpacity->start();
}

void MainWindow::fadeOut(void)
{
    QPropertyAnimation * changeOpacity = new QPropertyAnimation(this,"windowOpacity");
    changeOpacity->setStartValue(0.87);
    changeOpacity->setEndValue(0);
    changeOpacity->setDuration(850);
    changeOpacity->start();

    QTime start = QTime::currentTime().addMSecs(850);
    while(QTime::currentTime() < start)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::setText(const QString &s)
{
    ui->box->setText(s);
}

void MainWindow::setTextIf0ElseAppend(const QString &s)
{
    ui->box->text() == "0" ? setText(s) : appendText(s);
}

void MainWindow::setTextAndClearFocus(QPushButton *button, const QString &s)
{
    setText(s);
    button->clearFocus();
}

void MainWindow::on_num0_clicked()
{
    appendTextAndClearFocus(ui->num0,"0");
}

void MainWindow::on_num1_clicked()
{
    appendTextAndClearFocus(ui->num1,"1");
}

void MainWindow::on_num2_clicked()
{
    appendTextAndClearFocus(ui->num2,"2");
}

void MainWindow::on_num3_clicked()
{
    appendTextAndClearFocus(ui->num3,"3");
}

void MainWindow::on_num4_clicked()
{
    appendTextAndClearFocus(ui->num4,"4");
}

void MainWindow::on_num5_clicked()
{
    appendTextAndClearFocus(ui->num5,"5");
}

void MainWindow::on_num6_clicked()
{
    appendTextAndClearFocus(ui->num6,"6");
}

void MainWindow::on_num7_clicked()
{
    appendTextAndClearFocus(ui->num7,"7");
}


void MainWindow::on_num8_clicked()
{
    appendTextAndClearFocus(ui->num8,"8");
}

void MainWindow::on_num9_clicked()
{
    appendTextAndClearFocus(ui->num9,"9");
}

void MainWindow::on_CE_clicked()
{
    ui->box->setText("0");
}

void MainWindow::on_C_clicked()
{
    ui->box->setText("0");
}

void MainWindow::on_backspace_clicked()
{
    if(ui->box->text() != "0")
    {
        ui->box->setReadOnly(false);
        setText(ui->box->text().size() != 1 ? ui->box->text().mid(0,ui->box->text().size()-1) : "0");
        ui->box->setReadOnly(true);
        ui->backspace->clearFocus();
    }
}

void MainWindow::on_mutiply_clicked()
{
    appendTextAndClearFocus(ui->mutiply,"*");
}

void MainWindow::on_plus_clicked()
{
    appendTextAndClearFocus(ui->plus,"+");
}

void MainWindow::on_minus_clicked()
{
    appendTextAndClearFocus(ui->minus,"-");
}

void MainWindow::on_equal_clicked()
{
    setResult();
}

void MainWindow::on_divide_clicked()
{
    appendTextAndClearFocus(ui->divide,"/");
}

void MainWindow::on_pow_clicked()
{
    appendTextAndClearFocus(ui->pow,"^");
}

void MainWindow::on_percent_clicked()
{
    appendTextAndClearFocus(ui->percent,"%");
}

void MainWindow::on_dot_clicked()
{
    appendTextAndClearFocus(ui->dot,".");
}

void MainWindow::setResult(){
    QProcess p(0);
    p.start("./calc",QStringList()<<(ui->box->text().remove(QRegExp("\\s")))); //command是要执行的命令,args是参数
    p.waitForFinished();//等待完成
    qDebug()<<QString::fromLocal8Bit(p.readAllStandardError());
    QFile resultFile("result.txt");
        resultFile.open(QIODevice::ReadOnly);
        QString result = resultFile.readAll();
        resultFile.remove();
        resultFile.close();
        if(result == "#")
            result = "表达式错误,请重新输入.";
        else if(result == "#1")
            result = "除数为0";
        else
        {
            if(result.indexOf('e') == -1 && result.indexOf('E') == -1)
            {
                for(int len = result.size()-1;len>=0 && result[len] != '.';--len)
                {
                    if(result[len] == '0')
                        result.remove(len,1);
                    else
                        break;
                }
                if(result[result.size()-1] == '.')
                    result.remove(result.size()-1,1);
            }
            if(result.size() > 17)
                result = result.mid(0,17);
            if(result == "-0")
                result = "0";
        }
        ui->box->setText(result);
}




