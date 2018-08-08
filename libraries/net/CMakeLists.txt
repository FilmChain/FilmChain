file(GLOB HEADERS "include/fcc/net/*.hpp")

set(SOURCES node.cpp
            stcp_socket.cpp
            core_messages.cpp
            peer_database.cpp
            peer_connection.cpp
            upnp.cpp
            message_oriented_connection.cpp
            chain_downloader.cpp
            chain_server.cpp)

add_library( fcc_net ${SOURCES} ${HEADERS} )

target_link_libraries( fcc_net 
  PUBLIC fc fcc_wallet fcc_db fcc_utilities leveldb fcc_api fcc_rpc_stubs upnpc-static)
target_include_directories( fcc_net 
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
# currently depends on client for definitions, remove this
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../client/include"
# Looks like fcc_net and fcc_rpc also have cycle deps
          "${CMAKE_CURRENT_SOURCE_DIR}/../rpc/include"
# later, move upnp include into target_include_directories for upnp
"${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/miniupnp"
)

if (USE_PCH)
  set_target_properties(fcc_net PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
  cotire(fcc_net)
endif(USE_PCH)
