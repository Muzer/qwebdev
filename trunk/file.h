#ifndef FILE_H
#define FILE_H

#include <QTextEdit>
#include <QIcon>
#include <QString>

class File : public QTextEdit
{
	Q_OBJECT

public:
	File(QString title = "New File", QIcon icon = QIcon());
	~File();
	QIcon icon();
	QString title();
	QString text();
	QString filename();
	bool changed();
	void setIcon(QIcon newIcon);
	void setTitle(QString newTitle);
	void setText(QString newText);
	void setFilename(QString newFilename);
	void setChanged(bool newChangedValue);

private:
	QIcon vIcon;
	QString vTitle;
	QString vFilename;
	bool vChanged;
};

#endif // FILE_H
