#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

/*!
* \brief Функция, которая выполняет разделение строки на слова по заданному разделителю
* \param[in] s - представляет собой исходную строку, которую нужно разделить на слова.
* \param[in] delimeter - представляет собой разделитель, который будет использоваться для разделения строки на слова.
* \return вектор строк, который содержит разделенные слова.
*/
std::vector<std::string> split(const std::string& s, char delimeter);

/*!
* \brief Функция валидирования количества входных аргументов командной строки
* \param[in] argc - количество входных аргументов командной строки
*/
void validate_argument_count(int argc);

/*!
* \brief Функция, которая читает данные из файла
* \param[in] file_name - путь к файлу чтения
* \return read_data - поток считанных данных из файла
*/
void read_data(const std::string& file_name, std::string& read_data);

/*!
* \brief Функция записи текста в выходной файл
* \param[in] file_name - путь к файлу записи
* \param[in] write_data - поток записываемых данных в файл
*/
void write_data(const std::string& file_name, const std::string& write_data);

/*!
* \brief Функция валидации количества слов во входном файле
* \param[in] words - вектор слов файла
*/
void validate_words_count_in_file(const std::vector<std::string>& words);

/*!
* \brief Функция сопоставления количества слов в двух входных файлах
* \param[in] words_1 - вектор слов первого файла
* \param[in] words_2 - вектор слов второго файла
*/
void validate_incorrect_words_count(const std::vector<std::string>& words_1, const std::vector<std::string>& words_2);

/*!
* \brief Функция перевода строки в нижний регистр
* \param[in] sentence - строка, которую нужно перевести в нижний регистр.
*/
void to_lower_string(std::string& sentence);

/*!
* \brief Функция валидации строки на предмет того, что в строке есть символы английского алфавита
* \param[in] sentence - строка, которую нужно проверить на наличие символов английского алфавита.
*/
void validate_english_alphabet(const std::string& sentence);

/*!
* \brief Дополнительная функция для "среза" элементов строки с нужного индекса и в нужном количестве
* \param[in] word -  строка, из которой мы хотим извлечь символы
* \param[in] offset - указывает на индекс символа в строке word, с которого начнется извлечение символов.
* \param[in] count - параметр указывает, сколько символов нужно извлечь из строки
* \return строка, содержащая извлеченные символы
*/
std::string get_needed_chars(const std::string& word, int offset, int count);

/*!
* \brief Функция проверки того, что ошибка заключалась в неправильном сокращении глаголов
* \param[in] word - слово, которое нужно проверить на наличие неправильных сокращений глаголов.
*/
std::string check_abbreviations_in_word(const std::string& word);

/*!
* \brief Функция проверки того, что ошибка заключалась в неправильном употреблении количественных/порядковых числительных
* \param[in] word - слово, которое нужно проверить на наличие неправильных употреблений количественных и порядковых числительных.
*/
std::string check_ordinal_and_cardinal_pronouns(const std::string& word);

/*!
* \brief Функция поиска типа ошибки, допущенного в предложении
* \param[in] right_word - слово - эталон
* \param[in] right_word - слово, проверяющееся на ошибку
*/
std::string check_simple_words(std::string& right_word, std::string& wrong_word);

/*!
* \brief  Функция нахождение того слова, в котором есть ошибка
* \param[in] words_without_errors - вектор слов строки эталона
* \param[in] words_with_errors - вектор слов строки с ошибками
*/
std::string find_errors(std::vector<std::string> words_without_errors, std::vector<std::string> words_with_errors);

