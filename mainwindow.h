#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void moveTaskToDoing();
    void moveTaskToDone();
    void deleteTask();
    void updateButtonState();

private:
    QLineEdit *taskInput;
    QListWidget *todoList;
    QListWidget *doingList;
    QListWidget *doneList;

    QPushButton *moveToDoingButton;
    QPushButton *moveToDoneButton;
    QPushButton *deleteButton;

    void moveTask(QListWidget *from, QListWidget *to);
    void saveTasks();
    void loadTasks();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // MAINWINDOW_H
