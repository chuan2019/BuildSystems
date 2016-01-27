#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSignalMapper>

class NumericKeypad : public QWidget
{
	Q_OBJECT
public:
	NumericKeypad(QWidget *parent = 0);
	virtual ~NumericKeypad();
	
	const QString& text() const;
	
public slots:
	void setText(const QString &text);
	
signals:
	void textChanged(const QString &text);
	
private slots:
	void buttonClicked(const QString &text);
	
private:
	QString 	m_text;

	QLineEdit 	*m_lineEdit;
	QGridLayout *layout;

	QPushButton *button0;
	QPushButton *button1;
	QPushButton *button2;
	QPushButton *button3;
	QPushButton *button4;
	QPushButton *button5;
	QPushButton *button6;
	QPushButton *button7;
	QPushButton *button8;
	QPushButton *button9;
	
	QPushButton *buttonDot;
	QPushButton *buttonClear;

	QSignalMapper *mapper;
};



