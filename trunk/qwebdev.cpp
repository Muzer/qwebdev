#include "qwebdev.h"
#include "ui_qwebdev.h"

QWebDev::QWebDev(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWebDev)
{
    ui->setupUi(this);

	//ui->menuNew->setIcon(QIcon::fromTheme("document-new", ":/icons/16x16/document-new.png"));
	ui->menuNew->setIcon(QIcon(":/icons/16x16/document-new.png"));

	//ui->actionNewTextFile->setIcon(QIcon::fromTheme("text-plain", ":/icons/16x16/text-plain.png"));
	ui->actionNewTextFile->setIcon(QIcon(":/icons/16x16/text-plain.png"));

	//ui->actionNewHtmlFile->setIcon(QIcon::fromTheme("text-html", ":/icons/16x16/text-html.png"));
	ui->actionNewHtmlFile->setIcon(QIcon(":/icons/16x16/text-html.png"));

	//ui->actionOpen->setIcon(QIcon::fromTheme("document-open", ":/icons/16x16/document-open.png"));
	ui->actionOpen->setIcon(QIcon(":/icons/16x16/document-open.png"));

	//ui->actionSave->setIcon(QIcon::fromTheme("document-save", ":/icons/16x16/document-save.png"));
	ui->actionSave->setIcon(QIcon(":/icons/16x16/document-save.png"));

	//ui->actionSaveAs->setIcon(QIcon::fromTheme("document-save-as", ":/icons/16x16/document-save-as.png"));
	ui->actionSaveAs->setIcon(QIcon(":/icons/16x16/document-save-as.png"));

	//ui->actionSaveAll->setIcon(QIcon::fromTheme("document-save-all", ":/icons/16x16/document-save-all.png"));
	ui->actionSaveAll->setIcon(QIcon(":/icons/16x16/document-save-all.png"));

	//ui->actionCloseFile->setIcon(QIcon::fromTheme("document-close", ":/icons/16x16/document-close.png"));
	ui->actionCloseFile->setIcon(QIcon(":/icons/16x16/document-close.png"));

	//ui->actionQuit->setIcon(QIcon::fromTheme("application-exit", ":/icons/16x16/application-exit.png"));
	ui->actionQuit->setIcon(QIcon(":/icons/16x16/application-exit.png"));


	//ui->actionPreview->setIcon(QIcon::fromTheme("video-display", ":/icons/16x16/video-display.png"));
	ui->actionPreview->setIcon(QIcon(":/icons/16x16/video-display.png"));


	//ui->actionValidateWebpage->setIcon(QIcon::fromTheme("run-build-configure", ":/icons/16x16/run-build-configure.png"));
	ui->actionValidateWebpage->setIcon(QIcon(":/icons/16x16/run-build-configure.png"));


	//ui->actionHelp->setIcon(QIcon::fromTheme("help-contents", ":/icons/16x16/help-contents.png"));
	ui->actionHelp->setIcon(QIcon(":/icons/16x16/help-contents.png"));

	//ui->actionAbout->setIcon(QIcon::fromTheme("help-about", ":/icons/16x16/help-about.png"));
	ui->actionAbout->setIcon(QIcon(":/icons/16x16/help-about.png"));

	mainToolbar = new QToolBar("Main Toolbar", this);
	mainToolbar->setFloatable(false);
	mainToolbar->setMovable(false);
	mainToolbar->setIconSize(QSize(22, 22));

	btnNewTextFile = new QToolButton(this);
	//btnNewTextFile->setIcon(QIcon::fromTheme("document-new", ":/icons/22x22/document-new.png"));
	btnNewTextFile->setIcon(QIcon(":/icons/22x22/document-new.png"));
	mainToolbar->addWidget(btnNewTextFile);

	btnOpen = new QToolButton(this);
	//btnOpen->setIcon(QIcon::fromTheme("document-open", ":/icons/22x22/document-open.png"));
	btnOpen->setIcon(QIcon(":/icons/22x22/document-open.png"));
	mainToolbar->addWidget(btnOpen);

	btnSave = new QToolButton(this);
	//btnSave->setIcon(QIcon::fromTheme("document-save", ":/icons/22x22/document-save.png"));
	btnSave->setIcon(QIcon(":/icons/22x22/document-save.png"));
	mainToolbar->addWidget(btnSave);

	btnSaveAs = new QToolButton(this);
	//btnSaveAs->setIcon(QIcon::fromTheme("document-save-as", ":/icons/22x22/document-save-as.png"));
	btnSaveAs->setIcon(QIcon(":/icons/22x22/document-save-as.png"));
	mainToolbar->addWidget(btnSaveAs);

	btnCloseFile = new QToolButton(this);
	//btnCloseFile->setIcon(QIcon::fromTheme("document-close", ":/icons/22x22/document-close.png"));
	btnCloseFile->setIcon(QIcon(":/icons/22x22/document-close.png"));
	mainToolbar->addWidget(btnCloseFile);

	mainToolbar->addSeparator();

	btnPreview = new QToolButton(this);
	//btnPreview->setIcon(QIcon::fromTheme("video-display", ":/icons/22x22/video-display.png"));
	btnPreview->setIcon(QIcon(":/icons/22x22/video-display.png"));
	mainToolbar->addWidget(btnPreview);

	mainToolbar->move(0, ui->menuBar->height());
	mainToolbar->resize(this->width(), 32);

	tabs = new QTabWidget(this);
	tabs->move(0, mainToolbar->height() + ui->menuBar->height());
	tabs->resize(this->width(), this->height() - mainToolbar->height() - ui->menuBar->height() - ui->statusBar->height());

	connect(btnNewTextFile, SIGNAL(clicked()), this, SLOT(newTextFile()));
	connect(ui->actionNewTextFile, SIGNAL(triggered()), this, SLOT(newTextFile()));

	connect(ui->actionNewHtmlFile, SIGNAL(triggered()), this, SLOT(newHtmlFile()));

	connect(btnOpen, SIGNAL(clicked()), this, SLOT(open()));
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));

	connect(btnSave, SIGNAL(clicked()), this, SLOT(save()));
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));

	connect(btnSaveAs, SIGNAL(clicked()), this, SLOT(saveAs()));
	connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));

	connect(ui->actionSaveAll, SIGNAL(triggered()), this, SLOT(saveAll()));

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
	connect(ui->actionW3Consortium, SIGNAL(triggered()), this, SLOT(showW3Consortium()));

	this->newTextFile();
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

void QWebDev::newTextFile(QString title)
{
	File *file = new File(title);
	file->setChanged(true);
	connect(file, SIGNAL(textChanged()), this, SLOT(tChanged()));
	openFiles.append(file);
	tabs->addTab(file, file->title());
	tabs->setCurrentIndex(openFiles.length() - 1);
}

void QWebDev::newHtmlFile()
{
	QFile fp(":/defaults/html.txt");
	fp.open(QIODevice::ReadOnly | QIODevice::Text);
	QString text = fp.readAll();
	fp.close();
	this->newTextFile("New HTML File");
	openFiles[openFiles.length() - 1]->setText(text);
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

bool QWebDev::save(int id)
{
	int index = id;
	if (index == -1)
	{
		index = tabs->currentIndex();
	}
	if (index == -1)
	{
		return false;
	}
	File *file = openFiles[index];
	QString filename = file->filename();
	if (file->filename() == "none")
	{
		filename = QFileDialog::getSaveFileName(this, "Save File", "/home", "Web Files (*.html *.htm *.php *.pl *.py *.sql *.cgi *.txt)");
	}
	if (filename.length() == 0)
	{
		return false;
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

	tabs->setTabText(index, file->title());

	return true;
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

void QWebDev::saveAll()
{
	for (int i = 0; i < openFiles.count(); i++)
	{
		save(i);
	}
}

void QWebDev::closeFile()
{
	if (tabs->currentIndex() == -1)
	{
		return;
	}
	int i = tabs->currentIndex();
	if (openFiles[i]->changed() && openFiles[i]->text() != "")
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
		int ret = QMessageBox::question(this, "Save file?", "To continue, you will need to save this file. Do you want to save this file now?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		switch (ret)
		{
			case QMessageBox::Yes:
			{
				if (!this->save())
				{
					return;
				}
			}
			break;
			default:
			{
				return;
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
