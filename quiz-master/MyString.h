#pragma once
#include <fstream>

	class MyString
	{
		char* data;
		size_t size;
		size_t capacity;

		void free();
		void copyFrom(const MyString& other);
		void resize(unsigned newCapacity);
	public:
		MyString();
		MyString(const char* str);
		MyString(const MyString& other);
		MyString& operator=(const MyString& other);
		~MyString();

		size_t getSize() const;
		size_t getCapacity() const;

		void write(std::ofstream& ofs) const;
		void read(std::ifstream& ifs);

		const char* c_str() const;

		char& operator[](unsigned index);
		const char& operator[](unsigned indexs) const;

		MyString& operator+=(const MyString& other);
		MyString& operator+=(const char symbol);

		friend MyString operator+(const MyString& lhs, const MyString& rhs);
		friend std::ostream& operator<<(std::ostream& os, const MyString& str);
		friend std::istream& operator>>(std::istream& is, MyString& str);

		MyString substr(unsigned begin, unsigned howMany);
	};

	bool operator==(const MyString& lhs, const MyString& rhs);
	bool operator!=(const MyString& lhs, const MyString& rhs);
	bool operator>(const MyString& lhs, const MyString& rhs);
	bool operator>=(const MyString& lhs, const MyString& rhs);
	bool operator<(const MyString& lhs, const MyString& rhs);
	bool operator<=(const MyString& lhs, const MyString& rhs);
	