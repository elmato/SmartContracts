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

         void sendemail( account_name from, 
                         account_name to,
                         string       emailhash );

      private:
         struct email {
			account_name owner;
			string       emailhash;
			bool         is_sender = false;
			bool         is_cc = false;
			bool         is_bcc = false;
			uint32_t     status = 0;
			time         create_date;
			time         update_date;

			uint64_t primary_key()const { return owner; }
			string get_emailhash()const { return emailhash; }
		};

        typedef eosio::multi_index<N(emails), email, 
			indexed_by< N(byemail), const_mem_fun<email, string, &email::get_emailhash> >> emails;
   };

} /// namespace eosio
