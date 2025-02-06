#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSettings>
#include <QFont>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    taskInput = new QLineEdit(this);
    taskInput->setPlaceholderText("Enter task...");
    taskInput->setStyleSheet("font-size: 16px; padding: 5px; background-color: #333333; color: white; border: 1px solid #444444;");

    QPushButton *addButton = new QPushButton("Add Task", this);
    addButton->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px; font-size: 14px; border-radius: 5px;");
    addButton->setFixedHeight(35);

    inputLayout->addWidget(taskInput);
    inputLayout->addWidget(addButton);

    QLabel *todoLabel = new QLabel("To-Do", this);
    todoLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #F1F1F1;");
    QLabel *doingLabel = new QLabel("Doing", this);
    doingLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #F1F1F1;");
    QLabel *doneLabel = new QLabel("Done", this);
    doneLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #F1F1F1;");

    todoList = new QListWidget(this);
    doingList = new QListWidget(this);
    doneList = new QListWidget(this);

    todoList->setStyleSheet("background-color: #2C2F34; color: white; border-radius: 10px; padding: 5px;");
    doingList->setStyleSheet("background-color: #3C4348; color: white; border-radius: 10px; padding: 5px;");
    doneList->setStyleSheet("background-color: #1B5E20; color: white; border-radius: 10px; padding: 5px;");

    QVBoxLayout *todoLayout = new QVBoxLayout();
    QVBoxLayout *doingLayout = new QVBoxLayout();
    QVBoxLayout *doneLayout = new QVBoxLayout();

    todoLayout->addWidget(todoLabel);
    todoLayout->addWidget(todoList);

    doingLayout->addWidget(doingLabel);
    doingLayout->addWidget(doingList);

    doneLayout->addWidget(doneLabel);
    doneLayout->addWidget(doneList);

    QHBoxLayout *listLayout = new QHBoxLayout();
    listLayout->addLayout(todoLayout);
    listLayout->addLayout(doingLayout);
    listLayout->addLayout(doneLayout);

    moveToDoingButton = new QPushButton("Move to Doing", this);
    moveToDoingButton->setStyleSheet(
        "QPushButton { background-color: #FF9800; color: white; padding: 8px; font-size: 14px; border-radius: 5px; }"
        "QPushButton:disabled { background-color: #B0B0B0; color: #808080; }"
        );
    moveToDoingButton->setFixedSize(120, 35);
    moveToDoingButton->setEnabled(false);

    moveToDoneButton = new QPushButton("Move to Done", this);
    moveToDoneButton->setStyleSheet(
        "QPushButton { background-color: #4CAF50; color: white; padding: 8px; font-size: 14px; border-radius: 5px; }"
        "QPushButton:disabled { background-color: #B0B0B0; color: #808080; }"
        );
    moveToDoneButton->setFixedSize(120, 35);
    moveToDoneButton->setEnabled(false);

    deleteButton = new QPushButton("Delete", this);
    deleteButton->setStyleSheet(
        "QPushButton { background-color: #F44336; color: white; padding: 8px; font-size: 14px; border-radius: 5px; }"
        "QPushButton:disabled { background-color: #B0B0B0; color: #808080; }"
        );
    deleteButton->setFixedSize(120, 35);
    deleteButton->setEnabled(false);

    QVBoxLayout *todoButtonLayout = new QVBoxLayout();
    todoButtonLayout->addWidget(moveToDoingButton);
    todoButtonLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QVBoxLayout *doingButtonLayout = new QVBoxLayout();
    doingButtonLayout->addWidget(moveToDoneButton);
    doingButtonLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QVBoxLayout *doneButtonLayout = new QVBoxLayout();
    doneButtonLayout->addWidget(deleteButton);
    doneButtonLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addLayout(todoButtonLayout);
    buttonLayout->addLayout(doingButtonLayout);
    buttonLayout->addLayout(doneButtonLayout);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(listLayout);
    mainLayout->addLayout(buttonLayout);

    setCentralWidget(centralWidget);

    setStyleSheet("QMainWindow { background-color: #1C1C1C; border-radius: 10px; }");

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(taskInput, &QLineEdit::returnPressed, this, &MainWindow::addTask);  // Connect Enter key press to addTask
    connect(moveToDoingButton, &QPushButton::clicked, this, &MainWindow::moveTaskToDoing);
    connect(moveToDoneButton, &QPushButton::clicked, this, &MainWindow::moveTaskToDone);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteTask);

    connect(todoList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateButtonState);
    connect(doingList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateButtonState);
    connect(doneList, &QListWidget::itemSelectionChanged, this, &MainWindow::updateButtonState);

    loadTasks();
}

MainWindow::~MainWindow() { saveTasks(); }

void MainWindow::addTask()
{
    QString taskText = taskInput->text().trimmed();

    if (taskText.isEmpty()) {
        return;
    }

    bool taskExists = false;

    for (int i = 0; i < todoList->count(); ++i) {
        if (todoList->item(i)->text() == taskText) {
            taskExists = true;
            break;
        }
    }

    for (int i = 0; i < doingList->count(); ++i) {
        if (doingList->item(i)->text() == taskText) {
            taskExists = true;
            break;
        }
    }

    for (int i = 0; i < doneList->count(); ++i) {
        if (doneList->item(i)->text() == taskText) {
            taskExists = true;
            break;
        }
    }

    if (taskExists) {
        QMessageBox::warning(this, "Duplicate Task", "This task already exists in the list.");
        return;
    }

    todoList->addItem(taskText);
    taskInput->clear();
    saveTasks();
}


void MainWindow::moveTaskToDoing()
{
    QListWidgetItem *item = todoList->currentItem();
    if (item) {
        doingList->addItem(item->text());
        delete todoList->takeItem(todoList->row(item));

        todoList->clearSelection();
        doingList->clearSelection();

        saveTasks();
    }
}

void MainWindow::moveTaskToDone()
{
    QListWidgetItem *item = doingList->currentItem();
    if (item) {
        doneList->addItem(item->text());
        delete doingList->takeItem(doingList->row(item));

        doingList->clearSelection();
        doneList->clearSelection();

        saveTasks();
    }
}

void MainWindow::deleteTask()
{
    QListWidget *currentList = nullptr;


    if (!todoList->selectedItems().isEmpty()) {
        currentList = todoList;
    } else if (!doingList->selectedItems().isEmpty()) {
        currentList = doingList;
    } else if (!doneList->selectedItems().isEmpty()) {
        currentList = doneList;
    }


    if (currentList) {
        QListWidgetItem *item = currentList->takeItem(currentList->currentRow());
        if (item) {
            delete item;
            saveTasks();
        }


        currentList->clearSelection();
    }
}


void MainWindow::moveTask(QListWidget *from, QListWidget *to)
{
    QListWidgetItem *item = from->takeItem(from->currentRow());
    if (item) {
        to->addItem(item);
        saveTasks();
    }
}

void MainWindow::updateButtonState()
{
    moveToDoingButton->setEnabled(!todoList->selectedItems().isEmpty());
    moveToDoneButton->setEnabled(!doingList->selectedItems().isEmpty());
    deleteButton->setEnabled(
        !todoList->selectedItems().isEmpty() || !doingList->selectedItems().isEmpty() || !doneList->selectedItems().isEmpty()
        );


    if (todoList->hasFocus()) {
        doingList->clearSelection();
        doneList->clearSelection();
    } else if (doingList->hasFocus()) {
        todoList->clearSelection();
        doneList->clearSelection();
    } else if (doneList->hasFocus()) {
        todoList->clearSelection();
        doingList->clearSelection();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if (!todoList->underMouse() && !doingList->underMouse() && !doneList->underMouse()) {
        todoList->clearSelection();
        doingList->clearSelection();
        doneList->clearSelection();
    }
    QMainWindow::mousePressEvent(event);
}

void MainWindow::saveTasks()
{
    QSettings settings("MyCompany", "TaskManager");
    settings.beginGroup("Tasks");

    settings.setValue("todo", todoList->count());
    for (int i = 0; i < todoList->count(); ++i)
        settings.setValue(QString("todo_%1").arg(i), todoList->item(i)->text());

    settings.setValue("doing", doingList->count());
    for (int i = 0; i < doingList->count(); ++i)
        settings.setValue(QString("doing_%1").arg(i), doingList->item(i)->text());

    settings.setValue("done", doneList->count());
    for (int i = 0; i < doneList->count(); ++i)
        settings.setValue(QString("done_%1").arg(i), doneList->item(i)->text());

    settings.endGroup();
}

void MainWindow::loadTasks()
{
    QSettings settings("MyCompany", "TaskManager");
    settings.beginGroup("Tasks");

    int todoCount = settings.value("todo", 0).toInt();
    for (int i = 0; i < todoCount; ++i)
        todoList->addItem(settings.value(QString("todo_%1").arg(i)).toString());

    int doingCount = settings.value("doing", 0).toInt();
    for (int i = 0; i < doingCount; ++i)
        doingList->addItem(settings.value(QString("doing_%1").arg(i)).toString());

    int doneCount = settings.value("done", 0).toInt();
    for (int i = 0; i < doneCount; ++i)
        doneList->addItem(settings.value(QString("done_%1").arg(i)).toString());

    settings.endGroup();
}
