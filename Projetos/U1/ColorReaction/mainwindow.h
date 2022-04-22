#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chrono>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int cor;
    int score=0;
    int round = 1;
    int count = 0;
    int mean = 0.0;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
    ~MainWindow();
public slots:
    void reset();
    //void chronometer();
protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
