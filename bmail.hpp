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
                         string       email );


      private:
         struct account {
			account_name owner;
			string       email;
			bool         is_sender = false;

			uint64_t primary_key()const { return owner; }
		};

         typedef eosio::multi_index<N(accounts), account> accounts;
   };

} /// namespace eosio
