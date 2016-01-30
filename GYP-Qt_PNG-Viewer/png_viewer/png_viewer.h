#include <QtCore>
#include <QtGui>
#include <QtOpenGL>
#include <QGLWidget>

static QImage image;
static QMutex imageReadWriteMutex;
static QString fileName;

class GraphicsScene: public QGraphicsScene
{
public:
	void updateComplete(QPainter *painter, QWidget *widget)
	{
		drawItems(painter, 0, 0, 0, widget);
	}
};

class GraphicsView: public QGraphicsView
{
	Q_OBJECT
public:
	GraphicsView(QGraphicsScene *scene, QWidget *parent = 0);

	void dopaint();
	
public slots:
	void update();
	
protected:
	QGraphicsScene *m_scene;
};
