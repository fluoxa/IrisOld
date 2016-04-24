#include <app/App.hpp>

int main(int number, char** commandLine)
{
    App app(number, commandLine);

    app.init();

    //TODO: hier alle exceptions abfangen und den fehler ausgeben
    app.run();

    return 0;
}
