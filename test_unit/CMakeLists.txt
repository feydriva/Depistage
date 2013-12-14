
# INCLUDE_DIRECTORIES( ${Charm_SOURCE_DIR} )

# SET( TestApplication_SRCS TestApplication.cpp )

SET( TEST_LIBRARIES DepistageCore ${Qt5Test_LIBRARIES} ${QT_LIBRARIES} )

#QT_ADD_RESOURCES( TestDataResources_SRCS TestData.qrc )

SET( WordTests_SRCS WordTests.cpp )
ADD_EXECUTABLE( WordTests ${WordTests_SRCS} )
TARGET_LINK_LIBRARIES( WordTests ${TEST_LIBRARIES} )
ADD_TEST( NAME WordTests COMMAND WordTests )

# SET( TaskStructureTests_SRCS TaskStructureTests.cpp )
# ADD_EXECUTABLE(
    # TaskStructureTests
    # ${TaskStructureTests_SRCS}
    # ${TestDataResources_SRCS}
# )
# TARGET_LINK_LIBRARIES( TaskStructureTests ${TEST_LIBRARIES} )
# ADD_TEST( NAME TaskStructureTests COMMAND TaskStructureTests )
