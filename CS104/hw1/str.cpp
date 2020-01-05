#include <iostream>
#include <stdexcept>
#include <cstring>
#include "str.h"

using namespace std;

// Add your implementations here.
Str::Str()
{
	this->len = 0;
	this->data_ = new char[this->len+1];
	this->data_[this->len] = '\0';
}
  /**
   * Character array constructor
   *  If s is NULL create a string that contains
   *  only the null character (i.e. "")
   */
Str::Str(const char* s)
{
	if(s == NULL)
	{
		this->len = 0;
		this->data_ = new char[this->len+1];
	}
	else{
		this->len = strlen(s);
		this->data_ = new char[this->len+1];
		
		for(unsigned int i = 0; i < this->len; i++)
		{
			this->data_[i] = s[i];
		}
	}
	this->data_[this->len] = '\0';
}


Str::Str(const Str& s)
{
	this->len = s.len;
	this->data_ = new char[this->len+1];

	for(unsigned int i = 0; i < this->len; i++)
	{
		this->data_[i] = s.data_[i];
	}

	this->data_[this->len] = '\0';
}


// destructor
Str::~Str()
{
	delete [] this->data_;
}

  
  /**
   * Assignment operator
   * If s is NULL, set this to a blank string ("")
   */
Str& Str::operator=(const char* s)
{
	if(this->data_ == s)
	{
		return *this;
	}
	else
	{
		delete [] this->data_;
	
		if(s == NULL)
		{
			this->len = 0;
			this->data_ = new char[this->len+1];
			this->data_[this->len] = '\0';
		}
		else{
			this->len = strlen(s);
			this->data_ = new char[this->len+1];
			
			for(unsigned int i = 0; i < this->len; i++)
			{
				this->data_[i] = s[i];
			}
			this->data_[this->len] = '\0';
		}
		return *this;
	}
}


Str& Str::operator=(const Str& s)
{
	if(this == &s)
	{
		return *this;
	}
	else
	{
		delete [] this->data_;
	
		this->len = s.len;
		this->data_ = new char[this->len+1];
		
		for(unsigned int i = 0; i < this->len; i++)
		{
			this->data_[i] = s.data_[i];
		}
		this->data_[this->len] = '\0';

		return *this;
	}
}
  
  /**
   * Str concatenation-assignment operator
   *  E.g. s += t
   */
Str& Str::operator+=(const Str& s)
{
	unsigned int new_len = this->len + s.len;
	char* new_data = new char[new_len+1];
	
	for(unsigned int i = 0; i < new_len; i++)
	{
		if(i < this->len)
		{
			new_data[i] = this->data_[i];
		}
		else{
			new_data[i] = s.data_[i-this->len];
		}
	}
	new_data[new_len] = '\0';

	delete [] this->data_;

	this->len = new_len;
	this->data_ = new_data;
	return *this;
}
  /**
   * Char. array concatenation-assignment operator
   *  E.g. s += " more"
   *  If s is NULL simply return this Str
   */
Str& Str::operator+=(const char* s)
{
	if(s == NULL)
	{
		return *this;
	}
	else
	{
		unsigned int new_len = this->len + strlen(s);
		char* new_data = new char[new_len+1];

		for(unsigned int i = 0; i < new_len; i++)
		{
			if(i < this->len)
			{
				new_data[i] = this->data_[i];
			}
			else{
				new_data[i] = s[i-this->len];
			}
		}
		new_data[new_len] = '\0';
	
		delete [] this->data_;

		this->len = new_len;
		this->data_ = new_data;
		return *this;
	}
}

  /**
   * Return the size of the string (e.g. "Hello" => 5)
   */
size_t Str::size() const
{
	return this->len;
}

   /**
    * Non-const index operator
    *  E.g.  str s1("103");  s1[2] = '4';
    * Should throw std::out_of_range if invalid index is passed
    */
char& Str::operator[](unsigned int i)
{
	if(this->len-1 < i)
	{
		throw std::out_of_range("Index is out of range");
	}
	else{
		return this->data_[i];
	}
}
   /**
    * Const index operator
    *  E.g. str s1("104");  char c = s1[2];
    * Should throw std::out_of_range if invalid index is passed
    */
char const & Str::operator[](unsigned int i) const
{
	if(this->len-1 < i)
	{
		throw std::out_of_range("Index is out of range");
	}
	else{
		return this->data_[i];
	}
}

   
   /**
    * String concatenation operator
    *  E.g. str s1; cout << s1 + " world" << endl;
    *  If rhs is NULL, simply return a copy of this Str
    */
Str Str::operator+(const char* rhs) const
{
	Str result;
	if(rhs == NULL)
	{
		result.len = this->len;
		delete [] result.data_;
		result.data_ = new char[result.len+1];
		for(unsigned int i = 0; i < result.len; i++)
		{
			result.data_[i] = this->data_[i];
		}
	}
	else
	{
		result.len = this->len + strlen(rhs);
		delete [] result.data_;
		result.data_ = new char[result.len+1];
		for(unsigned int i = 0; i < result.len; i++)
		{
			if(i < this->len)
			{
				result.data_[i] = this->data_[i];
			}
			else{
				result.data_[i] = rhs[i-this->len];
			}
		}
	}
	result.data_[result.len] = '\0';
	return result;
}


Str Str::operator+(const Str& s) const
{
	Str result;

	result.len = this->len + s.len;
	delete [] result.data_;

	result.data_ = new char[result.len+1];
	for(unsigned int i = 0; i < result.len; i++)
	{
		if(i < this->len)
		{
			result.data_[i] = this->data_[i];
		}
		else{
			result.data_[i] = s.data_[i-this->len];
		}
	}
	result.data_[result.len] = '\0';

	return result;
}


bool Str::operator==(const Str& s) const
{
	if(this == &s)
	{
		return true;
	}
	else if(strcmp(this->data_, s.data_) == 0)
	{
		return true;
	}
	else{
		return false;
	}
}


bool Str::operator==(const char* s) const
{
	if(this->data_ == s)
	{
		return true;
	}
	else if(strcmp(this->data_, s) == 0)
	{
		return true;
	}
	else{
		return false;
	}
}


bool Str::operator!=(const Str& s) const
{
	if(this == &s)
	{
		return false;
	}
	else if(strcmp(this->data_, s.data_) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Str::operator!=(const char* s) const
{
	if(this->data_ == s)
	{
		return false;
	}
	else if(strcmp(this->data_, s) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Str::operator<(const Str& s) const
{
	if(this == &s)
	{
		return false;
	}
	else if(strcmp(this->data_, s.data_) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Str::operator<(const char* s) const
{
	if(this->data_ == s)
	{
		return false;
	}
	else if(strcmp(this->data_, s) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Str::operator>(const Str& s) const
{
	if(this == &s)
	{
		return false;
	}
	else if(strcmp(this->data_, s.data_) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Str::operator>(const char* s) const
{
	if(this->data_ == s)
	{
		return false;
	}
	else if(strcmp(this->data_, s) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Str operator+(const char* lhs, const Str& rhs)
{
	Str result;
	if(lhs == NULL)
	{
		result.len = rhs.len;
		delete [] result.data_;
		result.data_ = new char[result.len];
		for(unsigned int i = 0; i < result.len; i++)
		{
			result.data_[i] = rhs.data_[i];
		}
	}
	else
	{
		result.len = strlen(lhs) + rhs.len;
		delete [] result.data_;
		result.data_ = new char[result.len+1];
		for(unsigned int i = 0; i < result.len; i++)
		{
			if(i < strlen(lhs))
			{
				result.data_[i] = lhs[i];
			}
			else 
			{
				result.data_[i] = rhs.data_[i-strlen(lhs)];
			}
		}
	}
	result.data_[result.len] = '\0';
	return result;
}


bool operator==(const char* lhs, const Str& rhs)
{
	if(lhs == rhs.data_)
	{
		return true;
	}
	else if(strcmp(lhs, rhs.data_) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}	
}


bool operator!=(const char* lhs, const Str& rhs)
{
	if(lhs == rhs.data_)
	{
		return false;
	}
	else if(strcmp(lhs, rhs.data_) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}	
}


bool operator>(const char* lhs, const Str& rhs)
{
	if(lhs == rhs.data_)
	{
		return false;
	}
	else if(strcmp(lhs, rhs.data_) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}	
}


bool operator<(const char* lhs, const Str& rhs)
{
	if(lhs == rhs.data_)
	{
		return false;
	}
	else if(strcmp(lhs, rhs.data_) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}


istream& operator>>(istream& istr, Str& s)
{
  string stemp;
  istr >> stemp;
  s = stemp.c_str();
  return istr;
}


ostream& operator<<(ostream& ostr, const Str& s)
{
	if(s.len == 0)
	{
		ostr << "";
	}
	else
	{
		for(unsigned int i = 0; i < s.len; i++)
		{
			ostr << s.data_[i];
		}
	}
	return ostr;
}


ostream& operator<<(ostream& ostr, const char* s)
{
	if(s == NULL)
	{
		ostr << "";
	}
	else{
		for(unsigned int i = 0; i < strlen(s); i++)
		{
			ostr << s[i];
		}
	}
	return ostr;
}