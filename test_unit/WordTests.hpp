
#ifndef DEPISTAGE_TEST_FENETREPRINCIPALE_HPP
#define DEPISTAGE_TEST_FENETREPRINCIPALE_HPP

#include <QObject>

//#include <src/office/[...].hpp"

class WordTests : public QObject
{
    Q_OBJECT
public:
    WordTests();

private slots:
    void testActiveX();
};


#endif // SQLTRANSACTIONTESTS_H
