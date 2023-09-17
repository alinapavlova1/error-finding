#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

/*!
* \brief �������, ������� ��������� ���������� ������ �� ����� �� ��������� �����������
* \param[in] s - ������������ ����� �������� ������, ������� ����� ��������� �� �����.
* \param[in] delimeter - ������������ ����� �����������, ������� ����� �������������� ��� ���������� ������ �� �����.
* \return ������ �����, ������� �������� ����������� �����.
*/
std::vector<std::string> split(const std::string& s, char delimeter);

/*!
* \brief ������� ������������� ���������� ������� ���������� ��������� ������
* \param[in] argc - ���������� ������� ���������� ��������� ������
*/
void validate_argument_count(int argc);

/*!
* \brief �������, ������� ������ ������ �� �����
* \param[in] file_name - ���� � ����� ������
* \return read_data - ����� ��������� ������ �� �����
*/
void read_data(const std::string& file_name, std::string& read_data);

/*!
* \brief ������� ������ ������ � �������� ����
* \param[in] file_name - ���� � ����� ������
* \param[in] write_data - ����� ������������ ������ � ����
*/
void write_data(const std::string& file_name, const std::string& write_data);

/*!
* \brief ������� ��������� ���������� ���� �� ������� �����
* \param[in] words - ������ ���� �����
*/
void validate_words_count_in_file(const std::vector<std::string>& words);

/*!
* \brief ������� ������������� ���������� ���� � ���� ������� ������
* \param[in] words_1 - ������ ���� ������� �����
* \param[in] words_2 - ������ ���� ������� �����
*/
void validate_incorrect_words_count(const std::vector<std::string>& words_1, const std::vector<std::string>& words_2);

/*!
* \brief ������� �������� ������ � ������ �������
* \param[in] sentence - ������, ������� ����� ��������� � ������ �������.
*/
void to_lower_string(std::string& sentence);

/*!
* \brief ������� ��������� ������ �� ������� ����, ��� � ������ ���� ������� ����������� ��������
* \param[in] sentence - ������, ������� ����� ��������� �� ������� �������� ����������� ��������.
*/
void validate_english_alphabet(const std::string& sentence);

/*!
* \brief �������������� ������� ��� "�����" ��������� ������ � ������� ������� � � ������ ����������
* \param[in] word -  ������, �� ������� �� ����� ������� �������
* \param[in] offset - ��������� �� ������ ������� � ������ word, � �������� �������� ���������� ��������.
* \param[in] count - �������� ���������, ������� �������� ����� ������� �� ������
* \return ������, ���������� ����������� �������
*/
std::string get_needed_chars(const std::string& word, int offset, int count);

/*!
* \brief ������� �������� ����, ��� ������ ����������� � ������������ ���������� ��������
* \param[in] word - �����, ������� ����� ��������� �� ������� ������������ ���������� ��������.
*/
std::string check_abbreviations_in_word(const std::string& word);

/*!
* \brief ������� �������� ����, ��� ������ ����������� � ������������ ������������ ��������������/���������� ������������
* \param[in] word - �����, ������� ����� ��������� �� ������� ������������ ������������ �������������� � ���������� ������������.
*/
std::string check_ordinal_and_cardinal_pronouns(const std::string& word);

/*!
* \brief ������� ������ ���� ������, ����������� � �����������
* \param[in] right_word - ����� - ������
* \param[in] right_word - �����, ������������� �� ������
*/
std::string check_simple_words(std::string& right_word, std::string& wrong_word);

/*!
* \brief  ������� ���������� ���� �����, � ������� ���� ������
* \param[in] words_without_errors - ������ ���� ������ �������
* \param[in] words_with_errors - ������ ���� ������ � ��������
*/
std::string find_errors(std::vector<std::string> words_without_errors, std::vector<std::string> words_with_errors);

