
#ifndef DEPISTAGE_MAIN_PROGRAMME_ETIQUETTES_HPP
#define DEPISTAGE_MAIN_PROGRAMME_ETIQUETTES_HPP

#include <QtCore/QObject>

#include <gui/ElementGUI.hpp>
#include <gui/MetaRemplacer.hpp>
#include <gui/SelectionFichier.hpp>

namespace depistage { namespace main {

class ProgrammeEtiquettes : public QObject
{
   Q_OBJECT
public :
   ProgrammeEtiquettes();

   virtual const std::vector< gui::ElementGUI * > & getElementsGUI() const;

private:
   std::vector< gui::ElementGUI * > m_elementsGUI;

   gui::MetaRemplacer * m_codePatient;
   gui::MetaRemplacer * m_sex;
   gui::MetaRemplacer * m_dateDeNaissance;

   gui::SelectionFichier * m_fichierWord;
   gui::SelectionFichier * m_fichierExcel;

private slots:
   void lancerGeneration();
   void sauverConfig() const;
};

} }

#endif
