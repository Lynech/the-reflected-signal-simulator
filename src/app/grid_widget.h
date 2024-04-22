#ifndef GRID_WIDGET_H
#define GRID_WIDGET_H

#include <QWidget>
#include <QPainter>

class Grid : public QWidget {
    Q_OBJECT

public:
    explicit Grid(QWidget *parent = nullptr);
    void setStation(const int x, const int y);
    void setObject(const int x, const int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    struct Station {
        int x;
        int y;
        // int size;
    };

    struct Object {
        int x;
        int y;
    };

    int cellSize = 25;
    // QVector<Square> squares;
    Station station;
    Object object;
    // QVector<Ellipse> ellipses;
};

#endif // GRID_WIDGET_H
