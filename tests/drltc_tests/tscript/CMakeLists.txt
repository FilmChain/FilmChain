
add_executable( tscript tscript.cpp )
target_link_libraries( tscript fcc_client fcc_cli fcc_wallet fcc_blockchain fcc_net fcc_utilities deterministic_openssl_rand bitcoin fc )
target_include_directories( tscript
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/../.." )
