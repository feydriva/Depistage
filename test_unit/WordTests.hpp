
#ifndef DEPISTAGE_TEST_FENETREPRINCIPALE_HPP
#define DEPISTAGE_TEST_FENETREPRINCIPALE_HPP

#include <QObject>

//#include <src/office/[...].hpp"

namespace depistage { namespace office { namespace test {

class WordTests : public QObject
{
    Q_OBJECT
public:
    WordTests();

private slots:
    void testLaunchWord();
    void testOpenDocument();
};

} } }

#endif // SQLTRANSACTIONTESTS_H
