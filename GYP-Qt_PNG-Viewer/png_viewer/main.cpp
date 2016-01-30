#include <QApplication>
#include "png_viewer.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QWidget widget;
	QGridLayout *layout = new QGridLayout(&widget);

	QPushButton *btn = new QPushButton("Load Image");
	layout->addWidget(btn, 0, 0);

	GraphicsScene scene;
	scene.setSceneRect(QRect(-100, -50, 500, 450));
	GraphicsView view(&scene);
	view.setViewport(
		new QGLWidget(
			QGLFormat(
				QGL::NoDepthBuffer|
				QGL::NoStencilBuffer|
				QGL::NoSampleBuffers
			)
		)
	);
	view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	view.setFrameStyle(0);

	layout->addWidget(&view, 1, 0);
	
	QObject::connect(btn, SIGNAL(clicked()), &view, SLOT(update()));

	widget.show();

	return a.exec();
}

