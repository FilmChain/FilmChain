#include <fcc/blockchain/operations.hpp>

namespace mcc { namespace blockchain {

    struct data_operation
    {
        static const operation_type_enum  type;
        uint64_t                          tag;
        std::vector<char>                 data;
        void evaluate( transaction_evaluation_state& eval_state )const;
    };

}} // mcc::blockchain

FC_REFLECT( mcc::blockchain::data_operation,
            (tag)
            (data)
            )

