void encoding_newbasictype(void)
{
	//c++17
	/*char str1[] = u8"text";
	cout << str1 << endl;*/

	//c++20
	char8_t str2[] = u8"text";
	char8_t c8 = 'a';
	//c++20中cout不支持输出char8_t类型
	//basic_ostream<char8_t>& out = cout;
	//out << str2 << std::endl;
}