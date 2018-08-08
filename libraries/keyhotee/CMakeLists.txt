file(GLOB HEADERS "include/fcc/keyhotee/*.hpp")

add_library( fcc_keyhotee
             import_keyhotee_id.cpp
             ${HEADERS}
           )

target_link_libraries( fcc_keyhotee fc fcc_db fcc_blockchain leveldb bitcoin)
target_include_directories( fcc_keyhotee 
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
