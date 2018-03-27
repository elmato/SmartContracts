/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <bmail/bmail.hpp>

namespace eosio {

void token::sendemail( account_name from, 
                       account_name to,
                       string       emailhash ) 
{
    print( "sendemail" );
    require_auth( from );
	add_email(from, emailhash, true, from);
	add_email(to, emailhash, false, from);
}

void token::add_email( account_name owner, string emailhash, bool is_sender, account_name ram_payer )
{
   emails to_emails( _self, owner );
   auto existing_email = to_emails.find( emailhash ); //TODO: test search by secondary index email hash
   if( existing_email == to_acnts.end() ) {
      to_emails.emplace( ram_payer, [&]( auto& a ){
        a.emailhash = emailhash;
		a.is_sender = is_sender;
      });
   } else {
      eosio_assert( false, "email already exists" );
   }
}

} /// namespace eosio

EOSIO_ABI( eosio::token, (sendemail) )
