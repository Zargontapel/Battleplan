#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QWidget>
#include <QSizeGrip>
#include <QColor>
#include <QVector>
#include <QRubberBand>

#include "player.h"

namespace Ui {
class GameMap;
}

class GameMap : public QWidget
{
	Q_OBJECT

public:
	explicit GameMap(QWidget *parent = nullptr);
	~GameMap();

	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

	void setBackgroundImage(const QImage &value);

signals:
	void gridSizeChanged(qreal aSize);
	void gridHOffsetChanged(int aOffset);
	void gridVOffsetChanged(int aOffset);
	void playersChanged(QVector<Player*> players);

public slots:
	void changeGridSize(qreal size);
	void changeGridHOffset(int offset);
	void changeGridVOffset(int offset);

	void changeGridColor(QColor color);
	void addPlayer(Player* apPlayer);
	void removePlayer(Player* apPlayer);
	void EmitPlayerUpdate();
	int gridSize();
	QVector<Player*> getPlayers();

protected:
	bool eventFilter(QObject* obj, QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;

private:
	Ui::GameMap *ui;
	QSizeGrip* mpSizeGrip = nullptr;
	QColor mGridColor = Qt::white;
	QVector<Player*> mPlayers;
	qreal gridStep = 20;
	int gridHOffset = 0;
	int gridVOffset = 0;
	QRubberBand* mpSelectionBox = nullptr;

	Player* mpPlayerUnderMouse = nullptr;
	QPoint mRubberBandOrigin;
	QPoint mEventPos;
	QVector<Player*> mPlayerSelection;
	QImage backgroundImage;

private slots:
	void ShowContextMenu(const QPoint& pos);
};

#endif // GAMEMAP_H
