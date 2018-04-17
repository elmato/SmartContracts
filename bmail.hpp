/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */

#include <eosiolib/eosio.hpp>
#include <string>

namespace eosio {

   using std::string;
   using ipfshash_t = std::vector<char>;

   class bmail : public contract {
      public:
         bmail( account_name self ):contract(self){}

         void sendmail( account_name  from, 
                        account_name  to,
                        string        mailhash );

      private:
	 //@abi table
         struct mail {
		 mail() { mailhash.resize(34); }
			account_name  owner;
			ipfshash_t mailhash;
			bool          is_sender = false;
			bool          is_cc = false;
			bool          is_bcc = false;
			uint32_t      status = 0;
			time          create_date;
			time          update_date;

			uint64_t primary_key()const { return owner; }
		};

        typedef eosio::multi_index<N(mails), mail> mails;
	   
	void add_mail( account_name owner, string mailhash, bool is_sender, account_name ram_payer );
   };

} /// namespace eosio
