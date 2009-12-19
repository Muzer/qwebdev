#include "qwebdev.h"
#include "ui_qwebdev.h"

QWebDev::QWebDev(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWebDev)
{
    ui->setupUi(this);

	mainToolbar = new QToolBar("Main Toolbar", this);
	mainToolbar->setFloatable(false);
	mainToolbar->setMovable(false);

	btnNewTextFile = new QToolButton(this);
	//btnNew->setIcon(QIcon::fromTheme("document-new"));
	btnNewTextFile->setText("New");
	mainToolbar->addWidget(btnNewTextFile);

	btnOpen = new QToolButton(this);
	//btnNew->setIcon(QIcon::fromTheme("document-new"));
	btnOpen->setText("Open");
	mainToolbar->addWidget(btnOpen);

	btnSave = new QToolButton(this);
	//btnNew->setIcon(QIcon::fromTheme("document-new"));
	btnSave->setText("Save");
	mainToolbar->addWidget(btnSave);

	btnSaveAs = new QToolButton(this);
	//btnNew->setIcon(QIcon::fromTheme("document-new"));
	btnSaveAs->setText("Save As");
	mainToolbar->addWidget(btnSaveAs);

	btnCloseFile = new QToolButton(this);
	//btnNew->setIcon(QIcon::fromTheme("document-new"));
	btnCloseFile->setText("Close File");
	mainToolbar->addWidget(btnCloseFile);

	mainToolbar->addSeparator();

	btnPreview = new QToolButton(this);
	//btnNew->setIcon(QIcon::fromTheme("document-new"));
	btnPreview->setText("Preview");
	mainToolbar->addWidget(btnPreview);

	mainToolbar->move(0, ui->menuBar->height());
	mainToolbar->resize(this->width(), 32);

	tabs = new QTabWidget(this);
	tabs->move(0, mainToolbar->height() + ui->menuBar->height());
	tabs->resize(this->width(), this->height() - mainToolbar->height() - ui->menuBar->height() - ui->statusBar->height());

	connect(btnNewTextFile, SIGNAL(clicked()), this, SLOT(newTextFile()));
	connect(ui->actionNewTextFile, SIGNAL(triggered()), this, SLOT(newTextFile()));

	connect(btnOpen, SIGNAL(clicked()), this, SLOT(open()));
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));

	connect(btnSave, SIGNAL(clicked()), this, SLOT(save()));
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));

	connect(btnSaveAs, SIGNAL(clicked()), this, SLOT(saveAs()));
	connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));

	connect(btnCloseFile, SIGNAL(clicked()), this, SLOT(closeFile()));
	connect(ui->actionCloseFile, SIGNAL(triggered()), this, SLOT(closeFile()));


	connect(btnPreview, SIGNAL(clicked()), this, SLOT(preview()));
	connect(ui->actionPreview, SIGNAL(triggered()), this, SLOT(preview()));


	connect(ui->actionValidateWebpage, SIGNAL(triggered()), this, SLOT(validateWebpage()));


	connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(help()));
	connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
	connect(ui->actionAboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));

	connect(ui->actionW3Schools, SIGNAL(triggered()), this, SLOT(showW3Schools()));
	connect(ui->actionDaniweb, SIGNAL(triggered()), this, SLOT(showDaniweb()));
	connect(ui->actionW3_Consortium, SIGNAL(triggered()), this, SLOT(showW3Consortium()));
}

QWebDev::~QWebDev()
{
	delete ui;
	delete tabs;
	delete mainToolbar;
}

void QWebDev::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void QWebDev::resizeEvent(QResizeEvent *event)
{
	mainToolbar->move(0, ui->menuBar->height());
	mainToolbar->resize(this->width(), mainToolbar->height());

	tabs->resize(this->width(), this->height() - mainToolbar->height() - ui->menuBar->height() - ui->statusBar->height());
	tabs->move(0, mainToolbar->height() + ui->menuBar->height());

	event->accept();
}

void QWebDev::tChanged()
{
	File *file = openFiles[tabs->currentIndex()];
	file->setChanged(true);
}

void QWebDev::showWebsite(QString url)
{
	PreviewWindow *w = new PreviewWindow;
	w->setUrl(url);
	w->show();
}

void QWebDev::newTextFile()
{
	File *file = new File();
	file->setChanged(true);
	connect(file, SIGNAL(textChanged()), this, SLOT(tChanged()));
	openFiles.append(file);
	tabs->addTab(file, file->title());
}

void QWebDev::open()
{
	QString filename = QFileDialog::getOpenFileName(this, "Open File", "/home", "Web Files (*.html *.htm *.php *.pl *.py *.sql *.cgi *.txt)");
	if (filename.length() == 0)
	{
		return;
	}
	QString title = filename.split("/")[filename.split("/").length() - 1];
	File *file = new File(title);
	file->setFilename(filename);
	QFile fp(filename);
	fp.open(QIODevice::ReadOnly | QIODevice::Text);
	QString t = fp.readAll();
	fp.close();
	file->setText(t);
	connect(file, SIGNAL(textChanged()), this, SLOT(tChanged()));
	openFiles.append(file);
	tabs->addTab(file, file->title());
}

void QWebDev::save()
{
	if (tabs->currentIndex() == -1)
	{
		return;
	}
	File *file = openFiles[tabs->currentIndex()];
	QString filename = file->filename();
	if (file->filename() == "none")
	{
		filename = QFileDialog::getSaveFileName(this, "Save File", "/home", "Web Files (*.html *.htm *.php *.pl *.py *.sql *.cgi *.txt)");
	}
	if (filename.length() == 0)
	{
		return;
	}
	QFile fp(filename);
	fp.open(QIODevice::WriteOnly | QIODevice::Text);
	QByteArray data;
	data.append(file->text());
	fp.write(data);
	fp.close();

	file->setFilename(filename);
	file->setTitle(filename.split("/")[filename.split("/").length() - 1]);
	file->setChanged(false);

	tabs->setTabText(tabs->currentIndex(), file->title());
}

void QWebDev::saveAs()
{
	if (tabs->currentIndex() == -1)
	{
		return;
	}
	File *file = openFiles[tabs->currentIndex()];
	QString filename = QFileDialog::getSaveFileName(this, "Save File As", "/home", "Web Files (*.html *.htm *.php *.pl *.py *.sql *.cgi *.txt)");
	if (filename.length() == 0)
	{
		return;
	}
	QFile fp(filename);
	fp.open(QIODevice::WriteOnly | QIODevice::Text);
	QByteArray data;
	data.append(file->text());
	fp.write(data);
	fp.close();

	file->setFilename(filename);
	file->setTitle(filename.split("/")[filename.split("/").length() - 1]);
	file->setChanged(false);

	tabs->setTabText(tabs->currentIndex(), file->title());
}

void QWebDev::closeFile()
{
	if (tabs->currentIndex() == -1)
	{
		return;
	}
	int i = tabs->currentIndex();
	if (openFiles[i]->changed())
	{
		int ret = QMessageBox::question(this, "Save file?", "Do you want to save this file before you close it?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save);
		switch (ret)
		{
			case QMessageBox::Cancel:
			{
				return;
			}
			break;
			case QMessageBox::Save:
			{
				save();
			}
			break;
		}
	}
	tabs->removeTab(i);
	openFiles.removeAt(i);
}

void QWebDev::preview()
{
	if (tabs->currentIndex() == -1)
	{
		return;
	}
	int i = tabs->currentIndex();
	if (openFiles[i]->changed())
	{
		int ret = QMessageBox::question(this, "Save file?", "Do you want to save this file before you preview it?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		switch (ret)
		{
			case QMessageBox::Yes:
			{
				save();
			}
			break;
		}
	}
	PreviewWindow *w = new PreviewWindow;
	w->setPage(openFiles[i]->filename());
	w->show();
}

void QWebDev::validateWebpage()
{
	PreviewWindow *w = new PreviewWindow;
	QString url = "http://validator.w3.org/#validate_by_upload";
	w->setUrl(url);
	w->show();
}

void QWebDev::help()
{
	QMessageBox::critical(this, "No help!", "Currently, there is no help.");
}

void QWebDev::about()
{
	QMessageBox::about(this, "About QWebDev", "QWebDev is an application written in Qt to help with creating websites.");
}

void QWebDev::aboutQt()
{
	QMessageBox::aboutQt(this, "About Qt");
}

void QWebDev::showW3Schools()
{
	showWebsite("http://www.w3schools.com/");
}

void QWebDev::showDaniweb()
{
	showWebsite("http://www.daniweb.com/forums/forum31.html");
}

void QWebDev::showW3Consortium()
{
	showWebsite("http://www.w3.org/");
}
