
INCLUDE_DIRECTORIES( .
                     ../src )

# SET( TestApplication_SRCS TestApplication.cpp )

set( TEST_LIBRARIES DepistageCore ${Qt5Test_LIBRARIES} ${QT_LIBRARIES} )

qt5_add_resources( tests_SRC tests.qrc )

set( WordTests_SRCS WordTests.cpp )
add_executable( WordTests ${WordTests_SRCS} ${tests_SRC} )
target_link_libraries( WordTests ${TEST_LIBRARIES} )
add_test( NAME WordTests COMMAND WordTests )

set( ExcelTests_SRCS ExcelTests.cpp )
add_executable( ExcelTests ${ExcelTests_SRCS} ${tests_SRC} )
target_link_libraries( ExcelTests ${TEST_LIBRARIES} )
add_test( NAME ExcelTests COMMAND ExcelTests )

# SET( TaskStructureTests_SRCS TaskStructureTests.cpp )
# ADD_EXECUTABLE(
    # TaskStructureTests
    # ${TaskStructureTests_SRCS}
    # ${TestDataResources_SRCS}
# )
# TARGET_LINK_LIBRARIES( TaskStructureTests ${TEST_LIBRARIES} )
# ADD_TEST( NAME TaskStructureTests COMMAND TaskStructureTests )
