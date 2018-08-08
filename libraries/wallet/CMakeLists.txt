file(GLOB HEADERS "include/fcc/wallet/*.hpp")

add_library( fcc_wallet
             wallet_records.cpp
             wallet_db.cpp
             bitcoin.cpp
             transaction_builder.cpp
             transaction_ledger.cpp
             transaction_ledger_experimental.cpp
             login.cpp
             wallet.cpp
             ${HEADERS}
           )

target_link_libraries( fcc_wallet fc fcc_db fcc_utilities fcc_blockchain leveldb bitcoin fcc_keyhotee fcc_cli )
target_include_directories( fcc_wallet
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include" )

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/include/fcc/wallet/url.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/include/fcc/wallet/url.hpp" )


if(MSVC)
  set_source_files_properties(wallet.cpp PROPERTIES COMPILE_FLAGS "/bigobj")
endif()

if (USE_PCH)
  set_target_properties(fcc_wallet PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
  cotire(fcc_wallet)
endif(USE_PCH)
