file(GLOB HEADERS "include/fcc/light_wallet/*.hpp")

add_library( fcc_light_wallet
             light_wallet.cpp
             ${HEADERS}
           )

target_link_libraries( fcc_light_wallet fc fcc_utilities fcc_blockchain fcc_rpc_stubs )
target_include_directories( fcc_light_wallet
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include" )

if (USE_PCH)
  set_target_properties(fcc_light_wallet PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
  cotire(fcc_light_wallet)
endif(USE_PCH)
