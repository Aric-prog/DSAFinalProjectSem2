/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addNodeButton;
    QGraphicsView *graphicsView;
    QPushButton *setStart;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QMenu *menuDjikstra_s_Algorithm_Visualisation;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        addNodeButton = new QPushButton(centralwidget);
        addNodeButton->setObjectName(QString::fromUtf8("addNodeButton"));
        addNodeButton->setGeometry(QRect(10, 590, 121, 61));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1280, 720));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(1280, 720));
        graphicsView->setMaximumSize(QSize(1280, 720));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setSceneRect(QRectF(0, 0, 1280, 720));
        graphicsView->setDragMode(QGraphicsView::NoDrag);
        setStart = new QPushButton(centralwidget);
        setStart->setObjectName(QString::fromUtf8("setStart"));
        setStart->setGeometry(QRect(150, 590, 131, 61));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(1080, 590, 131, 61));
        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        addNodeButton->raise();
        setStart->raise();
        clearButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        menuDjikstra_s_Algorithm_Visualisation = new QMenu(menubar);
        menuDjikstra_s_Algorithm_Visualisation->setObjectName(QString::fromUtf8("menuDjikstra_s_Algorithm_Visualisation"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuDjikstra_s_Algorithm_Visualisation->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addNodeButton->setText(QCoreApplication::translate("MainWindow", "Add Node", nullptr));
        setStart->setText(QCoreApplication::translate("MainWindow", "Set Start Node", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        menuDjikstra_s_Algorithm_Visualisation->setTitle(QCoreApplication::translate("MainWindow", "Djikstra's Algorithm Visualisation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
