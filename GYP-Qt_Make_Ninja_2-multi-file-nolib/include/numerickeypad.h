#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSignalMapper>
#include <QScopedPointer>

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

	QScopedPointer<QLineEdit> m_lineEdit;
	QScopedPointer<QGridLayout> layout;

	QScopedPointer<QPushButton> button0;
	QScopedPointer<QPushButton> button1;
	QScopedPointer<QPushButton> button2;
	QScopedPointer<QPushButton> button3;
	QScopedPointer<QPushButton> button4;
	QScopedPointer<QPushButton> button5;
	QScopedPointer<QPushButton> button6;
	QScopedPointer<QPushButton> button7;
	QScopedPointer<QPushButton> button8;
	QScopedPointer<QPushButton> button9;
	
	QScopedPointer<QPushButton> buttonDot;
	QScopedPointer<QPushButton> buttonClear;

	QScopedPointer<QSignalMapper> mapper;
};



