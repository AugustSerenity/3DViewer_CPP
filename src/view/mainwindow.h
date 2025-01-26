#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QDir>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QStringList>
#include <QWidget>
#include <QtGui>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include "../controller/controller.h"
#include "gifimage/qgifimage.h"
#include "glview.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::controller *Controller, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_listView_doubleClicked(const QModelIndex &index);
  void on_pushButton_clicked();
  void setColor();
  void proectionChanged();
  void dotTypeChanged();
  void lineTypeChanged();
  void radioButtonValue();

  void on_verticalScrollBar_valueChanged(int value);
  void on_pushButtonGIF_clicked();
  void on_pushButtonJPG_clicked();
  void on_pushButtonBMP_clicked();
  void slotTimerFinish();

 private:
  void settingConfig();
  Ui::MainWindow *ui;
  s21::controller *Controller;
  glView *win;
  QFileSystemModel *fileList;
  QDir dir;
  QString choiceDirectory;
  s21::Settings Options;
  int index = 0;
  int valueScrolBar = 50;
  int valueZoomeLine = 0;
  int valueZoomeDot = 0;
  int valueZoomeModel = 50;
  QColor color;
  QString checkerName;
  QImage *images;
  int imagesCounter;
  QTimer *timer;
};
#endif  // MAINWINDOW_H
