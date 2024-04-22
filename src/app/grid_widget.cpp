#include "grid_widget.h"

Grid::Grid(QWidget *parent) : QWidget(parent) {
    // You can set the size policy or other properties here if needed
    setMinimumSize(2000, 2000);
}

void Grid::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));

    // Draw vertical lines
    for (int x = 0; x < width(); x += cellSize) {
        painter.drawLine(x, 0, x, height());
    }

    // Draw horizontal lines
    for (int y = 0; y < height(); y += cellSize) {
        painter.drawLine(0, y, width(), y);
    }

    // Draw station
    painter.setBrush(Qt::blue);
    painter.drawRect(station.x * cellSize, station.y * cellSize, cellSize, cellSize);
    update();


    // Draw object
    painter.setBrush(Qt::red);
    painter.drawEllipse(object.x * cellSize, object.y * cellSize, cellSize, cellSize);
    update();
}

void Grid::setStation(const int x, const int y) {
    station.x = x;
    station.y = y;
    update(); // Trigger a repaint
}

void Grid::setObject(const int x, const int y) {
    object.x = x;
    object.y = y;
    update(); // Trigger a repaint
}
