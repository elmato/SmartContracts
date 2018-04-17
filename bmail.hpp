/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <eosiolib/eosio.hpp>
#include <string>

namespace eosio {

   using std::string;

   class bmail : public contract {
      public:
         bmail( account_name self ):contract(self){}

         void sendmail( account_name  from, 
                        account_name  to,
                        unsigned char mailhash[34] );

      private:
         struct mail {
			account_name  owner;
			unsigned char mailhash[34];
			bool          is_sender = false;
			bool          is_cc = false;
			bool          is_bcc = false;
			uint32_t      status = 0;
			time          create_date;
			time          update_date;

			uint64_t primary_key()const { return owner; }
			string get_mailhash()const { return mailhash; }
		};

        typedef eosio::multi_index<N(mails), mail, 
			indexed_by< N(bymail), const_mem_fun<mail, string, &mail::get_mailhash> >> mails;
	   
	add_mail( account_name owner, string mailhash, bool is_sender, account_name ram_payer );
   };

} /// namespace eosio
