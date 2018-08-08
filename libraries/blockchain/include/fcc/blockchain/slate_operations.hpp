#pragma once

#include <fcc/blockchain/operations.hpp>

namespace mcc { namespace blockchain {

struct define_slate_operation
{
    static const operation_type_enum type;

    vector<signed_int> slate;

    void evaluate( transaction_evaluation_state& eval_state )const;
};

} } // mcc::blockchain

FC_REFLECT( mcc::blockchain::define_slate_operation, (slate) )
