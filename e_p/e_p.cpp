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
std::vector<std::string> split(const std::string& s, char delimeter) {
    std::string word = "";
    std::vector<std::string> words;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != delimeter)
            word += s[i];
        else 
        {
            words.push_back(word);
            word = "";
        }
    }
    if (word.size() >= 1)
        words.push_back(word);
    return words;
}


/*!
* \brief Функция валидирования количества входных аргументов командной строки
* \param[in] argc - количество входных аргументов командной строки
*/
void validate_argument_count(int argc)
{
    if (argc != 4)
    {
        std::cout << " Программа принимает два файла на вход и один на выход. Укажите три файла.\n";
        exit(1);
    }
}


/*!
* \brief Функция, которая читает данные из файла
* \param[in] file_name - путь к файлу чтения
* \return read_data - поток считанных данных из файла
*/
void read_data(const std::string& file_name, std::string& read_data)
{
    std::ifstream in (file_name);
    if (!in.is_open())
    {
        std::cout << " Неверно указан файл с входными данными. Возможно, файл не существует.\n";
        exit(1);
    }
    int count = 0;

    while (std::getline(in, read_data)) {
        count++;
        if (count > 1)
        {
            std::cout << " Программа принимает на вход файлы из одной строки. Разместите каждую строку в отдельный файл.\n";
            exit(1);
        }
    }
    if (count == 0)
    {
        std::cout << " Входной файл пустой. Введите предложение.\n";
        exit(1);
    }
    in.close();
}



/*!
* \brief Функция записи текста в выходной файл
* \param[in] file_name - путь к файлу записи
* \param[in] write_data - поток записываемых данных в файл
*/
void write_data(const std::string& file_name, const std::string& write_data) {
    std::ofstream out(file_name);
    if (!out.is_open())
    {
        std::cout << "Неверно указан файл для выходных данных. Возможно, указанного расположения не существует или нет прав на запись.\n";
        exit(1);
    }
    out << write_data;
    out.close();
}


/*!
* \brief Функция валидации количества слов во входном файле
* \param[in] words - вектор слов файла
*/
void validate_words_count_in_file(const std::vector<std::string>& words)
{
    if ((words.size() < 1) || (words.size() > 10))
    {
        std::cout << "Программа принимает на вход файлы с количеством слов в заданном диапазоне.\n";
        std::cout << "Перепишите файл, чтобы количесcтво слов в нем принадлежало заданному диапазону.\n";
        exit(1);
    }
}


/*!
* \brief Функция сопоставления количества слов в двух входных файлах
* \param[in] words_1 - вектор слов первого файла
* \param[in] words_2 - вектор слов второго файла
*/
void validate_incorrect_words_count(const std::vector<std::string>& words_1, const std::vector<std::string>& words_2) 
{
    validate_words_count_in_file(words_1);
    validate_words_count_in_file(words_2);

    if (words_1.size() > words_2.size())
    {
        std::cout << "Программа принимает на вход файлы с одинаковым количеством слов. \n"; 
        std::cout << "Перепишите предложение, чтобы количество слов в нём было не меньше чем в первом. \n";
        exit(1);
    }
    if (words_1.size() < words_2.size())
    {
        std::cout << "Программа принимает на вход файлы с одинаковым количеством слов. \n";
        std::cout << "Перепишите предложение, чтобы количество слов в нём было не больше чем в первом. \n";
        exit(1);
    }
}



/*!
* \brief Функция перевода строки в нижний регистр
* \param[in] sentence - строка, которую нужно перевести в нижний регистр.
*/
void to_lower_string(std::string& sentence)
{
    for (int i = 0; i < sentence.size(); ++i) {
        sentence[i] = tolower(sentence[i]);
    }
}


/*!
* \brief Функция валидации строки на предмет того, что в строке есть символы английского алфавита
* \param[in] sentence - строка, которую нужно проверить на наличие символов английского алфавита.
*/
void validate_english_alphabet(const std::string& sentence) 
{
    bool flag = false;
    for (int i = 0; i < sentence.size(); ++i)
    {
        if ('a' <= sentence[i] <= 'z') {
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        std::cout << "Программа принимает на вход файлы со словами на английском языке. Перепишите слова, чтобы они содержали буквы английского алфавита.";
        exit(1);
    }
}


/*!
* \brief Дополнительная функция для "среза" элементов строки с нужного индекса и в нужном количестве
* \param[in] word -  строка, из которой мы хотим извлечь символы
* \param[in] offset - указывает на индекс символа в строке word, с которого начнется извлечение символов.
* \param[in] count - параметр указывает, сколько символов нужно извлечь из строки
* \return строка, содержащая извлеченные символы
*/
std::string get_needed_chars(const std::string& word, int offset, int count) 
{
    std::string lastTwoChars;
    if (word.size() >= count)
        lastTwoChars = word.substr(offset, count);
    else
        lastTwoChars = word;
    return lastTwoChars;
}


/*!
* \brief Функция проверки того, что ошибка заключалась в неправильном сокращении глаголов
* \param[in] word - слово, которое нужно проверить на наличие неправильных сокращений глаголов. 
*/
std::string check_abbreviations_in_word(const std::string& word) 
{
    if (word.find('\'') != -1)
    {
        std::vector<std::string> sep_by_mark = split(word, '\'');
        if (sep_by_mark[1] == "ll")
            return "Неправильное употребление вспомогательного глагола future simple. Должно быть “" + sep_by_mark[0] + "’ll / " + sep_by_mark[0] + " will”.";

        std::string reduction[3] = { "m", "s", "re" };
        for (int i = 0; i < 3; ++i)
            if (reduction[i] == sep_by_mark[1])
                return "Неправильное употребление глагола to be. Должно быть “" + word + "”.";

        if (sep_by_mark[1] == "ve")
            return "Пропущено слово have.";
    }
    return "";
}

/*!
* \brief Функция проверки того, что ошибка заключалась в неправильном употреблении количественных/порядковых числительных
* \param[in] word - слово, которое нужно проверить на наличие неправильных употреблений количественных и порядковых числительных. 
*/
std::string check_ordinal_and_cardinal_pronouns(const std::string& word)
{
    std::string ordinal_pronouns[3] = { "first", "second", "third" };
    std::string cardinal_pronouns[30] = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
        "ninety", "hundred", "thousand", "million"
    };

    for (int i = 0; i < 3; ++i)
        if (ordinal_pronouns[i] == word)
            return "Неправильное употребление порядковых числительных. Должно быть  “" + word + "”.";

    for (int i = 0; i < 30; ++i)
    {
        // Проверим не составные количественные и порядковые числительные
        if (cardinal_pronouns[i] == word)
            return "Неправильное употребление числительных. Должно быть  “" + word + "”.";
        else if (get_needed_chars(word, word.size() - 2, 2) == "th" &&
            get_needed_chars(cardinal_pronouns[i], 0, 3) == get_needed_chars(word, 0, 3))
            return "Неправильное употребление порядковых числительных. Должно быть “" + word + "”.";
        // Проверим составные количественные и порядковые числительные (например, twenty-four или twenty-seventh)
        else if (word.find('-') != -1)
        {
            std::vector<std::string> sep_by_mark = split(word, '-');
            if (sep_by_mark[1] == cardinal_pronouns[i])
                return "Неправильное употребление числительных. Должно быть  “" + word + "”.";
            else if (get_needed_chars(word, word.size() - 2, 2) == "th" &&
                get_needed_chars(cardinal_pronouns[i], 0, 3) == get_needed_chars(sep_by_mark[1], 0, 3))
                return "Неправильное употребление порядковых числительных. Должно быть “" + word + "”.";
        }
    }
    return "";
}



/*!
* \brief Функция поиска типа ошибки, допущенного в предложении
* \param[in] right_word - слово - эталон 
* \param[in] right_word - слово, проверяющееся на ошибку 
*/
std::string check_simple_words(std::string& right_word, std::string& wrong_word) 
{
    std::string articles[3] = { "a", "an", "the" };
    std::string personal_pronouns[7] = { "i", "you", "he", "she", "it", "we", "they" };
    std::string possessive_pronouns[7] = { "my", "your", "his", "her", "its", "our", "their" };
    std::string demonstrative_pronouns[4] = { "this", "that", "these", "those" };
    std::string prepositions[7] = { "in", "on", "under", "between", "behind", "below", "above" };
    std::string to_be[5] = { "am", "is", "are", "isn’t", "aren’t" };
    std::string modal_verbs[4] = { "can", "can’t", "must", "will" };
    std::string question_words[9] = { "what", "where", "when", "why", "who", "which", "whose", "whom", "how" };
    std::string auxiliary_verbs_present_simple[4] = { "do", "does", "don’t", "doesn’t" };
    std::string auxiliary_verbs_past_simple[2] = { "did", "did’t"};
    std::string auxiliary_verbs_future_simple[2] = { "will", "won’t" };


    for (int i = 0; i < 4; ++i)
        if (auxiliary_verbs_present_simple[i] == right_word)
            return "Неправильное употребление вспомогательного глагола present simple. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 2; ++i)
        if (auxiliary_verbs_past_simple[i] == right_word)
            return "Неправильное употребление вспомогательного глагола past simple. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 2; ++i)
        if (auxiliary_verbs_future_simple[i] == right_word)
            return "Неправильное употребление вспомогательного глагола future simple. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 3; ++i)
        if (articles[i] == right_word)
            return "Неправильное употребление артикля. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 7; ++i)
        if (personal_pronouns[i] == right_word)
            return "Неправильное употребление личного местоимения. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 7; ++i)
        if (possessive_pronouns[i] == right_word)
            return "Неправильное употребление притяжательного местоимения. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 4; ++i)
        if (demonstrative_pronouns[i] == right_word)
            return "Неправильное употребление указательного местоимения. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 7; ++i)
        if (prepositions[i] == right_word)
            return "Неправильное употребление предлога. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 5; ++i)
        if (to_be[i] == right_word)
            return "Неправильное употребление глагола to be. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 4; ++i)
        if (modal_verbs[i] == right_word)
            return "Неправильное употребление модальных глаголов. Должно быть “" + right_word + "”.";

    for (int i = 0; i < 5; ++i)
        if (question_words[i] == right_word)
            return "Неправильное употребление вопросительных слов. Должно быть “" + right_word + "”.";

    if (check_ordinal_and_cardinal_pronouns(right_word) != "")
        return check_ordinal_and_cardinal_pronouns(right_word);

    if (check_abbreviations_in_word(right_word) != "")
        return check_abbreviations_in_word(right_word);

    if (get_needed_chars(right_word, right_word.size() - 2, 2) == "ed" && 
        get_needed_chars(right_word, 0, wrong_word.size()) == wrong_word)
        return "Неправильное употребление глагола past simple. Должно быть “" + right_word + "”.";

    if (right_word[right_word.size() - 1] == 's' && wrong_word != right_word)
        return "Неправильное употребление формы слова, оканчивающейся на “s”. Должно быть “" + right_word + "”.";

    if (wrong_word != right_word)
        return "Употреблено неверное слово. Должно быть “" + right_word + "”.";
}


//
/*!
* \brief  Функция нахождение того слова, в котором есть ошибка 
* \param[in] words_without_errors - вектор слов строки эталона
* \param[in] words_with_errors - вектор слов строки с ошибками
*/
std::string find_errors(std::vector<std::string> words_without_errors, std::vector<std::string> words_with_errors)
{
    for (int i = 0; i < words_without_errors.size() - 1; ++i) {
        if ((words_without_errors[i] == words_with_errors[i + 1]) && (words_without_errors[i + 1] == words_with_errors[i]))
            return "Неправильный порядок слов в предложении. Должно быть “" + words_without_errors[i] + " " + words_with_errors[i] + "”.";
    }

    for (int i = 0; i < words_without_errors.size(); ++i)
        if (words_without_errors[i] != words_with_errors[i])
           return check_simple_words(words_without_errors[i], words_with_errors[i]);
}


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    // Проверим, что количество аргументов командной строки совпадает с нужным и запомним названия файлов
    validate_argument_count(argc);
    std::string file_without_errors = argv[1];
    std::string file_with_errors = argv[2];
    std::string output_file = argv[3];
   
    // Считаем данные из файлов в две строчки
    std::string data_without_errors;
    std::string data_with_errors;
    read_data(file_without_errors, data_without_errors);
    read_data(file_with_errors, data_with_errors);
   
    // перенесем все данные в нижний регистр и поймем, есть ли в данных английские слова
    to_lower_string(data_without_errors);
    to_lower_string(data_with_errors);

    validate_english_alphabet(data_without_errors);
    validate_english_alphabet(data_with_errors);

    // Разобьем данные по массивам слов и проверим, совпадает ли в файлах количество слов
    std::vector<std::string> words_without_errors = split(data_without_errors, ' ');
    std::vector<std::string> words_with_errors = split(data_with_errors, ' ');
    validate_incorrect_words_count(words_without_errors, words_with_errors);

    // Вызовем функцию, которая занимается поиском ошибки и записывает выходные данные в файл
    write_data(output_file, find_errors(words_without_errors, words_with_errors));
}
