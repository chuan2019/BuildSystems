#include "numerickeypad.h"

NumericKeypad::NumericKeypad(QWidget *parent)
{
	layout.reset(new QGridLayout(this));
	m_lineEdit.reset(new QLineEdit);
	m_lineEdit->setAlignment(Qt::AlignRight);
	
	button0.reset(new QPushButton(tr("0")));
	button1.reset(new QPushButton(tr("1")));
	button2.reset(new QPushButton(tr("2")));
	button3.reset(new QPushButton(tr("3")));
	button4.reset(new QPushButton(tr("4")));
	button5.reset(new QPushButton(tr("5")));
	button6.reset(new QPushButton(tr("6")));
	button7.reset(new QPushButton(tr("7")));
	button8.reset(new QPushButton(tr("8")));
	button9.reset(new QPushButton(tr("9")));
	
	buttonDot.reset(new QPushButton(tr(".")));
	buttonClear.reset(new QPushButton(tr("C")));
	
	layout->addWidget(m_lineEdit.data(), 0, 0, 1, 3);
	
	layout->addWidget(button1.data(), 1, 0);
	layout->addWidget(button2.data(), 1, 1);
	layout->addWidget(button3.data(), 1, 2);
	layout->addWidget(button4.data(), 2, 0);
	layout->addWidget(button5.data(), 2, 1);
	layout->addWidget(button6.data(), 2, 2);
	layout->addWidget(button7.data(), 3, 0);
	layout->addWidget(button8.data(), 3, 1);
	layout->addWidget(button9.data(), 3, 2);
	layout->addWidget(button0.data(), 4, 0);
	layout->addWidget(buttonDot.data(), 4, 1);
	layout->addWidget(buttonClear.data(), 4, 2);
	
	mapper.reset(new QSignalMapper(this));
	
	mapper->setMapping(button0.data(), "0");
	mapper->setMapping(button1.data(), "1");
	mapper->setMapping(button2.data(), "2");
	mapper->setMapping(button3.data(), "3");
	mapper->setMapping(button4.data(), "4");
	mapper->setMapping(button5.data(), "5");
	mapper->setMapping(button6.data(), "6");
	mapper->setMapping(button7.data(), "7");
	mapper->setMapping(button8.data(), "8");
	mapper->setMapping(button9.data(), "9");
	mapper->setMapping(buttonDot.data(), ".");
	
	connect(button0.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button1.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button2.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button3.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button4.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button5.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button6.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button7.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button8.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(button9.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));
	connect(buttonDot.data(), SIGNAL(clicked()), mapper.data(), SLOT(map()));

	connect(mapper.data(), SIGNAL(mapped(QString)), this, SLOT(buttonClicked(QString)));
	
	connect(buttonClear.data(), SIGNAL(clicked()), m_lineEdit.data(), SLOT(clear()));
	connect(m_lineEdit.data(), SIGNAL(textChanged(QString)), this, SLOT(setText(QString)));
}

NumericKeypad::~NumericKeypad()
{
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


