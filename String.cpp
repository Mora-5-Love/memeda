#include <iostream>
using namespace std;


class String
{
	public:
		String(const char* str=nullptr);
		String(const String &other);
		~String(void);
		String & operator = (const String other);
	private:
		char *my_data;
};
String::String(const char *str)
{
	if(nullptr == str){
		my_data = new char[1];
		my_data = '\0';
	}
	else
	{
		auto len = strlen(str);
		my_data = new char[len+1];
		strcpy(my_data,str);
	}
}
String::String(const String &other)
{
	auto len = strlen(other.my_data);
	my_data = new char[len+1];
	strcpy(my_data,other.my_data);
}

String & String::operator = (const String& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	delete [] my_data;
	auto len = strlen(other.my_data);
	my_data = new char[len+1];
	strcpy(my_data,other.my_data);

	return *this;
}
String::~String(void)
{
	delete [] my_data;
}
int main(int argc, char *argv[])
{
	String a("hello world");
	String b("hello lyz");
	
	return 0;
}
