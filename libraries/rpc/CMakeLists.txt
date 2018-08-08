file(GLOB HEADERS "include/fcc/rpc/*.hpp")

add_library( fcc_rpc 
             rpc_server.cpp
             rpc_client.cpp
             ${HEADERS}
           )

target_link_libraries( fcc_rpc 
                       PUBLIC fcc_blockchain fcc_rpc_stubs fcc_api fcc_wallet fcc_client fcc_net fc 
                       PRIVATE fcc_db fcc_utilities leveldb)
target_include_directories( fcc_rpc 
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
if (USE_PCH)
  set_target_properties(fcc_rpc PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
  cotire(fcc_rpc)
endif(USE_PCH)
