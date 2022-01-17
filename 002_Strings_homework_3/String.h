#pragma once

#include <iostream>

namespace MyString
{
	template<typename T>
	class It {
	private:
		T *data;
	public:
		It(T *data)
		{
			this->data = data;
		}

		T &operator*()
		{
			return *data;
		}

		It<T> &operator++()
		{
			data++;
			return *this;
		}

		bool operator==(const It<T> &a)
		{
			return this->data == a.data;
		}

		bool operator!=(const It<T> &a)
		{
			return this->data = a.data;
		}
	};


	class String
	{
	private:
		char *data;
		size_t size;
	public:
		String(const char* data);
		String(size_t init_size = 20);
		//Вопрос
		String(const String &string);
		~String();
		char *getText();
		void setText(const char* text);
		size_t getLength() const;
		void setLength(size_t size);
		void add(const String &text);
		char get(size_t pos) const;
		bool compare(const String &string) const;
		char operator[](size_t pos);
		It<char> begin()
		{
			It<char> it(data);
			return it;
		}
		It<char> end()
		{
			It<char> it(data + size);
			return it;
		}

	};

}
