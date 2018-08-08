#pragma once
#include <fcc/blockchain/types.hpp>

namespace mcc { namespace blockchain {

static std::map<uint32_t, mcc::blockchain::block_id_type> CHECKPOINT_BLOCKS
{
    
};

// Initialized in load_checkpoints()
static uint32_t LAST_CHECKPOINT_BLOCK_NUM = 0;

} } // mcc::blockchain
