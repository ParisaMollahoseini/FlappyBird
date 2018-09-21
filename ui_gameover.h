/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameover
{
public:
    QWidget *centralwidget;
    QPushButton *again;
    QLabel *label;
    QLabel *label_2;
    QLabel *lscore;
    QLabel *lbest;
    QLabel *label_3;
    QPushButton *again_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameover)
    {
        if (gameover->objectName().isEmpty())
            gameover->setObjectName(QStringLiteral("gameover"));
        gameover->resize(902, 914);
        gameover->setStyleSheet(QLatin1String("background-image: url(:/sky111.jpg);\n"
""));
        centralwidget = new QWidget(gameover);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        again = new QPushButton(centralwidget);
        again->setObjectName(QStringLiteral("again"));
        again->setGeometry(QRect(300, 550, 241, 111));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        again->setFont(font);
        again->setCursor(QCursor(Qt::PointingHandCursor));
        again->setToolTipDuration(2);
        again->setStyleSheet(QLatin1String("background-color: rgb(12, 166, 200);\n"
"color: rgb(3, 6, 139);\n"
"background-image: url();\n"
"background-color: qlineargradient(spread:pad, x1:0.179, y1:0.176818, x2:1, y2:1, stop:0 rgba(40, 212, 187, 255), stop:1 rgba(139, 231, 139, 255));"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(140, 150, 541, 281));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(72);
        label->setFont(font1);
        label->setFocusPolicy(Qt::NoFocus);
        label->setToolTipDuration(2);
        label->setStyleSheet(QLatin1String("color: rgb(12, 28, 255);\n"
"background-image: url();"));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(-15);
        label->setMidLineWidth(-6);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        label->setMargin(2);
        label->setIndent(1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 400, 131, 51));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 255);\n"
"background-image: url();"));
        label_2->setAlignment(Qt::AlignCenter);
        lscore = new QLabel(centralwidget);
        lscore->setObjectName(QStringLiteral("lscore"));
        lscore->setGeometry(QRect(440, 400, 131, 51));
        lscore->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgb(170, 85, 127);"));
        lscore->setAlignment(Qt::AlignCenter);
        lbest = new QLabel(centralwidget);
        lbest->setObjectName(QStringLiteral("lbest"));
        lbest->setGeometry(QRect(440, 460, 131, 51));
        lbest->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgb(170, 85, 127);"));
        lbest->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 460, 131, 51));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 255);\n"
"background-image: url();"));
        label_3->setAlignment(Qt::AlignCenter);
        again_2 = new QPushButton(centralwidget);
        again_2->setObjectName(QStringLiteral("again_2"));
        again_2->setGeometry(QRect(350, 680, 141, 101));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        again_2->setFont(font2);
        again_2->setCursor(QCursor(Qt::PointingHandCursor));
        again_2->setToolTipDuration(2);
        again_2->setStyleSheet(QLatin1String("background-color: rgb(12, 166, 200);\n"
"color: rgb(3, 6, 139);\n"
"background-image: url();\n"
"background-color: qlineargradient(spread:pad, x1:0.179, y1:0.176818, x2:1, y2:1, stop:0 rgba(40, 212, 187, 255), stop:1 rgba(139, 231, 139, 255));"));
        gameover->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gameover);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 902, 26));
        gameover->setMenuBar(menubar);
        statusbar = new QStatusBar(gameover);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        gameover->setStatusBar(statusbar);

        retranslateUi(gameover);

        QMetaObject::connectSlotsByName(gameover);
    } // setupUi

    void retranslateUi(QMainWindow *gameover)
    {
        gameover->setWindowTitle(QApplication::translate("gameover", "MainWindow", nullptr));
        again->setText(QApplication::translate("gameover", "Play Again", nullptr));
        label->setText(QApplication::translate("gameover", "GAME OVER", nullptr));
        label_2->setText(QApplication::translate("gameover", "Your score", nullptr));
        lscore->setText(QApplication::translate("gameover", "TextLabel", nullptr));
        lbest->setText(QApplication::translate("gameover", "Your Best score", nullptr));
        label_3->setText(QApplication::translate("gameover", "Your Best score", nullptr));
        again_2->setText(QApplication::translate("gameover", "First Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameover: public Ui_gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
