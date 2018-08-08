#pragma once

#include <fc/exception/exception.hpp>

namespace mcc { namespace wallet {

FC_DECLARE_EXCEPTION        ( wallet_exception,                                            20000, "wallet error" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_password,             mcc::wallet::wallet_exception, 20001, "invalid password" );
FC_DECLARE_DERIVED_EXCEPTION( wallet_locked,                mcc::wallet::wallet_exception, 20002, "wallet locked" );
FC_DECLARE_DERIVED_EXCEPTION( wallet_already_exists,        mcc::wallet::wallet_exception, 20003, "wallet already exists" );
FC_DECLARE_DERIVED_EXCEPTION( no_such_wallet,               mcc::wallet::wallet_exception, 20004, "wallet does not exist" );
FC_DECLARE_DERIVED_EXCEPTION( unknown_wallet_account,        mcc::wallet::wallet_exception, 20005, "unknown local account" );
FC_DECLARE_DERIVED_EXCEPTION( unknown_account,              mcc::wallet::wallet_exception, 20006, "unknown account" );
FC_DECLARE_DERIVED_EXCEPTION( wallet_closed,                mcc::wallet::wallet_exception, 20007, "wallet closed" );
FC_DECLARE_DERIVED_EXCEPTION( negative_bid,                 mcc::wallet::wallet_exception, 20008, "negative bid" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_price,                mcc::wallet::wallet_exception, 20009, "invalid price" );
FC_DECLARE_DERIVED_EXCEPTION( insufficient_funds,           mcc::wallet::wallet_exception, 20010, "insufficient funds" );
FC_DECLARE_DERIVED_EXCEPTION( unknown_market_order,         mcc::wallet::wallet_exception, 20011, "unknown market order" );
FC_DECLARE_DERIVED_EXCEPTION( fee_greater_than_amount,      mcc::wallet::wallet_exception, 20012, "fee greater than amount" );
FC_DECLARE_DERIVED_EXCEPTION( unknown_address,              mcc::wallet::wallet_exception, 20013, "unknown address" );
FC_DECLARE_DERIVED_EXCEPTION( brain_key_too_short,          mcc::wallet::wallet_exception, 20014, "brain key is too short" );
FC_DECLARE_DERIVED_EXCEPTION( password_too_short,           mcc::wallet::wallet_exception, 20015, "password too short" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_timestamp,            mcc::wallet::wallet_exception, 20016, "invalid timestamp" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_name,                 mcc::wallet::wallet_exception, 20017, "invalid account name" );
FC_DECLARE_DERIVED_EXCEPTION( file_already_exists,          mcc::wallet::wallet_exception, 20018, "file already exists" );
FC_DECLARE_DERIVED_EXCEPTION( file_not_found,               mcc::wallet::wallet_exception, 20019, "file not found" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_timeout,              mcc::wallet::wallet_exception, 20020, "invalid timeout" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_operation,            mcc::wallet::wallet_exception, 20021, "invalid operation" );
FC_DECLARE_DERIVED_EXCEPTION( transaction_not_found,        mcc::wallet::wallet_exception, 20022, "transaction not found" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_transaction_id,       mcc::wallet::wallet_exception, 20023, "invalid transaction id" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_asset_symbol,         mcc::wallet::wallet_exception, 20024, "invalid asset symbol" );
FC_DECLARE_DERIVED_EXCEPTION( duplicate_account_name,       mcc::wallet::wallet_exception, 20025, "duplicate account name" );
FC_DECLARE_DERIVED_EXCEPTION( not_contact_account,          mcc::wallet::wallet_exception, 20026, "not contact account" );
FC_DECLARE_DERIVED_EXCEPTION( memo_too_long,                mcc::wallet::wallet_exception, 20027, "memo too long" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_pay_rate,             mcc::wallet::wallet_exception, 20028, "invalid pay rate" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_wallet_name,          mcc::wallet::wallet_exception, 20029, "invalid wallet name" );
FC_DECLARE_DERIVED_EXCEPTION( unsupported_version,          mcc::wallet::wallet_exception, 20030, "unsupported version" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_fee,                  mcc::wallet::wallet_exception, 20031, "invalid fee" );
FC_DECLARE_DERIVED_EXCEPTION( key_already_registered,       mcc::wallet::wallet_exception, 20032, "key belongs to other account" );
FC_DECLARE_DERIVED_EXCEPTION( double_cover,                 mcc::wallet::wallet_exception, 20033, "double cover" );
FC_DECLARE_DERIVED_EXCEPTION( stupid_order,                 mcc::wallet::wallet_exception, 20034, "stupid order" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_expiration_time,      mcc::wallet::wallet_exception, 20035, "invalid expiration time" );
FC_DECLARE_DERIVED_EXCEPTION( bad_collateral_amount,        mcc::wallet::wallet_exception, 20036, "bad collateral amount" );
FC_DECLARE_DERIVED_EXCEPTION( unknown_slate,                mcc::wallet::wallet_exception, 20037, "unknown slate" );
FC_DECLARE_DERIVED_EXCEPTION( duplicate_key,                mcc::wallet::wallet_exception, 20038, "duplicate key" );
FC_DECLARE_DERIVED_EXCEPTION( unauthorized_child_account,   mcc::wallet::wallet_exception, 20039, "unauthorized child account" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_slate,                mcc::wallet::wallet_exception, 20040, "invalid slate" );
FC_DECLARE_DERIVED_EXCEPTION( private_key_not_found,        mcc::wallet::wallet_exception, 20041, "private key not found" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_cancel,               mcc::wallet::wallet_exception, 20042, "invalid cancel" );
FC_DECLARE_DERIVED_EXCEPTION( account_not_registered,       mcc::wallet::wallet_exception, 20043, "account not registered" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_contact,              mcc::wallet::wallet_exception, 20044, "invalid contact" );
FC_DECLARE_DERIVED_EXCEPTION( label_already_in_use,         mcc::wallet::wallet_exception, 20045, "label already in use" );
FC_DECLARE_DERIVED_EXCEPTION( account_retracted,            mcc::wallet::wallet_exception, 20046, "account retracted" );
FC_DECLARE_DERIVED_EXCEPTION( issuer_not_found,             mcc::wallet::wallet_exception, 20047, "asset issuer not found" );
FC_DECLARE_DERIVED_EXCEPTION(authority_address_not_found, mcc::wallet::wallet_exception, 20048, "the authority address to remove not found");
FC_DECLARE_DERIVED_EXCEPTION(authority_address_not_supplied, mcc::wallet::wallet_exception, 20049, "the authority address not supplied");

} } // mcc::wallet
