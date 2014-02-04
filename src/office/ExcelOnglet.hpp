
#ifndef DEPISTAGE_TEST_EXCEL_ONGLET_HPP
#define DEPISTAGE_TEST_EXCEL_ONGLET_HPP

#include <ActiveQt/QAxObject>
#include <QtCore/QObject>

#include <memory>
#include <string>

namespace depistage { namespace office {

class ExcelOnglet
{
   public:
      ExcelOnglet( QAxObject * onglet, QObject * parent = nullptr );

      void ajouterLigne( std::vector< std::string > informations );

      bool isOpen() const;

   private:
      std::unique_ptr< QAxObject > m_onglet;

      QObject * m_parent;

      QAxObject * recupererDerniereCelluleNonVidePremiereColonne();
      QAxObject * recupererPremiereCelluleVidePremiereColonne();
};

} }

#endif
