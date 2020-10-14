#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QColor>
#include <QVector>

class Player : public QWidget
{

	Q_OBJECT
public:
	explicit Player(QWidget *parent = nullptr);

	int size() const;
	void setSize(int size);

	QColor color() const;
	void setColor(const QColor &color);

	int getXPos() const;
	void setXPos(int value);

	int getYPos() const;
	void setYPos(int value);

	QString getName() const;
	void setName(const QString &name);

	int getMaxHitpoints() const;
	void setMaxHitpoints(int maxHitpoints);

	int getCurrentHitpoints() const;
	void setCurrentHitpoints(int currentHitpoints);

	QVector<QString> getConditions() const;
	void setConditions(const QVector<QString> &conditions);

signals:


protected:
	bool event(QEvent *e) override;
	void hoverEnter(QHoverEvent *event);
	void hoverLeave(QHoverEvent *event);
private:
	int mSize = 80;
	int xPos = 0;
	int yPos = 0;
	QColor mColor = Qt::black;
	QString mName = "Jeff";
	int mMaxHitpoints = 10;
	int mCurrentHitpoints = 8;
	QVector<QString> mConditions = { "Charmed", "Invisible" };
};

#endif // PLAYER_H