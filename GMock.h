#pragma once
#include "DBConnection.h"


TEST(PainterTest, test1)
{
    std::cout << "Start GMock" << std::endl;
    Mockclass mockclass;
    ClassThatUsesDB ClassThatUsesDB;

    // указываем «ожидания» по использованию — методы будут вызваны хотя бы N раз
    EXPECT_CALL(mockclass, open).Times(::testing::AtLeast(1));//1 раз вызван
    EXPECT_CALL(mockclass, close).Times(::testing::AtLeast(1));//1 раз вызван

    EXPECT_CALL(mockclass, exceQuery).Times(::testing::AtLeast(1));//1 раз вызван
    // запускаем алгоритм на выполнение
    
    ClassThatUsesDB.openConnection(&mockclass);
    ClassThatUsesDB.useConnection(&mockclass);
    ClassThatUsesDB.closeConnection(&mockclass);

}
