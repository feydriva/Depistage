
#ifndef DEPISTAGE_TEST_EXCEL_HPP
#define DEPISTAGE_TEST_EXCEL_HPP

#include "ExcelDocument.hpp"

#include <QtCore/QObject>

#include <memory>
#include <string>

namespace depistage { namespace office {

class Excel
{
   public:
      Excel( QObject * parent = NULL );
      ~Excel();

      ExcelDocument open( const std::string & path );

      bool isLaunched() const;

   private:
      std::unique_ptr< QAxObject > m_excel;
      std::unique_ptr< QAxObject > m_workbooks;

      QObject * m_parent;

      void initializeWorkbooks();
};

} }

#endif
