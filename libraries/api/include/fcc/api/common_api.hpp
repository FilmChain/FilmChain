//                                   _           _    __ _ _      
//                                  | |         | |  / _(_) |     
//    __ _  ___ _ __   ___ _ __ __ _| |_ ___  __| | | |_ _| | ___ 
//   / _` |/ _ \ '_ \ / _ \ '__/ _` | __/ _ \/ _` | |  _| | |/ _ \`
//  | (_| |  __/ | | |  __/ | | (_| | ||  __/ (_| | | | | | |  __/
//   \__, |\___|_| |_|\___|_|  \__,_|\__\___|\__,_| |_| |_|_|\___|
//    __/ |                                                       
//   |___/                                                        
//
//
// Warning: this is a generated file, any changes made here will be
//          overwritten by the build process.  If you need to change what is
//          generated here, you should either modify the input json files
//          (network_api.json, wallet_api.json, etc) or modify the code
//          generator (mcc_api_generator.cpp) itself
//
#pragma once

#include <fc/crypto/elliptic.hpp>
#include <fc/crypto/sha256.hpp>
#include <fc/exception/exception.hpp>
#include <fc/filesystem.hpp>
#include <fc/network/ip.hpp>
#include <fc/optional.hpp>
#include <fc/time.hpp>
#include <fcc/api/api_metadata.hpp>
#include <fcc/blockchain/address.hpp>
#include <fcc/blockchain/asset_record.hpp>
#include <fcc/blockchain/block.hpp>
#include <fcc/blockchain/block_record.hpp>
#include <fcc/blockchain/chain_database.hpp>
#include <fcc/blockchain/feed_operations.hpp>
#include <fcc/blockchain/market_records.hpp>
#include <fcc/blockchain/operations.hpp>
#include <fcc/blockchain/pts_address.hpp>
#include <fcc/blockchain/transaction.hpp>
#include <fcc/blockchain/types.hpp>
#include <fcc/net/node.hpp>
#include <fcc/wallet/pretty.hpp>
#include <fcc/wallet/transaction_builder.hpp>
#include <fcc/wallet/wallet.hpp>
#include <fcc/wallet/wallet_records.hpp>
#include <stdint.h>
#include <string>
namespace mcc { namespace api {

  class common_api
  {
  public:
    /**
     * Returns version number and associated information for this client.
     *
     * @return json_object
     */
    virtual fc::variant_object about() const = 0;
    /**
     * Returns version number and associated information for this client.
     *
     * @return json_object
     */
    virtual fc::variant_object get_info() const = 0;
    /**
     * shut down the RPC server and exit this client.
     */
    virtual void stop() = 0;
    /**
     * display a list of commands, or detailed help on an individual command.
     *
     * @param command_name the name of the method to get detailed help, or omit this for a list of commands
     *                     (method_name, optional, defaults to "")
     *
     * @return string
     */
    virtual std::string help(const std::string& command_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Return information about given BitShares address.
     *
     * @param address the address or public key to validate (string, required)
     *
     * @return json_object
     */
    virtual fc::variant_object validate_address(const std::string& address) const = 0;
    /**
     * Convert a BTC or PTS address into a MCC address.
     *
     * @param raw_address the BTC or PTS address to convert (string, required)
     *
     * @return address
     */
    virtual mcc::blockchain::address convert_to_native_address(const std::string& raw_address) const = 0;
    /**
     * Execute the given command as if it were typed on the CLI.
     *
     * @param input The entire command input as if it were a CLI input (passphrase, required)
     *
     * @return string
     */
    virtual std::string execute_command_line(const std::string& input) const = 0;
    /**
     * Execute the given file as if it were typed on the CLI.
     *
     * @param script Name of a file containing CLI commands to execute (filename, required)
     */
    virtual void execute_script(const fc::path& script) const = 0;
    /**
     * Takes any no_prerequisites command and an array of its arguments and returns an array of results. Example: batch
     * blockchain_get_blockhash [[1], [2]].
     *
     * @param method_name The command name for calling (string, required)
     * @param parameters_list The list of list of parameters for this command, the return will be the list of execute
     *                        result of corresponding parameters (parameters_list, required)
     *
     * @return variants
     */
    virtual fc::variants batch(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const = 0;
    /**
     * Takes any no_prerequisites command and an array of its arguments and returns an array of results. Example:
     * batch_authenticated blockchain_get_blockhash [[1], [2]].
     *
     * @param method_name The command name for calling (string, required)
     * @param parameters_list The list of list of parameters for this command, the return will be the list of execute
     *                        result of corresponding parameters (parameters_list, required)
     *
     * @return variants
     */
    virtual fc::variants batch_authenticated(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const = 0;
    /**
     * Takes a transaction builder and returns a signed transaction for broadcasting.
     *
     * @param builder (transaction_builder, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record builder_finalize_and_sign(const mcc::wallet::transaction_builder& builder) const = 0;
    /**
     * Returns help information as JSON data.
     *
     * @return method_map_type
     */
    virtual std::map<std::string, mcc::api::method_data> meta_help() const = 0;
    /**
     * Set the username for basic auth for the http server.
     *
     * @param username Username for basic auth (string, optional, defaults to "")
     */
    virtual void rpc_set_username(const std::string& username = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Set the password for basic auth for the http server.
     *
     * @param password Password for basic auth (passphrase, optional, defaults to "")
     */
    virtual void rpc_set_password(const std::string& password = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Set the port and start rpc server.
     *
     * @param port Port for rpc server (uint32_t, optional, defaults to "65065")
     */
    virtual void rpc_start_server(uint32_t port = fc::json::from_string("\"65065\"").as<uint32_t>()) = 0;
    /**
     * Set the port and start http server.
     *
     * @param port Port for http server (uint32_t, optional, defaults to "65066")
     */
    virtual void http_start_server(uint32_t port = fc::json::from_string("\"65066\"").as<uint32_t>()) = 0;
    /**
     * Update the NTP time right now.
     */
    virtual void ntp_update_time() = 0;
    /**
     * Report disk space taken up by different groups of client files.
     *
     * @return variant
     */
    virtual fc::variant disk_usage() const = 0;
    /**
     * Attempts add or remove <node> from the peer list or try a connection to <node> once.
     *
     * @param node The node (see network_get_peer_info for nodes) (string, required)
     * @param command 'add' to add a node to the list, 'remove' to remove a node from the list, 'onetry' to try a
     *                connection to the node once (string, optional, defaults to "add")
     */
    virtual void network_add_node(const std::string& node, const std::string& command = fc::json::from_string("\"add\"").as<std::string>()) = 0;
    /**
     * Returns the number of fully-established connections to other nodes.
     *
     * @return uint32_t
     */
    virtual uint32_t network_get_connection_count() const = 0;
    /**
     * Returns data about each connected node.
     *
     * @param not_firewalled true to output only peers not behind a firewall and false otherwise (bool, optional,
     *                       defaults to false)
     *
     * @return json_object_array
     */
    virtual std::vector<fc::variant_object> network_get_peer_info(bool not_firewalled = fc::json::from_string("false").as<bool>()) const = 0;
    /**
     * Broadcast a previously-created signed transaction to the network.
     *
     * @param transaction_to_broadcast The transaction to broadcast to the network (signed_transaction, required)
     *
     * @return transaction_id
     */
    virtual mcc::blockchain::transaction_id_type network_broadcast_transaction(const mcc::blockchain::signed_transaction& transaction_to_broadcast) = 0;
    /**
     * Sets advanced node parameters, used for setting up automated tests.
     *
     * @param params A JSON object containing the name/value pairs for the parameters to set (json_object, required)
     */
    virtual void network_set_advanced_node_parameters(const fc::variant_object& params) = 0;
    /**
     * Sets advanced node parameters, used for setting up automated tests.
     *
     * @return json_object
     */
    virtual fc::variant_object network_get_advanced_node_parameters() const = 0;
    /**
     * Returns the time the transaction was first seen by this client.
     *
     * This interrogates the p2p node's message cache to find out when it first saw this transaction. The data in the
     * message cache is only kept for a few blocks, so you can only use this to ask about recent transactions. This is
     * intended to be used to track message propagation delays in our test network.
     *
     * @param transaction_id the id of the transaction (transaction_id, required)
     *
     * @return message_propagation_data
     */
    virtual mcc::net::message_propagation_data network_get_transaction_propagation_data(const mcc::blockchain::transaction_id_type& transaction_id) = 0;
    /**
     * Returns the time the block was first seen by this client.
     *
     * This interrogates the p2p node's message cache to find out when it first saw this block. The data in the message
     * cache is only kept for a few blocks, so you can only use this to ask about recent transactions. This is intended
     * to be used to track message propagation delays in our test network.
     *
     * @param block_hash the id of the block (block_id_type, required)
     *
     * @return message_propagation_data
     */
    virtual mcc::net::message_propagation_data network_get_block_propagation_data(const mcc::blockchain::block_id_type& block_hash) = 0;
    /**
     * Sets the list of peers this node is allowed to connect to.
     *
     * This function sets the list of peers we're allowed to connect to. It is used during testing to force network
     * splits or other weird topologies.
     *
     * @param allowed_peers the list of allowable peers (node_id_list, required)
     */
    virtual void network_set_allowed_peers(const std::vector<mcc::net::node_id_t>& allowed_peers) = 0;
    /**
     * Returns assorted information about the network settings and connections.
     *
     * @return json_object
     */
    virtual fc::variant_object network_get_info() const = 0;
    /**
     * Returns list of potential peers.
     *
     * @return potential_peer_record_array
     */
    virtual std::vector<mcc::net::potential_peer_record> network_list_potential_peers() const = 0;
    /**
     * Get information on UPNP status including whether it's enabled and what the client believes its IP to be.
     *
     * @return json_object
     */
    virtual fc::variant_object network_get_upnp_info() const = 0;
    /**
     * Get bandwidth usage stats.
     *
     * @return json_object
     */
    virtual fc::variant_object network_get_usage_stats() const = 0;
    /**
     * Returns current settings used during local block production.
     *
     * @return variant
     */
    virtual fc::variant delegate_get_config() const = 0;
    /**
     * Set minimum network connection count required for block production.
     *
     * @param count minimum network connection count (uint32_t, required)
     */
    virtual void delegate_set_network_min_connection_count(uint32_t count) = 0;
    /**
     * Set maximum number of transactions allowed in a block.
     *
     * @param count maximum transaction count (uint32_t, required)
     */
    virtual void delegate_set_block_max_transaction_count(uint32_t count) = 0;
    /**
     * Set maximum block size allowed.
     *
     * @param size maximum block size in bytes (uint32_t, required)
     */
    virtual void delegate_set_block_max_size(uint32_t size) = 0;
    /**
     * Set maximum time spent producing a block.
     *
     * @param time maximum production time in microseconds (uint64_t, required)
     */
    virtual void delegate_set_block_max_production_time(uint64_t time) = 0;
    /**
     * Set maximum transaction size allowed.
     *
     * @param size maximum transaction size in bytes (uint32_t, required)
     */
    virtual void delegate_set_transaction_max_size(uint32_t size) = 0;
    /**
     * Set whether canonical signatures are required.
     *
     * @param required whether canonical signatures are required (bool, required)
     */
    virtual void delegate_set_transaction_canonical_signatures_required(bool required) = 0;
    /**
     * Set minimum transaction fee allowed.
     *
     * @param fee minimum transaction fee in shares (uint64_t, required)
     */
    virtual void delegate_set_transaction_min_fee(uint64_t fee) = 0;
    /**
     * Add specified transaction to blacklist.
     *
     * @param id transaction to add to blacklist (transaction_id, required)
     */
    virtual void delegate_blacklist_add_transaction(const mcc::blockchain::transaction_id_type& id) = 0;
    /**
     * Remove specified transaction from blacklist.
     *
     * @param id transaction to remove from blacklist (transaction_id, required)
     */
    virtual void delegate_blacklist_remove_transaction(const mcc::blockchain::transaction_id_type& id) = 0;
    /**
     * Add specified operation to blacklist.
     *
     * @param id operation to add to blacklist (operation_type, required)
     */
    virtual void delegate_blacklist_add_operation(const mcc::blockchain::operation_type_enum& id) = 0;
    /**
     * Remove specified operation from blacklist.
     *
     * @param id operation to remove from blacklist (operation_type, required)
     */
    virtual void delegate_blacklist_remove_operation(const mcc::blockchain::operation_type_enum& id) = 0;
    /**
     * Returns current blockchain information and parameters.
     *
     * @return json_object
     */
    virtual fc::variant_object blockchain_get_info() const = 0;
    /**
     * Save snapshot of current base asset balances to specified file.
     *
     * @param filename filename to save snapshot to (string, required)
     */
    virtual void blockchain_generate_snapshot(const std::string& filename) const = 0;
    /**
     * Save snapshot of current state to specified file in Graphene genesis format.
     *
     * @param filename filename to save snapshot to (string, required)
     * @param whitelist_filename filename containing set of account names to whitelist from name-prefixing (string,
     *                           optional, defaults to "")
     */
    virtual void blockchain_graphene_snapshot(const std::string& filename, const std::string& whitelist_filename = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * A utility to help verify UIA distribution. Returns a snapshot map of all issuances for a particular UIA.
     *
     * @param symbol the UIA for which to compute issuance map (string, required)
     * @param filename filename to save snapshot to (string, required)
     */
    virtual void blockchain_generate_issuance_map(const std::string& symbol, const std::string& filename) const = 0;
    /**
     * Calculate the total supply of an asset from the current blockchain database state.
     *
     * @param asset asset ticker symbol or ID to calculate supply for (string, required)
     *
     * @return asset
     */
    virtual mcc::blockchain::asset blockchain_calculate_supply(const std::string& asset) const = 0;
    /**
     * Calculate the total amount of a market-issued asset that is owed to the network by open short positions.
     *
     * @param asset asset ticker symbol or ID to calculate debt for (string, required)
     * @param include_interest true to include current outstanding interest and false otherwise (bool, optional,
     *                         defaults to "false")
     *
     * @return asset
     */
    virtual mcc::blockchain::asset blockchain_calculate_debt(const std::string& asset, bool include_interest = fc::json::from_string("\"false\"").as<bool>()) const = 0;
    /**
     * Calculate the maximum possible supply of the core asset from the current time assuming a maximum dilution
     * schedule.
     *
     * @param average_delegate_pay_rate average delegate pay rate percentage (uint8_t, optional, defaults to 100)
     *
     * @return asset
     */
    virtual mcc::blockchain::asset blockchain_calculate_max_supply(uint8_t average_delegate_pay_rate = fc::json::from_string("100").as<uint8_t>()) const = 0;
    /**
     * Returns the current head block number.
     *
     * @return uint32_t
     */
    virtual uint32_t blockchain_get_block_count() const = 0;
    /**
     * Returns registered accounts starting with a given name upto a the limit provided.
     *
     * @param first_account_name the first account name to include (account_name, optional, defaults to "")
     * @param limit the maximum number of items to list (uint32_t, optional, defaults to 20)
     *
     * @return account_record_array
     */
    virtual std::vector<mcc::blockchain::account_record> blockchain_list_accounts(const std::string& first_account_name = fc::json::from_string("\"\"").as<std::string>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) const = 0;
    /**
     * Returns a list of recently updated accounts.
     *
     * @return account_record_array
     */
    virtual std::vector<mcc::blockchain::account_record> blockchain_list_recently_updated_accounts() const = 0;
    /**
     * Returns a list of recently registered accounts.
     *
     * @return account_record_array
     */
    virtual std::vector<mcc::blockchain::account_record> blockchain_list_recently_registered_accounts() const = 0;
    /**
     * Returns registered assets starting with a given name upto a the limit provided.
     *
     * @param first_symbol the prefix of the first asset symbol name to include (asset_symbol, optional, defaults to
     *                     "")
     * @param limit the maximum number of items to list (uint32_t, optional, defaults to 20)
     *
     * @return asset_record_array
     */
    virtual std::vector<mcc::blockchain::asset_record> blockchain_list_assets(const std::string& first_symbol = fc::json::from_string("\"\"").as<std::string>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) const = 0;
    /**
     * Returns a list of all currently valid feed prices.
     *
     * @return string_map
     */
    virtual std::map<std::string, std::string> blockchain_list_feed_prices() const = 0;
    /**
     * returns all burn records associated with an account.
     *
     * @param account_name the name of the account to fetch the burn records for (account_name, optional, defaults to
     *                     "")
     *
     * @return burn_records
     */
    virtual std::vector<mcc::blockchain::burn_record> blockchain_get_account_wall(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Return a list of transactions that are not yet in a block.
     *
     * @return signed_transaction_array
     */
    virtual std::vector<mcc::blockchain::signed_transaction> blockchain_list_pending_transactions() const = 0;
    /**
     * Get detailed information about the specified transaction in the blockchain.
     *
     * @param transaction_id_prefix the base58 transaction ID to return (string, required)
     * @param exact whether or not a partial match is ok (bool, optional, defaults to false)
     *
     * @return transaction_record_pair
     */
    virtual std::pair<mcc::blockchain::transaction_id_type, mcc::blockchain::transaction_record> blockchain_get_transaction(const std::string& transaction_id_prefix, bool exact = fc::json::from_string("false").as<bool>()) const = 0;
    /**
     * Retrieves the block record for the given block number, ID or timestamp.
     *
     * @param block timestamp, number or ID of the block to retrieve (string, required)
     *
     * @return oblock_record
     */
    virtual fc::optional<mcc::blockchain::block_record> blockchain_get_block(const std::string& block) const = 0;
    /**
     * Retrieves the detailed transaction information for a block.
     *
     * @param block the number or id of the block to get transactions from (string, required)
     *
     * @return transaction_record_map
     */
    virtual std::map<mcc::blockchain::transaction_id_type, mcc::blockchain::transaction_record> blockchain_get_block_transactions(const std::string& block) const = 0;
    /**
     * Retrieves the record for the given account name or ID.
     *
     * @param account account name, ID, or public key to retrieve the record for (string, required)
     *
     * @return optional_account_record
     */
    virtual fc::optional<mcc::blockchain::account_record> blockchain_get_account(const std::string& account) const = 0;
    /**
     * Retrieves a map of delegate IDs and names defined by the given slate ID or recommending account.
     *
     * @param slate slate ID or recommending account name for which to retrieve the slate of delegates (string,
     *              required)
     *
     * @return map<account_id_type, string>
     */
    virtual std::map<mcc::blockchain::account_id_type, std::string> blockchain_get_slate(const std::string& slate) const = 0;
    /**
     * Retrieves the specified balance record.
     *
     * @param balance_id the ID of the balance record (address, required)
     *
     * @return balance_record
     */
    virtual mcc::blockchain::balance_record blockchain_get_balance(const mcc::blockchain::address& balance_id) const = 0;
    /**
     * Lists balance records for the specified asset.
     *
     * @param asset the symbol or ID of the asset to list balances for, or empty to include all assets (string,
     *              optional, defaults to "0")
     * @param limit the maximum number of items to list (uint32_t, optional, defaults to 20)
     *
     * @return balance_record_map
     */
    virtual std::unordered_map<mcc::blockchain::balance_id_type, mcc::blockchain::balance_record> blockchain_list_balances(const std::string& asset = fc::json::from_string("\"0\"").as<std::string>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) const = 0;
    /**
     * Lists balance records which are the balance IDs or which can be claimed by signature for this address.
     *
     * @param addr address to scan for (string, required)
     * @param chanced_since Filter all balances that haven't chanced since the provided timestamp (timestamp, optional,
     *                      defaults to "1970-1-1T00:00:01")
     *
     * @return balance_record_map
     */
    virtual std::unordered_map<mcc::blockchain::balance_id_type, mcc::blockchain::balance_record> blockchain_list_address_balances(const std::string& addr, const fc::time_point& chanced_since = fc::json::from_string("\"1970-1-1T00:00:01\"").as<fc::time_point>()) const = 0;
    /**
     * Lists all transactions that involve the provided address after the specified time.
     *
     * @param addr address to scan for (string, required)
     * @param filter_before Filter all transactions that occured prior to the specified block number (uint32_t,
     *                      optional, defaults to "0")
     *
     * @return variant_object
     */
    virtual fc::variant_object blockchain_list_address_transactions(const std::string& addr, uint32_t filter_before = fc::json::from_string("\"0\"").as<uint32_t>()) const = 0;
    /**
     * Get the public balances associated with the specified account name; this command can take a long time.
     *
     * @param account_name the account name to query public balances for (account_name, required)
     *
     * @return asset_balance_map
     */
    virtual std::map<mcc::blockchain::asset_id_type, mcc::blockchain::share_type> blockchain_get_account_public_balance(const std::string& account_name) const = 0;
    /**
     * Get the account record for a given name.
     *
     * @param symbol the asset symbol to fetch the median price of in MCC (asset_symbol, required)
     *
     * @return string
     */
    virtual std::string blockchain_median_feed_price(const std::string& symbol) const = 0;
    /**
     * Lists balance records which can be claimed by signature for this key.
     *
     * @param key Key to scan for (public_key, required)
     *
     * @return balance_record_map
     */
    virtual std::unordered_map<mcc::blockchain::balance_id_type, mcc::blockchain::balance_record> blockchain_list_key_balances(const mcc::blockchain::public_key_type& key) const = 0;
    /**
     * Retrieves the record for the given asset ticker symbol or ID.
     *
     * @param asset asset ticker symbol or ID to retrieve (string, required)
     *
     * @return optional_asset_record
     */
    virtual fc::optional<mcc::blockchain::asset_record> blockchain_get_asset(const std::string& asset) const = 0;
    /**
     * Retrieves all current feeds for the given asset.
     *
     * @param asset asset ticker symbol or ID to retrieve (string, required)
     *
     * @return feed_entry_list
     */
    virtual std::vector<mcc::blockchain::feed_entry> blockchain_get_feeds_for_asset(const std::string& asset) const = 0;
    /**
     * Retrieves all current feeds published by the given delegate.
     *
     * @param delegate_name the name of the delegate to list feeds from (string, required)
     *
     * @return feed_entry_list
     */
    virtual std::vector<mcc::blockchain::feed_entry> blockchain_get_feeds_from_delegate(const std::string& delegate_name) const = 0;
    /**
     * Returns the bid side of the order book for a given market.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param base_symbol the item being bought in this market (asset_symbol, required)
     * @param limit the maximum number of items to return, -1 for all (uint32_t, optional, defaults to "-1")
     *
     * @return market_order_array
     */
    virtual std::vector<mcc::blockchain::market_order> blockchain_market_list_bids(const std::string& quote_symbol, const std::string& base_symbol, uint32_t limit = fc::json::from_string("\"-1\"").as<uint32_t>()) const = 0;
    /**
     * Returns the ask side of the order book for a given market.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param base_symbol the item being bought in this market (asset_symbol, required)
     * @param limit the maximum number of items to return, -1 for all (uint32_t, optional, defaults to "-1")
     *
     * @return market_order_array
     */
    virtual std::vector<mcc::blockchain::market_order> blockchain_market_list_asks(const std::string& quote_symbol, const std::string& base_symbol, uint32_t limit = fc::json::from_string("\"-1\"").as<uint32_t>()) const = 0;
    /**
     * Returns the short side of the order book for a given market.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param limit the maximum number of items to return, -1 for all (uint32_t, optional, defaults to "-1")
     *
     * @return market_order_array
     */
    virtual std::vector<mcc::blockchain::market_order> blockchain_market_list_shorts(const std::string& quote_symbol, uint32_t limit = fc::json::from_string("\"-1\"").as<uint32_t>()) const = 0;
    /**
     * Returns the covers side of the order book for a given market.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param base_symbol the symbol name the market is collateralized in (asset_symbol, optional, defaults to "XTS")
     * @param limit the maximum number of items to return, -1 for all (uint32_t, optional, defaults to "-1")
     *
     * @return market_order_array
     */
    virtual std::vector<mcc::blockchain::market_order> blockchain_market_list_covers(const std::string& quote_symbol, const std::string& base_symbol = fc::json::from_string("\"XTS\"").as<std::string>(), uint32_t limit = fc::json::from_string("\"-1\"").as<uint32_t>()) const = 0;
    /**
     * Returns the total collateral for an asset of a given type.
     *
     * @param symbol the symbol for the asset to count collateral for (asset_symbol, required)
     *
     * @return share_type
     */
    virtual mcc::blockchain::share_type blockchain_market_get_asset_collateral(const std::string& symbol) const = 0;
    /**
     * Returns the long and short sides of the order book for a given market.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param base_symbol the item being bought in this market (asset_symbol, required)
     * @param limit the maximum number of items to return, -1 for all (uint32_t, optional, defaults to "10")
     *
     * @return pair<market_order_array,market_order_array>
     */
    virtual std::pair<std::vector<mcc::blockchain::market_order>,std::vector<mcc::blockchain::market_order>> blockchain_market_order_book(const std::string& quote_symbol, const std::string& base_symbol, uint32_t limit = fc::json::from_string("\"10\"").as<uint32_t>()) const = 0;
    /**
     * Fetch an order.
     *
     * @param order_id market order id (string, required)
     *
     * @return market_order
     */
    virtual mcc::blockchain::market_order blockchain_get_market_order(const std::string& order_id) const = 0;
    /**
     * List an order list of a specific market.
     *
     * @param base_symbol the base symbol of the market (asset_symbol, required)
     * @param quote_symbol the quote symbol of the market (asset_symbol, required)
     * @param account_address the account for which to get the orders (string, required)
     * @param limit the maximum number of items to return, -1 for all (uint32_t, optional, defaults to "10")
     *
     * @return market_order_map
     */
    virtual std::map<mcc::blockchain::order_id_type, mcc::blockchain::market_order> blockchain_list_address_orders(const std::string& base_symbol, const std::string& quote_symbol, const std::string& account_address, uint32_t limit = fc::json::from_string("\"10\"").as<uint32_t>()) const = 0;
    /**
     * Returns a list of recently filled orders in a given market, in reverse order of execution.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param base_symbol the item being bought in this market (asset_symbol, required)
     * @param skip_count Number of transactions before head block to skip in listing (uint32_t, optional, defaults to
     *                   "0")
     * @param limit The maximum number of transactions to list (uint32_t, optional, defaults to "20")
     * @param owner If present, only transactions belonging to this owner key will be returned (string, optional,
     *              defaults to "")
     *
     * @return order_history_record_array
     */
    virtual std::vector<mcc::blockchain::order_history_record> blockchain_market_order_history(const std::string& quote_symbol, const std::string& base_symbol, uint32_t skip_count = fc::json::from_string("\"0\"").as<uint32_t>(), uint32_t limit = fc::json::from_string("\"20\"").as<uint32_t>(), const std::string& owner = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Returns historical data on orders matched within the given timeframe for the specified market.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param base_symbol the item being bought in this market (asset_symbol, required)
     * @param start_time The time to begin getting price history for (timestamp, required)
     * @param duration The maximum time period to get price history for (time_interval_in_seconds, required)
     * @param granularity The frequency of price updates (each_block, each_hour, or each_day)
     *                    (market_history_key::time_granularity, optional, defaults to "each_block")
     *
     * @return market_history_points
     */
    virtual mcc::blockchain::market_history_points blockchain_market_price_history(const std::string& quote_symbol, const std::string& base_symbol, const fc::time_point& start_time, const fc::microseconds& duration, const mcc::blockchain::market_history_key::time_granularity_enum& granularity = fc::json::from_string("\"each_block\"").as<mcc::blockchain::market_history_key::time_granularity_enum>()) const = 0;
    /**
     * Returns stats on orders matched within the given timeframe for the specified market.
     *
     * @param quote_symbol the symbol name the market is quoted in (asset_symbol, required)
     * @param base_symbol the item being bought in this market (asset_symbol, required)
     * @param start_time The time to begin getting price history for (timestamp, required)
     * @param duration The maximum time period to get price history for (time_interval_in_seconds, required)
     * @param granularity The frequency of price updates (each_block, each_hour, or each_day)
     *                    (market_history_key::time_granularity, optional, defaults to "each_block")
     *
     * @return market_history_stat
     */
    virtual mcc::blockchain::market_history_stat blockchain_market_stat(const std::string& quote_symbol, const std::string& base_symbol, const fc::time_point& start_time, const fc::microseconds& duration, const mcc::blockchain::market_history_key::time_granularity_enum& granularity = fc::json::from_string("\"each_block\"").as<mcc::blockchain::market_history_key::time_granularity_enum>()) const = 0;
    /**
     * Returns a list of the current round's active delegates in signing order.
     *
     * @param first (uint32_t, optional, defaults to 0)
     * @param count (uint32_t, optional, defaults to 20)
     *
     * @return account_record_array
     */
    virtual std::vector<mcc::blockchain::account_record> blockchain_list_active_delegates(uint32_t first = fc::json::from_string("0").as<uint32_t>(), uint32_t count = fc::json::from_string("20").as<uint32_t>()) const = 0;
    /**
     * Returns a list of all the delegates sorted by vote.
     *
     * @param first (uint32_t, optional, defaults to 0)
     * @param count (uint32_t, optional, defaults to 20)
     *
     * @return account_record_array
     */
    virtual std::vector<mcc::blockchain::account_record> blockchain_list_delegates(uint32_t first = fc::json::from_string("0").as<uint32_t>(), uint32_t count = fc::json::from_string("20").as<uint32_t>()) const = 0;
    /**
     * Returns a descending list of block records starting from the specified block number.
     *
     * @param max_block_num the block num to start from; negative to count backwards from the current head block
     *                      (uint32_t, optional, defaults to -1)
     * @param limit max number of blocks to return (uint32_t, optional, defaults to 20)
     *
     * @return block_record_array
     */
    virtual std::vector<mcc::blockchain::block_record> blockchain_list_blocks(uint32_t max_block_num = fc::json::from_string("-1").as<uint32_t>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) = 0;
    /**
     * Returns any delegates who were supposed to produce a given block number but didn't.
     *
     * @param block_number The block to examine (uint32_t, required)
     *
     * @return account_name_array
     */
    virtual std::vector<std::string> blockchain_list_missing_block_delegates(uint32_t block_number) = 0;
    /**
     * dumps the fork data to graphviz format.
     *
     * @param start_block the first block number to consider (uint32_t, optional, defaults to 1)
     * @param end_block the last block number to consider (uint32_t, optional, defaults to -1)
     * @param filename the filename to save to (string, optional, defaults to "")
     *
     * @return string
     */
    virtual std::string blockchain_export_fork_graph(uint32_t start_block = fc::json::from_string("1").as<uint32_t>(), uint32_t end_block = fc::json::from_string("-1").as<uint32_t>(), const std::string& filename = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * returns a list of all blocks for which there is a fork off of the main chain.
     *
     * @return map<uint32_t, vector<fork_record>>
     */
    virtual std::map<uint32_t, std::vector<mcc::blockchain::fork_record>> blockchain_list_forks() const = 0;
    /**
     * Query the most recent block production slot records for the specified delegate.
     *
     * @param delegate_name Delegate whose block production slot records to query (string, required)
     * @param limit The maximum number of slot records to return (uint32_t, optional, defaults to "10")
     *
     * @return slot_records_list
     */
    virtual std::vector<mcc::blockchain::slot_record> blockchain_get_delegate_slot_records(const std::string& delegate_name, uint32_t limit = fc::json::from_string("\"10\"").as<uint32_t>()) const = 0;
    /**
     * Get the delegate that signed a given block.
     *
     * @param block block number or ID to retrieve the signee for (string, required)
     *
     * @return string
     */
    virtual std::string blockchain_get_block_signee(const std::string& block) const = 0;
    /**
     * Returns a list of active markets.
     *
     * @return market_status_array
     */
    virtual std::vector<mcc::blockchain::string_status_record> blockchain_list_markets() const = 0;
    /**
     * Returns a list of market transactions executed on a given block.
     *
     * @param block_number Block to get market operations for. (uint32_t, required)
     *
     * @return market_transaction_array
     */
    virtual std::vector<mcc::blockchain::market_transaction> blockchain_list_market_transactions(uint32_t block_number) const = 0;
    /**
     * Returns the status of a particular market, including any trading errors.
     *
     * @param quote_symbol quote symbol (asset_symbol, required)
     * @param base_symbol base symbol (asset_symbol, required)
     *
     * @return market_status
     */
    virtual mcc::blockchain::string_status_record blockchain_market_status(const std::string& quote_symbol, const std::string& base_symbol) const = 0;
    /**
     * Returns the total shares in the genesis block which have never been fully or partially claimed.
     *
     * @return asset
     */
    virtual mcc::blockchain::asset blockchain_unclaimed_genesis() const = 0;
    /**
     * Verify that the given signature proves the given hash was signed by the given account.
     *
     * @param signer A public key, address, or account name whose signature to check (string, required)
     * @param hash The hash the signature claims to be for (sha256, required)
     * @param signature A signature produced by wallet_sign_hash (compact_signature, required)
     *
     * @return bool
     */
    virtual bool blockchain_verify_signature(const std::string& signer, const fc::sha256& hash, const fc::ecc::compact_signature& signature) const = 0;
    /**
     * Takes a signed transaction and broadcasts it to the network.
     *
     * @param trx The transaction to broadcast (signed_transaction, required)
     */
    virtual void blockchain_broadcast_transaction(const mcc::blockchain::signed_transaction& trx) = 0;
    /**
     * Extra information about the wallet.
     *
     * @return json_object
     */
    virtual fc::variant_object wallet_get_info() = 0;
    /**
     * Opens the wallet of the given name.
     *
     * @param wallet_name the name of the wallet to open (wallet_name, required)
     */
    virtual void wallet_open(const std::string& wallet_name) = 0;
    /**
     * Get the account entry for a given name.
     *
     * @param account_name the name of the account whose public address you want (account_name, required)
     *
     * @return string
     */
    virtual std::string wallet_get_account_public_address(const std::string& account_name) const = 0;
    /**
     * Lists all accounts and account addresses for which we have a private key in this wallet.
     *
     * @return account_address_data_array
     */
    virtual std::vector<mcc::wallet::account_address_data> wallet_list_my_addresses() const = 0;
    /**
     * Creates a wallet with the given name.
     *
     * @param wallet_name name of the wallet to create (wallet_name, required)
     * @param new_passphrase a passphrase for encrypting the wallet; must be surrounded with quotes if contains spaces
     *                       (new_passphrase, required)
     * @param brain_key a strong passphrase that will be used to generate all private keys, defaults to a large random
     *                  number (brainkey, optional, defaults to "")
     * @param new_passphrase_verify optionally provide passphrase again to double-check (passphrase, optional, defaults
     *                              to "")
     */
    virtual void wallet_create(const std::string& wallet_name, const std::string& new_passphrase, const std::string& brain_key = fc::json::from_string("\"\"").as<std::string>(), const std::string& new_passphrase_verify = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Loads the private key into the specified account. Returns which account it was actually imported to.
     *
     * @param wif_key A private key in bitcoin Wallet Import Format (WIF) (wif_private_key, required)
     * @param account_name the name of the account the key should be imported into, if null then the key must belong to
     *                     an active account (account_name, optional, defaults to null)
     * @param create_new_account If true, the wallet will attempt to create a new account for the name provided rather
     *                           than import the key into an existing account (bool, optional, defaults to false)
     * @param rescan If true, the wallet will rescan the blockchain looking for transactions that involve this private
     *               key (bool, optional, defaults to false)
     *
     * @return account_name
     */
    virtual std::string wallet_import_private_key(const std::string& wif_key, const std::string& account_name = fc::json::from_string("null").as<std::string>(), bool create_new_account = fc::json::from_string("false").as<bool>(), bool rescan = fc::json::from_string("false").as<bool>()) = 0;
    /**
     * Imports a Bitcoin Core or BitShares PTS wallet.
     *
     * @param wallet_filename the Bitcoin/PTS wallet file path (filename, required)
     * @param passphrase the imported wallet's password (passphrase, required)
     * @param account_name the account to receive the contents of the wallet (account_name, required)
     *
     * @return uint32_t
     */
    virtual uint32_t wallet_import_bitcoin(const fc::path& wallet_filename, const std::string& passphrase, const std::string& account_name) = 0;
    /**
     * Imports an Electrum wallet.
     *
     * @param wallet_filename the Electrum wallet file path (filename, required)
     * @param passphrase the imported wallet's password (passphrase, required)
     * @param account_name the account to receive the contents of the wallet (account_name, required)
     *
     * @return uint32_t
     */
    virtual uint32_t wallet_import_electrum(const fc::path& wallet_filename, const std::string& passphrase, const std::string& account_name) = 0;
    /**
     * Create the key from keyhotee config and import it to the wallet, creating a new account using this key.
     *
     * @param firstname first name in keyhotee profile config, for salting the seed of private key (name, required)
     * @param middlename middle name in keyhotee profile config, for salting the seed of private key (name, required)
     * @param lastname last name in keyhotee profile config, for salting the seed of private key (name, required)
     * @param brainkey brainkey in keyhotee profile config, for salting the seed of private key (brainkey, required)
     * @param keyhoteeid using keyhotee id as account name (keyhoteeid, required)
     */
    virtual void wallet_import_keyhotee(const std::string& firstname, const std::string& middlename, const std::string& lastname, const std::string& brainkey, const std::string& keyhoteeid) = 0;
    /**
     * Imports anything that looks like a private key from the given JSON file.
     *
     * @param json_filename the full path and filename of JSON wallet to import (filename, required)
     * @param imported_wallet_passphrase passphrase for encrypted keys (passphrase, required)
     * @param account Account into which to import keys. (account_name, required)
     *
     * @return uint32_t
     */
    virtual uint32_t wallet_import_keys_from_json(const fc::path& json_filename, const std::string& imported_wallet_passphrase, const std::string& account) = 0;
    /**
     * Closes the curent wallet if one is open.
     */
    virtual void wallet_close() = 0;
    /**
     * Exports the current wallet to a JSON file.
     *
     * @param json_filename the full path and filename of JSON file to generate (filename, required)
     */
    virtual void wallet_backup_create(const fc::path& json_filename) const = 0;
    /**
     * Creates a new wallet from an exported JSON file.
     *
     * @param json_filename the full path and filename of JSON wallet to import (filename, required)
     * @param wallet_name name of the wallet to create (wallet_name, required)
     * @param imported_wallet_passphrase passphrase of the imported wallet (passphrase, required)
     */
    virtual void wallet_backup_restore(const fc::path& json_filename, const std::string& wallet_name, const std::string& imported_wallet_passphrase) = 0;
    /**
     * Exports encrypted keys to a JSON file.
     *
     * @param json_filename the full path and filename of JSON file to generate (filename, required)
     */
    virtual void wallet_export_keys(const fc::path& json_filename) const = 0;
    /**
     * Enables or disables automatic wallet backups.
     *
     * @param enabled true to enable and false to disable (bool, required)
     *
     * @return bool
     */
    virtual bool wallet_set_automatic_backups(bool enabled) = 0;
    /**
     * Set transaction expiration time.
     *
     * @param seconds seconds before new transactions expire (uint32_t, required)
     *
     * @return uint32_t
     */
    virtual uint32_t wallet_set_transaction_expiration_time(uint32_t seconds) = 0;
    /**
     * Lists transaction history for the specified account.
     *
     * @param account_name the name of the account for which the transaction history will be returned, "" for all
     *                     accounts (string, optional, defaults to "")
     * @param asset_symbol only include transactions involving the specified asset, or "" to include all (string,
     *                     optional, defaults to "")
     * @param limit limit the number of returned transactions; negative for most recent and positive for least recent.
     *              0 does not limit (int32_t, optional, defaults to 0)
     * @param start_block_num the earliest block number to list transactions from; 0 to include all transactions
     *                        starting from genesis (uint32_t, optional, defaults to 0)
     * @param end_block_num the latest block to list transaction from; -1 to include all transactions ending at the
     *                      head block (uint32_t, optional, defaults to -1)
     *
     * @return pretty_transactions
     */
    virtual std::vector<mcc::wallet::pretty_transaction> wallet_account_transaction_history(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>(), const std::string& asset_symbol = fc::json::from_string("\"\"").as<std::string>(), int32_t limit = fc::json::from_string("0").as<int32_t>(), uint32_t start_block_num = fc::json::from_string("0").as<uint32_t>(), uint32_t end_block_num = fc::json::from_string("-1").as<uint32_t>()) const = 0;
    /**
     * Lists wallet's balance at the given time.
     *
     * @param time the date and time for which the balance will be computed (timestamp, required)
     * @param account_name the name of the account for which the historic balance will be returned, "" for all accounts
     *                     (string, optional, defaults to "")
     *
     * @return account_balance_summary_type
     */
    virtual mcc::wallet::account_balance_summary_type wallet_account_historic_balance(const fc::time_point& time, const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     *
     * @param account_name the name of the account for which the transaction history will be returned, "" for all
     *                     accounts (string, optional, defaults to "")
     *
     * @return experimental_transactions
     */
    virtual std::set<mcc::wallet::pretty_transaction_experimental> wallet_transaction_history_experimental(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Removes the specified transaction record from your transaction history. USE WITH CAUTION! Rescan cannot
     * reconstruct all transaction details.
     *
     * @param transaction_id the id (or id prefix) of the transaction record (string, required)
     */
    virtual void wallet_remove_transaction(const std::string& transaction_id) = 0;
    /**
     * Return any errors for your currently pending transactions.
     *
     * @param filename filename to save pending transaction errors to (string, optional, defaults to "")
     *
     * @return map<transaction_id_type, fc::exception>
     */
    virtual std::map<mcc::blockchain::transaction_id_type, fc::exception> wallet_get_pending_transaction_errors(const std::string& filename = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Lock the private keys in wallet, disables spending commands until unlocked.
     */
    virtual void wallet_lock() = 0;
    /**
     * Unlock the private keys in the wallet to enable spending operations.
     *
     * @param timeout the number of seconds to keep the wallet unlocked (uint32_t, required)
     * @param passphrase the passphrase for encrypting the wallet (passphrase, required)
     */
    virtual void wallet_unlock(uint32_t timeout, const std::string& passphrase) = 0;
    /**
     * Change the password of the current wallet.
     *
     * This will change the wallet's spending passphrase, please make sure you remember it.
     *
     * @param new_passphrase the new passphrase for encrypting the wallet; must be surrounded with quotes if contains
     *                       spaces (new_passphrase, required)
     * @param new_passphrase_verify optionally provide passphrase again to double-check (passphrase, optional, defaults
     *                              to "")
     */
    virtual void wallet_change_passphrase(const std::string& new_passphrase, const std::string& new_passphrase_verify = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Return a list of wallets in the current data directory.
     *
     * @return wallet_name_array
     */
    virtual std::vector<std::string> wallet_list() const = 0;
    /**
     * Add new account for receiving payments.
     *
     * @param account_name the name you will use to refer to this receive account (account_name, required)
     *
     * @return public_key
     */
    virtual mcc::blockchain::public_key_type wallet_account_create(const std::string& account_name) = 0;
    /**
     * List all contact entries.
     *
     * @return wallet_contact_record_array
     */
    virtual std::vector<mcc::wallet::wallet_contact_record> wallet_list_contacts() const = 0;
    /**
     * Get the specified contact entry.
     *
     * @param contact the value or label (prefixed by "label:") of the contact to query (string, required)
     *
     * @return owallet_contact_record
     */
    virtual mcc::wallet::owallet_contact_record wallet_get_contact(const std::string& contact) const = 0;
    /**
     * Add a new contact entry or update the label for an existing entry.
     *
     * @param contact a registered account name, a public key, an address, or a btc address that represents this
     *                contact (string, required)
     * @param label an optional custom label to use when referring to this contact (string, optional, defaults to "")
     *
     * @return wallet_contact_record
     */
    virtual mcc::wallet::wallet_contact_record wallet_add_contact(const std::string& contact, const std::string& label = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Remove a contact entry.
     *
     * @param contact the value or label (prefixed by "label:") of the contact to remove (string, required)
     *
     * @return owallet_contact_record
     */
    virtual mcc::wallet::owallet_contact_record wallet_remove_contact(const std::string& contact) = 0;
    /**
     * List all approval entries.
     *
     * @return wallet_approval_record_array
     */
    virtual std::vector<mcc::wallet::wallet_approval_record> wallet_list_approvals() const = 0;
    /**
     * Get the specified approval entry.
     *
     * @param approval the name of the approval to query (string, required)
     *
     * @return owallet_approval_record
     */
    virtual mcc::wallet::owallet_approval_record wallet_get_approval(const std::string& approval) const = 0;
    /**
     * Approve or disapprove the specified account or proposal.
     *
     * @param name a registered account or proposal name to set approval for (string, required)
     * @param approval 1, 0, or -1 respectively for approve, neutral, or disapprove (int8_t, optional, defaults to 1)
     *
     * @return wallet_approval_record
     */
    virtual mcc::wallet::wallet_approval_record wallet_approve(const std::string& name, int8_t approval = fc::json::from_string("1").as<int8_t>()) = 0;
    /**
     * Burns given amount to the given account. This will allow you to post message and +/- sentiment on someones
     * account as a form of reputation.
     *
     * @param amount_to_burn the amount of shares to burn (string, required)
     * @param asset_symbol the asset to burn (asset_symbol, required)
     * @param from_account_name the source account to draw the shares from (sending_account_name, required)
     * @param for_or_against the value 'for' or 'against' (string, required)
     * @param to_account_name the account to which the burn should be credited (for or against) and on which the public
     *                        message will appear (receive_account_name, required)
     * @param public_message a public message to post (string, optional, defaults to "")
     * @param anonymous true if anonymous, else signed by from_account_name (bool, optional, defaults to "false")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_burn(const std::string& amount_to_burn, const std::string& asset_symbol, const std::string& from_account_name, const std::string& for_or_against, const std::string& to_account_name, const std::string& public_message = fc::json::from_string("\"\"").as<std::string>(), bool anonymous = fc::json::from_string("\"false\"").as<bool>()) = 0;
    /**
     * Creates an address which can be used for a simple (non-TITAN) transfer.
     *
     * @param account_name The account name that will own this address (string, required)
     * @param label (string, optional, defaults to "")
     * @param legacy_network_byte If not -1, use this as the network byte for a BTC-style address. (int32_t, optional,
     *                            defaults to -1)
     *
     * @return string
     */
    virtual std::string wallet_address_create(const std::string& account_name, const std::string& label = fc::json::from_string("\"\"").as<std::string>(), int32_t legacy_network_byte = fc::json::from_string("-1").as<int32_t>()) = 0;
    /**
     * Do a simple (non-TITAN) transfer to an address.
     *
     * @param amount_to_transfer the amount of shares to transfer (string, required)
     * @param asset_symbol the asset to transfer (asset_symbol, required)
     * @param from_account_name the source account to draw the shares from (account_name, required)
     * @param to_address the address or pubkey to transfer to (string, required)
     * @param memo_message a memo to store with the transaction (string, optional, defaults to "")
     * @param strategy enumeration [vote_none | vote_all | vote_random | vote_recommended] (vote_strategy, optional,
     *                 defaults to "vote_recommended")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_transfer_to_address(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_address, const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>(), const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_recommended\"").as<mcc::wallet::vote_strategy>()) = 0;
    /**
     * check the password of the current wallet.
     *
     * This will check the wallet's spending passphrase.
     *
     * @param passphrase the passphrase to be checking (passphrase, required)
     *
     * @return bool
     */
    virtual bool wallet_check_passphrase(const std::string& passphrase) = 0;
    /**
     * Sends given amount to the given account, with the from field set to the payer. This transfer will occur in a
     * single transaction and will be cheaper, but may reduce your privacy.
     *
     * @param amount_to_transfer the amount of shares to transfer (string, required)
     * @param asset_symbol the asset to transfer (asset_symbol, required)
     * @param from_account_name the source account to draw the shares from (sending_account_name, required)
     * @param recipient the account name, public key, address, btc address, or contact label (prefixed by "label:")
     *                  which will receive the funds (string, required)
     * @param memo_message a memo to send if the recipient is an account (string, optional, defaults to "")
     * @param strategy enumeration [vote_recommended | vote_all | vote_none] (vote_strategy, optional, defaults to
     *                 "vote_recommended")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_transfer(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& recipient, const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>(), const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_recommended\"").as<mcc::wallet::vote_strategy>()) = 0;
    /**
     *
     * @param symbol which asset (string, required)
     * @param m Required number of signatures (uint32_t, required)
     * @param addresses List of possible addresses for signatures (address_list, required)
     *
     * @return address
     */
    virtual mcc::blockchain::address wallet_multisig_get_balance_id(const std::string& symbol, uint32_t m, const std::vector<mcc::blockchain::address>& addresses) const = 0;
    /**
     *
     * @param amount how much to transfer (string, required)
     * @param symbol which asset (string, required)
     * @param from_name TITAN name to withdraw from (string, required)
     * @param m Required number of signatures (uint32_t, required)
     * @param addresses List of possible addresses for signatures (address_list, required)
     * @param strategy enumeration [vote_recommended | vote_all | vote_none] (vote_strategy, optional, defaults to
     *                 "vote_none")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_multisig_deposit(const std::string& amount, const std::string& symbol, const std::string& from_name, uint32_t m, const std::vector<mcc::blockchain::address>& addresses, const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_none\"").as<mcc::wallet::vote_strategy>()) = 0;
    /**
     *
     * @param amount how much to transfer (string, required)
     * @param symbol which asset (string, required)
     * @param from_address the balance address to withdraw from (address, required)
     * @param to address or account to receive funds (string, required)
     * @param strategy enumeration [vote_recommended | vote_all | vote_none] (vote_strategy, optional, defaults to
     *                 "vote_none")
     * @param sign_and_broadcast (bool, optional, defaults to true)
     * @param builder_path If specified, will write builder here instead of to DATA_DIR/transactions/latest.trx
     *                     (string, optional, defaults to "")
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_withdraw_from_address(const std::string& amount, const std::string& symbol, const mcc::blockchain::address& from_address, const std::string& to, const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_none\"").as<mcc::wallet::vote_strategy>(), bool sign_and_broadcast = fc::json::from_string("true").as<bool>(), const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     *
     * @param amount how much to transfer (string, required)
     * @param symbol which asset (string, required)
     * @param from_address the balance address to withdraw from (legacy_address, required)
     * @param to address or account to receive funds (string, required)
     * @param strategy enumeration [vote_recommended | vote_all | vote_none] (vote_strategy, optional, defaults to
     *                 "vote_none")
     * @param sign_and_broadcast (bool, optional, defaults to true)
     * @param builder_path If specified, will write builder here instead of to DATA_DIR/transactions/latest.trx
     *                     (string, optional, defaults to "")
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_withdraw_from_legacy_address(const std::string& amount, const std::string& symbol, const mcc::blockchain::pts_address& from_address, const std::string& to, const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_none\"").as<mcc::wallet::vote_strategy>(), bool sign_and_broadcast = fc::json::from_string("true").as<bool>(), const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     *
     * @param amount how much to transfer (string, required)
     * @param symbol which asset (string, required)
     * @param from multisig balance ID to withdraw from (address, required)
     * @param to_address address to receive funds (address, required)
     * @param strategy enumeration [vote_recommended | vote_all | vote_none] (vote_strategy, optional, defaults to
     *                 "vote_none")
     * @param builder_path If specified, will write builder here instead of to DATA_DIR/transactions/latest.trx
     *                     (string, optional, defaults to "")
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_multisig_withdraw_start(const std::string& amount, const std::string& symbol, const mcc::blockchain::address& from, const mcc::blockchain::address& to_address, const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_none\"").as<mcc::wallet::vote_strategy>(), const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Review a transaction and add a signature.
     *
     * @param builder A transaction builder object created by a wallet. If null, tries to use builder in file.
     *                (transaction_builder, required)
     * @param broadcast Try to broadcast this transaction? (bool, optional, defaults to false)
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_builder_add_signature(const mcc::wallet::transaction_builder& builder, bool broadcast = fc::json::from_string("false").as<bool>()) = 0;
    /**
     * Review a transaction in a builder file and add a signature.
     *
     * @param builder_path If specified, will write builder here instead of to DATA_DIR/transactions/latest.trx
     *                     (string, optional, defaults to "")
     * @param broadcast Try to broadcast this transaction? (bool, optional, defaults to false)
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_builder_file_add_signature(const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>(), bool broadcast = fc::json::from_string("false").as<bool>()) = 0;
    /**
     * Releases escrow balance to third parties.
     *
     * @param pay_fee_with_account_name when releasing escrow a transaction fee must be paid by funds not in escrow,
     *                                  this account will pay the fee (account_name, required)
     * @param escrow_balance_id The balance id of the escrow to be released. (address, required)
     * @param released_by_account the account that is to perform the release. (account_name, required)
     * @param amount_to_sender Amount to release back to the sender. (string, optional, defaults to 0)
     * @param amount_to_receiver Amount to release to receiver. (string, optional, defaults to 0)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_release_escrow(const std::string& pay_fee_with_account_name, const mcc::blockchain::address& escrow_balance_id, const std::string& released_by_account, const std::string& amount_to_sender = fc::json::from_string("0").as<std::string>(), const std::string& amount_to_receiver = fc::json::from_string("0").as<std::string>()) = 0;
    /**
     * Sends given amount to the given name, with the from field set to a different account than the payer. This
     * transfer will occur in a single transaction and will be cheaper, but may reduce your privacy.
     *
     * @param amount_to_transfer the amount of shares to transfer (string, required)
     * @param asset_symbol the asset to transfer (asset_symbol, required)
     * @param paying_account_name the source account to draw the shares from (sending_account_name, required)
     * @param from_account_name the account to show the recipient as being the sender (requires account's private key
     *                          to be in wallet). (sending_account_name, required)
     * @param to_account_name the account to transfer the shares to (receive_account_name, required)
     * @param escrow_account_name the account of the escrow agent which has the power to decide how to divide the funds
     *                            among from/to accounts. (account_name, required)
     * @param agreement the hash of an agreement between the sender/receiver in the event a dispute arises can be given
     *                  to escrow agent (digest, optional, defaults to "")
     * @param memo_message a memo to store with the transaction (string, optional, defaults to "")
     * @param strategy enumeration [vote_recommended | vote_all | vote_none] (vote_strategy, optional, defaults to
     *                 "vote_recommended")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_transfer_from_with_escrow(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& paying_account_name, const std::string& from_account_name, const std::string& to_account_name, const std::string& escrow_account_name, const mcc::blockchain::digest_type& agreement = fc::json::from_string("\"\"").as<mcc::blockchain::digest_type>(), const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>(), const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_recommended\"").as<mcc::wallet::vote_strategy>()) = 0;
    /**
     * Scans the blockchain history for operations relevant to this wallet.
     *
     * @param start_block_num the first block to scan (uint32_t, optional, defaults to 0)
     * @param limit the maximum number of blocks to scan (uint32_t, optional, defaults to -1)
     * @param scan_in_background if true then scan asynchronously in the background, otherwise block until scan is done
     *                           (bool, optional, defaults to true)
     */
    virtual void wallet_rescan_blockchain(uint32_t start_block_num = fc::json::from_string("0").as<uint32_t>(), uint32_t limit = fc::json::from_string("-1").as<uint32_t>(), bool scan_in_background = fc::json::from_string("true").as<bool>()) = 0;
    /**
     * Cancel any current scan task.
     */
    virtual void wallet_cancel_scan() = 0;
    /**
     * Queries your wallet for the specified transaction.
     *
     * @param transaction_id the id (or id prefix) of the transaction (string, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_get_transaction(const std::string& transaction_id) = 0;
    /**
     * Scans the specified transaction.
     *
     * @param transaction_id the id (or id prefix) of the transaction (string, required)
     * @param overwrite_existing true to overwrite existing wallet transaction record and false otherwise (bool,
     *                           optional, defaults to false)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_scan_transaction(const std::string& transaction_id, bool overwrite_existing = fc::json::from_string("false").as<bool>()) = 0;
    /**
     * Scans the specified transaction.
     *
     * @param transaction_id the id (or id prefix) of the transaction (string, required)
     * @param overwrite_existing true to overwrite existing wallet transaction record and false otherwise (bool,
     *                           optional, defaults to false)
     */
    virtual void wallet_scan_transaction_experimental(const std::string& transaction_id, bool overwrite_existing = fc::json::from_string("false").as<bool>()) = 0;
    /**
     * Adds a custom note to the specified transaction.
     *
     * @param transaction_id the id (or id prefix) of the transaction (string, required)
     * @param note note to add (string, required)
     */
    virtual void wallet_add_transaction_note_experimental(const std::string& transaction_id, const std::string& note) = 0;
    /**
     * Rebroadcasts the specified transaction.
     *
     * @param transaction_id the id (or id prefix) of the transaction (string, required)
     */
    virtual void wallet_rebroadcast_transaction(const std::string& transaction_id) = 0;
    /**
     * Updates the data published about a given account.
     *
     * @param account_name the account that will be updated (account_name, required)
     * @param pay_from_account the account from which fees will be paid (account_name, required)
     * @param public_data public data about the account (json_variant, optional, defaults to null)
     * @param delegate_pay_rate -1 for non-delegates; otherwise the percent of delegate pay to accept per produced
     *                          block (uint8_t, optional, defaults to -1)
     * @param account_type titan_account | public_account - public accounts do not receive memos and all payments are
     *                     made to the active key (string, optional, defaults to "public_account")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_account_register(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data = fc::json::from_string("null").as<fc::variant>(), uint8_t delegate_pay_rate = fc::json::from_string("-1").as<uint8_t>(), const std::string& account_type = fc::json::from_string("\"public_account\"").as<std::string>()) = 0;
    /**
     * Overwrite the local custom data for an account, contact, or approval.
     *
     * @param type specify one of {account_record_type, contact_record_type, approval_record_type} (wallet_record_type,
     *             required)
     * @param item name of the account, contact, or approval (string, required)
     * @param custom_data the custom data object to store (variant_object, required)
     */
    virtual void wallet_set_custom_data(const mcc::wallet::wallet_record_type_enum& type, const std::string& item, const fc::variant_object& custom_data) = 0;
    /**
     * Updates the data published about a given account.
     *
     * @param account_name the account that will be updated (account_name, required)
     * @param pay_from_account the account from which fees will be paid (account_name, required)
     * @param public_data public data about the account (json_variant, optional, defaults to null)
     * @param delegate_pay_rate -1 for non-delegates; otherwise the percent of delegate pay to accept per produced
     *                          block (uint8_t, optional, defaults to -1)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_account_update_registration(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data = fc::json::from_string("null").as<fc::variant>(), uint8_t delegate_pay_rate = fc::json::from_string("-1").as<uint8_t>()) = 0;
    /**
     * Updates the specified account's active key and broadcasts the transaction.
     *
     * @param account_to_update The name of the account to update the active key of. (account_name, required)
     * @param pay_from_account The account from which fees will be paid. (account_name, required)
     * @param new_active_key WIF private key to update active key to. If empty, a new key will be generated. (string,
     *                       optional, defaults to "")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_account_update_active_key(const std::string& account_to_update, const std::string& pay_from_account, const std::string& new_active_key = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Lists all account entries.
     *
     * @return wallet_account_record_array
     */
    virtual std::vector<mcc::wallet::wallet_account_record> wallet_list_accounts() const = 0;
    /**
     * Get the specified account entry.
     *
     * @param account the name, key, address, or id of the account to query (string, required)
     *
     * @return owallet_account_record
     */
    virtual mcc::wallet::owallet_account_record wallet_get_account(const std::string& account) const = 0;
    /**
     * Rename an account in wallet.
     *
     * @param current_account_name the current name of the account (account_name, required)
     * @param new_account_name the new name for the account (new_account_name, required)
     */
    virtual void wallet_account_rename(const std::string& current_account_name, const std::string& new_account_name) = 0;
    /**
     * Create a new market-issued asset (BitAsset) on the blockchain. Warning: creation fees can be very high!.
     *
     * @param payer_account The local account name that will pay the creation fee (string, required)
     * @param symbol A unique symbol that will represent the new asset. Short symbols are very expensive!
     *               (asset_symbol, required)
     * @param name A human-readable name for the new asset (string, required)
     * @param description A human-readable description of the new asset (string, required)
     * @param max_divisibility Choose the max share divisibility for the new asset. Must be an inverse power of ten.
     *                         For example: 0.00001 or 1 (string, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_mia_create(const std::string& payer_account, const std::string& symbol, const std::string& name, const std::string& description, const std::string& max_divisibility) = 0;
    /**
     * Create a new user-issued asset on the blockchain. Warning: creation fees can be very high!.
     *
     * @param issuer_account The registered account name that will pay the creation fee and control the new asset
     *                       (string, required)
     * @param symbol A unique symbol that will represent the new asset. Short symbols are very expensive!
     *               (asset_symbol, required)
     * @param name A human-readable name for the new asset (string, required)
     * @param description A human-readable description of the new asset (string, required)
     * @param max_supply_with_trailing_decimals Choose the max share supply and max share divisibility for the new
     *                                          asset. For example: 10000000000.00000 or 12345.6789 (string, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_create(const std::string& issuer_account, const std::string& symbol, const std::string& name, const std::string& description, const std::string& max_supply_with_trailing_decimals) = 0;
    /**
     * Issue shares of a user-issued asset to the specified recipient.
     *
     * @param asset_amount the amount of shares of the asset to issue (string, required)
     * @param asset_symbol specify the unique symbol of the asset (asset_symbol, required)
     * @param recipient the account name, public key, address, btc address, or contact label (prefixed by "label:")
     *                  which will receive the funds (string, required)
     * @param memo_message a memo to send if the recipient is an account (string, optional, defaults to "")
     * @param builder_path builder path (string, optional, defaults to "")
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_uia_issue(const std::string& asset_amount, const std::string& asset_symbol, const std::string& recipient, const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>(), const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Issues new UIA shares to specific addresses.
     *
     * This is intended to be used with a helper script to break up snapshots. It will not do any magic for you.
     *
     * @param symbol the ticker symbol for asset (asset_symbol, required)
     * @param addresses A map of addresses-to-amounts to transfer the new shares to (snapshot_map, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_issue_to_addresses(const std::string& symbol, const std::map<std::string, mcc::blockchain::share_type>& addresses) = 0;
    /**
     * Issues new UIA shares to specific asset holders.
     *
     * @param account issue account (string, required)
     * @param issue_symbol the ticker symbol for asset (asset_symbol, required)
     * @param target_symbol the ticker symbol for target asset (asset_symbol, required)
     * @param issue_amount issue amount (string, required)
     * @param builder_path builder path (string, required)
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_uia_issue_to_asset(const std::string& account, const std::string& issue_symbol, const std::string& target_symbol, const std::string& issue_amount, const std::string& builder_path) = 0;
    /**
     * Issues new UIA shares to specific asset holders.
     *
     * @param account issue account (string, required)
     * @param transfer_amount transfer amount (string, required)
     * @param transfer_symbol the ticker symbol for asset (asset_symbol, required)
     * @param target_symbol the ticker symbol for target asset (asset_symbol, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_transfer_to_asset(const std::string& account, const std::string& transfer_amount, const std::string& transfer_symbol, const std::string& target_symbol) = 0;
    /**
     * Withdraw fees collected in the specified user-issued asset and deposit to the specified recipient.
     *
     * @param asset_symbol specify the unique symbol of the asset (asset_symbol, required)
     * @param recipient the account name, public key, address, btc address, or contact label (prefixed by "label:")
     *                  which will receive the funds (string, required)
     * @param memo_message a memo to send if the recipient is an account (string, optional, defaults to "")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_collect_fees(const std::string& asset_symbol, const std::string& recipient, const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Update the name, description, public data of the specified user-issue asset.
     *
     * @param paying_account the account that will pay the transaction fee (account_name, required)
     * @param asset_symbol the user-issued asset to update (asset_symbol, required)
     * @param name A human-readable name for the new asset (string, optional, defaults to "")
     * @param description A human-readable description of the new asset (string, optional, defaults to "")
     * @param public_data Extra data to attach to the asset (variant, optional, defaults to null)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_update_description(const std::string& paying_account, const std::string& asset_symbol, const std::string& name = fc::json::from_string("\"\"").as<std::string>(), const std::string& description = fc::json::from_string("\"\"").as<std::string>(), const fc::variant& public_data = fc::json::from_string("null").as<fc::variant>()) = 0;
    /**
     * Update the max supply and max divisibility of the specified user-issued asset if permitted.
     *
     * @param paying_account the account that will pay the transaction fee (account_name, required)
     * @param asset_symbol the user-issued asset to update (asset_symbol, required)
     * @param max_supply_with_trailing_decimals Choose the max share supply and max share divisibility for the asset.
     *                                          For example: 10000000000.00000 or 12345.6789 (string, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_update_supply(const std::string& paying_account, const std::string& asset_symbol, const std::string& max_supply_with_trailing_decimals) = 0;
    /**
     * Update the transaction fee, market fee rate for the specified user-issued asset if permitted.
     *
     * @param paying_account the account that will pay the transaction fee (account_name, required)
     * @param asset_symbol the user-issued asset to update (asset_symbol, required)
     * @param withdrawal_fee the transaction fee for the asset in shares of the asset (string, optional, defaults to
     *                       "")
     * @param market_fee_rate the market fee rate for the asset as a percentage between 0.01 and 100, or 0 (string,
     *                        optional, defaults to "")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_update_fees(const std::string& paying_account, const std::string& asset_symbol, const std::string& withdrawal_fee = fc::json::from_string("\"\"").as<std::string>(), const std::string& market_fee_rate = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Activate or deactivate one of the special flags for the specified user-issued asset as permitted.
     *
     * @param paying_account the account that will pay the transaction fee (account_name, required)
     * @param asset_symbol the user-issued asset to update (asset_symbol, required)
     * @param flag the special flag to enable or disable; one of {dynamic_max_supply, dynamic_fees, halted_markets,
     *             halted_withdrawals, retractable_balances, restricted_accounts} (asset_flag_enum, required)
     * @param enable_instead_of_disable true to enable, or false to disable (bool, required)
     * @param builder_path filepath to save builder (string, required)
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_uia_update_active_flags(const std::string& paying_account, const std::string& asset_symbol, const mcc::blockchain::asset_record::flag_enum& flag, bool enable_instead_of_disable, const std::string& builder_path) = 0;
    /**
     * Update the authority's special flag permissions for the specified user-issued asset. Warning: If any shares have
     * been issued, then revoked permissions cannot be restored!.
     *
     * @param paying_account the account that will pay the transaction fee (account_name, required)
     * @param asset_symbol the user-issued asset to update (asset_symbol, required)
     * @param permission the special permission to enable or disable; one of {dynamic_max_supply, dynamic_fees,
     *                   halted_markets, halted_withdrawals, retractable_balances, restricted_accounts}
     *                   (asset_flag_enum, required)
     * @param add_instead_of_remove True to add, or false to remove. Use with extreme caution! (bool, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_update_authority_permissions(const std::string& paying_account, const std::string& asset_symbol, const mcc::blockchain::asset_record::flag_enum& permission, bool add_instead_of_remove) = 0;
    /**
     * Add or remove the specified registered account from the specified user-issued asset's whitelist.
     *
     * @param paying_account the account that will pay the transaction fee (account_name, required)
     * @param asset_symbol the user-issued asset that will have its whitelist updated (asset_symbol, required)
     * @param account_name the name of the account to add or remove from the whitelist (string, required)
     * @param add_to_whitelist true to add to whitelist, or false to remove (bool, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_update_whitelist(const std::string& paying_account, const std::string& asset_symbol, const std::string& account_name, bool add_to_whitelist) = 0;
    /**
     * Retract all funds from the specified user-issued asset balance record.
     *
     * @param balance_id the ID of the balance record (address, required)
     * @param account_name the local account name that will receive the funds and pay the fee (string, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_uia_retract_balance(const mcc::blockchain::address& balance_id, const std::string& account_name) = 0;
    /**
     * Lists the total asset balances for all open escrows.
     *
     * @param account_name the account to get a escrow summary for, or leave empty for all accounts (account_name,
     *                     optional, defaults to "")
     *
     * @return escrow_summary_array
     */
    virtual std::vector<mcc::wallet::escrow_summary> wallet_escrow_summary(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Lists the total asset balances for the specified account.
     *
     * @param account_name the account to get a balance for, or leave empty for all accounts (account_name, optional,
     *                     defaults to "")
     *
     * @return account_balance_summary_type
     */
    virtual mcc::wallet::account_balance_summary_type wallet_account_balance(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Lists the balance IDs for the specified account.
     *
     * @param account_name the account to get a balance IDs for, or leave empty for all accounts (account_name,
     *                     optional, defaults to "")
     *
     * @return account_balance_id_summary_type
     */
    virtual mcc::wallet::account_balance_id_summary_type wallet_account_balance_ids(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Lists the total asset balances across all withdraw condition types for the specified account.
     *
     * @param account_name the account to get a balance for, or leave empty for all accounts (account_name, optional,
     *                     defaults to "")
     *
     * @return account_extended_balance_type
     */
    virtual mcc::wallet::account_extended_balance_type wallet_account_balance_extended(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * List the vesting balances available to the specified account.
     *
     * @param account_name the account name to list vesting balances for, or leave empty for all accounts
     *                     (account_name, optional, defaults to "")
     *
     * @return account_vesting_balance_summary_type
     */
    virtual mcc::wallet::account_vesting_balance_summary_type wallet_account_vesting_balances(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Lists the total accumulated yield for asset balances.
     *
     * @param account_name the account to get yield for, or leave empty for all accounts (account_name, optional,
     *                     defaults to "")
     *
     * @return account_balance_summary_type
     */
    virtual mcc::wallet::account_balance_summary_type wallet_account_yield(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Lists all public keys in this account.
     *
     * @param account_name the account for which public keys should be listed (account_name, required)
     *
     * @return public_key_summary_array
     */
    virtual std::vector<mcc::wallet::public_key_summary> wallet_account_list_public_keys(const std::string& account_name) = 0;
    /**
     * Used to transfer some of the delegate's pay from their balance.
     *
     * @param delegate_name the delegate whose pay is being cashed out (account_name, required)
     * @param to_account_name the account that should receive the funds (account_name, required)
     * @param amount_to_withdraw the amount to withdraw (string, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_delegate_withdraw_pay(const std::string& delegate_name, const std::string& to_account_name, const std::string& amount_to_withdraw) = 0;
    /**
     * Set the fee to add to new transactions.
     *
     * @param fee the wallet transaction fee to set (string, required)
     *
     * @return asset
     */
    virtual mcc::blockchain::asset wallet_set_transaction_fee(const std::string& fee) = 0;
    /**
     * Returns .
     *
     * @param symbol the wallet transaction if paid in the given asset type (asset_symbol, optional, defaults to "")
     *
     * @return asset
     */
    virtual mcc::blockchain::asset wallet_get_transaction_fee(const std::string& symbol = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Used to place a request to buy a quantity of assets at a price specified in another asset.
     *
     * @param from_account_name the account that will provide funds for the bid (account_name, required)
     * @param quantity the quantity of items you would like to buy (string, required)
     * @param quantity_symbol the type of items you would like to buy (asset_symbol, required)
     * @param base_price the price you would like to pay (string, required)
     * @param base_symbol the type of asset you would like to pay with (asset_symbol, required)
     * @param allow_stupid_bid Allow user to place bid at more than 5% above the current sell price. (bool, optional,
     *                         defaults to "false")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_submit_bid(const std::string& from_account_name, const std::string& quantity, const std::string& quantity_symbol, const std::string& base_price, const std::string& base_symbol, bool allow_stupid_bid = fc::json::from_string("\"false\"").as<bool>()) = 0;
    /**
     * Used to place a request to sell a quantity of assets at a price specified in another asset.
     *
     * @param from_account_name the account that will provide funds for the ask (account_name, required)
     * @param sell_quantity the quantity of items you would like to sell (string, required)
     * @param sell_quantity_symbol the type of items you would like to sell (asset_symbol, required)
     * @param ask_price the price per unit sold. (string, required)
     * @param ask_price_symbol the type of asset you would like to be paid (asset_symbol, required)
     * @param allow_stupid_ask Allow user to place ask at more than 5% below the current buy price. (bool, optional,
     *                         defaults to "false")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_submit_ask(const std::string& from_account_name, const std::string& sell_quantity, const std::string& sell_quantity_symbol, const std::string& ask_price, const std::string& ask_price_symbol, bool allow_stupid_ask = fc::json::from_string("\"false\"").as<bool>()) = 0;
    /**
     * Used to place a request to short sell a quantity of assets at a price specified.
     *
     * @param from_account_name the account that will provide funds for the ask (account_name, required)
     * @param short_collateral the amount of collateral you wish to fund this short with (string, required)
     * @param collateral_symbol the type of asset collateralizing this short (i.e. XTS) (asset_symbol, required)
     * @param interest_rate the APR you wish to pay interest at (0.0% to 50.0%) (string, required)
     * @param quote_symbol the asset to short sell (i.e. USD) (asset_symbol, required)
     * @param short_price_limit maximim price (USD per XTS) that the short will execute at, if 0 then no limit will be
     *                          applied (string, optional, defaults to 0)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_submit_short(const std::string& from_account_name, const std::string& short_collateral, const std::string& collateral_symbol, const std::string& interest_rate, const std::string& quote_symbol, const std::string& short_price_limit = fc::json::from_string("0").as<std::string>()) = 0;
    /**
     * Used to place a request to cover an existing short position.
     *
     * @param from_account_name the account that will provide funds for the ask (account_name, required)
     * @param quantity the quantity of asset you would like to cover (string, required)
     * @param quantity_symbol the type of asset you are covering (ie: USD) (asset_symbol, required)
     * @param cover_id the order ID you would like to cover (order_id, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_cover(const std::string& from_account_name, const std::string& quantity, const std::string& quantity_symbol, const mcc::blockchain::order_id_type& cover_id) = 0;
    /**
     * Cancel and/or create many market orders in a single transaction.
     *
     * @param cancel_order_ids Order IDs of all market orders to cancel in this transaction. (order_ids, required)
     * @param new_orders Descriptions of all new orders to create in this transaction. (order_descriptions, required)
     * @param sign True if transaction should be signed and broadcast (if possible), false otherwse. (bool, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_batch_update(const std::vector<mcc::blockchain::order_id_type>& cancel_order_ids, const std::vector<mcc::wallet::order_description>& new_orders, bool sign) = 0;
    /**
     * Add collateral to a short position.
     *
     * @param from_account_name the account that will provide funds for the ask (account_name, required)
     * @param cover_id the ID of the order to recollateralize (order_id, required)
     * @param real_quantity_collateral_to_add the quantity of collateral of the base asset to add to the specified
     *                                        position (string, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_add_collateral(const std::string& from_account_name, const mcc::blockchain::order_id_type& cover_id, const std::string& real_quantity_collateral_to_add) = 0;
    /**
     * List an order list of a specific market.
     *
     * @param base_symbol the base symbol of the market (asset_symbol, required)
     * @param quote_symbol the quote symbol of the market (asset_symbol, required)
     * @param limit the maximum number of items to return (uint32_t, optional, defaults to -1)
     * @param account_name the account for which to get the orders, or empty for all accounts (account_name, optional,
     *                     defaults to "")
     *
     * @return market_order_map
     */
    virtual std::map<mcc::blockchain::order_id_type, mcc::blockchain::market_order> wallet_market_order_list(const std::string& base_symbol, const std::string& quote_symbol, uint32_t limit = fc::json::from_string("-1").as<uint32_t>(), const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * List an order list of a specific account.
     *
     * @param account_name the account for which to get the orders, or empty for all accounts (account_name, optional,
     *                     defaults to "")
     * @param limit the maximum number of items to return (uint32_t, optional, defaults to -1)
     *
     * @return market_order_map
     */
    virtual std::map<mcc::blockchain::order_id_type, mcc::blockchain::market_order> wallet_account_order_list(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>(), uint32_t limit = fc::json::from_string("-1").as<uint32_t>()) = 0;
    /**
     * Cancel an order: deprecated - use wallet_market_cancel_orders.
     *
     * @param order_id the ID of the order to cancel (order_id, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_cancel_order(const mcc::blockchain::order_id_type& order_id) = 0;
    /**
     * Cancel more than one order at a time.
     *
     * @param order_ids the IDs of the orders to cancel (order_ids, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_market_cancel_orders(const std::vector<mcc::blockchain::order_id_type>& order_ids) = 0;
    /**
     * Reveals the private key corresponding to the specified public key or address; use with caution.
     *
     * @param input public key or address to dump private key for (string, required)
     *
     * @return optional_string
     */
    virtual fc::optional<std::string> wallet_dump_private_key(const std::string& input) const = 0;
    /**
     * Reveals the specified account private key; use with caution.
     *
     * @param account_name account name to dump private key for (string, required)
     * @param key_type which account private key to dump; one of {owner_key, active_key, signing_key}
     *                 (account_key_type, required)
     *
     * @return optional_string
     */
    virtual fc::optional<std::string> wallet_dump_account_private_key(const std::string& account_name, const mcc::wallet::account_key_type& key_type) const = 0;
    /**
     * Returns the allocation of votes by this account.
     *
     * @param account_name the account to report votes on, or empty for all accounts (account_name, optional, defaults
     *                     to "")
     *
     * @return account_vote_summary
     */
    virtual mcc::wallet::account_vote_summary_type wallet_account_vote_summary(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const = 0;
    /**
     * Set a property in the GUI settings DB.
     *
     * @param name the name of the setting to set (string, required)
     * @param value the value to set the setting to (variant, required)
     */
    virtual void wallet_set_setting(const std::string& name, const fc::variant& value) = 0;
    /**
     * Get the value of the given setting.
     *
     * @param name The name of the setting to fetch (string, required)
     *
     * @return optional_variant
     */
    virtual fc::optional<fc::variant> wallet_get_setting(const std::string& name) = 0;
    /**
     * Enable or disable block production for a particular delegate account.
     *
     * @param delegate_name The delegate to enable/disable block production for; ALL for all delegate accounts (string,
     *                      required)
     * @param enabled true to enable block production, false otherwise (bool, required)
     */
    virtual void wallet_delegate_set_block_production(const std::string& delegate_name, bool enabled) = 0;
    /**
     * Enable or disable wallet transaction scanning.
     *
     * @param enabled true to enable transaction scanning, false otherwise (bool, required)
     *
     * @return bool
     */
    virtual bool wallet_set_transaction_scanning(bool enabled) = 0;
    /**
     * Signs the provided message digest with the account key.
     *
     * @param signer A public key, address, or account name whose key to sign with (string, required)
     * @param hash SHA256 digest of the message to sign (sha256, required)
     *
     * @return compact_signature
     */
    virtual fc::ecc::compact_signature wallet_sign_hash(const std::string& signer, const fc::sha256& hash) = 0;
    /**
     * Initiates the login procedure by providing a BitShares Login URL.
     *
     * @param server_account Name of the account of the server. The user will be shown this name as the site he is
     *                       logging into. (string, required)
     *
     * @return string
     */
    virtual std::string wallet_login_start(const std::string& server_account) = 0;
    /**
     * Completes the login procedure by finding the user's public account key and shared secret.
     *
     * @param server_key The one-time public key from wallet_login_start. (public_key, required)
     * @param client_key The client's one-time public key. (public_key, required)
     * @param client_signature The client's signature of the shared secret. (compact_signature, required)
     *
     * @return variant
     */
    virtual fc::variant wallet_login_finish(const mcc::blockchain::public_key_type& server_key, const mcc::blockchain::public_key_type& client_key, const fc::ecc::compact_signature& client_signature) = 0;
    /**
     * Set this balance's voting address and slate.
     *
     * @param balance_id the current name of the account (address, required)
     * @param voter_address The new voting address. If none is specified, tries to re-use existing address. (string,
     *                      optional, defaults to "")
     * @param strategy enumeration [vote_recommended | vote_all | vote_none] (vote_strategy, optional, defaults to
     *                 "vote_all")
     * @param sign_and_broadcast (bool, optional, defaults to "true")
     * @param builder_path If specified, will write builder here instead of to DATA_DIR/transactions/latest.trx
     *                     (string, optional, defaults to "")
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_balance_set_vote_info(const mcc::blockchain::address& balance_id, const std::string& voter_address = fc::json::from_string("\"\"").as<std::string>(), const mcc::wallet::vote_strategy& strategy = fc::json::from_string("\"vote_all\"").as<mcc::wallet::vote_strategy>(), bool sign_and_broadcast = fc::json::from_string("\"true\"").as<bool>(), const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Publishes the current wallet delegate slate to the public data associated with the account.
     *
     * @param publishing_account_name The account to publish the slate ID under (account_name, required)
     * @param paying_account_name The account to pay transaction fees or leave empty to pay with publishing account
     *                            (account_name, optional, defaults to "")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_publish_slate(const std::string& publishing_account_name, const std::string& paying_account_name = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Publish your current client version to the specified account's public data record.
     *
     * @param publishing_account_name The account to publish the client version under (account_name, required)
     * @param paying_account_name The account to pay transaction fees with or leave empty to pay with publishing
     *                            account (account_name, optional, defaults to "")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_publish_version(const std::string& publishing_account_name, const std::string& paying_account_name = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Collect specified account's genesis balances.
     *
     * @param account_name account to collect genesis balances for (account_name, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_collect_genesis_balances(const std::string& account_name) = 0;
    /**
     * Collect specified account's vested balances.
     *
     * @param account_name account to collect vested balances for (account_name, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_collect_vested_balances(const std::string& account_name) = 0;
    /**
     * Update a delegate's block signing and feed publishing key.
     *
     * @param authorizing_account_name The account that will authorize changing the block signing key (account_name,
     *                                 required)
     * @param delegate_name The delegate account which will have its block signing key changed (account_name, required)
     * @param signing_key The new key that will be used for block signing (public_key, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_delegate_update_signing_key(const std::string& authorizing_account_name, const std::string& delegate_name, const mcc::blockchain::public_key_type& signing_key) = 0;
    /**
     * Attempts to recover accounts created after last backup was taken and returns number of successful recoveries.
     * Use if you have restored from backup and are missing accounts.
     *
     * @param accounts_to_recover The number of accounts to attept to recover (int32_t, required)
     * @param maximum_number_of_attempts The maximum number of keys to generate trying to recover accounts (int32_t,
     *                                   optional, defaults to 1000)
     *
     * @return int32_t
     */
    virtual int32_t wallet_recover_accounts(int32_t accounts_to_recover, int32_t maximum_number_of_attempts = fc::json::from_string("1000").as<int32_t>()) = 0;
    /**
     * Attempts to recover any missing recipient and memo information for the specified transaction.
     *
     * @param transaction_id_prefix the id (or id prefix) of the transaction record (string, required)
     * @param recipient_account the account name of the recipient (if known) (string, optional, defaults to "")
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_recover_titan_deposit_info(const std::string& transaction_id_prefix, const std::string& recipient_account = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * Verify whether the specified transaction made a TITAN deposit to the current wallet; returns null if not.
     *
     * @param transaction_id_prefix the id (or id prefix) of the transaction record (string, required)
     *
     * @return optional_variant_object
     */
    virtual fc::optional<fc::variant_object> wallet_verify_titan_deposit(const std::string& transaction_id_prefix) = 0;
    /**
     * publishes a price feed for BitAssets, only active delegates may do this.
     *
     * @param delegate_account the delegate to publish the price under (account_name, required)
     * @param price the number of this asset per XTS (string, required)
     * @param asset_symbol the type of asset being priced (asset_symbol, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_publish_price_feed(const std::string& delegate_account, const std::string& price, const std::string& asset_symbol) = 0;
    /**
     * publish price feeds for market-pegged assets; pays fee from delegate pay balance otherwise wallet account
     * balance.
     *
     * @param delegate_account the delegate to publish the price under (account_name, required)
     * @param symbol_to_price_map maps the BitAsset symbol to its price per share (string_map, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_publish_feeds(const std::string& delegate_account, const std::map<std::string, std::string>& symbol_to_price_map) = 0;
    /**
     * publishes a set of feeds for BitAssets for all active delegates, most useful for testnets.
     *
     * @param symbol_to_price_map maps the BitAsset symbol to its price per share (string_map, required)
     *
     * @return vector<std::pair<string, wallet_transaction_record>>
     */
    virtual std::vector<std::pair<std::string, mcc::wallet::wallet_transaction_record>> wallet_publish_feeds_multi_experimental(const std::map<std::string, std::string>& symbol_to_price_map) = 0;
    /**
     * tries to repair any inconsistent wallet account, key, and transaction records.
     *
     * @param collecting_account_name collect any orphan balances into this account (account_name, optional, defaults
     *                                to "")
     */
    virtual void wallet_repair_records(const std::string& collecting_account_name = fc::json::from_string("\"\"").as<std::string>()) = 0;
    /**
     * regenerates private keys as part of wallet recovery.
     *
     * @param account_name the account the generated keys should be a part of (account_name, required)
     * @param max_key_number the last key number to regenerate (uint32_t, required)
     *
     * @return int32_t
     */
    virtual int32_t wallet_regenerate_keys(const std::string& account_name, uint32_t max_key_number) = 0;
    /**
     * Retract (permanently disable) the specified account in case of master key compromise.
     *
     * @param account_to_retract The name of the account to retract. (account_name, required)
     * @param pay_from_account The account from which fees will be paid. (account_name, required)
     *
     * @return transaction_record
     */
    virtual mcc::wallet::wallet_transaction_record wallet_account_retract(const std::string& account_to_retract, const std::string& pay_from_account) = 0;
    /**
     * Generates a human friendly brain wallet key starting with a public salt as the last word.
     *
     * @return string
     */
    virtual std::string wallet_generate_brain_seed() const = 0;
    /**
     * update the authority of asset.
     *
     * @param account_name The name of the account to update asset authority. (account_name, required)
     * @param asset_symbol The asset to update. (asset_symbol, required)
     * @param vec_addr the addresses string to update the authority of asset. (string_array, required)
     * @param min_addr_num min address required. (uint32_t, required)
     * @param add_or_remove add or remove addresses from authority. (bool, required)
     * @param builder_path Filepath to save transaction_builder (string, required)
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_update_asset_authority(const std::string& account_name, const std::string& asset_symbol, const std::vector<std::string>& vec_addr, uint32_t min_addr_num, bool add_or_remove, const std::string& builder_path) = 0;
    /**
     * update the authority of asset.
     *
     * @param account_name The name of the account to update asset authority. (account_name, required)
     * @param asset_symbol The asset to update. (asset_symbol, required)
     * @param vec_addr the addresses string to update the authority of asset. (string_array, required)
     * @param min_addr_num min address signatures required. (uint32_t, required)
     * @param builder_path Filepath to save transaction_builder (string, required)
     *
     * @return transaction_builder
     */
    virtual mcc::wallet::transaction_builder wallet_set_asset_authority(const std::string& account_name, const std::string& asset_symbol, const std::vector<std::string>& vec_addr, uint32_t min_addr_num, const std::string& builder_path) = 0;
    /**
     * Return all the data a light wallet needs to bootstrap itself.
     *
     * @param arguments Arguments to fetch_welcome_package (variant_object, required)
     *
     * @return variant_object
     */
    virtual fc::variant_object fetch_welcome_package(const fc::variant_object& arguments) = 0;
    /**
     * Adds an account record to the request queue.
     *
     * @param account the account to be registered (account_record, required)
     *
     * @return bool
     */
    virtual bool request_register_account(const mcc::blockchain::account_record& account) = 0;
    /**
     * Adds an account record to the request queue.
     *
     * @param account_salt the salt property of the registered account (string, required)
     * @param paying_account_name the name of the account that should pay (account_name, required)
     *
     * @return bool
     */
    virtual bool approve_register_account(const std::string& account_salt, const std::string& paying_account_name) = 0;
    /**
     * Begin using simulated time for testing.
     *
     * @param new_simulated_time The simulated time to start with (timestamp, required)
     */
    virtual void debug_start_simulated_time(const fc::time_point& new_simulated_time) = 0;
    /**
     * Advance simulated time.
     *
     * @param delta_time_seconds How far in the future to advance the time (int32_t, required)
     * @param unit The unit of time ("seconds", "blocks", or "rounds") (string, optional, defaults to "seconds")
     */
    virtual void debug_advance_time(int32_t delta_time_seconds, const std::string& unit = fc::json::from_string("\"seconds\"").as<std::string>()) = 0;
    /**
     * Break into debugger (UNIX: SIGINT, win32: __debugbreak).
     *
     * @param block_number Delay trap until we start to process the given blocknum (uint32_t, required)
     */
    virtual void debug_trap(uint32_t block_number) = 0;
    /**
     * wait for specified amount of time.
     *
     * @param wait_time time in seconds to wait before accepting more input (uint32_t, required)
     */
    virtual void debug_wait(uint32_t wait_time) const = 0;
    /**
     * Don't return until the specified block has arrived.
     *
     * @param block_number The block number (or offset) to wait for (uint32_t, required)
     * @param type Whether to wait for an "absolute" block number, or a count of blocks "relative" to the current block
     *             number (string, optional, defaults to "absolute")
     */
    virtual void debug_wait_for_block_by_number(uint32_t block_number, const std::string& type = fc::json::from_string("\"absolute\"").as<std::string>()) = 0;
    /**
     * wait for n block intervals.
     *
     * @param wait_time_in_block_intervals time in block intervals to wait before accepting more input (uint32_t,
     *                                     required)
     */
    virtual void debug_wait_block_interval(uint32_t wait_time_in_block_intervals) const = 0;
    /**
     * enables or disables output from the CLI.
     *
     * @param enable_flag true to enable output, false to disable it (bool, required)
     */
    virtual void debug_enable_output(bool enable_flag) = 0;
    /**
     * prevents printing any times or other unpredictable data.
     *
     * @param enable_flag true to enable filtering, false to disable it (bool, required)
     */
    virtual void debug_filter_output_for_tests(bool enable_flag) = 0;
    /**
     * updates logging configuration (level, etc) based on settings in config.json.
     */
    virtual void debug_update_logging_config() = 0;
    /**
     * Returns call timings for node_delegate callbacks.
     *
     * @return json_object
     */
    virtual fc::variant_object debug_get_call_statistics() const = 0;
    /**
     * Returns client's debug name specified in config.json.
     *
     * @return string
     */
    virtual std::string debug_get_client_name() const = 0;
    /**
     * Generate/import deterministically generated private keys.
     *
     * @param start the number of the first key, or -1 to suppress suffix (int32_t, optional, defaults to "-1")
     * @param count the number of keys to generate (int32_t, optional, defaults to "1")
     * @param prefix a string prefix added to the seed used to generate keys (string, optional, defaults to "")
     * @param import whether to import generated keys (bool, optional, defaults to "false")
     * @param account_name the name of the account the key should be imported into, if null then the key must belong to
     *                     an active account (account_name, optional, defaults to null)
     * @param create_new_account If true, the wallet will attempt to create a new account for the name provided rather
     *                           than import the key into an existing account (bool, optional, defaults to false)
     * @param rescan If true, the wallet will rescan the blockchain looking for transactions that involve this private
     *               key (bool, optional, defaults to false)
     *
     * @return variants
     */
    virtual fc::variants debug_deterministic_private_keys(int32_t start = fc::json::from_string("\"-1\"").as<int32_t>(), int32_t count = fc::json::from_string("\"1\"").as<int32_t>(), const std::string& prefix = fc::json::from_string("\"\"").as<std::string>(), bool import = fc::json::from_string("\"false\"").as<bool>(), const std::string& account_name = fc::json::from_string("null").as<std::string>(), bool create_new_account = fc::json::from_string("false").as<bool>(), bool rescan = fc::json::from_string("false").as<bool>()) = 0;
    /**
     * stop before given block number.
     *
     * @param block_number The block number to stop before (uint32_t, required)
     */
    virtual void debug_stop_before_block(uint32_t block_number) = 0;
    /**
     * enables or disables (slow) market matching verification code.
     *
     * @param enable_flag true to enable checking, false to disable it (bool, required)
     */
    virtual void debug_verify_market_matching(bool enable_flag) = 0;
    /**
     * returns a list of blocks flagged by debug_verify_market_matching.
     *
     * @return variants
     */
    virtual fc::variants debug_list_matching_errors() const = 0;
  };

} } // end namespace mcc::api
