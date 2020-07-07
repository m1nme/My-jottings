#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QTime>
#include <QProcess>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //当前光标的坐标
    QPoint mousePoint;
    //当前窗口坐标
    QPoint windowPoint;
    //各个对象增加阴影效果
    QGraphicsDropShadowEffect *num0_shadow;
    QGraphicsDropShadowEffect *num1_shadow;
    QGraphicsDropShadowEffect *num2_shadow;
    QGraphicsDropShadowEffect *num3_shadow;
    QGraphicsDropShadowEffect *num4_shadow;
    QGraphicsDropShadowEffect *num5_shadow;
    QGraphicsDropShadowEffect *num6_shadow;
    QGraphicsDropShadowEffect *num7_shadow;
    QGraphicsDropShadowEffect *num8_shadow;
    QGraphicsDropShadowEffect *num9_shadow;

    QGraphicsDropShadowEffect *plus_shadow;
    QGraphicsDropShadowEffect *minus_shadow;
    QGraphicsDropShadowEffect *mutiply_shadow;
    QGraphicsDropShadowEffect *divide_shadow;
    QGraphicsDropShadowEffect *percent_shadow;
    QGraphicsDropShadowEffect *pow_shadow;
    QGraphicsDropShadowEffect *dot_shadow;
    QGraphicsDropShadowEffect *equal_shadow;

    QGraphicsDropShadowEffect *c_shadow;
    QGraphicsDropShadowEffect *ce_shadow;
    QGraphicsDropShadowEffect *brace_shadow;
    QGraphicsDropShadowEffect *bracket_shadow;
    QGraphicsDropShadowEffect *parentheses_shadow;
    QGraphicsDropShadowEffect *space_shadow;
    QGraphicsDropShadowEffect *backspace_shadow;
    //阴影处理
    void addNumButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void initButtonShadow(void);
    void setButtonShadow(void);
    void installButtonEventFilter(void);
    //添加文本
    void appendText(const QString &);
    //清除焦点
    void appendTextAndClearFocus(QPushButton *,const QString &);
    //阴影去掉
    void removeSignButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void removeNumButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);


    void setText(const QString &s);
    void setTextIf0ElseAppend(const QString &s);
    void setTextAndClearFocus(QPushButton *button, const QString &s);
    void setTextIf0ElseAppendAndClearFocus(QPushButton *button, const QString &s);

    //淡入效果
    void fadeIn(void);
    //淡出效果
    void fadeOut(void);

    void setResult(void);
    void clearButtonFocus(QPushButton *);

    void addSignButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    bool previousIsNotDot(void);
    bool previousIsNotSign(void);
    bool previousIsNotLeftBrace(void);
    bool previousIsNotRightBrace(void);
    bool previousIsNotNum(void);


    QString result(void);
protected:
    //鼠标监听函数
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    //移入与移出事件过滤器
    bool eventFilter(QObject *,QEvent *);
    //按键按下添加阴影
    void keyPressEvent(QKeyEvent *);
    //按键按下输出框添加输出
    void keyReleaseEvent(QKeyEvent *);


private slots:
    void on_minimize_clicked();
    void on_close_clicked();

    void on_num0_clicked();
    void on_num1_clicked();
    void on_num2_clicked();
    void on_num3_clicked();
    void on_num4_clicked();
    void on_num5_clicked();
    void on_num6_clicked();
    void on_num7_clicked();
    void on_num8_clicked();
    void on_num9_clicked();

    void on_percent_clicked();
    void on_dot_clicked();
    void on_mutiply_clicked();
    void on_plus_clicked();
    void on_minus_clicked();
    void on_equal_clicked();
    void on_divide_clicked();
    void on_pow_clicked();
    void on_backspace_clicked();
    void on_CE_clicked();
    void on_C_clicked();
};
#endif // MAINWINDOW_H
