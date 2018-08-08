if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/bitcoin/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/utilities/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/client/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/net/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/blockchain/include )
add_executable( btc_wallet_dump bitcoin_recovery.cpp )
target_link_libraries( btc_wallet_dump fc fcc_blockchain fcc_utilities bitcoin )

add_executable( fcc_create_key mcc_create_key.cpp )
target_link_libraries( fcc_create_key fc fcc_blockchain fcc_utilities deterministic_openssl_rand )

add_executable( fcc_create_genesis mcc_create_genesis.cpp )
target_link_libraries( fcc_create_genesis fc fcc_blockchain fcc_utilities)

add_executable( key_to_wif key_to_wif.cpp )
target_link_libraries( key_to_wif fc fcc_blockchain fcc_utilities)

add_executable( fcc_key_info mcc_key_info.cpp )
target_link_libraries( fcc_key_info fc fcc_blockchain fcc_utilities)

add_executable( fcc_convert_addresses mcc_convert_addresses.cpp )
target_link_libraries( fcc_convert_addresses fc fcc_blockchain fcc_utilities)

# I've added two small files here that are also compiled in fcc_blockchain
# to avoid a circular dependency.  The circular dependency could be broken more cleanly
# by splitting fcc_blockchain, but it doesn't seem worth it just for this
add_executable( fcc_genesis_to_bin mcc_genesis_to_bin.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/blockchain/types.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/blockchain/pts_address.cpp )
target_link_libraries( fcc_genesis_to_bin fc )
target_include_directories( fcc_genesis_to_bin PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/blockchain/include" )

add_executable( fcc_json_to_cpp mcc_json_to_cpp.cpp )
target_link_libraries( fcc_json_to_cpp fc fcc_utilities)

add_executable( map_mcc_network map_mcc_network.cpp )
target_link_libraries( map_mcc_network fc fcc_net fcc_client)

add_executable( pack_web pack_web.cpp )
target_link_libraries( pack_web fc )

add_executable( compute_item_hashes compute_item_hashes.cpp )
target_link_libraries( compute_item_hashes fc fcc_net fcc_client)

if( ${INCLUDE_QT_WALLET} )
  add_subdirectory( web_update_utility )
endif()
