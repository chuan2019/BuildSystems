#include <QApplication>
#include "../include/numerickeypad.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QWidget widget;
	QVBoxLayout *layout = new QVBoxLayout(&widget);

	NumericKeypad pad;
	layout->addWidget(&pad);
	
	QLabel *label = new QLabel;
	layout->addWidget(label);
	
	QObject::connect(&pad, SIGNAL(textChanged(const QString&)),
					 label, SLOT(setText(const QString&)) );
	
	widget.show();

	return a.exec();
}



