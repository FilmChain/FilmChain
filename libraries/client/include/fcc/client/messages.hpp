#pragma once
#include <fcc/blockchain/block.hpp>
#include <fcc/client/client.hpp>

namespace mcc { namespace client {

   enum message_type_enum
   {
      trx_message_type          = 1000,
      block_message_type        = 1001
   };

   struct trx_message
   {
      static const message_type_enum type;

      mcc::blockchain::signed_transaction trx;
      trx_message() {}
      trx_message(mcc::blockchain::signed_transaction transaction) :
        trx(std::move(transaction))
      {}
   };

   struct block_message
   {
      static const message_type_enum type;

      block_message(){}
      block_message(const mcc::blockchain::full_block& blk )
      :block(blk),block_id(blk.id()){}

      mcc::blockchain::full_block    block;
      mcc::blockchain::block_id_type block_id;

   };

} } // mcc::client

FC_REFLECT_ENUM( mcc::client::message_type_enum, (trx_message_type)(block_message_type) )
FC_REFLECT( mcc::client::trx_message, (trx) )
FC_REFLECT( mcc::client::block_message, (block)(block_id) )
