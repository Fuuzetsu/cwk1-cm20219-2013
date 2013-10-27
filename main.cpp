#include <QApplication>
#include "window.h"

//Main is needed in all win32 applications
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Window appWindow;

    appWindow.show();

    app.exec();

    return 0;
}
