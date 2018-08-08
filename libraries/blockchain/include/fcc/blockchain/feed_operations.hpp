#pragma once

#include <fcc/blockchain/feed_record.hpp>
#include <fcc/blockchain/operations.hpp>
#include <fcc/blockchain/types.hpp>

namespace mcc { namespace blockchain {

  struct update_feed_operation
  {
      static const operation_type_enum type;
      feed_index   index;
      fc::variant  value;

      void evaluate( transaction_evaluation_state& eval_state )const;
      void evaluate_v1( transaction_evaluation_state& eval_state )const;
  };

} } // mcc::blockchain

FC_REFLECT( mcc::blockchain::update_feed_operation, (index)(value) )
