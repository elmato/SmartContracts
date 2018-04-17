/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <bmail.hpp>

namespace eosio {

	
void bmail::sendmail( account_name from, 
                      account_name to,
                      ipfshash_t   mailhash ) 
{
    print( "sendmail" );
    require_auth( from );
    add_mail(from, mailhash, true, from);
    add_mail(to, mailhash, false, from);
}

void bmail::add_mail( account_name owner, ipfshash_t mailhash, bool is_sender, account_name ram_payer )
{
   mails to_mails( _self, owner );
   to_mails.emplace( ram_payer, [&]( auto& a ){
      for (int i=0; i < 34; i++)
          a.mailhash[i] = mailhash[i];
      a.is_sender = is_sender;
   });
}

} /// namespace eosio

EOSIO_ABI( eosio::bmail, (sendmail) )
