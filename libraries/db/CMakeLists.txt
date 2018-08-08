file(GLOB HEADERS "include/fcc/db/*.hpp")
add_library( fcc_db upgrade_leveldb.cpp ${HEADERS} )
target_link_libraries( fcc_db fc leveldb )
target_include_directories( fcc_db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
