#pragma once
#include "DBConnection.h"


 class MyTestSuite : public ::testing::Test//создаём и настраиваем условия, в которых будем прогонять тесты
{
protected:
    
    
    void SetUp()
    {
        //в нашем случае просто создаём объект для тестирования
        //и присваиваем начальное значение
        std::cout << "local setup" << std::endl;
        objUnderTesting = new ClassThatUsesDB;
        objUnderTesting->i = 10;
    }


    //Тирдаун:
    //очищаем ресурсы, выделенные и задействованные во время тестирования
    void TearDown()
    {
        //в нашем случае просто удаляем объект, с которым проводим тестирование
        std::cout << "local teardown" << std::endl;
        delete objUnderTesting;
    }

protected:
    ClassThatUsesDB* objUnderTesting;
};

//Тест-кейс 1
TEST_F(MyTestSuite, testcase1)
{
    std::cout << "Start GTest" << std::endl;
    ASSERT_EQ(objUnderTesting->i, 10); //проверка — значение в объекте должно быть 10
}
