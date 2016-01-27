#include "numerickeypad.h"

NumericKeypad::NumericKeypad(QWidget *parent)
{
	layout = new QGridLayout(this);
	m_lineEdit = new QLineEdit;
	m_lineEdit->setAlignment(Qt::AlignRight);
	
	button0 = new QPushButton(tr("0"));
	button1 = new QPushButton(tr("1"));
	button2 = new QPushButton(tr("2"));
	button3 = new QPushButton(tr("3"));
	button4 = new QPushButton(tr("4"));
	button5 = new QPushButton(tr("5"));
	button6 = new QPushButton(tr("6"));
	button7 = new QPushButton(tr("7"));
	button8 = new QPushButton(tr("8"));
	button9 = new QPushButton(tr("9"));
	
	buttonDot = new QPushButton(tr("."));
	buttonClear = new QPushButton(tr("C"));
	
	layout->addWidget(m_lineEdit, 0, 0, 1, 3);
	
	layout->addWidget(button1, 1, 0);
	layout->addWidget(button2, 1, 1);
	layout->addWidget(button3, 1, 2);
	layout->addWidget(button4, 2, 0);
	layout->addWidget(button5, 2, 1);
	layout->addWidget(button6, 2, 2);
	layout->addWidget(button7, 3, 0);
	layout->addWidget(button8, 3, 1);
	layout->addWidget(button9, 3, 2);
	layout->addWidget(button0, 4, 0);
	layout->addWidget(buttonDot, 4, 1);
	layout->addWidget(buttonClear, 4, 2);
	
	mapper = new QSignalMapper(this);
	
	mapper->setMapping(button0, "0");
	mapper->setMapping(button1, "1");
	mapper->setMapping(button2, "2");
	mapper->setMapping(button3, "3");
	mapper->setMapping(button4, "4");
	mapper->setMapping(button5, "5");
	mapper->setMapping(button6, "6");
	mapper->setMapping(button7, "7");
	mapper->setMapping(button8, "8");
	mapper->setMapping(button9, "9");
	mapper->setMapping(buttonDot, ".");
	
	connect(button0, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button1, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button2, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button3, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button4, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button5, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button6, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button7, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button8, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(button9, SIGNAL(clicked()), mapper, SLOT(map()));
	connect(buttonDot, SIGNAL(clicked()), mapper, SLOT(map()));

	connect(mapper, SIGNAL(mapped(QString)), this, SLOT(buttonClicked(QString)));
	
	connect(buttonClear, SIGNAL(clicked()), m_lineEdit, SLOT(clear()));
	connect(m_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(setText(QString)));
}

NumericKeypad::~NumericKeypad()
{
	delete m_lineEdit;
	delete layout;
	delete button0;
	delete button1;
	delete button2;
	delete button3;
	delete button4;
	delete button5;
	delete button6;
	delete button7;
	delete button8;
	delete button9;
	delete buttonDot;
	delete buttonClear;
	delete mapper;
}

void NumericKeypad::buttonClicked(const QString &newText)
{
	setText(m_text + newText);
}

void NumericKeypad::setText(const QString &newText)
{
	if (newText == m_text) return;
	m_text = newText;
	m_lineEdit->setText(m_text);
	emit textChanged(m_text);
}

const QString& NumericKeypad::text() const
{
	return m_text;
}


