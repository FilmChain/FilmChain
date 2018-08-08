#include <fcc/blockchain/address.hpp>
#include <fcc/blockchain/genesis_state.hpp>
#include <fcc/blockchain/config.hpp>
#include <fcc/blockchain/pts_address.hpp>
#include <fc/crypto/elliptic.hpp>
#include <fc/exception/exception.hpp>
#include <fc/log/logger.hpp>
#include <fc/io/json.hpp>
#include <fc/reflect/variant.hpp>
#include <fc/filesystem.hpp>
#include <fcc/utilities/key_conversion.hpp>

#include <iostream>

using namespace mcc::blockchain;

struct founder
{
    std::string              keyhotee_id_utf8;
    int64_t                  balance;
    fc::ecc::public_key_data public_key;
};

FC_REFLECT(founder, (keyhotee_id_utf8)(balance)(public_key))

void transform_name(std::string& name)
{
    for (char& c : name)
    {
        if (c == ' ') c = '-';
        if (c == '.') c = '-';
        if (c == '_') c = '-';
        if (c == '#') c = '-';
    }
}

#define MY_BLOCKCHAIN_NUM_DELEGATES 25
#define MY_DELEGATES_NAME  "init"

int main(int argc, char** argv)
{
    genesis_state config;
    config.timestamp = fc::time_point::now();
    config.delegates.reserve(MY_BLOCKCHAIN_NUM_DELEGATES);
    config.delegates.resize(MY_BLOCKCHAIN_NUM_DELEGATES);
    config.initial_balances.resize(MY_BLOCKCHAIN_NUM_DELEGATES);

    std::vector<fc::ecc::private_key> keys;
    keys.reserve(MY_BLOCKCHAIN_NUM_DELEGATES);

    for (unsigned i = 0; i < MY_BLOCKCHAIN_NUM_DELEGATES; ++i)
    {
        keys.push_back(fc::ecc::private_key::generate());
        config.delegates[i].name = MY_DELEGATES_NAME + fc::to_string(i);
        config.delegates[i].owner = keys[i].get_public_key().serialize();

        config.initial_balances[i].raw_address = address(keys[i].get_public_key()).operator fc::string();
        if (i == 0)
        {
            config.initial_balances[i].balance = 100000000ll*MCC_BLOCKCHAIN_PRECISION;
        }
        else
        {
            config.initial_balances[i].balance = 0;
        }
        

    }

    /*
    if( fc::exists( "founders.json" ) )
    {
    try {
    auto founders = fc::json::from_file( "founders.json" ).as<std::vector<founder>>();
    int64_t total_founder_balance = 0;
    for( auto f : founders )
    total_founder_balance += f.balance;

    double scale = 3623.188405796104 / total_founder_balance;

    for( auto f : founders )
    {
    config.names.resize( config.names.size() + 1 );
    config.names.back().name = fc::to_lower( f.keyhotee_id_utf8 );
    transform_name( config.names.back().name  );
    config.names.back().is_delegate = false;
    config.names.back().owner = f.public_key;

    config.balances.push_back( std::make_pair( pts_address( f.public_key ), (f.balance * scale) ) );
    }
    } catch ( const fc::exception& e )
    {
    elog( "${e}", ("e",e.to_detail_string() ) );
    }
    }
    */

    fc::json::save_to_file(config, fc::path("init_genesis.json"), true);
    std::vector<std::string> wif_keys;
    for (auto k : keys)
        wif_keys.push_back(mcc::utilities::key_to_wif(k));
    fc::json::save_to_file(wif_keys, fc::path("wif_keys.json"), true);

    std::cout << "saving init_genesis.json\n";
    std::cout << "saving wif_keys.json\n";
    std::cout << "pressing any key to exit!\n";
    getchar();
    return 0;
}
