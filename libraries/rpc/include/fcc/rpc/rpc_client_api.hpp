#pragma once

#include <fcc/net/node.hpp>
#include <fcc/wallet/wallet.hpp>

#include <fc/filesystem.hpp>
#include <fc/network/ip.hpp>

#include <memory>

namespace mcc { namespace rpc {
  namespace detail { class rpc_client_impl; }

    using namespace mcc::blockchain;
    using namespace mcc::wallet;

    typedef vector<std::pair<share_type,string> > balances;

    enum generate_transaction_flag
    {
      sign_and_broadcast    = 0,
      do_not_broadcast      = 1,
      do_not_sign           = 2
    };

} } // mcc::rpc
FC_REFLECT_ENUM( mcc::rpc::generate_transaction_flag, (do_not_broadcast)(do_not_sign)(sign_and_broadcast) )
