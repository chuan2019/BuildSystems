#include "png_viewer.h"

GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent):
	QGraphicsView(scene, parent),
	m_scene(scene)
{
	setBackgroundBrush(QBrush(Qt::black));
}

void GraphicsView::dopaint()
{
	QString fileName = QFileDialog::getOpenFileName(0, "Load Image", "../images", 
		"Image Files (*.png *.jpg *.bmp)");

	if (!fileName.isEmpty())
	{
		QMutexLocker lock(&imageReadWriteMutex);
		m_scene->clear();
		image.load(fileName,"PNG");
		m_scene->addPixmap(QPixmap::fromImage(image));
	}
	QPainter painter(viewport());
	QPainter::CompositionMode currentCompositionMode = painter.compositionMode();
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.fillRect(sceneRect(), Qt::transparent);
	painter.setCompositionMode(currentCompositionMode);
	((GraphicsScene*)scene())->updateComplete(&painter, viewport());
	painter.end();
}

void GraphicsView::update()
{
	dopaint();
}






