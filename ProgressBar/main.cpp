#include "widget.h"

#include <QApplication>
#include <QProgressBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //QApplication 객체 a를 생성 이 객체는 Qt 애플리케이션의 필수 요소로, 애플리케이션의 실행과 이벤트 처리를 관리

    QProgressBar *progBar = new QProgressBar(); // QProgressBar 객체 progBar를 동적으로 생성
    progBar->setValue(20); // progBar의 진행상태값 설정
    progBar->setRange(0,50); // progBar의 진행 범위 0부터 50
    progBar->show();

    return a.exec();
}
