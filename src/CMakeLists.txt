
SET( QT_USE_QTXML TRUE )

ADD_DEFINITIONS( ${QT_DEFINITIONS} )

INCLUDE_DIRECTORIES( .
                     gui
                     main
                     office
                     ${CMAKE_CURRENT_SOURCE_DIR} )

MESSAGE( STATUS ${CMAKE_CURRENT_BINARY_DIR} )
CONFIGURE_FILE( ${CMAKE_CURRENT_SOURCE_DIR}/config_version.hpp.cmake ${CMAKE_CURRENT_SOURCE_DIR}/config_version.hpp )

SET( SOURCES_RC resources/resource.qrc )

FILE( GLOB GUI_SRC "gui/*.*" )
FILE( GLOB MAIN_SRC "main/*.*" )
FILE( GLOB OFFICE_SRC "office/*.*" )

#SET( QTFILE_HEADERS
#     gui/FenetrePrincipale.hpp )

#qt5_wrap_cpp( QTFILE_HEADERS_MOC ${QTFILE_HEADERS} )
qt5_add_resources( SOURCES_RC_SRC ${SOURCES_RC} )

SOURCE_GROUP( Gui FILES ${GUI_SRC} )
SOURCE_GROUP( Main FILES ${MAIN_SRC} )
SOURCE_GROUP( Office FILES ${OFFICE_SRC} )

ADD_LIBRARY( DepistageCore
             ${GUI_SRC}
             ${MAIN_SRC}
             ${OFFICE_SRC}
             ${QTFILE_HEADERS_MOC}
             ${SOURCES_RC_SRC} )

TARGET_LINK_LIBRARIES( DepistageCore ${QT_LIBRARIES} )

ADD_EXECUTABLE( ${PROJECT_NAME}
                ${GUI_TYPE}
                main.cpp )

qt5_use_modules( ${PROJECT_NAME} Widgets )

TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${QT_LIBRARIES} DepistageCore )
