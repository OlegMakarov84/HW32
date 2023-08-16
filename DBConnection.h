#pragma once
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// определяем интерфейс объекта, который далее будем использовать в алгоритме
class DBConnection// интерфейс для рисования
{
public:
    DBConnection()
    {}

    // как и положено, не забудем виртуальный деструктор
    virtual ~DBConnection()
    {}

    // несколько виртуальных методов, которыми будем пользоваться
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void exceQuery() = 0;
};

class Mockclass : public DBConnection {// gmock устанавливаем в качестве дочернего класса
public:
    // пользуемся макросами GTest для определения мок-методов в объекте
    MOCK_METHOD(void, open, (), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(void, exceQuery, (), (override));
};

class ClassThatUsesDB
{private:
    Mockclass* mockclass;
public:
    ClassThatUsesDB() {};
    ClassThatUsesDB(Mockclass* mockclass): mockclass(mockclass)//в конструкторе указываем указатель на мок-объект, в дальнейшем класс будет работать с ним
    {
        std::cout << "ClassThatUsesDB()" << std::endl;
    }

    ~ClassThatUsesDB()
    {
        std::cout << "~ClassThatUsesDB()" << std::endl;
    }
    void openConnection(Mockclass* mockclass) { mockclass->open(); };
    void useConnection(Mockclass* mockclass) { mockclass->exceQuery(); };
    void closeConnection(Mockclass* mockclass) { mockclass->close(); };
    int i = 0;
};

