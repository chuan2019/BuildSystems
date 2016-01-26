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
	
	const QString& text() const;
	
public slots:
	void setText(const QString &text);
	
signals:
	void textChanged(const QString &text);
	
private slots:
	void buttonClicked(const QString &text);
	
private:
	QLineEdit *m_lineEdit;
	QString m_text;
};



