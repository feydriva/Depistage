
#include "WordTests.hpp"

#include <ActiveQt/QAxWidget>
#include <QtTest/QtTest>

#include <memory>

WordTests::WordTests()
{
}

void WordTests::testActiveX()
{
	std::unique_ptr< QAxWidget > word( new QAxWidget( "Word.Application", NULL ) );
    QVERIFY( word.get() );
}
/*
void WordTests::testOpenDocument()
{
	QAxWidget wordApplication("Word.Application"); 
    QVERIFY( true );
}*/

QTEST_MAIN( WordTests )
