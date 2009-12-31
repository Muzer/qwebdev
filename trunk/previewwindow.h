#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QResizeEvent>
#include <QUrl>

namespace Ui {
    class PreviewWindow;
}

class PreviewWindow : public QWidget {
    Q_OBJECT
public:
    PreviewWindow(QWidget *parent = 0);
    ~PreviewWindow();
	void setPage(QString page);
	void setUrl(QString url);

protected:
    void changeEvent(QEvent *e);
	void resizeEvent(QResizeEvent *event);

private:
    Ui::PreviewWindow *ui;

private slots:
	void webViewTitleChanged(QString title);
	void webViewUrlChanged(QUrl url);
	void go();
};

#endif // PREVIEWWINDOW_H
