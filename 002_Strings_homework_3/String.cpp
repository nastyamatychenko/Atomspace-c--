#pragma warning(suppress : 4996)
#include "String.h"
#include <string.h>

namespace MyString {

	String::String(size_t init_size)
	{
		this->data = new char[init_size];
		this->size = init_size;

		if (this->data != NULL)
		{
			for (size_t i = 0; i < init_size; i++)
			{
				data[i] = '\0';
			}
		}
	}

	String::String(const char* data)
	{
		size_t size = strlen(data);
		this->data = new char[size];
		this->size = size;

		if (this->data != NULL)
		{
		strncpy(this->data, data, size);
		}
	}

	String::String(const String &string)
	{
		this->size = string.getLength();
		this->data = new char[this->size];

		if (this->data != NULL)
		{
			strncpy(this->data, data, size);
		}
	}


	String::~String()
	{
		if (this->data != NULL)
		{
			delete[] this->data;
		}
	}



	//Methods
	char* String::getText()
	{
		return data;
	}

	void String::setText(const char* text)
	{
		delete[] this->data;
		this->size = strlen(text);
		this->data = new char[this->size];
		strncpy(this->data, text, this->size);
	}

	size_t String::getLength() const
	{
		return strlen(this->data);
	}

	void String::setLength(size_t size)
	{
		size_t old_length = this->getLength();
		char* old_data = this->data;

		this->size = size;
		this->data = new char[size];

		for (size_t i = 0; i < size; i++)
		{
			if (i < old_length)
			{
				this->data[i] = old_data[i];
			}
			else
			{
				this->data[i] = '\0';
			}
		}

		delete[] old_data;
		this->data[size] = '\0';
	}

	void String::add(const String &text)
	{
		size_t new_size = this->size + text.size;
		setLength(new_size);
		size_t length = getLength();
		for (size_t i = length; i < new_size; i++)
		{
			this->data[i] = text.data[i - length];
		}
	}

	char String::get(size_t pos) const
	{
		if (pos > getLength())
		{
			return '\0';
		}
		return data[pos];
	}

	bool String::compare(const String &string) const
	{
		return strcmp(this->data, string.data) == 0;
	}

	char String::operator[](size_t pos)
	{
		return this->get(pos);
	}

}