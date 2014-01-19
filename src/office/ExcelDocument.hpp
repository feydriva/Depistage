
#ifndef DEPISTAGE_TEST_EXCEL_DOCUMENT_HPP
#define DEPISTAGE_TEST_EXCEL_DOCUMENT_HPP

#include "ExcelOnglet.hpp"

#include <ActiveQt/QAxObject>
#include <QtCore/QObject>

#include <memory>
#include <string>

namespace depistage { namespace office {

class ExcelDocument
{
   public:
      ExcelDocument( QAxObject * workbook, QObject * parent = NULL );

      ExcelOnglet recupererOnglet( unsigned int ongletId );

      bool isOpen() const;

   private:
      std::unique_ptr< QAxObject > m_workbook;

      QObject * m_parent;
};

} }

#endif
