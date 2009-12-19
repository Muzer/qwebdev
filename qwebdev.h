#ifndef QWEBDEV_H
#define QWEBDEV_H

#include <iostream>
#include <QMainWindow>
#include <QTabWidget>
#include <QResizeEvent>
#include <QToolBar>
#include <QToolButton>
#include <QTextEdit>
#include <QList>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include "file.h"
#include "previewwindow.h"

using namespace std;

namespace Ui {
    class QWebDev;
}

class QWebDev : public QMainWindow {
    Q_OBJECT
public:
    QWebDev(QWidget *parent = 0);
    ~QWebDev();

protected:
    void changeEvent(QEvent *e);
	void resizeEvent(QResizeEvent *event);

private:
    Ui::QWebDev *ui;

	QList<File *> openFiles;

	QTabWidget *tabs;
	QToolBar *mainToolbar;

	QToolButton *btnNewTextFile;
	QToolButton *btnOpen;
	QToolButton *btnSave;
	QToolButton *btnSaveAs;
	QToolButton *btnCloseFile;

	QToolButton *btnPreview;

private slots:
	void tChanged();
	void showWebsite(QString url);

	void newTextFile();
	void open();
	void save();
	void saveAs();
	void closeFile();

	void preview();

	void validateWebpage();

	void help();
	void about();
	void aboutQt();
	void showW3Schools();
	void showDaniweb();
	void showW3Consortium();
};

#endif // QWEBDEV_H
