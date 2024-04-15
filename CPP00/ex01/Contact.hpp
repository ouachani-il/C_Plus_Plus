#ifndef CONTACT_H
# define CONTACT_H

class   Contact{
    public :
		Contact(std::string fN,
                std::string lN,
                std::string nN,
                std::string pNum,
                std::string secret) : _firstName(fN), 
                                    _lastName(lN),
                                    _nickName(nN),
                                    _phoneNumber(pNum),
                                    _darkestSecret(secret);
		~Contact(void);
	private :
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

    	static int	_nbrContact;
	
};

#endif