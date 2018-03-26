/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <bmail/bmail.hpp>

namespace eosio {

void token::sendemail( account_name from, 
                       account_name to,
                       string       email ) 
{
    print( "sendemail" );
    require_auth( from );

}

} /// namespace eosio

EOSIO_ABI( eosio::token, (sendemail) )
