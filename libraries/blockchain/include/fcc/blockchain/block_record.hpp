#pragma once
#include <fcc/blockchain/block.hpp>

namespace mcc { namespace blockchain {

struct block_record : public mcc::blockchain::digest_block
{
    block_id_type       id;
    uint64_t            block_size = 0; /* Bytes */
    fc::microseconds    latency; /* Time between block timestamp and first push_block */

    share_type          signee_shares_issued = 0;
    share_type          signee_fees_collected = 0;
    share_type          signee_fees_destroyed = 0;
    fc::ripemd160       random_seed;

    fc::microseconds    processing_time; /* Time taken for extend_chain to run */
};
typedef optional<block_record> oblock_record;

} } // mcc::blockchain

FC_REFLECT_DERIVED( mcc::blockchain::block_record,
                    (mcc::blockchain::digest_block),
                    (id)
                    (block_size)
                    (latency)
                    (signee_shares_issued)
                    (signee_fees_collected)
                    (signee_fees_destroyed)
                    (random_seed)
                    (processing_time)
                    )
