#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <QKeyEvent>
#include <iostream>
#include <thread>
struct timeval start, end;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(reset()));
    //connect(ui->timer, SIGNAL(timeout()), this, SLOT(chronometer()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: paintEvent(QPaintEvent *e) {

    srand(time(NULL));
    QPainter painter(this);
    cor = rand()%4;

    if(cor==0){
        painter.setBrush(Qt::cyan);
    }
    else if(cor == 1){
        painter.setBrush(Qt::magenta);
    }
    else if(cor == 2){
        painter.setBrush(Qt::yellow);
    }
    else if(cor == 3){
        painter.setBrush(Qt::gray);
    }
    //800 por 450
    painter.drawEllipse(100+rand()%500,100+rand()%200,60,60);
    QWidget :: paintEvent(e);
    gettimeofday(&start, NULL);
}

void MainWindow :: keyPressEvent(QKeyEvent *e){
    gettimeofday(&end, NULL);
    int tempo = (end.tv_sec*1000 + end.tv_usec/1000) - (start.tv_sec*1000 + start.tv_usec/1000);
    bool acertou = true;
    if(tempo < 3000 && round <= 10){
        if(cor == 0 && e->key() == Qt::Key_W){
            score +=1;
        }
        else if(cor == 1 && e->key() == Qt::Key_S){
            score +=1;
        }
        else if(cor == 2 && e->key() == Qt::Key_A){
            score +=1;
        }
        else if(cor == 3 && e->key() == Qt::Key_D){
            score +=1;
        }
        else{
            acertou = false;
            score-=1;
        }
    } else if(round<=10) {
        acertou = false;
        score-=1;
    }
    QWidget ::update();
    //mostrar pontuacao
    ui->score->display(score);

    if(round <= 10 && acertou){
        count++;
        round++;
        //calcular a média
        mean = mean + tempo;
        //Mostrar a média
        ui->mean->display(tempo);
        ui->acertos->display(count);

    } else if(round <=10 && !acertou){
        round++;
    }
    if(round==11){ //acabaram os 10 rounds
        if(count != 0){
            ui->acertos->display(count);
            ui->media->display(mean/count);
            ui->resetButton->setFocus();

        }
    }
    //mostrar a media e round
    ui->round->display(round);
}


void MainWindow::reset(){
    score = 0;
    round = 1;
    mean = 0;
    count =0 ;
    QWidget ::update();
    ui->round->display(round);
    ui->mean->display(mean);
    ui->score->display(score);
    ui->acertos->display(count);
    ui->media->display(mean);
}

/*
void MainWindow::chronometer()
{
    gettimeofday(&now, NULL);
    int t = now.tv_sec*1000 + now.tv_usec/1000;
    ui->timer->display(t);
}

*/
