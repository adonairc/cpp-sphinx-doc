cmake_minimum_required(VERSION 3.9)
project(cpp-sphinx-doc VERSION 0.1.0)

# Add the cmake folder so the FindSphinx module is found
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(Doxygen REQUIRED)
find_package(Sphinx REQUIRED)


include(CTest)
enable_testing()

set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include")


# Source files, without extensions or directory names
# Here assuming each file has both header and implementation
set(SRC_FILES cpp-sphinx-doc)

# Create SOURCE_FILES
foreach(file ${SRC_FILES})
	list(APPEND SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/${file}.cpp
        ${PROJECT_INCLUDE_DIR}/${file}.hpp
	)
endforeach()

# Set up such that your IDE organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

add_executable(cpp-sphinx-doc ${PROJECT_SOURCE_DIR}/main.cpp)

#######################
#       Doxygen       #
#######################

if(DOXYGEN_FOUND)

  # doxygen settings can be set here, prefixed with "DOXYGEN_"
  set(DOXYGEN_GENERATE_HTML NO)
  set(DOXYGEN_GENERATE_XML YES)
  set(DOXYGEN_SOURCE_BROWSER YES)
  set(DOXYGEN_EXTRACT_PRIVATE YES)
  doxygen_add_docs(
    doxygen EXCLUDE_FROM_ALL
    # To include both sources and headers change to "${PROJECT_INCLUDE_DIR},${PROJECT_SOURCE_DIR}"
    "${PROJECT_INCLUDE_DIR}"  
    COMMENT "Generating documentation with Doxygen"
  )
endif(DOXYGEN_FOUND)

#######################
#       Sphinx        #
#######################

sphinx_add_docs(
  docs EXCLUDE_FROM_ALL
  BREATHE_PROJECTS doxygen
  BUILDER html
  SOURCE_DIRECTORY docs
)
set_target_properties(docs doxygen PROPERTIES EXCLUDE_FROM_ALL true)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

