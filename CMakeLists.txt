cmake_minimum_required(VERSION 3.5)

project(Iris)

# define custom cmake option

# Define executable name
set( EXEC_NAME Iris )

# Define executable directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# source files for main application - main.cpp is added separately below
set(SOURCE_FILES

    src/app/appconfig/ConfigDom/ConfigDom.cpp
    src/app/appconfig/ConfigDom/ConfigDom.hpp
    src/app/appconfig/AppConfig.cpp
    src/app/appconfig/AppConfig.hpp
    src/app/appstart/AppStart.cpp
    src/app/appstart/AppStart.hpp
    src/app/App.cpp
    src/app/App.hpp
    src/common/definitions/enums/repository/Repository.hpp
    src/common/exception/baseexception/BaseException.cpp
    src/common/exception/baseexception/BaseException.hpp
    src/common/iocfactory/ioccontainer/IocContainer.hpp
    src/common/iocfactory/IocFactory.cpp
    src/common/iocfactory/IocFactory.hpp
    src/persistance/crudworker/contract/ICrudWorker.hpp
    src/persistance/crudworker/impl/CrudWorker.hpp
    src/persistance/repository/contract/IRepository.hpp
    src/utils/helper/enumhelper/EnumHelper.hpp
    src/utils/helper/enumhelper/EnumHelper_imp.hpp
    src/utils/parser/pugixmlparser/PugiXmlparser.cpp
    src/utils/parser/pugixmlparser/PugiXmlParser.hpp
)

# source files for unit tests
set(TEST_SOURCE_FILES

    test/common/iocfactory/IocFactoryTest.cpp
)

# Find includes in corresponding build directories
include_directories(    ${CMAKE_CURRENT_SOURCE_DIR}/src
                        ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
					)

# set external directories for library binaries
set(ext_lib_path "${CMAKE_CURRENT_SOURCE_DIR}/lib/bin")

# Add Debug-Macro on Debug-Mode
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O0 -pthread")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -pthread")

# Set C++-Standard
add_definitions(-std=c++1y)

# Tell CMake to create the executable
add_executable(	${EXEC_NAME} src/main.cpp ${SOURCE_FILES})
target_link_libraries(${EXEC_NAME}  pthread )

# Testing Excecuteable
enable_testing()
add_executable( runUnitTests ${SOURCE_FILES} ${TEST_SOURCE_FILES} )

# link mocking and testing frame work
target_link_libraries(runUnitTests  ${ext_lib_path}/gtest/libgtest.a
                                    ${ext_lib_path}/gtest/libgtest_main.a
                                    ${ext_lib_path}/gmock/libgmock.a
                                    ${ext_lib_path}/gmock/libgmock_main.a
                                    pthread
)

add_test(runUnitTests runUnitTests)
