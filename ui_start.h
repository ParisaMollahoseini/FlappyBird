/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QWidget *centralwidget;
    QPushButton *newgame;
    QPushButton *start;
    QPushButton *yourscore;
    QLabel *scorelabel;
    QListWidget *scorelist;
    QPushButton *back;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QStringLiteral("Start"));
        Start->resize(902, 917);
        Start->setStyleSheet(QStringLiteral("background-image: url(:/Picture1.jpg);"));
        centralwidget = new QWidget(Start);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        newgame = new QPushButton(centralwidget);
        newgame->setObjectName(QStringLiteral("newgame"));
        newgame->setGeometry(QRect(150, 560, 171, 71));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        newgame->setFont(font);
        newgame->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        start = new QPushButton(centralwidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(530, 560, 171, 71));
        start->setFont(font);
        start->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        yourscore = new QPushButton(centralwidget);
        yourscore->setObjectName(QStringLiteral("yourscore"));
        yourscore->setGeometry(QRect(330, 660, 181, 71));
        yourscore->setFont(font);
        yourscore->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        scorelabel = new QLabel(centralwidget);
        scorelabel->setObjectName(QStringLiteral("scorelabel"));
        scorelabel->setGeometry(QRect(300, 90, 261, 101));
        scorelabel->setFont(font);
        scorelabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        scorelabel->setAlignment(Qt::AlignCenter);
        scorelist = new QListWidget(centralwidget);
        scorelist->setObjectName(QStringLiteral("scorelist"));
        scorelist->setGeometry(QRect(330, 220, 221, 192));
        QFont font1;
        font1.setFamily(QStringLiteral("8514oem"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        scorelist->setFont(font1);
        scorelist->setStyleSheet(QLatin1String("background-image: url();\n"
"color: rgb(0, 85, 0);\n"
"border-color: qlineargradient(spread:pad, x1:0.179, y1:0.176818, x2:1, y2:1, stop:0 rgba(40, 212, 187, 255), stop:1 rgba(139, 231, 139, 255));\n"
"border-color: rgb(170, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0.179, y1:0.176818, x2:1, y2:1, stop:0 rgba(40, 212, 187, 255), stop:1 rgba(139, 231, 139, 255));"));
        scorelist->setFrameShape(QFrame::StyledPanel);
        scorelist->setFrameShadow(QFrame::Sunken);
        scorelist->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scorelist->setSelectionMode(QAbstractItemView::NoSelection);
        scorelist->setFlow(QListView::TopToBottom);
        scorelist->setResizeMode(QListView::Adjust);
        scorelist->setViewMode(QListView::IconMode);
        back = new QPushButton(centralwidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(650, 250, 101, 161));
        back->setFont(font);
        back->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        Start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Start);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 902, 26));
        Start->setMenuBar(menubar);
        statusbar = new QStatusBar(Start);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Start->setStatusBar(statusbar);

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QMainWindow *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "MainWindow", nullptr));
        newgame->setText(QApplication::translate("Start", "New Game", nullptr));
        start->setText(QApplication::translate("Start", "Continue", nullptr));
        yourscore->setText(QApplication::translate("Start", "Your Scores", nullptr));
        scorelabel->setText(QApplication::translate("Start", "Your Scores", nullptr));
        back->setText(QApplication::translate("Start", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
