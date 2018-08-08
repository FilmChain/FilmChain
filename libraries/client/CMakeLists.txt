file(GLOB HEADERS "include/fcc/client/*.hpp")
file(GLOB APIS "*_api.cpp")
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/bitcoin/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/utilities/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/client/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/net/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/blockchain/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/api/include )
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/include/fcc/client/build_info.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/include/fcc/client/build_info.hpp" @ONLY)

add_definitions( -DMCC_GLOBAL_API_LOG=1 )

add_library( fcc_client
             client.cpp
             messages.cpp
             notifier.cpp
             api_logger.cpp
             ${APIS}
             ${HEADERS}
             "${CMAKE_CURRENT_BINARY_DIR}/include/fcc/client/build_info.hpp" )

if(MSVC)
  set_source_files_properties(client.cpp PROPERTIES COMPILE_FLAGS "/bigobj")
endif(MSVC)

target_link_libraries( fcc_client
                       PRIVATE fcc_db fcc_blockchain bitcoin fc leveldb
                       PUBLIC fcc_api fcc_net fcc_wallet fcc_cli fcc_rpc fcc_rpc_stubs )
target_include_directories( fcc_client
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
                            PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/include" )
