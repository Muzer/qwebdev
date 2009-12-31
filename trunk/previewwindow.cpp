#include "previewwindow.h"
#include "ui_previewwindow.h"

PreviewWindow::PreviewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewWindow)
{
    ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(clicked()), ui->webView, SLOT(back()));
	connect(ui->pushButton_2, SIGNAL(clicked()), ui->webView, SLOT(forward()));
	connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(go()));
	connect(ui->webView, SIGNAL(titleChanged(QString)), this, SLOT(webViewTitleChanged(QString)));
	connect(ui->webView, SIGNAL(urlChanged(QUrl)), this, SLOT(webViewUrlChanged(QUrl)));

	this->resize(800, 600);
}

PreviewWindow::~PreviewWindow()
{
    delete ui;
}

void PreviewWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PreviewWindow::resizeEvent(QResizeEvent *event)
{
	ui->verticalLayoutWidget->resize(event->size());
}

void PreviewWindow::setPage(QString page)
{
	QFile fp(page);
	fp.open(QIODevice::ReadOnly | QIODevice::Text);
	QString html = fp.readAll();
	fp.close();
	ui->webView->setHtml(html);
	this->setWindowTitle("Preview for " + page);
}

void PreviewWindow::setUrl(QString url)
{
	ui->webView->load(QUrl(url));
}

void PreviewWindow::webViewTitleChanged(QString title)
{
	this->setWindowTitle(title);
}

void PreviewWindow::webViewUrlChanged(QUrl url)
{
	ui->lineEdit->setText(url.toString());
}

void PreviewWindow::go()
{
	this->setUrl(ui->lineEdit->text());
}
