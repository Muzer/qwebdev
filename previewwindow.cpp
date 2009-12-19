#include "previewwindow.h"
#include "ui_previewwindow.h"

PreviewWindow::PreviewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewWindow)
{
    ui->setupUi(this);
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
	ui->webView->resize(event->size());
	event->accept();
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
	this->setWindowTitle(url);
	this->resize(800, 600);
}
