#include "file.h"

File::File(QString title, QIcon icon)
{
	vTitle = title;
	vIcon = icon;
	vFilename = "none";
	vChanged = false;
	this->setFontFamily("fixed");
}

QIcon File::icon()
{
	return vIcon;
}

QString File::title()
{
	return vTitle;
}

QString File::text()
{
	return this->toPlainText();
}

QString File::filename()
{
	return vFilename;
}

bool File::changed()
{
	return vChanged;
}

void File::setIcon(QIcon newIcon)
{
	vIcon = newIcon;
}

void File::setTitle(QString newTitle)
{
	vTitle = newTitle;
}

void File::setText(QString newText)
{
	this->clear();
	this->setPlainText(newText);
}

void File::setFilename(QString newFilename)
{
	vFilename = newFilename;
}

void File::setChanged(bool newChangedValue)
{
	vChanged = newChangedValue;
}
