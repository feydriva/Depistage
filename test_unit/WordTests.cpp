
#include "WordTests.hpp"

#include <ActiveQt/QAxWidget>
#include <QtTest/QtTest>

WordTests::WordTests()
{
}

void WordTests::testActiveX()
{
	QAxWidget * wordWidget = new QAxWidget( "Word.Application", NULL );
    QVERIFY( wordWidget );
}
/*
void WordTests::testOpenDocument()
{
	QAxWidget wordApplication("Word.Application"); 
    QVERIFY( true );
}*/

QTEST_MAIN( WordTests )
