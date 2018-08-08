
add_executable( serial_tests serial.cpp serial_tester.cpp serial_test_ecc.cpp )
target_link_libraries( serial_tests fcc_client fcc_cli fcc_wallet fcc_blockchain fcc_net fcc_utilities deterministic_openssl_rand bitcoin fc )
target_include_directories( serial_tests
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/../.." )
