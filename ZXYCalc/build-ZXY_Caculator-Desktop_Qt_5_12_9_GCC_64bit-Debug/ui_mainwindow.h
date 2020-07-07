/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *MainWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *keyboard;
    QPushButton *num7;
    QPushButton *num1;
    QPushButton *equal;
    QPushButton *num3;
    QPushButton *num2;
    QPushButton *num0;
    QPushButton *pow;
    QPushButton *num6;
    QPushButton *backspace;
    QPushButton *divide;
    QPushButton *num9;
    QPushButton *num8;
    QPushButton *C;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *dot;
    QPushButton *CE;
    QPushButton *plus;
    QPushButton *minus;
    QPushButton *percent;
    QPushButton *mutiply;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *title;
    QSpacerItem *horizontalSpacer_2;
    QLabel *Calculator;
    QSpacerItem *bar;
    QPushButton *minimize;
    QPushButton *close;
    QLineEdit *box;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(581, 536);
        MainWindow->setMinimumSize(QSize(581, 536));
        MainWindow->setMaximumSize(QSize(581, 536));
        QPalette palette;
        QBrush brush(QColor(245, 245, 245, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setMouseTracking(true);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        MainWindow->setAcceptDrops(true);
        MainWindow->setWindowOpacity(0.870000000000000);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("background:rgb(245,245,245);"));
        MainWindow->setIconSize(QSize(0, 0));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextOnly);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->setFocusPolicy(Qt::NoFocus);
        MainWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        MainWidget->setLayoutDirection(Qt::LeftToRight);
        MainWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayoutWidget = new QWidget(MainWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 140, 581, 391));
        gridLayoutWidget->setFocusPolicy(Qt::StrongFocus);
        keyboard = new QGridLayout(gridLayoutWidget);
        keyboard->setSpacing(2);
        keyboard->setContentsMargins(11, 11, 11, 11);
        keyboard->setObjectName(QString::fromUtf8("keyboard"));
        keyboard->setSizeConstraint(QLayout::SetDefaultConstraint);
        keyboard->setContentsMargins(5, 0, 5, 0);
        num7 = new QPushButton(gridLayoutWidget);
        num7->setObjectName(QString::fromUtf8("num7"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(num7->sizePolicy().hasHeightForWidth());
        num7->setSizePolicy(sizePolicy);
        num7->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nirmala UI"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        num7->setFont(font1);
        num7->setFocusPolicy(Qt::ClickFocus);
        num7->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num7, 1, 0, 1, 1);

        num1 = new QPushButton(gridLayoutWidget);
        num1->setObjectName(QString::fromUtf8("num1"));
        sizePolicy.setHeightForWidth(num1->sizePolicy().hasHeightForWidth());
        num1->setSizePolicy(sizePolicy);
        num1->setMinimumSize(QSize(0, 0));
        num1->setFont(font1);
        num1->setFocusPolicy(Qt::StrongFocus);
        num1->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num1, 4, 0, 1, 1);

        equal = new QPushButton(gridLayoutWidget);
        equal->setObjectName(QString::fromUtf8("equal"));
        sizePolicy.setHeightForWidth(equal->sizePolicy().hasHeightForWidth());
        equal->setSizePolicy(sizePolicy);
        equal->setMinimumSize(QSize(0, 0));
        equal->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        equal->setFont(font2);
        equal->setFocusPolicy(Qt::StrongFocus);
        equal->setAutoFillBackground(false);
        equal->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(equal, 5, 2, 1, 1);

        num3 = new QPushButton(gridLayoutWidget);
        num3->setObjectName(QString::fromUtf8("num3"));
        sizePolicy.setHeightForWidth(num3->sizePolicy().hasHeightForWidth());
        num3->setSizePolicy(sizePolicy);
        num3->setMinimumSize(QSize(0, 0));
        num3->setFont(font1);
        num3->setFocusPolicy(Qt::StrongFocus);
        num3->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num3, 4, 2, 1, 1);

        num2 = new QPushButton(gridLayoutWidget);
        num2->setObjectName(QString::fromUtf8("num2"));
        sizePolicy.setHeightForWidth(num2->sizePolicy().hasHeightForWidth());
        num2->setSizePolicy(sizePolicy);
        num2->setMinimumSize(QSize(0, 0));
        num2->setFont(font1);
        num2->setFocusPolicy(Qt::StrongFocus);
        num2->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num2, 4, 1, 1, 1);

        num0 = new QPushButton(gridLayoutWidget);
        num0->setObjectName(QString::fromUtf8("num0"));
        num0->setEnabled(true);
        sizePolicy.setHeightForWidth(num0->sizePolicy().hasHeightForWidth());
        num0->setSizePolicy(sizePolicy);
        num0->setMinimumSize(QSize(0, 0));
        num0->setFont(font1);
        num0->setFocusPolicy(Qt::StrongFocus);
        num0->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num0, 5, 1, 1, 1);

        pow = new QPushButton(gridLayoutWidget);
        pow->setObjectName(QString::fromUtf8("pow"));
        sizePolicy.setHeightForWidth(pow->sizePolicy().hasHeightForWidth());
        pow->setSizePolicy(sizePolicy);
        pow->setMinimumSize(QSize(0, 0));
        pow->setBaseSize(QSize(0, 0));
        pow->setFont(font2);
        pow->setFocusPolicy(Qt::StrongFocus);
        pow->setAutoFillBackground(false);
        pow->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(pow, 0, 3, 1, 1);

        num6 = new QPushButton(gridLayoutWidget);
        num6->setObjectName(QString::fromUtf8("num6"));
        sizePolicy.setHeightForWidth(num6->sizePolicy().hasHeightForWidth());
        num6->setSizePolicy(sizePolicy);
        num6->setMinimumSize(QSize(0, 0));
        num6->setFont(font1);
        num6->setFocusPolicy(Qt::StrongFocus);
        num6->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num6, 2, 2, 1, 1);

        backspace = new QPushButton(gridLayoutWidget);
        backspace->setObjectName(QString::fromUtf8("backspace"));
        sizePolicy.setHeightForWidth(backspace->sizePolicy().hasHeightForWidth());
        backspace->setSizePolicy(sizePolicy);
        backspace->setMinimumSize(QSize(0, 0));
        backspace->setBaseSize(QSize(0, 0));
        backspace->setFont(font2);
        backspace->setFocusPolicy(Qt::StrongFocus);
        backspace->setAutoFillBackground(false);
        backspace->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(backspace, 0, 2, 1, 1);

        divide = new QPushButton(gridLayoutWidget);
        divide->setObjectName(QString::fromUtf8("divide"));
        sizePolicy.setHeightForWidth(divide->sizePolicy().hasHeightForWidth());
        divide->setSizePolicy(sizePolicy);
        divide->setMinimumSize(QSize(0, 0));
        divide->setBaseSize(QSize(0, 0));
        divide->setFont(font2);
        divide->setFocusPolicy(Qt::StrongFocus);
        divide->setAutoFillBackground(false);
        divide->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(divide, 0, 4, 1, 1);

        num9 = new QPushButton(gridLayoutWidget);
        num9->setObjectName(QString::fromUtf8("num9"));
        sizePolicy.setHeightForWidth(num9->sizePolicy().hasHeightForWidth());
        num9->setSizePolicy(sizePolicy);
        num9->setMinimumSize(QSize(0, 0));
        num9->setFont(font1);
        num9->setFocusPolicy(Qt::StrongFocus);
        num9->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num9, 1, 2, 1, 1);

        num8 = new QPushButton(gridLayoutWidget);
        num8->setObjectName(QString::fromUtf8("num8"));
        sizePolicy.setHeightForWidth(num8->sizePolicy().hasHeightForWidth());
        num8->setSizePolicy(sizePolicy);
        num8->setMinimumSize(QSize(0, 0));
        num8->setFont(font1);
        num8->setFocusPolicy(Qt::StrongFocus);
        num8->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num8, 1, 1, 1, 1);

        C = new QPushButton(gridLayoutWidget);
        C->setObjectName(QString::fromUtf8("C"));
        sizePolicy.setHeightForWidth(C->sizePolicy().hasHeightForWidth());
        C->setSizePolicy(sizePolicy);
        C->setMinimumSize(QSize(0, 0));
        C->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        C->setFont(font3);
        C->setFocusPolicy(Qt::StrongFocus);
        C->setAutoFillBackground(false);
        C->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(C, 0, 0, 1, 1);

        num4 = new QPushButton(gridLayoutWidget);
        num4->setObjectName(QString::fromUtf8("num4"));
        sizePolicy.setHeightForWidth(num4->sizePolicy().hasHeightForWidth());
        num4->setSizePolicy(sizePolicy);
        num4->setMinimumSize(QSize(0, 0));
        num4->setFont(font1);
        num4->setFocusPolicy(Qt::StrongFocus);
        num4->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num4, 2, 0, 1, 1);

        num5 = new QPushButton(gridLayoutWidget);
        num5->setObjectName(QString::fromUtf8("num5"));
        sizePolicy.setHeightForWidth(num5->sizePolicy().hasHeightForWidth());
        num5->setSizePolicy(sizePolicy);
        num5->setMinimumSize(QSize(0, 0));
        num5->setFont(font1);
        num5->setFocusPolicy(Qt::StrongFocus);
        num5->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"\n"
"background-color:rgb(243,243,243);"));

        keyboard->addWidget(num5, 2, 1, 1, 1);

        dot = new QPushButton(gridLayoutWidget);
        dot->setObjectName(QString::fromUtf8("dot"));
        sizePolicy.setHeightForWidth(dot->sizePolicy().hasHeightForWidth());
        dot->setSizePolicy(sizePolicy);
        dot->setMinimumSize(QSize(0, 0));
        dot->setBaseSize(QSize(0, 0));
        dot->setFont(font2);
        dot->setFocusPolicy(Qt::StrongFocus);
        dot->setAutoFillBackground(false);
        dot->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(dot, 5, 0, 1, 1);

        CE = new QPushButton(gridLayoutWidget);
        CE->setObjectName(QString::fromUtf8("CE"));
        sizePolicy.setHeightForWidth(CE->sizePolicy().hasHeightForWidth());
        CE->setSizePolicy(sizePolicy);
        CE->setMinimumSize(QSize(0, 0));
        CE->setBaseSize(QSize(0, 0));
        CE->setFont(font3);
        CE->setFocusPolicy(Qt::StrongFocus);
        CE->setAutoFillBackground(false);
        CE->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(CE, 0, 1, 1, 1);

        plus = new QPushButton(gridLayoutWidget);
        plus->setObjectName(QString::fromUtf8("plus"));
        sizePolicy.setHeightForWidth(plus->sizePolicy().hasHeightForWidth());
        plus->setSizePolicy(sizePolicy);
        plus->setMinimumSize(QSize(0, 0));
        plus->setBaseSize(QSize(0, 0));
        plus->setFont(font2);
        plus->setFocusPolicy(Qt::StrongFocus);
        plus->setAutoFillBackground(false);
        plus->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(plus, 4, 3, 2, 1);

        minus = new QPushButton(gridLayoutWidget);
        minus->setObjectName(QString::fromUtf8("minus"));
        sizePolicy.setHeightForWidth(minus->sizePolicy().hasHeightForWidth());
        minus->setSizePolicy(sizePolicy);
        minus->setMinimumSize(QSize(0, 0));
        minus->setBaseSize(QSize(0, 0));
        minus->setFont(font2);
        minus->setFocusPolicy(Qt::StrongFocus);
        minus->setAutoFillBackground(false);
        minus->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(minus, 4, 4, 2, 1);

        percent = new QPushButton(gridLayoutWidget);
        percent->setObjectName(QString::fromUtf8("percent"));
        sizePolicy.setHeightForWidth(percent->sizePolicy().hasHeightForWidth());
        percent->setSizePolicy(sizePolicy);
        percent->setMinimumSize(QSize(0, 0));
        percent->setBaseSize(QSize(0, 0));
        percent->setFont(font2);
        percent->setFocusPolicy(Qt::StrongFocus);
        percent->setAutoFillBackground(false);
        percent->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(percent, 1, 3, 2, 1);

        mutiply = new QPushButton(gridLayoutWidget);
        mutiply->setObjectName(QString::fromUtf8("mutiply"));
        sizePolicy.setHeightForWidth(mutiply->sizePolicy().hasHeightForWidth());
        mutiply->setSizePolicy(sizePolicy);
        mutiply->setMinimumSize(QSize(0, 0));
        mutiply->setBaseSize(QSize(0, 0));
        mutiply->setFont(font2);
        mutiply->setFocusPolicy(Qt::StrongFocus);
        mutiply->setAutoFillBackground(false);
        mutiply->setStyleSheet(QString::fromUtf8("border:1px groove rgb(220,220,220);\n"
"background-color:rgb(222,222,222);"));

        keyboard->addWidget(mutiply, 1, 4, 2, 1);

        horizontalLayoutWidget = new QWidget(MainWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 581, 38));
        title = new QHBoxLayout(horizontalLayoutWidget);
        title->setSpacing(6);
        title->setContentsMargins(11, 11, 11, 11);
        title->setObjectName(QString::fromUtf8("title"));
        title->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        title->addItem(horizontalSpacer_2);

        Calculator = new QLabel(horizontalLayoutWidget);
        Calculator->setObjectName(QString::fromUtf8("Calculator"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nirmala UI"));
        font4.setPointSize(12);
        Calculator->setFont(font4);

        title->addWidget(Calculator);

        bar = new QSpacerItem(362, 36, QSizePolicy::Fixed, QSizePolicy::Minimum);

        title->addItem(bar);

        minimize = new QPushButton(horizontalLayoutWidget);
        minimize->setObjectName(QString::fromUtf8("minimize"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(minimize->sizePolicy().hasHeightForWidth());
        minimize->setSizePolicy(sizePolicy1);
        minimize->setMaximumSize(QSize(51, 21));
        QFont font5;
        font5.setFamily(QString::fromUtf8("OCR A Extended"));
        font5.setPointSize(14);
        minimize->setFont(font5);
        minimize->setStyleSheet(QString::fromUtf8("border:10px  rgb(220,220,220);\n"
"background-color:rgb(243,243,243);"));

        title->addWidget(minimize);

        close = new QPushButton(horizontalLayoutWidget);
        close->setObjectName(QString::fromUtf8("close"));
        sizePolicy1.setHeightForWidth(close->sizePolicy().hasHeightForWidth());
        close->setSizePolicy(sizePolicy1);
        close->setMaximumSize(QSize(51, 21));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Myriad Pro"));
        font6.setPointSize(15);
        close->setFont(font6);
        close->setContextMenuPolicy(Qt::CustomContextMenu);
        close->setStyleSheet(QString::fromUtf8("border:10px  rgb(220,220,220);\n"
"background-color:rgb(243,243,243);"));

        title->addWidget(close);

        box = new QLineEdit(MainWidget);
        box->setObjectName(QString::fromUtf8("box"));
        box->setGeometry(QRect(4, 40, 572, 91));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(box->sizePolicy().hasHeightForWidth());
        box->setSizePolicy(sizePolicy2);
        box->setBaseSize(QSize(0, 0));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(39);
        font7.setBold(false);
        font7.setWeight(50);
        font7.setStrikeOut(false);
        font7.setKerning(true);
        font7.setStyleStrategy(QFont::PreferDefault);
        box->setFont(font7);
        box->setCursor(QCursor(Qt::ArrowCursor));
        box->setStyleSheet(QString::fromUtf8("border:0px groove rgb(243,243,243);\n"
"background-color:rgb(245,245,245);"));
        box->setFrame(true);
        box->setCursorPosition(1);
        box->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        box->setReadOnly(true);
        box->setCursorMoveStyle(Qt::VisualMoveStyle);
        MainWindow->setCentralWidget(MainWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        num7->setText(QApplication::translate("MainWindow", "7", nullptr));
        num1->setText(QApplication::translate("MainWindow", "1", nullptr));
#ifndef QT_NO_TOOLTIP
        equal->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        equal->setText(QApplication::translate("MainWindow", "=", nullptr));
        num3->setText(QApplication::translate("MainWindow", "3", nullptr));
        num2->setText(QApplication::translate("MainWindow", "2", nullptr));
        num0->setText(QApplication::translate("MainWindow", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        pow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pow->setText(QApplication::translate("MainWindow", "^", nullptr));
        num6->setText(QApplication::translate("MainWindow", "6", nullptr));
#ifndef QT_NO_TOOLTIP
        backspace->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        backspace->setText(QApplication::translate("MainWindow", "\342\235\216", nullptr));
#ifndef QT_NO_TOOLTIP
        divide->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        divide->setText(QApplication::translate("MainWindow", "/", nullptr));
        num9->setText(QApplication::translate("MainWindow", "9", nullptr));
        num8->setText(QApplication::translate("MainWindow", "8", nullptr));
#ifndef QT_NO_TOOLTIP
        C->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        C->setText(QApplication::translate("MainWindow", "C", nullptr));
        num4->setText(QApplication::translate("MainWindow", "4", nullptr));
        num5->setText(QApplication::translate("MainWindow", "5", nullptr));
#ifndef QT_NO_TOOLTIP
        dot->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        dot->setText(QApplication::translate("MainWindow", ".", nullptr));
#ifndef QT_NO_TOOLTIP
        CE->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        CE->setText(QApplication::translate("MainWindow", "CE", nullptr));
#ifndef QT_NO_TOOLTIP
        plus->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        plus->setText(QApplication::translate("MainWindow", "+", nullptr));
#ifndef QT_NO_TOOLTIP
        minus->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        minus->setText(QApplication::translate("MainWindow", "-", nullptr));
#ifndef QT_NO_TOOLTIP
        percent->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        percent->setText(QApplication::translate("MainWindow", "%", nullptr));
#ifndef QT_NO_TOOLTIP
        mutiply->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        mutiply->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
        Calculator->setText(QApplication::translate("MainWindow", "<html><head/><body><p>ZXY18281059</p></body></html>", nullptr));
        minimize->setText(QApplication::translate("MainWindow", "-", nullptr));
        close->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
        box->setText(QApplication::translate("MainWindow", "0", nullptr));
        box->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
