#ifndef ZENWRITER_H
#define ZENWRITER_H

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMainWindow>
#include <phonon/mediaobject.h>

namespace Ui {
    class ZenWriter;
}

class ZenWriter : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZenWriter(QWidget *parent = 0);
    ~ZenWriter();

private slots:
    void on_actionSave_activated();

    void on_actionOpen_activated();

    void on_actionSave_as_activated();

    void on_actionQuit_activated();

    void on_plainTextEdit_cursorPositionChanged();

private:
    QFile file;
    Ui::ZenWriter *ui;
    Phonon::MediaObject *typewriter;
};

#endif // ZENWRITER_H
