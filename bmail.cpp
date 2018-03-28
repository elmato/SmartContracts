/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <bmail/bmail.hpp>

namespace eosio {

void bmail::sendmail( account_name from, 
                       account_name to,
                       string       mailhash ) 
{
    print( "sendmail" );
    require_auth( from );
	add_mail(from, mailhash, true, from);
	add_mail(to, mailhash, false, from);
}

void bmail::add_mail( account_name owner, string mailhash, bool is_sender, account_name ram_payer )
{
   mails to_mails( _self, owner );
   auto existing_mail = to_mails.find( mailhash ); //TODO: test search by secondary index mail hash
   if( existing_mail == to_mails.end() ) {
      to_mails.emplace( ram_payer, [&]( auto& a ){
        a.mailhash = mailhash;
	a.is_sender = is_sender;
      });
   } else {
      eosio_assert( false, "mail already exists" );
   }
}

} /// namespace eosio

EOSIO_ABI( eosio::bmail, (sendmail) )
