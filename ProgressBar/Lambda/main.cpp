#include "widget.h"

#include <QApplication>
#include <QProgressBar>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //QApplication 객체 a를 생성 이 객체는 Qt 애플리케이션의 필수 요소로, 애플리케이션의 실행과 이벤트 처리를 관리
    QProgressBar *progBar = new QProgressBar(); // QProgressBar 객체 progBar를 동적으로 생성
    progBar->show();

    QTimer timer;
    int n = 0;
    QObject::connect(&timer,&QTimer::timeout,[&]{progBar->setValue(++n%101);});

    /*
    QObject::connect 시그널과 슬롯을 연결하는 함수,timer 객체의 timeout 시그널이 발생할 때마다 람다 함수가 호출
    &QTimer::timeout QTimer의 타이머가 종료될 때 발생하는 시그널을 나타냄
    [&]{ progBar->setValue(++n % 101); } 람다 함수, n 값을 증가시키고 101로 나눈 나머지를 진행 표시줄의 값으로 설정
    ++n n을 1 증가시키고, n % 101은 증가된 n을 101로 나눈 나머지를 계산하여, 진행 표시줄의 값이 0에서 100 사이를 반복
    */

    timer.start(10);

    return a.exec();
}
